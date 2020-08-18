
#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int tc,n,v;
    cin >> tc;
    while(tc--) {
        cin >> n;
        vector<ll> v1(n);
        for(int i=0;i<n;i++) {cin >> v1[i];}
        sort(v1.begin(), v1.end());
        int res = 0;
        for(int i=1;i<=n*2;i++) {
            int low = 0, high = v1.size()-1;
            int subres = 0;
            while(low<high) {
                int sum = v1[low] + v1[high];
                if(sum==i) {
                    subres++;
                    low++; high--;
                } else if(sum>i) high--;
                else low++;
            }
            res = max(subres, res);
        }
        cout << res << "\n";
    }
}
