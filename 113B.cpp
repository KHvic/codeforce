#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 2005;
bool is_start[MAXN], is_end[MAXN];

struct Node {
    Node *child[26];
};
string a,b,c;

vector<int> preprocess(string& b) {
    int n = b.size();
    vector<int> bt(n+1);
    bt[0] = -1;
    int i=0,j=-1;
    while(i<n) {
        while(j>=0 && b[j] != b[i]) j = bt[j];
        bt[++i] = ++j;
    }
    return bt;
}

vector<int> kmp(string&a, string& b) {
    auto bt = preprocess(b);
    int i=0,j=0;
    vector<int> res;
    while(i<a.size()) {
        while(j>=0 && b[j] != a[i]) j = bt[j];
        ++i; ++j;
        if(j==b.size()) {
            res.push_back(i-j);
            j = bt[j];
        }
    }
    return res;
}

int main()
{
    fastio
    cin >> a >> b >> c;
    vector<int> startpos = kmp(a, b);
    vector<int> endpos = kmp(a, c);
    for(int pos : startpos) is_start[pos] = true;
    for(int pos : endpos) is_end[pos+c.size()-1] = true;
    Node *root = new Node();

    int minLen = max(b.size(), c.size());
    int res = 0;
    int n = a.size();
    for(int i=0;i<n;i++) {
        if(!is_start[i]) continue;
        Node* cur = root;
        for(int j=i;j<n;j++) {
            int idx = a[j] - 'a';
            if(cur->child[idx] == NULL) {
                if(is_end[j] && (j-i+1)>=minLen) res++;
                cur->child[idx] = new Node();
            }
            cur = cur->child[idx];
        }
    }
    cout << res;
}
