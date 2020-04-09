#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n,v;
    vector<pair<int,int>> cans;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v;
        cans.push_back({v,i+1});
    }
    sort(cans.begin(),cans.end(),greater<pair<int,int>>());
    int res = 0;
    for(int i=0;i<n;i++) {
        res += (cans[i].first*i + 1);
    }
    cout << res << endl;
    for(auto& p : cans) {
        cout << p.second;
        if(&p == &cans.back()) cout << endl;
        else cout << " ";
    }
}
