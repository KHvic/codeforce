#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    scanf("%d",&t);
    auto cmp = [&](vector<int>& a, vector<int>& b) {
        int lenA = a[1] - a[0];
        int lenB = b[1] - b[0];
        if(lenB==lenA) return a[0] > b[0];
        return lenA < lenB;
    };
    while(t--) {
        scanf("%d",&n);
        vector<int> res(n);
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
        pq.push({0,n-1});
        int idx = 1;
        while(idx<=n) {
            vector<int> range = pq.top(); pq.pop();
            int mid = (range[0]+range[1])/2;
            res[mid] = idx++;
            int left = mid-1, right = mid+1;
            if(left>=range[0]) pq.push({range[0],left});
            if(right<=range[1]) pq.push({right,range[1]});
        }
        for(int i=0;i<n;i++) {
            printf("%d", res[i]);
            if(i==n-1) printf("\n");
            else printf(" ");
        }
    }
}
