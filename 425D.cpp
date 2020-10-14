#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

typedef pair<int, int> ii;

struct custom_hash{
    size_t operator()(const ii&x)const{
        return x.first * 33333 + x.second;
    }
};

int main(){
    fastio
    int x,y,n;
    unordered_set<ii, custom_hash> pts;
    unordered_map<int, vector<int>> same_x, same_y;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x >> y;
        pts.insert({x,y});
        same_x[x].push_back(y);
    }
    ll res = 0;
    int sroot = sqrt(n);
    for(auto& p : same_x) {
        int x = p.first;
        int sz = p.second.size();
        if(sz > sroot) continue;
        for(int i=0;i<sz;i++) {
            int y1 = p.second[i];
            for(int j=i+1;j<sz;j++) {
                int y2 = p.second[j];
                int dy = abs(y2-y1);
                if(pts.count({x+dy, y1}) && pts.count({x+dy, y2})) res++;
                if(pts.count({x-dy, y1}) && pts.count({x-dy, y2})) res++;
            }
            pts.erase({x, y1});
        }
    }
    for(auto& p : pts) {
        tie(x, y) = p;
        same_y[y].push_back(x);
    }
    for(auto& p : same_y) {
        int y = p.first;
        int sz = p.second.size();
        for(int i=0;i<sz;i++) {
            int x1 = p.second[i];
            for(int j=i+1;j<sz;j++) {
                int x2 = p.second[j];
                int dx = abs(x2-x1);
                if(pts.count({x1, y+dx}) && pts.count({x2, y+dx})) res++;
                if(pts.count({x1, y-dx}) && pts.count({x2, y-dx})) res++;
            }
            pts.erase({x1, y});
        }
    }
    cout << res;
}
