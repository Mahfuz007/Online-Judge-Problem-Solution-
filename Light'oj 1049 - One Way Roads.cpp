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
#define mx 103

void err() { cout<<"No\n";exit(0);}

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

typedef pair<int,int>pii;

vector<pii>graph[mx];

int dfs(int n,int p)
{
    if(n==1) return 0;
    for(auto i:graph[n]){
        if(i.first!=p) return dfs(i.first,n)+i.second;
    }
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

        for(int i=1;i<=n;i++){
            int u,v,w;
            sci(u);sci(v);sci(w);

            graph[u].push_back({v,0});
            graph[v].push_back({u,w}); //Creating reverse edge with w cost.
        }

        int ans=dfs(graph[1][0].first,1)+graph[1][0].second; //Traverse clock wise
        ans=min(ans,dfs(graph[1][1].first,1)+graph[1][1].second);// Traverse anti-clock wise
        pfc(cs++);
        pfi(ans);pn;

        for(int i=1;i<=n;i++) graph[i].clear();
    }
    return 0;
}

