#include<bits/stdc++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<int> vis( n+1, 0 );
        vector<int> ans( n+1 );

        for ( int i = 3; i <= n; i += 2 ) {
            if( vis[i] ) continue;

            if ( 2*i <= n ) vis[i] = 1;
            int j = 2;
            int k = 1;
            while ( j*i <= n ) {
                if ( !vis[j*i] ) {
                    vis[j*i] = 1;
                    ans[k*i] = j*i;
                    k = j;
                }
                j++;
            }
            ans[k*i] = i;
        }
        int j = 2;
        int k = 1;
        vis[2] = 1;
        while ( j*2 <= n ) {
            if ( !vis[j*2] ) {
                vis[j*2] = 1;
                ans[k*2] = j*2;
                k = j;
            }
            j++;
        }
        ans[k*2] = 2;

        for ( int i = 1; i <= n; i++ ) {
            if ( !vis[i] ) cout << i << " ";
            else cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
