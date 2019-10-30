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
#define mx 1002

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

int spf[mx],level[mx];

void seive()
{
    for(int i=1;i<mx;i++) spf[i]=i;
    for(int i=4;i<mx;i+=2) spf[i]=2;

    for(int i=3;i*i<mx;i++){
        if(spf[i]==i)
        {
            for(int j=i*i;j<mx;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}

int bfs(int s,int d)
{
    queue<int>q;
    q.push(s);

    memset(level,-1,sizeof level);
    level[s]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        int x=u;
        vector<int>prime;
        while(x>1)
        {
            prime.push_back(spf[x]);
            x/=spf[x];
        }

        sv(prime);

        for(int i=prime.size()-1;i>=0;i--)
        {
            if(u+prime[i]>d || level[u+prime[i]]!=-1 || prime[i]==u) continue;
            level[u+prime[i]]=level[u]+1;
            if(u+prime[i]==d) return level[u+prime[i]];
            q.push(u+prime[i]);
        }
    }

    return level[d];
}
int main()
{
    seive();

    int t,cs=1;
    sci(t);

    while(t--)
    {
        int s,d;
        sci(s);sci(d);

        pfc(cs++);
        pfi(bfs(s,d));pn;

    }
    return 0;
}

