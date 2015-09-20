#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unsigned Rand(){
    static unsigned x = 1234567;
    return x = x * 0xdefabcd+1;
}
struct Node{
    Node *L, *R;
    int val, sz, pri;
    ll sum;
    Node(int _v) : L(NULL), R(NULL), val(_v), sz(1), pri(Rand()), sum(_v) {}
};
int size(Node *x){
    return x ? x->sz : 0;
}
void up(Node *x){
    x->sz = size(x->L) + size(x->R) + 1;
    x->sum = x->val;
    if(x->L){
        x->sum += x->L->sum;
    }
    if(x->R){
        x->sum += x->R->sum;
    }
}
void _print(Node* now){
    if(!now) return;
    _print(now->L);
    printf("%d ", now->val);
    _print(now->R);
}
void print(Node* now){
    _print(now);
    cout << endl;
}
vector<Node*> root;
Node* Merge(Node *a, Node *b, bool add = false){
    if(!a || !b) return a ? a : b;
    if(a->pri > b->pri){
        if(add){
            Node *r = new Node(a->val);
            r->pri = a->pri;
            r->L = a->L;
            r->R = Merge(a->R, b, add);
            up(r);
            return r;
        } else{
            a->R = Merge(a->R, b);
            up(a);
            return a;
        }
    } else {
        if(add){
            Node *r = new Node(b->val);
            r->pri = b->pri;
            r->L = Merge(a, b->L, add);
            r->R = b->R;
            up(r);
            return r;
        } else {
            b->L = Merge(a, b->L);
            up(b);
            return b;
        }
    }
}
Node* build(int n){
    Node *r = NULL;
    for(int i = 1 ; i <= n ; i++){
        r = Merge(r, new Node(0));
    }
    return r;
}
void Split(Node *now, Node *&a, Node *&b, int k){
    if(k == 0) a = NULL, b = now;
    else if(k == size(now)) a = now, b = NULL;
    else{
        if(size(now->L) >= k){
            b = now;
            Split(now->L, a, b->L, k);
            up(b);
        } else {
            a = now;
            Split(now->R, a->R, b, k-size(now->L)-1);
            up(a);
        }
    }
}
ll query(Node* x, int l, int r){
    Node *a, *b, *c;
    Split(x, b, c, r);
    Split(b, a, b, l-1);
    ll re = b->sum;
    b = Merge(a, b);
    b = Merge(b, c);
    return re;
}
Node* update(Node* x, int p, int v){
    Node *a, *b, *c;
    Split(x, b, c, p);
    Split(b, a, b, p-1);
    Node *node = new Node(v);
    node->pri = b->pri;
    Node *nroot;
    nroot = Merge(a, node, 1);
    nroot = Merge(nroot, c, 1);
    b = Merge(a, b);
    b = Merge(b, c);
    return nroot;
}
int main(){
    int n, t;
    scanf("%d%d", &n, &t);
    root.push_back(build(n));
    for(int i = 0 ; i < t ; i++){
        int a, b, c;
        scanf("%d", &a);
        if(a == 1){
            scanf("%d%d", &b, &c);
            root.push_back(update(root.back(), b, c));
        } else if(a == 2) {
            scanf("%d%d", &b, &c);
            printf("%lld\n", query(root.back(), b, c));
            root.push_back(root.back());
        } else {
            scanf("%d", &b);
            root.push_back(root[root.size()-b-1]);
        }
    }


}
