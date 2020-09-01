#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fastio
    // find previous and next smallest index for each i
    // then given an index i, it is the smallest element for an array of size nle[i] - ple[i] - 1
    int n;
    cin >> n;
    vector<int> ple(n,-1), nle(n,n);
    stack<int> mstack;
    vector<int> vals(n), res(n,-1);
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        while(!mstack.empty() && vals[i] < vals[mstack.top()]) {
            int idx = mstack.top(); mstack.pop();
            nle[idx] = i;
        }
        if(!mstack.empty()) ple[i] = mstack.top();
        mstack.push(i);
    }

    for(int i=0;i<n;i++) {
        int len = nle[i] - ple[i] - 1; // is the smallest element for an length sized array
        res[len-1] = max(res[len-1], vals[i]);
    }
    // key observation: if there exist a len s array with smallest element of value x
    // then there exist an array of len s-1 with at least smallest element of value x
    for(int i=n-1;i>=0;i--) {
        if(i<n-1) res[i] = max(res[i], res[i+1]);
    }
    for(int i=0;i<n;i++) cout << res[i] << " \n"[i==n-1];
}
