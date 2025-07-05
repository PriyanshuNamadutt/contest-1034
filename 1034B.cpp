#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n, j, k;
        cin >> n >> j >> k;
        int mx = 0;
        j--;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
            mx = max( mx, a[i] );
        }

        if ( k > 1 || ( k == 1 && a[j] == mx ) ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
