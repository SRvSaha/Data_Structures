/*
Trie used for calculating prefix of an string
Question:given an array find the pair whose XOR is maximum
Without trie complexity will be O(n^2)
using trie Complexity reduces to O(n*log(MX)) where MX is number of bits in the numbers,Here we are taking 32 bit numbers

*/
#include<bits/stdc++.h>
#define null 0
using namespace std;
//structure used as trie
struct trie{
	bool data;
	struct trie *left1,*right1;
};
int val[100];
void insert(struct trie *head,int bit,int i)
{

	if(bit>=0)//insert upto 0th bit
	{
	if(val[i]&(1<<(bit)))//if the current bit in val[i] is 1
	{
		if(head->left1==null)//if its left is not created create it 
		{
			head->left1=new trie();
			head->left1->data=true;
			head->left1->left1=null;//make left and right pointer null
			head->left1->right1=null;

		}
		
			insert(head->left1,bit-1,i);
		
	}
	else //if current bit is 0
	{
		if(head->right1==null)
		{
			head->right1=new trie();
			head->right1->data=false;
			head->right1->right1=null;
			head->right1->left1=null;
		}
		
			insert(head->right1,bit-1,i);
	}
	}

}
long query(struct trie *head,int bit,int val)
{
	long ans=0;

	if(bit>=0)
	{
		if(val&(1<<bit))
		{
			if(head->right1!=null)
			{
				ans+=(1<<bit);
			return	ans+query(head->right1,bit-1,val);
			}
			else
			{
				return query(head->left1,bit-1,val);
			}

		}
		else
		{
			if(head->left1!=null)
			{
				ans+=(1<<bit);
				return ans+query(head->left1,bit-1,val);
			}
			else
				return query(head->right1,bit-1,val);

		}

	}
	return 0;

}
int main()
{
	int n;
	cout<<"Enter number of elements inside array: ";
	cin>>n;
	struct trie *head;//head pointer which point to the begning of the trie
	head=new trie();
	head->left1=null;
	head->right1=null;
	cout<<"Please Enter "<<n<<" elements :";
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
		//insert elements inside trie
		if(val[i]&(1<<31))
			insert(head,6,i);
		else
			insert(head,6,i);
	}
long 	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,query(head,6,val[i]));
	}
	cout<<ans<<endl;

	return 0;
}
