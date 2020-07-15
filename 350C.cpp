#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,x,y;
    cin >> n;
    int tot = 0;
    vector<vector<int>> points;
    for(int i=0;i<n;i++) {
        cin >> x >> y;
        points.push_back({x,y});
    }
    sort(points.begin(), points.end(),[](auto a, auto b) {
         if(abs(a[0]) == abs(b[0])) return abs(a[1]) < abs(b[1]);
         return abs(a[0]) < abs(b[0]);
    });
    vector<string> res;
    for(int i=0;i<n;i++) {
        x = points[i][0], y = points[i][1];

        if(x!=0) {
            tot++;
            if(x>0) res.push_back("1 " + to_string(x) + " R");
            else res.push_back("1 " + to_string(-x) + " L");
        }
        if(y!=0) {
            tot++;
            if(y>0) res.push_back("1 " + to_string(y) + " U");
            else res.push_back("1 " + to_string(-y) + " D");
        }
        res.push_back("2");
        if(x!=0) {
            tot++;
            if(x>0) res.push_back("1 " + to_string(x) + " L");
            else res.push_back("1 " + to_string(-x) + " R");
        }
        if(y!=0) {
            tot++;
            if(y>0) res.push_back("1 " + to_string(y) + " D");
            else res.push_back("1 " + to_string(-y) + " U");
        }
        res.push_back("3");
        tot+=2;
    }
    cout << tot << "\n";
    for(auto x : res) cout << x << "\n";
}
