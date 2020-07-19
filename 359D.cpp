#include<bits/stdc++.h>
using namespace std;
#define ll long long

// idea: a range of number is divisible by some number x in this range
// when GCD(L..R) == MIN(L..R)

const int MAXN = 3*1e5 + 10;
const int MAXP = log2(MAXN) + 10;
int min_table[MAXP][MAXN];
int gcd_table[MAXP][MAXN];
int a[MAXN];
int numlog[MAXN];
int n;


void init() {
    numlog[1] = 0;
    for(int i=2;i<=n;i++) numlog[i] = numlog[i/2] + 1;

    for(int i=0;i<=numlog[n];i++) {
        int skiprange = 1<<i;
        for(int j=0;j+skiprange<=n;j++) {
            if(i==0) {
                gcd_table[i][j] = min_table[i][j] = a[j];
                continue;
            }
            gcd_table[i][j] = __gcd(gcd_table[i-1][j], gcd_table[i-1][j+(skiprange>>1)]);
            min_table[i][j] = min(min_table[i-1][j], min_table[i-1][j+(skiprange>>1)]);
        }
    }
}

bool query(int low, int high) {
    int range = high-low+1;
    int p = numlog[range];
    int ggcd = __gcd(gcd_table[p][low], gcd_table[p][high-(1<<p)+1]);
    int mn = min(min_table[p][low], min_table[p][high-(1<<p)+1]);
    return mn == ggcd;
}

vector<int> computeValid(int range) {
    vector<int> res;
    for(int i=0;i+range<n;i++) {
        if(query(i, i+range)) res.push_back(i);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    vector<int> res;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        res.push_back(i);
    }
    init();
    // binary search, bisect right to find largest range
    int low = 0, high = n-1;
    while(low<high) {
        int mid = (low+high+1) >> 1;
        auto subres = computeValid(mid);
        if(subres.size()) {
            low = mid;
            res = subres;
        } else {
            high = mid-1;
        }
    }
    cout << res.size() << " " << low << "\n";
    for(int& x : res) {
        if(&x != &res[0]) cout << " ";
        cout << x+1;
    }
}
