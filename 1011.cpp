#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long

#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define scd(x) scanf("%lf",&x)

#define pfi(x) printf("%d",x)
#define pfl(x) printf("%lld",x)
#define pfd(x) printf("%lf",x)
#define pfc(x) printf("Case %d: ",x)
#define ps printf(" ")
#define pn printf("\n")
#define pb(x) push_back(x)
#define ppb(x) pop_back(x)
#define pf(x) push_front(x)
#define ppf(x) pop_front(x)
#define in(x,y) insert({x,y})
#define sv(a) sort(a.begin(),a.end())
#define mx 17
#define inf 999999999999

int Set(int x, int pos) { return x= x|(1<<pos);}
int reset(int x,int pos){ return x=x & (~(1<<pos));}
bool check(int x, int pos){ return (bool)(x&(1<<pos));}

int data[17][17],dp[17][(1<<17)+2];
int n;

int solve(int curr, int mask)
{
    if(curr==n) return 0;
    if(dp[curr][mask]!=-1) return dp[curr][mask];

    int tot=0;
    for(int i=0;i<n;i++){
        if(!check(mask,i)) tot=max(tot, data[curr][i]+solve(curr+1,Set(mask,i)));
    }

    return dp[curr][mask]=tot;
}

int main()
{
    int t;
    sci(t);

    for(int cs=1;cs<=t;cs++){
        sci(n);
        memset(dp,-1,sizeof dp);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sci(data[i][j]);
            }
        }

        int ans=solve(0,0);
        pfc(cs);pfi(ans);pn;
    }

    return 0;
}


