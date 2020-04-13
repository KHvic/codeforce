#include <bits/stdc++.h>
using namespace std;

vector<string> sudo;

// actually just need to replace all 1 with 2

int main(){
    int tc;
    string in;
    scanf("%d",&tc);
    while(tc--) {
        sudo.clear();
        for(int i=0;i<9;i++) {
            cin >> in;
            sudo.push_back(in);
        }
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                int ridx = j*3+i;
                int cidx = i*3+j;
                int val = sudo[ridx][cidx]-'0';
                val--;
                if(val == 0) val = 9;
                sudo[ridx][cidx] = (char)(val+'0');
            }
        }
        for(auto& s : sudo)
            cout << s << endl;
    }
}
