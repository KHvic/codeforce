#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

struct SA {
    vector<int> sa, tmpSA, ra, tmpRA, lcp;
    string s;
    int n;

    SA(string& str):s(str) {
        s += "$";
        n = s.size();
        sa = tmpSA = ra = tmpRA = vector<int>(n);
        for(int i=0;i<n;i++) ra[i] = s[i], sa[i] = i;
        for(int k=1;k<n;k<<=1) {
            countSort(k), countSort(0);
            tmpRA[sa[0]] = 0;
            for(int i=1;i<n;i++)
                tmpRA[sa[i]] = tmpRA[sa[i-1]] + (ra[sa[i]] != ra[sa[i-1]] || ra[sa[i]+k] != ra[sa[i-1]+k]);
            for(int i=0;i<n;i++) ra[i] = tmpRA[i];
            if(ra[sa[n-1]] == n-1) break;
        }
        buildLCP();
    }
    void countSort(int k) {
        int mx = max(300, n);
        vector<int> cnt(mx);
        for(int i=0;i<n;i++) cnt[i+k < n ? ra[i+k] : 0]++;
        for(int i=0,sum=0,tmp;i<mx;i++,sum+=tmp) tmp=cnt[i], cnt[i] = sum;
        for(int i=0;i<n;i++) tmpSA[cnt[sa[i]+k < n ? ra[sa[i]+k] : 0]++] = sa[i];
        for(int i=0;i<n;i++) sa[i] = tmpSA[i];
    }
    void buildLCP() {
        lcp = vector<int>(n);
        for(int i=0,k=0;i<n;i++) {
            if(ra[i] != 0) {
                for(int j=sa[ra[i]-1]; s[i+k] == s[j+k];) k++;
                lcp[ra[i]] = k;
                k = max(k-1, 0);
            }
        }
    }
};

int main()
{
    fastio
    string s;
    int m, n;
    cin >> s >> m;
    n = s.size();
    if(m>1LL*n*(n+1)/2) {
        cout << "No such line."; return 0;
    }
    SA sa(s);
    for(int i=1;i<=n;i++) {
        for(int j=sa.lcp[i]+1;j<=n-sa.sa[i];j++) { // 0..lcp[i] already covered
            for(int k=i;k<=n;k++) {
                if(k>i&&j>sa.lcp[k]) break;
                if(--m==0) {
                    cout << s.substr(sa.sa[i], j); return 0;
                }
            }
        }
    }
}
