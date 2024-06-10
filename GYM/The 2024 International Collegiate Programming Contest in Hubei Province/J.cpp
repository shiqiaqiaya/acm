#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int power(int x,int t)
{
    int b=1;
    while(t)
    {
        if(t&1) b=b*x%mod;
        x=x*x%mod; t>>=1;
    }
    return b;
}
void QWQ() {

}

void QAQ() {
    int n;
    cin>>n;
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    sum%=mod;
    // (sum*=n-1)%=mod;
    (sum*=power(n,mod-2))%=mod;
    cout<<sum<<"\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int t = 1;
    // cin >> t;

    while (t--) {
        QAQ();
    }
}