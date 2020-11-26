#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string in;
    cin >> n >> in;
    int numReplace = 0;
    for(int i=0;i<n/2;i++) {
        int idx1 = i*2;
        int idx2 = i*2+1;
        if(in[idx1] == in[idx2]) {
            numReplace++;
            in[idx1] = in[idx1] == 'a' ? 'b' : 'a';
        }
    }
    cout << numReplace << endl;
    cout << in << endl;
}
