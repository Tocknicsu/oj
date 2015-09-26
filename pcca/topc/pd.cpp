#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
typedef pair<ll, ll> PLL;
    std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
void gcd(ll &x, ll &y){
    ll t = __gcd(x, y);
    x /= t;
    y /= t;
}
int main(){

    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        ll rb = b;
        ll tx = 1, ty = 1;
        ll nx = 1, ny = a+b;
        gcd(nx, ny);
        while(rb - 2 >= 0){
            tx = tx * rb;
            ty = ty * (a+rb);
            gcd(tx, ty);
            rb--;
            tx = tx * rb;
            ty = ty * (a+rb);
            gcd(tx, ty);
            rb--;
            ll x = tx;
            ll y = ty * (a+rb);
            gcd(x, y);
            ll _gcd = __gcd(ny, y);
            nx = nx * (y/_gcd) + x * (ny / _gcd);
            ny = ny / _gcd * y;
            gcd(nx, ny);
        }
        nx *= a;
        gcd(nx, ny);
        cout << nx << '/' << ny << endl;
    }
}
