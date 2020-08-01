#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> to_base(int val, int base, int len) {
    vector<int> res;
    while(val) {
        int digit = val % base;
        res.push_back(digit+1); // 1-indexed
        val /= base;
    }
    vector<int> actual(len, 1);
    for(int i=0;i<res.size();i++) actual[len-1-i] = res[i];
    return actual;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,k,d;
    // notice that we have total of k^d possible sequence
    // and we are trying to n unique sequence
    // by pigeonhole principle, n>k^d then no answer is available
    // otherwise, just assign them n of them in base k
    cin >> n >> k >> d;
    double possible = pow(k, d);
    if(n > possible) {
        cout << "-1"; return 0;
    }
    int res[d][n];
    for(int i=0;i<n;i++) {
        auto allocation = to_base(i, k, d);
        for(int j=0;j<d;j++) res[j][i] = allocation[j];
    }
    for(int i=0;i<d;i++) {
        for(int j=0;j<n;j++) {
            if(j) cout << " ";
            cout << res[i][j];
        }
        cout << "\n";
    }
}
