#include <bits/stdc++.h>
#include <string>
using namespace std;

int arr[100006];
int tree[600006];
void segm(int N,int lo,int hi)
{
	if(lo==hi){
		tree[N]=arr[lo];
		return;
		}
	int left=N*2;
	int right=N*2 + 1;
	int mid=(lo+hi)/2;
	segm(left,lo,mid);
	segm(right,mid+1,hi);
	tree[N]=min(tree[left],tree[right]);
}
int quary(int N,int lo,int hi,int i,int j)
{
	if(i>hi || j<lo)
		return INT_MAX;
	if(lo>=i && hi<=j)
		return tree[N];
   	int left=N*2;
	int right=N*2 + 1;
	int mid=(lo+hi)/2;
  	int value1=quary(left, lo,mid, i, j);
	int value2=quary(right, mid+1, hi, i, j);
	return min(value1,value2);
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    scanf("%d",&t);
    int j=0;
    while(t>0){
            j++;
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        segm(1,1,n);
        printf("Case %d:\n",j);
        for(int i=1;i<=q;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            int k=quary(1,1,n,a,b);
            printf("%d\n",k);
        }
        t--;
    }
    return 0;
}
