#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,n,k,v;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        priority_queue<int,vector<int>,greater<int>> pq1;
        priority_queue<int> pq2;
        int sum = 0;
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            pq1.push(v);
            sum += v;
        }
        for(int i=0;i<n;i++) {
            scanf("%d",&v);
            pq2.push(v);
        }
 
        while(k) {
            int minV = pq1.top();
            int maxV = pq2.top();
            if(maxV <= minV) break;
            pq1.pop(); pq2.pop();
            sum += (maxV-minV);
            pq2.push(minV);
            pq1.push(maxV);
            k--;
        }
 
        printf("%d\n", sum);
    }
}
