#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t,n;
    string in;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> in;
        int inv = 0;
        int left = 0;
        for(char c :  in) {
            if(c=='(') left++;
            else if(left == 0) inv++;
            else left--;
        }
        inv += left;
        cout << inv/2 << endl;
    }
}
