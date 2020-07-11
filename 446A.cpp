#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> leftInc(n,1), rightDec(n,1);
    vector<int> vals(n);
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        if(i>0 && vals[i] > vals[i-1]) leftInc[i] = leftInc[i-1]+1;
    }
    for(int i=n-2;i>=0;i--) {
        if(vals[i] < vals[i+1]) rightDec[i] = rightDec[i+1]+1;
    }
    int res = 1;

    for(int i=0;i<n;i++){
        if(i<n-1) res = max(res, rightDec[i+1] + 1);
        if(i>0) res = max(res, leftInc[i-1] + 1);
        // middle
        if(i>0 && i<n-1 && vals[i+1] - vals[i-1] > 1)
            res = max(res, 1+leftInc[i-1]+rightDec[i+1]);
    }
    cout << res;
}
