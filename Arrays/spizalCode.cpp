/*
* @author     : SRvSaha
* Description : Given a Matrix, print the Spizal order traversal of it.
*
*/
#include <iostream>
#include <cstdio>
using namespace std;
int a[100][100];
int main()
{
    int row = 0, column = 0;
    int m , n ;
    cout<<"Enter the dimension of the array : \n";
    scanf("%d %d",&m,&n);
    cout<<"Enter the elements in to the array: \n";
    for(row = 0; row < m; row ++){
         for(column = 0 ; column < n; column++ ){
            scanf("%d",&a[row][column]);
        }
    }
    int size = m*n;
    int i = 0;
    int count = 0;
    cout<<"SPIZAL FORM IS :\n";
    while(count != size){
        //FOR SPIZAL
        for(row = 0 + i, column = i ; column < n - i ; column++ ){
            cout<<a[row][column]<<" ";
            count++;
        }
        if(count == size)
            break; // Everytime this is checked so that there is no useless repetition
        for(row = 1 + i, column = n-1 - i; row < m -i ; row ++)
        {
            cout<<a[row][column]<<" ";
            count++;
        }
        if(count == size)
            break;
        for(row = m-1 -i , column = n-2 -i; column >= 0+i; column-- ){
            cout<<a[row][column]<<" ";
            count++;
        }
        if(count == size)
            break;
        for(row = m-2 -i, column = 0+i; row > 0+i; row-- ){
           cout<<a[row][column]<<" ";
           count++;
        }
        if(count == size)
            break;
        ++i;
}
    cout<<endl;
    return 0;
}

