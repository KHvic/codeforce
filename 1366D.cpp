#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
// idea:
// A = p1^a + p2^b + p3^c ..., prime factorization
// Let d1 = p1^a, d2 = A/d1 => d2 is prime factors of A without p1^a
// then we know A % p1 == 0, d1 % p1 == 0, but d2 % p1 != 0
// thus, (d1+d2) % p1 ==  d2 % p1 != 0, also (d1+d2) % (p2...px) ==  d1 % (p2...px) != 0
// so we know that (d1+d2) does not have a prime divisor from A

ll lim = 1e7+5;
vector<ll> spf; // smallest prime factor
 
void sieve() {
    spf.assign(lim, -1);
    for(ll i=2;i<lim;i++) {
        if(spf[i] != -1) continue;
        spf[i] = i;
        for(ll j=i*i;j<lim;j+=i)
            if(spf[j] == -1)
                spf[j] = i;
    }
}
 
int main()
{
    sieve();
    int t,v;
    scanf("%d",&t);
    vector<int> res1(t,-1), res2(t,-1);
    for(int i=0;i<t;i++) {
        scanf("%d",&v);
        ll smallest_prime = spf[v];
        while(v%smallest_prime == 0)
            v /= smallest_prime;
        if(v!=1) {
            res1[i] = smallest_prime;
            res2[i] = v;
        }
    }
    for(int i=0;i<t;i++) {
        if(i) printf(" ");
        printf("%d",res1[i]);
    }
    printf("\n");
    for(int i=0;i<t;i++) {
        if(i) printf(" ");
        printf("%d",res2[i]);
    }
}
