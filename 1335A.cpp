#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    int tc, n;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        if(n%2==0) n--;
        printf("%d\n", n/2);
    }
}
