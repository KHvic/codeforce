#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,k;
    string in;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        cin >> in;
        vector<int> rightmost(n,INT_MAX);
        for(int i=n-1;i>=0;i--)
            if(in[i] == '1') rightmost[i] = i;
            else if(i<n-1) rightmost[i] = rightmost[i+1];
        int res = 0;
        int leftmost = -n-k;
        for(int i=0;i<n;i++)
            if(in[i] == '1') leftmost = i;
            else if(i-leftmost>=k+1 && rightmost[i]-i>=k+1) res++, leftmost=i;
        printf("%d\n", res);
    }
}
