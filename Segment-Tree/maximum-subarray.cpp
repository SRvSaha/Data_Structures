/*
-----------------------Maximum sub-array---------------------------
    Finding sub-array (l,r) with  Maximum sum
    Build time:O(n)
    Time of each Complexity: O(logn)
*/
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#define gc getchar_unlocked
using namespace std;
typedef unsigned long long int  ull;
typedef long long int  ll;
#define SETPRES  std::setprecision(6),std::fixed;
#define pb push_back
#define mp make_pair
#define FR freopen("input.txt", "r", stdin);
#define FW freopen("output.txt", "w", stdout);
#define Help_me  ios_base::sync_with_stdio(false);
#define lg(x)  ceil(log2(x))
#define MX 12345679
#define mod 1000000007
const int inf=100000005;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()){
        x = (x<<1) + (x<<3) + c - 48;
    }
}
struct node
{
	int sum;
	int pre;
	int suff;
	int ns;
};
struct node segment[200];
int val[100];
struct node combine(struct node l,struct node r)
{
	struct node temp;
    temp.ns = max(l.suff+r.pre,max(l.ns,r.ns));
    temp.pre = max(l.sum+r.suff,l.pre);
    temp.suff = max(r.suff,r.sum+l.suff);
    temp.sum = l.sum+r.sum;
    return temp;
}
void build(int node,int l,int r)
{
	if(l==r)
	{
		segment[node].suff = segment[node].pre = segment[node].sum = segment[node].ns = val[l];
	}
	else
	{
	   int mid = (l+r)/2;
	   build(2*node,l,mid);
	   build(2*node+1,mid+1,r);
	   segment[node] = combine(segment[2*node],segment[2*node+1]);
    }
}
struct node query(int node,int l,int r,int left,int right)
{
	if(l==left&&r==right)
		return segment[node];
	int mid=(l+r)/2;
	if(right<=mid)
	{
		return query(2*node,l,mid,left,right);
	}
	else if (left>mid)
	{
		return query(2*node+1,mid+1,r,left,right);
		/* code */
	}
	else
	{

		return combine(query(2*node,l,mid,left,mid),query(2*node+1,mid+1,r,mid+1,right));
	}
}
int main()
{
	Help_me
	int start = clock();
	#ifndef ONLINE_JUDGE
	#endif
	int n;//number of element in the array
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>val[i];
    build(1,0,n-1);//building the segment tree.with  node 1 cover the range 0 to n-1
    int q;//enter number of query
    cin>>q;
    while(q--)
    {
        int left,right;
        cin>>left>>right;
        cout<<"Maximum subarray is  "<<query(1,0,n-1,left,right).ns<<endl;
    }
    	#ifndef LOCAL_TEST
    		cout << "[Finished in " << clock() - start << " ms]" << endl;
    	#endif

    return 0;
}
