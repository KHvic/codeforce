#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

struct Node {
    Node *childs[26];
    bool leaf=true;

    void insert(string& s) {
        Node* cur = this;
        for(char c : s) {
            int idx = c-'a';
            cur->leaf = false;
            if(cur->childs[idx] == NULL)
                cur->childs[idx] = new Node();
            cur = cur->childs[idx];
        }
    }
};

bool canWin(Node* n, bool win) {
    if(n->leaf) return !win;
    for(int i=0;i<26;i++) {
        if(n->childs[i] != NULL && !canWin(n->childs[i], win))
            return true;
    }
    return false;
}

int main(){
    fastio
    int n,k;
    string s;
    cin >> n >> k;
    Node *root = new Node();
    for(int i=0;i<n;i++) {
        cin >> s;
        root->insert(s);
    }
    bool win = canWin(root, 1), lose = canWin(root, 0);
    if(win&&lose) cout << "First";
    else if(lose) cout << "Second";
    else if(win) cout << (k%2 ? "First" : "Second");
    else cout << "Second";
}
