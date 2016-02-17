#include <vector>
#include <cstdio>
using namespace std;
#define MAX 1048576
typedef long long ll;
int p;
int rev_mod[MAX];
int mpow(ll a, int b){
    ll re = 1;
    while(b){
        if(b&1)
            re = a * re % p;
        a = a * a % p;
        b >>= 1;
    }
    return re;
}
class Matrix{
public:
    vector<vector<ll> > D;
    int R, C;
    Matrix(): R(0), C(0) {}

    Matrix(int r, int c): R(r), C(c) {
        D = vector< vector<ll> > (R);
        for(int i  = 0 ; i < R ; i++)
            D[i] = vector<ll>(C);
    }

    ll& at(const int &rhs1, const int &rhs2) {
        return D[rhs1][rhs2];
    }

    const ll& at(const int &rhs1, const int &rhs2) const {
        return D[rhs1][rhs2];
    }

    vector<ll> Solve() {
        vector<ll> res(R);
        for(int i = 0 ; i < R ; i++){
            for(int j = i ; j < R ; j++){
                if(at(j, i)){
                    swap(D[i], D[j]);
                    break;
                }
            }
            for(int j = 0 ; j < R ; j++){
                if(i == j) continue;
                int t = at(j, i) * rev_mod[at(i, i)] % p;
                for(int k = i ; k < C ; k++){
                    at(j, k) -= at(i, k) * t % p;
                    at(j, k) = (at(j, k) + p) % p;
                }

            }
        }
        return res;
    }
};
int main(){
    scanf("%d", &p);
    for(int i = 1 ; i < p ; i++){
        rev_mod[i] = mpow(i, p-2);
    }
    int t;
    while(scanf("%d", &t), t){
        Matrix m(t, t + 1);
        for(int i = 0 ; i < t ; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            m.at(i, 0) = 1;
            for(int j = 1 ; j < t ; j++){
                m.at(i, j) = m.at(i, j-1) * x % p;
            }
            m.at(i, t) = y;
        }
        m.Solve();
        printf("%lld\n", m.at(0, t));
    }
    return 0;
}

