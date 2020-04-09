#include <bits/stdc++.h>
 
using namespace std;
string row1, row2;
vector<vector<bool>> visited;
int k;
 
// 3rd parameter, 0-left,1-up,2-right,3-down
bool solve(int x, int y, int dir) {
    if(x==1 && y==k && dir==0) return true;
    else if(x<0 || y<0 || x>=2 || y>=k) return false;
    if(visited[x][y]) return false;
    visited[x][y] = true;
    char cur;
    if(x == 0) cur = row1[y];
    else cur = row2[y];
//    cout << x  << ":" << y << ":" << dir << cur << endl;
    if(cur == '1') {
        if(dir==0 && solve(x,y+1,dir)) return true;
        else if(dir==1 && solve(x-1,y,dir)) return true;
        else if(dir==2 && solve(x,y-1,dir)) return true;
        else if(dir==3 && solve(x+1,y,dir)) return true;
    } else if(cur == '3') {
        if((dir==0 || dir==2) && (solve(x-1,y,1) || solve(x+1,y,3))) return true;
        else if((dir==1 || dir==3) && (solve(x,y-1,3) || solve(x,y+1,0))) return true;
    }
    visited[x][y] = false;
    return false;
}
 
int main() {
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        cin >> row1 >> row2;
        for(int i=0;i<row1.size();i++){
            if(row1[i] < '3') row1[i] = '1';
            else row1[i]='3';
            if(row2[i] < '3') row2[i] = '1';
            else row2[i]='3';
        }
        visited.assign(2,vector<bool>(k,false));
        bool res = solve(0,0,0);
 
        cout << (res ? "YES" : "NO") << endl;
    }
}
