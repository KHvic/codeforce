#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int k;
    string s;
    cin >> k >> s;
    // solution one, count left and right
    //    vector<int> pos(1, -1);
    //    ll res = 0;
    //    int consecutive = 0;
    //    for(int i=0;i<s.size();i++)
    //        if(s[i] == '1') {
    //            pos.push_back(i);
    //            consecutive = 0;
    //        } else if(!k) {
    //            res += ++consecutive;
    //        }
    //    pos.push_back(s.size());
    //    if(k) {
    //        for(int i=k;i<pos.size()-1;i++) {
    //            ll left = pos[i-k+1] - pos[i-k];
    //            ll right = pos[i+1] - pos[i];
    //            res += left*right;
    //        }
    //    }
    //    cout << res;
    // solution two, prefix sum
    int sum = 0;
    unordered_map<int, int> cnt;
    cnt[0] = 1;
    ll res = 0;
    for(char c : s) {
        sum += c - '0';
        res += cnt[sum-k];
        cnt[sum]++;
    }
    cout << res;
}
