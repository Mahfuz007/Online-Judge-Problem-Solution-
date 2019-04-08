#include <bits/stdc++.h>
#include <string>
using namespace std;
#define ll long long

#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define scd(x) scanf("%lf",&x)
#define scs(x) scanf("%s",x)

#define pfi(x) printf("%d",x)
#define pfs(x) printf("%s",s)
#define pfl(x) printf("%lld",x)
#define pfd(x) printf("%lf",x)
#define pfc(x) printf("Case %d:",x)
#define ps printf(" ")
#define pn printf("\n")

#define FOR(i, s, n) for (int i = s; i <= (int)n; i++)
#define pb(x) push_back(x)

#define ppb(x) pop_back(x)
#define pf(x) push_front(x)
#define ppf(x) pop_front(x)
#define in(x,y) insert({x,y})
#define sv(a) sort(a.begin(),a.end()
#define mx 100010
int arr[mx];
ll tree[6*mx];
void seg(int N,int lo,int hi)
{
    if(lo==hi){
        tree[N]=arr[lo];
        return;
    }
    int left=2*N;
    int right=2*N + 1;
    int mid=(lo+hi)/2;
    seg(left,lo,mid);
    seg(right,mid+1,hi);
    tree[N]=tree[left]+tree[right];
}

ll quary(int N,int lo,int hi,int i, int j)
{
    if(i>hi || j<lo)
        return 0;
    if(lo>=i && hi<=j)
        return tree[N];
    int left=2*N;
    int right=2*N + 1;
    int mid=(lo+hi)/2;
    ll val1=quary(left,lo,mid,i,j);
    ll val2=quary(right,mid+1,hi,i,j);
    return val1+val2;
}
void add(int N,int lo,int hi,int pos, int newv)
{
    if(pos>hi || pos<lo)
        return;
    if(lo>=pos && hi<=pos)
        {
            tree[N]+=newv;
            return ;
        }
    int left=2*N;
    int right=2*N + 1;
    int mid=(lo+hi)/2;
    add(left,lo,mid,pos,newv);
    add(right,mid+1,hi,pos,newv);
    tree[N]=tree[left]+tree[right];
}
void gave(int N,int lo,int hi,int pos)
{
    if(pos>hi || pos<lo)
        return;
    if(lo>=pos && hi<=pos){
        cout<<tree[N]<<"\n";
        tree[N]=0;
        return;
    }
    int left=2*N;
    int right=2*N + 1;
    int mid=(lo+hi)/2;
    gave(left,lo,mid,pos);
    gave(right,mid+1,hi,pos);
    tree[N]=tree[left]+tree[right];
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1112-in.txt","r",stdin);
    //freopen("1112-out.txt","w",stdout);
    int t;
    sci(t);
    for(int i=1;i<=t;i++)
    {
        int n,q;
        sci(n);sci(q);
        memset(arr,0,sizeof arr);
        memset(tree,0,sizeof tree);
        for(int j=1;j<=n;j++)
            sci(arr[j]);
        seg(1,1,n);
        pfc(i);pn;
        for(int k=1;k<=q;k++)
        {
            int a;
            sci(a);
            if(a==1)
            {
                int w;
                sci(w);
                w++;
                //pfi(tree[w]);pn;
                gave(1,1,n,w);
            }
            else if(a==2)
            {
                int w1,w2;
                sci(w1);sci(w2);
                w1++;
                add(1,1,n,w1,w2);
            }
            else
            {
                int w1,w2;
                sci(w1);sci(w2);
                w1++;w2++;
                ll x = quary(1,1,n,w1,w2);
                pfl(x);pn;
            }
        }

    }
    return 0;
}
