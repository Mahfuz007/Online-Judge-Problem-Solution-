/* SPARROW 2019 */
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
#define zero(arr,a) memset(arr,a,sizeof arr)
#define mk
#define mx 105

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

int pi[mx],ci[mx],wi[mx],dp[mx][10006];
int n,w;

int solve(int i, int cnt)
{
    if(i==n || cnt<=0) return 0;
    if(dp[i][cnt]!=-1) return dp[i][cnt];
    int ans1=0,ans2=0;
    ans1=solve(i+1,cnt);

    if(cnt-wi[i]>=0) ans2=solve(i,cnt-wi[i])+pi[i];

    return dp[i][cnt]=max(ans1,ans2);
}

void clean(int n1,int w1)
{
    for(int i=0;i<n1;i++){
        for(int j=0;j<w1;j++){
            dp[i][j]=-1;
        }
    }

}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1015.txt","w",stdout);
    int t;
    sci(t);

    for(int cs=1;cs<=t;cs++)
    {

        sci(n);sci(w);

        for(int i=0;i<n;i++){
            sci(pi[i]);sci(ci[i]);sci(wi[i]);
            w-=(wi[i]*ci[i]);
        }

        pfc(cs);
        if(w<0){
            printf("Impossible\n");
        }
        else if(w==0) printf("0\n");
        else{
            clean(n+2,w+2);
            printf("%d\n",solve(0,w));
        }

    }
    return 0;
}

