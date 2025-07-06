#include<iostream>
#include<vector>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<int> a( n+1, 0);
        vector<int> vis( n+1, 0);
        for ( int i = 0; i < n; i++ ) {
            int x; cin >> x;
            a[x]++;
            vis[x] = 1;
        }

        int num = 0;
        while( num <= n ) {
            if ( vis[num] ) num++;
            else break;
        }

        vector<int> ans( n+1, 0 );
        for ( int i = 0; i <= num; i++ ) {
            for ( int j = a[i]; j <= n-i; j++ ) {
                ans[j]++;
            }
        }
        for ( int i = 0; i <= n; i++ ) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
