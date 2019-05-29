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

vector<int> compute_prefix(const char *ptr)
{
    int n=strlen(ptr+1);
    vector<int>prefix(n+1);

    int k=0;

    for(int i=2;i<=n;i++){
        while(k>0 && ptr[k+1]!=ptr[i])k =prefix[k];
        if(ptr[k+1]==ptr[i]) k++;
        prefix[i]=k;
    }

    return prefix;
}

int solve(const char *txt,const char *ptr)
{
    int n=strlen(txt+1);
    int m=strlen(ptr+1);

    int cnt=0;

    vector<int>prefix;
    prefix=compute_prefix(ptr);

    int k=0;

    for(int i=1;i<=n;i++){
        while(k>0 && txt[i]!=ptr[k+1]) k=prefix[k];
        if(txt[i]==ptr[k+1]) k++;
        if(k==m) cnt++,k=prefix[k];
    }

    return cnt;
}

int main()
{
    int t,cs=1;
    sci(t);

    while(t--)
    {
        char a[1000006],b[1000006];
        scanf("%s %s",a+1,b+1);
        pfc(cs++);pfi(solve(a,b));pn;
    }
    return 0;
}

