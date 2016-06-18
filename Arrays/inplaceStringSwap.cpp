/*
 * @author     : SRvSaha
 * Filename    : inplaceStringSwap.cpp
 * Timestamp   : 17:23 18-June-2016 (Saturday)
 * Description : Complexity : O(n). Given a String, reverse it IN-PLACE.
 *
 */
#include <iostream>
#include <string>
using namespace std;
void swap(char *p, char *q){
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
int lengthOfString(string s){
    int count = 0;
    while(s[count] != '\0'){
        count ++;
    }
    return count;
}
int main()
{
    string s;
    cin>> s;
    cout<<"MIRROR EFFECT \t:";
    cout<<s<<"||";
    for(int i=0, j = lengthOfString(s)-1; i < j ; i++, j--){
        swap(&s[i],&s[j]);
    }
    cout<<s<<endl;
    return 0;
}
