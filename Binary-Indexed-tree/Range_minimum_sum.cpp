 //Range Minimum sum Query By BIT
 /*
 ##### @author : Sunil Dinday
 #####Binary Indexed tree
 #####time Complexity:O(logn) for query and update as well
 #####Space Complexity:O(n)
 #####Applications:(1)Prefix sum in O(logn) (2) Range minimum query
 #####Advantages over Segment Tree:(1)less space n as compare to 2n (2)Easy and fast to code
 Note:-here we are taking array is 1-indexed array and here we are implamenting it get Range Minimum sum Query
 */
#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int bit[1000]; //BIT array used to store
int n; //number of element in the array
void update(int x,int vl)
{

	for( ; x<=n ;x += x&(-x) )
		bit[x]+=vl;
}
int query(int x)
{
	int sum=0;
	for( ; x>=1 ; x -= x&(-x) )
		sum+=bit[x];
    return sum;
}
int main()
{
    cin>>n;
    memset(bit,0,sizeof(bit));//first initialize bit array with zero
    for(int i=1 ; i<=n; i++)
    {
        cin>>arr[i];
        update(i,arr[i]);//update
    }
    int q; //number of query for the Range minimum sum
    cin>>q;
    while(q--)
    {
    	int l,r; //index in the array  for which you want to find the sum between l and r index
    	cin>>l>>r;
    	cout<<query(r)-query(l-1)<<endl;
    }
    return 0;
}
