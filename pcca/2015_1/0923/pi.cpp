#include <bits/stdc++.h>
using namespace std;
#define MAX 1048576 
#define f first
#define s second
typedef pair<int, int> PII;
map<int, PII> M;    //pos, size
int Rand(){
    static int x = 192837;
    return x = x * 0xdefabcd+1;
}
struct Node{
    Node *L, *R;
    int val, sz, pri, lazy, mm, mx;
    Node(int _v) : L(NULL), R(NULL), val(_v), sz(1), pri(Rand()), lazy(0), mm(_v), mx(_v) {}
};
int size(Node *x){
    return x ? x->sz : 0;
}
void up(Node *x){
    x->sz = size(x->L) + size(x->R) + 1;
    x->mm = x->mx = x->val;
    if(x->L){
        x->mm = min(x->mm, x->L->mm);
        x->mx = max(x->mx, x->L->mx);
    }
    if(x->R){
        x->mm = min(x->mm, x->R->mm);
        x->mx = max(x->mx, x->R->mx);
    }
}
void down(Node *x){
    if(x->L){
        x->L->val += x->lazy;
        x->L->mm += x->lazy;
        x->L->mx += x->lazy;
        x->L->lazy += x->lazy;
    }
    if(x->R){
        x->R->val += x->lazy;
        x->R->mm += x->lazy;
        x->R->mx += x->lazy;
        x->R->lazy += x->lazy;
    }
    x->lazy = 0;
}
Node* Merge(Node *a, Node *b){
    if(!a || !b) return a ? a : b;
    if(a->pri > b->pri){
        down(a);
        a->R = Merge(a->R, b);
        up(a);
        return a;
    } else {
        down(b);
        b->L = Merge(a, b->L);
        up(b);
        return b;
    }
}
void Split(Node *now, Node *&a, Node *&b, int k){
    if(k==0) a = NULL, b = now;
    else if(k == size(now)) a = now, b = NULL;
    else{
        if(size(now->L) >= k){
            b = now;
            down(b);
            Split(now->L, a, b->L, k);
            up(b);
        } else {
            a = now;
            down(a);
            Split(now->R, a->R, b, k-size(now->L)-1);
            up(a);
        }
    }
}
void print(Node *now){
    if(!now) return;
    down(now);
    print(now->L);
    printf("%d %d %d %d\n", now->val, now->mm, now->mx, now->lazy);
    print(now->R);
}

int val[MAX];
vector<int> ed[MAX];
vector<int> ary;

int dfs(int x){
    M[x] = PII(ary.size(), 0);
    ary.push_back(x);
    for(int i = 0 ; i < (int)ed[x].size() ; i++)
        M[x].s += dfs(ed[x][i]);
    return M[x].s += 1;
}
void del(Node *now){
    if(!now) return;
    del(now->L);
    del(now->R);
    delete now;
}

void Solve(){
    int n;
    scanf("%d", &n);
    cout << n << endl;
    for(int i = 0 ; i <= n ; i++)
        ed[i].clear();
    cout << "Holy" << endl;
    ary.clear();
    M.clear();
    for(int i = 2 ; i <= n ; i++){
        int x;
        scanf("%d", &x);
        ed[x].push_back(i);
    }
    cout << "QQonly" << endl;
    for(int i = 1 ; i <= n ; i++)
        scanf("%d", &val[i]);
    stack<PII> dfs;
    dfs.push(PII(1, 0));
    while(dfs.size()){
        int x = dfs.top().f;
        int i = dfs.top().s;
        if(dfs.top().s >= (int)ed[dfs.top().f].size()) continue;
        dfs.top().s += 1;
        
        if(i+1 < (int)ed[x].size())
            dfs.push(PII(x, i+1));

    }
    /*
    stack<int> s;
    s.push(1);
    */
    Node *root = NULL;
    for(int i = 0 ; i < (int)ary.size() ; i++){
        cout << i << endl;
        Node *x = new Node(val[ary[i]]);
        root = Merge(root, x);
    }
    Node *a, *b, *c;
    int q;
    scanf("%d", &q);
    cout << q << endl;
    char s[2];
    while(q--){
        scanf("%s", s);
        int t;
        scanf("%d", &t);
        Split(root, a, b, M[t].f);
        Split(b, b, c, M[t].s);
        if(s[0] == 'Q'){
    //        printf("%d\n", b->mx - b->mm);
        } else {
            scanf("%d", &t);
            b->val += t;
            b->lazy += t;
            b->mm += t;
            b->mx += t;
        }
        root = Merge(a, b);
        root = Merge(root, c);
    }
    del(root);
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--)
        Solve();
    return 0;
}
