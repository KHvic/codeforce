#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    double p1 = a/b, p2 = c/d;
    double res = 0;
    double cur = 1;
    for(int i=0;i<10000;i++) {
        res += cur*p1; // probability p1 win
        cur *= (1.0-p1)*(1.0-p2); // probability p1 lose and p2 lose
    }
    cout << fixed << setprecision(10) << res;
    // note: can also use math formula
    // p*q^0+p*q^1+p*q^2+... where q = (1-p1)*(1-p2)
    // using geometric series limit => p/(1-q)
}

/*
Let A = a/b, B = c/d
Let C = ((1-A)*(1-B)), probability of my turn again
R = A + C*R, probability of winning
R = A/(1-C)
*/

// better solution based on math formula
int solution2(){
    fastio
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double A = a/b, B = c/d;
    double C = (1-A)*(1-B);
    double R = A/(1-C);

    cout << fixed << setprecision(10) << R;
}
