#include <bits/stdc++.h>
using namespace std;
#define ll long long

string in, valid;
int k;
int countNodes = 0;

struct Node {
    Node* childs[26];
};

Node* root = new Node();

void addWord(string& s, int start) {
    int invalid = 0;
    Node* cur = root;
    for(int i=start;i<s.size();i++) {
        int idx = s[i] - 'a';
        if(valid[idx] == '0' && ++invalid > k) break;
        if(cur->childs[idx] == NULL) {
            countNodes++;
            cur->childs[idx] = new Node();
        }
        cur = cur->childs[idx];
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> in >> valid >> k;
    for(int i=0;i<in.size();i++) {
        addWord(in, i);
    }
    cout << countNodes;
}
