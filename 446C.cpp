#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

// Unsolved, some bugs

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long ll;
const ll mod = 1e9+7;

struct Matrix {
    ll m[2][2];
    Matrix operator *(Matrix other) {
        Matrix res{{{0,0},{0,0}}};
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    res.m[i][j] = (res.m[i][j] + m[i][k]*other.m[k][j]%mod)%mod;
        return res;
    }
    Matrix operator +(Matrix other) {
        Matrix res{{{0,0},{0,0}}};
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                res.m[i][j] = (m[i][j] + other.m[i][j]) % mod;
        return res;
    }
};

vector<Matrix> matrices, sum_matrices;

struct ST {
    int n;
    vector<ll> segment, lazyA, lazyB;
    ST(int n):n(n){
        segment.assign(4*n, 0);
        lazyA.assign(4*n, 0);
        lazyB.assign(4*n, 0);
    }

    void updateLazy(int idx, int low, int high) {
        ll a = lazyA[idx], b = lazyB[idx];
        if(a+b != 0 && low != high) {
            (lazyA[idx*2+1] += a) %= mod;
            (lazyB[idx*2+1] += b) %= mod;

            int mid = (low+high) >> 1;
            int shift = mid-low;
            ll na = (a*matrices[shift].m[0][0]%mod + b*matrices[shift].m[0][1]%mod)%mod;
            ll nb = (a*matrices[shift].m[1][0]%mod + b*matrices[shift].m[1][1]%mod)%mod;
            (lazyA[idx*2+2] += na) %= mod;
            (lazyB[idx*2+2] += nb) %= mod;
        }
        // update logic
        if(a+b != 0) {
            int len = high-low;
            segment[idx] = (segment[idx] + sum_matrices[len].m[0][0]*a%mod + sum_matrices[len].m[0][1]*b%mod)%mod;
        }
        lazyA[idx] = lazyB[idx] = 0;
    }

    void update(int idx, int low, int hi, int qlow, int qhi, ll a, ll b) {
        updateLazy(idx, low, hi);
        if(low>qhi || hi<qlow) return;
        else if(low>=qlow && hi<=qhi) {
            (lazyA[idx] += a) %= mod;
            (lazyB[idx] += b) %= mod;
            updateLazy(idx, low, hi);
        } else {
            int mid = (low+hi) >> 1;
            if(qlow<=mid) {
                update(idx*2+1, low, mid, qlow, min(qhi, mid), a, b);

                int shift = mid-qlow;
                ll na = (a*matrices[shift].m[0][0]%mod + b*matrices[shift].m[0][1]%mod)%mod;
                ll nb = (a*matrices[shift].m[1][0]%mod + b*matrices[shift].m[1][1]%mod)%mod;
                update(idx*2+2, mid+1, hi, max(qlow, mid+1), qhi, na, nb);
            } else {
                update(idx*2+2, mid+1, hi, max(qlow, mid+1), qhi, a, b);
            }
            updateLazy(idx*2+1, low, mid);
            updateLazy(idx*2+2, low, mid);
            segment[idx] = (segment[idx*2+1] + segment[idx*2+2])%mod;
        }
    }

    void update(int qlow, int qhi, ll a, ll b) {
        update(0, 0, n-1, qlow, qhi, a, b);
    }

    ll query(int idx, int low, int hi, int qlow, int qhi) {
        updateLazy(idx, low, hi);
        if(low>qhi || hi<qlow) return 0;
        else if(low>=qlow && hi<=qhi) return segment[idx];
        int mid = (low+hi) >> 1;
        return (query(idx*2+1, low, mid, qlow, qhi) + query(idx*2+2, mid+1, hi, qlow, qhi))%mod;
    }

    ll query(int qlow, int qhi) {
        return query(0, 0, n-1, qlow, qhi);
    }
};

void print(ST& st, int n) {
    for(int i=0;i<n;i++) {
        debug(st.query(i, i));
    }
}


int main(){
    fastio
    int n, m, v;
    cin >> n >> m;
    vector<ll> psum(1,0);
    for(int i=0;i<n;i++) {
        cin >> v;
        psum.push_back((psum.back()+v)%mod);
    }
    matrices.reserve(n+1); sum_matrices.reserve(n+1);
    Matrix mi{{{0, 1},{1, 1}}};
    matrices.push_back(mi); sum_matrices.push_back(mi);
    for(int i=1;i<=n;i++) {
        matrices[i] = matrices[i-1] * mi;
        sum_matrices[i] = sum_matrices[i-1] + matrices[i];
    }
    ST st(n);
    int t, l, r;
    while(m--) {
        cin >> t >> l >> r; l--; r--;
        if(t==1) {
            st.update(l, r, 0, 1);
        } else {
            ll range = psum[r+1] - psum[l];
            ll range2 = st.query(l, r);
            cout << (range+range2)%mod << "\n";
        }
    }
}
