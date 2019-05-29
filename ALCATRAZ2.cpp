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
#define mx

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

vector<int>data[9],arr(9);

int Set(int n,int pos) { return n=(n|(1<<pos));}
bool check(int n,int pos){ return (bool) (n&(1<<pos));}

int solve(int pos,int n)
{
    if(pos==8) return 0;
    int ans1=0,ans2=0;

    ans1=solve(pos+1,n);

    if(!check(n,pos)){
        for(int i=0;i<data[pos].size();i++){
            n=Set(n,data[pos][i]);
        }
        ans2=arr[pos]+solve(pos+1,n);
    }
    else ans2=solve(pos+1,n);

    return max(ans1,ans2);
}
int main()
{
    for(int i=0;i<8;i++) sci(arr[i]);

    int q;
    sci(q);

    while(q--)
    {
        int u,v;
        sci(u);sci(v);
        u--;v--;
        data[u].pb(v);
        data[v].pb(u);
    }

    cout<<solve(0,0);pn;

    return 0;
}

