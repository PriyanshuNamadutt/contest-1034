#include<iostream>
#include<vector>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }

        vector<int> prev( n, 0);
        int mn = a[0];
        for ( int i = 1; i < n-1; i++ ) {
            if ( a[i] > mn ) prev[i] = 0;
            else prev[i] = 1;

            mn = min( mn, a[i] );
        }
        int mx = a[n-1];
        vector<int> next(n ,0 );
        for ( int i = n-2; i > 0; i-- ) {
            if ( a[i] < mx ) next[i] = 0;
            else next[i] = 1;

            mx = max( mx, a[i] );
        }
        cout << 1;
        for ( int i = 1; i < n-1; i++ ) {
            cout << ( prev[i] && next[i] ? 1 : 0 );
        }
        cout << 1 << endl;
    }
    return 0;
}
