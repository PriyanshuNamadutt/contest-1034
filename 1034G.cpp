#include<bits/stdc++.h>
using namespace std;

bool solve( vector<int> &a, int &k, int &m ) {
    vector<int> temp = a;
    int gd = __gcd( k, m);
    int it = m/gd;
    int sum = temp[0];
    for ( int i = 0; i < it; i++ ) {
        temp[0] = min( temp[0], sum % m );
        sum += k;
    }

    for ( int i = 1; i < a.size(); i++ ) {
        int cnt = temp[i];
        vector<int> v(it);
        for ( int j = 0; j < it; j++ ) {
            v[j] = cnt % m;
            cnt += k;
        }
        sort( v.begin(), v.end() );
        auto val = lower_bound( v.begin(), v.end(), temp[i-1] );

        if ( val != v.end() ) temp[i] = *val;
        else return false;
    }
    return true;
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }

        for ( int i = 0; i < q; i++ ) {
            int x; cin >> x;
            if ( x == 1 ) {
                int idx, num;
                cin >> idx >> num;
                idx -= 1;
                a[idx] = num;
            }
            else {
                int k; cin >> k;
                cout << ( solve( a, k, m) ? "YES" : "NO" ) << endl;
            }
        }
    }
    return 0;
}
