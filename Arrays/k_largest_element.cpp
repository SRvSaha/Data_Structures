/*
 * @author     : SRvSaha
 * Filename    : k_largest_element.cpp
 * Timestamp   : 22:09 17-June-2016 (Friday)
 * Description : Question: Write an efficient program for printing k largest elements in *                         an array. Elements in array can be in any order.

 *   For example, if given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the
 *          largest 3 elements i.e., k = 3 then your program should print 50, 30 and 23.
 *
 * Solution : Using SORTING METHOD in O(nlogn) time. Can be optimized. Refer *Geeksforgeeks.
 */
#include <iostream>
#include <cstdio>
#include <algorithm> // for sort() :: STL
#define CIN(n) scanf("%d",&n)
#define MAX 100
using namespace std;

int main()
{
    int test_cases;
    int size,k;
    int array[MAX];
    cin>>test_cases;
    while(test_cases --)
    {
        CIN(size);
        CIN(k);
        for(int i = 0 ; i < size; i++)
        {
            cin>>array[i];
        }
        sort(array,array+size); // Using the Sort method using algorithm header
        for (int i=size-1;i>size-1-k; i--)
        {
            cout<<array[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
