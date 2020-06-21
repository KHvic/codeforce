#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,v;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        int odd = 0, even = 0;
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            if(i%2 == v%2) continue;
            else if(v%2) odd++;
            else even++;
        }
        if(odd!=even) printf("-1\n");
        else printf("%d\n", odd);
    }
}
