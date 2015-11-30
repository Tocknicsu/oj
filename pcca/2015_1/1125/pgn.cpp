#include <bits/stdc++.h>
using namespace std;
#define INF 1029384756
#define MAX 300003
int state[MAX];
int status[MAX];
char str[MAX];
struct Node{
    int lazy;
    int _min;
    int rl, rr;
    Node *l, *r;
    Node() : lazy(0), l(NULL), r(NULL){}
};
void print(){
    int len = strlen(str);
    for(int i = 1 ; i <= len ; i++)
        printf("%c", state[i] ? ')' : '(');
    printf("\n");
}
Node* root;
void pull(Node* now){
    now->_min = INF;
    if(now->l){
        now->_min = min(now->l->_min, now->_min);
    }
    if(now->r){
        now->_min = min(now->r->_min, now->_min);
    }
    now->_min += now->lazy;
}
Node* build(Node *now, int l, int r){
    if(l + 1 == r){
        now = new Node();
        now->rl = l;
        now->rr = r;
        now->_min = status[l];
    } else {
        now = new Node();
        int mid = (l+r) / 2;
        now->l = build(now->l, l, mid);
        now->r = build(now->r, mid, r);
        now->rl = l;
        now->rr = r;
        pull(now);
    }
    return now;
}
int query(Node *now, int l, int r){
    if(now == NULL){
        return INF;
    }
    if(now->rr <= l || r <= now->rl){
        return INF;
    }
    if(l <= now->rl && now->rr <= r){
        return now->_min;
    }
    return min(query(now->l, l, r), query(now->r, l, r)) + now->lazy;
}
void update(Node *now, int l, int r, int value){
    if(now == NULL){
        return;
    }
    if(now->rr <= l || r <= now->rl){
        return;
    }
    if(l <= now->rl && now->rr <= r){
        now->lazy += value;
        now->_min += value;
    } else {
        update(now->l, l, r, value);
        update(now->r, l, r, value);
        pull(now);
    }
}

int main(){
    //freopen("pg.in", "r", stdin);
    int n, q;
    set<int> r;
    scanf("%d%d", &n, &q);
    scanf("%s", str);
    for(int i = 1 ; i <= n ; i++){
        state[i] = str[i-1] == ')';
        status[i] = status[i-1] + (str[i-1] == '(' ? 1 : -1);
        if(str[i-1] == ')')
            r.insert(i);
    }
    root = build(root, 1, n+1);
    int t;
    for(int i = 0 ; i < q ; i++){
        scanf("%d", &t);
        if(state[t]){
            state[t] ^= 1;
            update(root, t, n+1, 2);
            int now = n, step = n / 2;
            r.erase(t);
            while(step){
                int x = query(root, now-step, n+1);
                if(x >= 2){
                    now -= step;
                } else {
                    step >>= 1;
                }
            }
            printf("%d\n", now);
            state[now] ^= 1;
            update(root, now, n+1, -2);
            r.insert(now);
        } else {
            state[t] ^= 1;
            update(root, t, n+1, -2);
            r.insert(t);
            int now = *r.begin();
            r.erase(now);
            update(root, now, n+1, +2);
            printf("%d\n", now);
            state[now] ^= 1;
        }
    //    print();
    }
    return 0;
}
