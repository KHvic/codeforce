#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

// main property of mod =>
// when mod m > some value x, x % m = x
// else x % m will result in x to at least be halved
// thus, each value x can only be mod m by log_2 times

// we use a sum + max segment tree
// time complexity analysis is tricky here
// update2 mod would seemingly have a time complexity of O(N)
// but each node in the tree would only be able to run logA times before reaching value 0
// since there are O(N) nodes, it would take O(NlogA) times of mod operation to deplete the entire tree
// each update operation restore the node back to logA 'charges'
// overall time complexity is thus O(NlogN*logA)

struct ST {
    int n;
    vector<ll> sum, mx;
    ST(int len):n(len){
        sum.assign(4*n, 0);
        mx.assign(4*n, 0);
    }

private:
    void update(int idx, int low, int hi, int qlow, int qhi, ll val) {
        if(low>qhi || hi<qlow) return;
        else if(low==hi) {
            mx[idx] = sum[idx] = val;
        } else {
            int mid = (low+hi) >> 1;
            update(idx*2+1, low, mid, qlow, qhi, val);
            update(idx*2+2, mid+1, hi, qlow, qhi, val);
            sum[idx] = sum[idx*2+1] + sum[idx*2+2];
            mx[idx] = max(mx[idx*2+1], mx[idx*2+2]);
        }
    }

    void update2(int idx, int low, int hi, int qlow, int qhi, ll val) {
        if(low>qhi || hi<qlow || val > mx[idx]) return;
        else if(low==hi) {
            mx[idx] = sum[idx] = sum[idx] % val;
        } else {
            int mid = (low+hi) >> 1;
            update2(idx*2+1, low, mid, qlow, qhi, val);
            update2(idx*2+2, mid+1, hi, qlow, qhi, val);
            sum[idx] = sum[idx*2+1] + sum[idx*2+2];
            mx[idx] = max(mx[idx*2+1], mx[idx*2+2]);
        }
    }

    ll query(int idx, int low, int hi, int qlow, int qhi) {
        if(low>qhi || hi<qlow) return 0;
        else if(low>=qlow && hi<=qhi) return sum[idx];
        int mid = (low+hi) >> 1;
        return query(idx*2+1, low, mid, qlow, qhi) + query(idx*2+2, mid+1, hi, qlow, qhi);
    }
public:
    void update(int qlow, int qhi, ll val) {
        update(0, 0, n-1, qlow, qhi, val);
    }
    void update2(int qlow, int qhi, ll val) {
        update2(0, 0, n-1, qlow, qhi, val);
    }
    ll query(int qlow, int qhi) {
        return query(0, 0, n-1, qlow, qhi);
    }
};

int main()
{
    fastio
    int n,m,t,l,r,k,x;
    cin >> n >> m;
    ST st(n);
    for(int i=0;i<n;i++) {
        cin >> x;
        st.update(i, i, x);
    }
    while(m--) {
        cin >> t;
        if(t==1) {
            cin >> l >> r; l--; r--;
            cout << st.query(l, r) << "\n";
        } else if(t==2) {
            cin >> l >> r >> x; l--; r--;
            st.update2(l, r, x);
        } else {
            cin >> k >> x; k--;
            st.update(k, k, x);
        }
    }
}
