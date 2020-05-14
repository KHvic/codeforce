#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,v;
    scanf("%d %d",&n,&m);
    vector<int> vals(n);
    for(int i=0;i<n;i++) scanf("%d",&vals[i]);

    vector<int> suffix(n+1,0);
    unordered_set<int> exist;
    for(int i=n-1;i>=0;i--) {
        suffix[i] = suffix[i+1];
        if(!exist.count(vals[i]))
            exist.insert(vals[i]), suffix[i]++;
    }
    for(int i=0;i<m;i++) {
        scanf("%d", &v);
        printf("%d\n", suffix[v-1]);
    }
}
