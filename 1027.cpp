/* SPARROW 2019 */
#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long

#define pr(x) cerr << "\n" << (#x) << " is " << (x) << endl
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
#define mx

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1015.txt","w",stdout);
    int t,cs=1;
    sci(t);

    while(t--)
    {
        int n;
        sci(n);
        int cnt=0,ans=0;

        for(int i=1;i<=n;i++){
            int x;
            sci(x);
            if(x>0) cnt++;
            ans+=(ll)(abs(x));
        }

        if(cnt)
        {
            int gg;
            while((gg=gcd(ans,cnt))>1)
            {
                ans/=gg;
                cnt/=gg;
            }
        }

        pfc(cs++);
        if(cnt==0) printf("inf\n");
        else{
            printf("%d/%d\n",ans,cnt);
        }
    }
    return 0;
}

