#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string in;
    cin >> in;

    int n = in.size();
    vector<pair<char,int>> groups;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        char c = in[i];
        cnt++;
        // last or not same
        if(i==n-1 || c != in[i+1]) {
            groups.push_back({c,cnt});
            cnt = 0;
        }
    }
    string res = "";
    for(int i=0;i<groups.size();i++) {
        char c = groups[i].first; int cnt = groups[i].second;
        if(cnt>=3) {
            groups[i].second=cnt=2; // delete till two
        }
        if(i && cnt>=2 && groups[i-1].second>=2) {
            groups[i].second=cnt=1;
        }
        for(int j=0;j<cnt;j++) res+=c;
    }
    cout << res;
}
