#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    int t,n,k,a,b,c;
    cin >> n >> k;
    vector<int> both, as, bs;
    for(int i=0;i<n;i++) {
        cin >> a >> b >> c;
        if(b&c) both.push_back(a);
        else if(b) bs.push_back(a);
        else if(c) as.push_back(a);
    }
    sort(both.begin(), both.end());
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    if(both.size() + as.size() < k || both.size() + bs.size() < k) {
        cout << -1 << endl;
    } else {
        int res = 0;
        int i = 0, j = 0;
        while(k>0) {
            if(i>=both.size()) {
                res += as[j] + bs[j];
                j++;
            } else if(j>=bs.size() || j>=as.size()) {
                res += both[i++];
            } else {
                int add = bs[j] + as[j];
                if(add < both[i]) {
                    j++;
                    res += add;
                } else {
                    res += both[i++];
                }
            }
            k--;
        }
        cout << res << endl;
    }
}
