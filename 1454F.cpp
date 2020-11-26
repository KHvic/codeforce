#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// here I iterate from largest to smallest value tracking the middle window
// if rmq(middle window) == current value && value exist to the left and also the right of the window
// then answer exist

// another solution is to do binary search with prefix and suffix max + sparse table

struct RMQ {
    int n;
    vector<int> numlog;
    vector<vector<int>> min_table;
    RMQ(vector<int>& vals):n(vals.size()) {
        numlog = vector<int>(n+1);
        numlog[1] = 0;
        for(int i=2;i<=n;i++) numlog[i] = numlog[i/2] + 1;

        min_table = vector<vector<int>>(numlog[n]+1, vector<int>(n+1));
        for(int i=0;i<=numlog[n];i++) {
            int skiprange = 1<<i;
            for(int j=0;j+skiprange<=n;j++) {
                if(i==0) {
                    min_table[i][j] = vals[j];
                    continue;
                }
                min_table[i][j] = operate(min_table[i-1][j], min_table[i-1][j+(skiprange>>1)]);
            }
        }
    }

    int query(int low, int high) {
        int range = high-low+1;
        int p = numlog[range];
        int mn = operate(min_table[p][low], min_table[p][high-(1<<p)+1]);
        return mn;
    }

    int operate(int a, int b) {
        return min(a, b);
    }
};

int main(){
    fastio
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        map<int, int> cnt, first, last;
        vector<int> vals(n);
        for(int i=0;i<n;i++) {
            cin >> vals[i];
            cnt[vals[i]]++;
            if(!first.count(vals[i])) first[vals[i]] = i;
            last[vals[i]] = i;
        }

        RMQ rmq(vals);
        int l = n, r = -1;
        int res = -1;
        for(auto it=cnt.rbegin();it!=cnt.rend()&&res==-1;it++) {
            int k = it->first, v = it->second;
            if(v>=3) {
                while(r!=-1&&l-1>first[k] && vals[l-1] == k) l--;
                while(r!=-1&&r+1<last[k] && vals[r+1] == k) r++;
                if(r==-1 || (first[k] < l && last[k] > r && rmq.query(l, r) == k)) {
                    res = k;
                    if(r==-1) {
                        int mid = find(vals.begin()+first[k]+1, vals.end(), k) - vals.begin();
                        l = min(l, mid);
                        r = max(r, mid);
                    }
                    break;
                }
            }
            l = min(l, first[k]);
            r = max(r, last[k]);
        }
        if(res==-1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int m = r-l+1;
            r = n-r-1;
            l = n-m-r;
            cout << l << " " << m << " " << r << "\n";
        }
    }
}
