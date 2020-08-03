#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,t,w;
    vector<int> one, two;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> t >> w;
        if(t==1) one.push_back(w);
        else two.push_back(w);
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());

    int res = INT_MAX;
    // brute force, select all smaller width combination
    // the rest use as vertical books
    int cur_one = 0, cur_two = 0;
    int a = one.size(), b = two.size();
    for(int i=0;i<=a;i++) {
        if(i>0) cur_one += one[i-1];
        cur_two = 0;
        for(int j=0;j<=b;j++) {
            if(j>0) cur_two += two[j-1];
            int total_vert = (a-i) + 2*(b-j);
            if(cur_one+cur_two <= total_vert) res = min(res, total_vert);
        }
    }
    cout << res;
}
