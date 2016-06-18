/*
 * @author     : SRvSaha
 * Filename    : duplicateRemove.cpp
 * Timestamp   : 16:29 18-June-2016 (Saturday)
 * Description : Removing the duplicates from a given string.RUNNING TIME OF THIS CODE IS *               O(n^2). Need to Optimize it.
 *
 */

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{

    string input;
    string result;
    cin >> input;
    for(int i = 0; i< input.size(); i++){
        if(i == 0){
            result += input[i];
        }
        else{
            for(int j = 0 ; j < result.size(); j++){
                if( input[i] != result[j] && j == result.size()-1 )
                    result += input[i];
                else if( input[i] != result[j] )
                    continue;
                else if( input[i] == result[j])
                    break;
            }
        }
    }
    cout<<"Resultant String : "<<result<<endl;
    return 0;
}
