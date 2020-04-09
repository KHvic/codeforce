#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc,n,m;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i==0 && j==0) printf("W");
                else printf("B");
            }
            printf("\n");
        }
    }
}
