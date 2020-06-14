#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define mod 998244353
#define ll long long

int main(){
    int a[maxn],b[maxn],n,m;
    ll res=1;
	int l,r;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<m;i++) scanf("%d",&b[i]);
	r=n-1; // right pointer
	for(int i=m-1;i>=0;i--){// reverse
        // try to find b[i]
        // while larger than item
        // At the end of the loop, either
        // a[r]==b[i] => found rightmost for b[i]
        // or a[r]<b[i] => invalid because smaller than b[i]
        // or r==-1 => end of array, did not find target
		while(a[r]>b[i]) r--;
		if(a[r]!=b[i]||r==-1) {
            res=0; break; // fail because invalid
        }

		// find leftmost valid
		// At the end of the loop, either
		// a[l]<b[i]
		// or l==0
		l=r;
		while(l>=0 && a[l]>=b[i])l--;
		if(i!=0) {
            // When it is not the first grouping
            // the interval [l+1,r] can be selected as left index for this group
            res = res *(r-l)%mod;
		} else if(l!=-1) // must reach the end for first grouping
            res=0;
		r=l;
	}
	printf("%lld\n",res);
}
