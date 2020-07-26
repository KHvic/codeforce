#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m, s;
    double v;
    cin >> n >> m;
    // idea: basically finding LIS, replant the rest
    vector<int> lis;
    for(int i=0;i<n;i++) {
        cin >> s >> v;
        // >= next
        auto it = upper_bound(lis.begin(), lis.end(), s);
        if(it == lis.end()) {
            lis.push_back(s);
        } else {
            *it = s;
        }
    }
    cout << n - lis.size();
}
