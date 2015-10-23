#include "sh.h"

SH::SH(){
}
void SH::init(){
    chdir("./ras");
    std::cout << setenv("PATH", "bin:.", 1) << std::endl;
}
bool can_exec(std::string file){
    std::string path = getenv("PATH");
    std::vector<std::string> dir;
    dir.push_back("");
    for(int i = 0 ; i < (int)path.size() ; i++){
        if(path[i]==':') dir.push_back("");
        else dir.back().push_back(path[i]);
    }
    for(int i = 0 ; i < (int)dir.size() ; i++){
        std::string look_file = dir[i] + std::string("/") + file;
        struct stat st;
        if (stat(look_file.c_str(), &st) >= 0)
            if ((st.st_mode & S_IEXEC) != 0)
                return true;
    }
    return false;
}
std::string SH::get_cwd(){
    char buffer[1024];
    getcwd(buffer, 1024);
    return std::string(buffer);
}
std::vector<std::string> SH::parse_single_cmd(std::string str){
    std::vector<std::string> cmd;
    cmd.push_back("");
    for(int i = 0 ; i < (int)str.size() ; i++){
        if(str[i] == ' '){
            if(cmd.back().size())
                cmd.push_back("");
        } else {
            cmd.back().push_back(str[i]);
        }
    }
    while(cmd.size() && !cmd.back().size())
        cmd.pop_back();
    return cmd;
}
void SH::external(std::vector<std::string> cmd){
    char **args;
    args = new char*[cmd.size()+1];
    for(int i = 0 ; i < (int)cmd.size() ; i++){
        args[i] = new char[cmd[i].size()+1];
        strcpy(args[i], cmd[i].c_str());
    }
    args[cmd.size()] = 0;
    if(execvp(cmd[0].c_str(), args)){
        std::cout << "Command not found: " << cmd[0] << std::endl;
    }
    exit(1);
}
int SH::internal(std::string cmd){
    std::vector<std::string> parse_cmd = parse_single_cmd(cmd);
    if(parse_cmd.size()==0) return false;
    if(parse_cmd[0] == std::string("exit")){
        exit(0);
    } else if(parse_cmd[0] == std::string("setenv")){
        setenv(parse_cmd[1].c_str(),parse_cmd[2].c_str(),1);
        return true;
    } else if(parse_cmd[0] == std::string("printenv")){
        std::cout << getenv(parse_cmd[1].c_str()) << std::endl;
        return true;
    }
    return false;
}
void SH::create_map_pipe(int num){
    if(pipemap.find(num) == pipemap.end()){
        pipemap[num] = PIPE();
        pipe(pipemap[num].pip);
    }
}
int SH::exec(std::string cmd){
    std::stringstream ss(cmd);
    std::vector<std::string> cmds;
    cmds.push_back("");
    while(ss >> cmd){
        if(cmd != "|")
            cmds.back() += (cmds.back().size()?" ":"")+cmd;
        else
            cmds.push_back("");
    }
    if(internal(cmds[0]))
        return 0;
    std::vector<std::vector<std::string> > parse_cmd;
    for(int i = 0 ; i < (int)cmds.size() ; i++){
        parse_cmd.push_back(parse_single_cmd(cmds[i]));
        if(!can_exec(parse_cmd[i][0])){
            std::cout << "Unknown command: [" << parse_cmd[i][0] << "]." << std::endl;
            break;
        }
    }

    int first_pid = 0;
    int pip_num = cmds.size() - 1;
    int pip[pip_num][2];
    for(int i = 0 ; i < pip_num ; i++)
        pipe(pip[i]);


    int last_stderr = -1;
    int last_stdout = -1;



    for(int i = 0 ; i < (int)parse_cmd.size() ; i++){
        if(i == 0){
            m_count++;
            if(pipemap.find(m_count) != pipemap.end())
                close(pipemap[m_count].pip[1]);
        }
        if(i == cmds.size() - 1){
            for(int k = 0 ; k < 2 ; k++){
                if(parse_cmd[i].size() > 1 && parse_cmd[i].back()[0] == '|'){
                    last_stdout = atoi(parse_cmd[i].back().substr(1, parse_cmd[i].back().size()-1).c_str());
                    parse_cmd[i].pop_back();
                }
                if(parse_cmd[i].size() > 1 && parse_cmd[i].back()[0] == '!'){
                    last_stderr = atoi(parse_cmd[i].back().substr(1, parse_cmd[i].back().size()-1).c_str());
                    parse_cmd[i].pop_back();
                }
            }
            std::cout << last_stderr << ' ' << last_stdout << std::endl;
            if(last_stderr != -1){
                create_map_pipe(m_count+last_stderr);
            }
            if(last_stdout != -1){
                create_map_pipe(m_count+last_stdout);
            }
        }
        int pid = fork();
        /*
        if(i == 0){
            m_count++;
            if(pipemap.find(m_count) != pipemap.end()){
                close(pipemap[m_count].pip[1]);
            }
        }
        */
        if(pid){
            setpgid(pid, first_pid);
            if(!first_pid)
                first_pid = pid;
        } else {
            if(i == cmds.size() - 1){
                if(parse_cmd[i].size() > 2 && parse_cmd[i][parse_cmd[i].size()-2] == ">"){
                    std::cout << "dup to: " << parse_cmd[i].back() << std::endl;
                    freopen(parse_cmd[i].back().c_str(), "w", stdout);
                    parse_cmd[i].pop_back();
                    parse_cmd[i].pop_back();
                }
            }
            if(i != pip_num)
                dup2(pip[i][1], 1);
            if(i != 0)
                dup2(pip[i-1][0], 0);

            for(int j = 0 ; j < pip_num ; j++)
                close(pip[j][0]), close(pip[j][1]);
            external(parse_cmd[i]);
        }
    }
    if(pipemap.find(m_count) != pipemap.end()){
        close(pipemap[m_count].pip[0]);
        pipemap.erase(pipemap.find(m_count));
    }
    for(int i = 0 ; i < pip_num ; i++)
        close(pip[i][0]), close(pip[i][1]);
    int num = parse_cmd.size();
    int status;
    for(int i = 0 ; i < num ; i++)
        waitpid(-first_pid, &status, 0);
    return 0;
}
void SH::prompt(){
    std::cout << "% " << std::flush;
}
