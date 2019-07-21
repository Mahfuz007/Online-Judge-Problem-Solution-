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
#define mx 55

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

string s1,s2,s3;
int dp[mx][mx][mx];

int solve(int i,int j,int k)
{
    if(i>=s1.size() || j>=s2.size() || k>=s3.size()) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int cnt=0;

    if(s1[i]==s2[j] && s2[j]==s3[k]) cnt=solve(i+1,j+1,k+1)+1;
    else cnt=max(cnt,max(solve(i+1,j,k), max(solve(i,j+1,k),solve(i,j,k+1))));

    return dp[i][j][k]=cnt;
}

void clean()
{
    for(int i=0;i<mx;i++){
        for(int j=0;j<mx;j++){
            for(int k=0;k<mx;k++){
                dp[i][j][k]=-1;
            }
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
        clean();
        cin>>s1>>s2>>s3;

        int res=solve(0,0,0);
        pfc(cs);
        pfi(res);pn;
    }
    return 0;
}


