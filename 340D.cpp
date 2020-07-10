#include <bits/stdc++.h>
using namespace std;
#define ll long long

// two observation
// exist an edge between i and j (i<j) only if ai > aj
// no edge if ai < aj, thus the problem can be reduced to longest increasing subsequence to find MIS
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, v;
    cin >> n;
    vector<int> lis;
    for(int i=0;i<n;i++) {
        cin >> v;
        auto lower = lower_bound(lis.begin(), lis.end(), v);
        if(lower == lis.end()) lis.push_back(v);
        else *lower = v;
    }
    cout << lis.size();
}
