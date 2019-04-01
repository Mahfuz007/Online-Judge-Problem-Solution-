 /*
    SPOJ- ALLIZWEL - ALL IZZ WELL
    https://www.spoj.com/problems/ALLIZWEL/
    */
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
#define mx 105

char data[mx][mx];
int n,m;

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

string s="ALLIZZWELL";
bool vis[mx][mx],flag;

void dfs(int x,int y,int pos)
{
    if(pos==s.size()-1){
        flag=true; return;
    }
    for(int i=0;i<8;i++){
        int u=x+fx[i],v=y+fy[i];
        if(u>=1 && u<=n && v>=1 && v<=m && data[u][v]==s[pos+1] && !vis[u][v] ){
            vis[u][v]=true;
            dfs(u,v,pos+1);
            vis[u][v]=false;
        }
    }

}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("in.txt","r",stdin);
    int t;
    sci(t);

    while(t--)
    {
        sci(n);sci(m);
        flag=false;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>data[i][j];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(data[i][j]=='A'){
                    memset(vis,false,sizeof vis);
                    dfs(i,j,0);
                    if(flag) break;
               }
            }
            if(flag) break;
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}


