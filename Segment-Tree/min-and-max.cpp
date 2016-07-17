/*--------------------------Belleman-Ford (Shortest Path)-----------------
Note :can be used on edges with negative weight and can be used to detect cycle with negative weight(Total weight)
Complexity:O(n*m)

*/
                #include <bits/stdc++.h>
                #include<vector>
                #include<map>
                #include<set>
                #include<algorithm>
#include<cstdio>
#define gc getchar_unlocked
using namespace std;
typedef unsigned long long int  ull;
typedef long long int  ll;
#define SETPRES  std::setprecision(6),std::fixed;
#define pb push_back
#define mp make_pair
#define FR freopen("input.txt", "r", stdin);
#define FW freopen("output.txt", "w", stdout);
#define  Help_me  ios_base::sync_with_stdio(false);
#define  lg(x)  ceil(log2(x))
#define MX 12345679
#define mod 1000000007
const int inf=100000005;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
std::vector<pair<int,int> > adj[100];//adjancy list for the graph
int val[100];
struct seg
{
    int mx;//store maximum
    int mn;//store minimum
};
struct seg segment[201];
void build(int node,int l,int r)
{
    if(l==r)//leaf node will store the  l to r where l==r
    {
        segment[node].mx=val[l];//storing maximum
        segment[node].mn=val[l];//storing minimum
    }


    else
    {
        int mid=(l+r)>>1;
        build(2*node,l,mid);//taking left turn 
        build(2*node+1,mid+1,r);//taking right turn
        segment[node].mx=max(segment[2*node].mx,segment[2*node+1].mx);//taking maximum of two child of the current node
        segment[node].mn=min(segment[2*node].mn,segment[2*node+1].mn);//taking maximum of two child of the current node
    }
}
int query(int node,int l,int r,int left,int right,int flag)
{
    if(left==l&&r==right)
    {
        if(flag==1)
            return segment[node].mx;//return maximum value
        else
            return segment[node].mn;//return minimum value
    }
    int  mid=(l+r)/2;
    if(right<=mid)
    {
      return  query(2*node,l,mid,left,right,flag);
    }
    else if(left>mid)
      return  query(2*node+1,mid+1,r,left,right,flag);
    else
    {
        if(flag==1)
        return max(query(2*node,l,mid,left,mid,flag),query(2*node+1,mid+1,r,mid+1,right,flag));
    else
         return min(query(2*node,l,mid,left,mid,flag),query(2*node+1,mid+1,r,mid+1,right,flag));
    }

}
int main()
{
    Help_me
    int start = clock();
    #ifndef ONLINE_JUDGE
    //int number
    //string s="646";
    //stringstream s1(s);
    //s1>>number
    //stringstream convert;
    //convert>>numbemidre;
    //convert<<s
    //getline(cin>>ws,s);
//  FR
//  FW
    #endif
int n;//number of element in the array
cin>>n;
for(int i=0;i<n;i++)
    cin>>val[i];
build(1,0,n-1);//buiulding the segment tree.with  node 1 cover the range 0 to n-1
int q;//enter number of query
cin>>q;
while(q--)
{
    int left,right,flag;//Enter the range in which you want to find minimum and maximum and press 1 for maximum and 0 for minimum
    cin>>left>>right>>flag;
    if(flag)
    cout<<"Maximum is "<<query(1,0,n-1,left,right,1)<<endl;
else
cout<<"Minimum is "<<query(1,0,n-1,left,right,0)<<endl;
}
return 0;
    
    }
