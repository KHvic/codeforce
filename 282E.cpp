#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXM = 41;

struct Node {
    Node* childs[2];
    void add(ll bits) {
        Node* cur = this;
        for(int i=MAXM;i>=0;i--) {
            int v = (bits>>i)&1;
            if(cur->childs[v] == NULL) cur->childs[v] = new Node();
            cur = cur->childs[v];
        }
    }
    ll qryMax(ll bits) {
        Node *cur = this;
        ll res = 0;
        for(int i=MAXM;i>=0;i--) {
            ll v = (bits>>i)&1;
            ll target = 1-v;
            if(cur->childs[target] != NULL) {
                res |= (1LL<<i);
                cur = cur->childs[target];
            } else {
                cur = cur->childs[v];
            }
        }
        return res;
    }
};

int main()
{
    fastio
    int n;
    cin >> n;
    vector<ll> vals(n);
    ll x = 0;
    for(int i=0;i<n;i++) {
        cin >> vals[i];
        x ^= vals[i];
    }
    Node* root = new Node();
    root->add(0);
    ll x2 = 0, res = x;
    for(int i=0;i<n;i++) {
        x ^= vals[i];
        x2 ^= vals[i];
        root->add(x2);
        res = max(res, root->qryMax(x));
    }
    cout << res;
}
