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
ll k;

int mod(string t)
{
    int res=0;
    for(int i=0;i<t.size();i++){
        res=res*10+(int)(t[i]-'0');
        res=res%k;
    }

    return res;
}

string getSolve()
{
    queue<string>q;
    string t="1";
    q.push(t);
    set<int>vis;

    while(!q.empty())
    {
        t=q.front();
        q.pop();

        int rem=mod(t);

        if(!rem) return t;

        if(vis.find(rem)==vis.end())
        {
            vis.insert(rem);
            q.push(t+'0');
            q.push(t+'1');
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1015.txt","w",stdout);

    int t;
    sci(t);

    while(t--)
    {
        scl(k);
        cout<<getSolve();pn;
    }
    return 0;
}


