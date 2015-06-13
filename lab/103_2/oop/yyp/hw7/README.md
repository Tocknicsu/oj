void print(stringstream &ss){
    string str;
    getline(ss, str);
    for(int i = 0 ; i < (int)str.size() ; i++)
        cout << hex << (((int)str[i])&255) << ' ';
    ss.seekg(0, ss.beg);
    cout << endl;
}
