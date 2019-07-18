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
#define mx

int fx[]={0,1,1,1,0,-1,-1,-1};
int fy[]={1,1,0,-1,-1,-1,0,1};

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("1015.txt","w",stdout);
    int t;
    sci(t);

    int cs=1;

    while(t--)
    {
        int n;
        sci(n);
        vector<ll>data(n);

        for(int i=0;i<n;i++) scl(data[i]);

        sv(data);

        ll res=data[data.size()-1]+1;
        ll cnt=res-1;
        for(int i=data.size()-2;i>=0;i--){

            if(data[i]==data[i+1]){
                if(cnt>0) cnt--;
                else{
                    res+=(data[i]+1);
                    cnt=data[i];
                }
            }
            else{
                res+=(data[i]+1);
                cnt=data[i];
            }
        }

        pfc(cs++);
        pfl(res);pn;
    }
    return 0;
}


