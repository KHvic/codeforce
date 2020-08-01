#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> kmp_preprocess(vector<int>& pattern) {
    int n = pattern.size();
    vector<int> backtable(n+1);
    backtable[0] = -1;
    int i=0, j=-1;
    while(i<n) {
        while(j>=0 && pattern[j] != pattern[i]) j = backtable[j];
        backtable[++i] = ++j;
    }
    return backtable;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> vals1(n), vals2(m);
    for(int i=0;i<n;i++) cin >> vals1[i];
    for(int i=0;i<m;i++) cin >> vals2[i];
    if(m==1) {
        cout << n << "\n";
        return 0;
    }

    vector<int> diff1(n-1), diff2(m-1);
    for(int i=0;i<n-1;i++) diff1[i] = vals1[i] - vals1[i+1];
    for(int i=0;i<m-1;i++) diff2[i] = vals2[i] - vals2[i+1];

    // kmp
    auto backtable = kmp_preprocess(diff2);
    int i=0,j=0,res=0;
    while(i<diff1.size()) {
        while(j>=0 && diff1[i] != diff2[j]) j = backtable[j];
        j++; i++;
        if(j==diff2.size()) {
            res++;
            j = backtable[j];
        }
    }
    cout << res;
}
