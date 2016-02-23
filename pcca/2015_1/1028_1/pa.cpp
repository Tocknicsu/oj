#include <bits/stdc++.h>
using namespace std;

#define CHARMAX 29

char s[32768][128];
int cnt;

struct Node {
    char s;
    vector<int> ans;
    Node *next[CHARMAX];
    void init(){
        for(int i = 0 ; i < CHARMAX ; i++)
            next[i] = 0;
    }
    Node(){init();}
    Node(char _s){
        init();
        s = _s;
    }
};

Node *root;
Node *other;
void insert(Node *r, char str[], int id){
    Node *now = r;
    for(int i = 0 ; str[i] ; i++){
        if(r == root){
            if(str[i] == '.') continue;
            if(str[i] == '+') break;
            if(str[i] == '@') break;
        }
        int next = (int)str[i];
        if(next == '.') next = 26;
        else if(next == '+') next = 27;
        else if(next == '@') next = 28;
        else if(next >= 'A' && next <= 'Z') next = next - 'A';
        else next = next - 'a';
        if(now->next[next] == NULL){
            now->next[next] = new Node(char(next));
        }
        now = now->next[next];
    }
    if((*now).ans.size()) cnt--;
    (*now).ans.push_back(id);
}
void travel(Node* now, bool p = 0){
    if( (*now).ans.size() ){
        if(p){
            printf("%d", (int)(*now).ans.size());
            for(int i = 0 ; i < (int)(*now).ans.size() ; i++){
                printf(" %s", s[(*now).ans[i]]);
            }
            printf("\n");
        }
    }
    for(int i = 0 ; i < CHARMAX ; i++){
        if(now->next[i]){
            travel(now->next[i], p);
        }
    }
}
bool check(char str[]){
    int len = strlen(str);
    char com[] = "@bmail.com";
    char *com_now = com;
    char *str_now = str + len - 10;
    for(int i = 0 ; i < 10 ; i++, com_now++, str_now++){
        if(*com_now == *str_now) continue;
        if( ((*com_now) | 32) == ((*str_now) | 32) )continue;
        return false;
    }
    return true;
    
}

int main(){
    root = new Node();
    other = new Node();
    int n;
    scanf("%d", &n);
    cnt = n;
    for(int i = 0 ; i < n ; i++){
        scanf("%s", s[i]);
        if(check(s[i])){
            insert(root, s[i], i);
        } else {
            insert(other, s[i], i);
        }
    }
    printf("%d\n", cnt);
    travel(root, 1);
    travel(other, 1);
    return 0;
}
