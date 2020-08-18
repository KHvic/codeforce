#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ss second
#define ff first
#define N 100005
#define ll long long
#define pii pair<ll,ll>
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
const int mod = 1e9+7;
const ll inf = 1e18;

int tt;
int n;
ll x,y,S;
ll sum,dp[N],ans,w;
vector<pii>E[N];
priority_queue<pair<ll,pii>>p;
 
void dfs(int nd,int pr){
	if(nd != 1 and sz(E[nd]) == 1){
		dp[nd] = 1;
		return;
	}
	for(auto i : E[nd]){
		if(i.ff != pr){
			dfs(i.ff,nd);
			sum += dp[i.ff]*i.ss;
			ll z = i.ss/2;
			p.push({dp[i.ff]*i.ss-dp[i.ff]*z,{dp[i.ff],z}});
			dp[nd] += dp[i.ff];
		}
	}
 
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 
	cin >> tt;
	while(tt--){
		cin >> n >> S;
		for(int i = 1;i <= n;i++) E[i].clear();
		for(int i = 1;i < n;i++){
			cin >> x >> y >> w;
			E[x].pb({y,w});
			E[y].pb({x,w});
		}
		sum = 0;
		while(!p.empty()) p.pop();
		for(int i = 1;i <= n;i++) dp[i] = 0;
		dfs(1,0);
		ans = 0;
		while(sum > S){
			ll z = p.top().ff;
			x = p.top().ss.ff;
			y = p.top().ss.ss;
			p.pop();
			sum -= z;
			w = y/2;
			p.push({x*y-x*w,{x,w}});
			ans++;
		}
		cout<<ans<<'\n';
	}
}
