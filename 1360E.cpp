#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<bool>> vis;
vector<string> grid;
vector<vector<int>> dirs = {{-1,0},{0,-1}};
 
 
int dfs(int i,int j) {
    if(i<0||j<0||vis[i][j]||grid[i][j] != '1') return 0;
    vis[i][j] = true;
    int res = 1;
    for(auto d : dirs)
        res += dfs(i+d[0],j+d[1]);
    return res;
}
 
int main() {
    int t,n,k;
    scanf("%d",&t);
    string in;
    while(t--) {
        scanf("%d",&n);
        grid.clear();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            cin >> in;
            grid.push_back(in);
            for(char c : in)
                if(c=='1') cnt++;
        }
        vis.assign(n,vector<bool>(n,false));
        for(int i=0;i<n;i++) {
            cnt -= dfs(i,n-1);
            cnt -= dfs(n-1,i);
        }
        if(cnt==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
