#include <bits/stdc++.h>
using namespace std;
#define ll long long

// union find on employees as node
// a better idea is to do union find on languages as node (for each employee join all lang to first language)
vector<int> pars;

int find(int a) {
    return pars[a] == a ? a : pars[a] = find(pars[a]);
}

void join(int a, int b) {
    int parA = find(a), parB = find(b);
    pars[parA] = parB;
}

bool connected(int a, int b) {
    return find(a) == find(b);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n,m,k,v;
    cin >> n >> m;
    vector<pair<ll,ll>> skills;
    int noskill = 0;
    // models skill of employee as two 64 bitmasks
    for(int i=0;i<n;i++) {
        ll skillA = 0, skillB = 0;
        cin >> k;
        if(k==0) noskill++;
        while(k--) {
            cin >> v;
            v--;
            if(v>63) {
                v -= 64;
                skillB |= (1LL<<v);
            } else skillA |= (1LL<<v);
        }
        skills.push_back({skillA, skillB});
    }

    for(int i=0;i<n;i++) pars.push_back(i);
    // find number of connected components with union find
    int components = n;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            auto s1 = skills[i], s2 = skills[j];
            if((s1.first & s2.first) | (s1.second & s2.second)) {
                if(!connected(i, j)) {
                    components--;
                    join(i, j);
                }
            }
        }
    }
    cout << max(components-1, noskill) << endl;
}
