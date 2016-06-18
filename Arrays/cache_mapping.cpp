/*
 * @author     : SRvSaha
 * Filename    : cache.cpp
 * Timestamp   : 11-Apr-2016
 * Description : Given a 8-bit address, identify the tag, word, set bits in cache
 *  mapping. Coded as a part of Implemention of Cache Mapping in CSP 1401
 */

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
using namespace std;
//////////////////////////////////////////////////////////////
void directMapping(int* arr,int length);
void setAssociativeMapping(int* arr, int length);
void print(int* arr,int length);
int binaryToDecimal(int*,int length);
/////////////////////////////////////////////////////////////
int main()
{
    int input[8],choice;
    char input_string[9];
    cout<<"Enter a 8-bit address :\t";
    cin>>input_string;
    int size = strlen(input_string);
    for(int i = 0; i<size; i++)
    {
        char ch ='0';
        input[i] = input_string[i] - ch;
    }
    cout<<"\n";
    print(input,size);
    cout<<"\n\nEnter your choice :\n1.Direct Mapping\n2.Set Associative Mapping\n3.Any Other Key to EXIT\n\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
            directMapping(input,size);
            break;
        case 2:
            setAssociativeMapping(input,size);
            break;
        default:
            cout<<"Wrong Choice\n";
    }
    if (choice != 1 || choice != 2){
        return 0;
    }
    return 0;

}
/////////////////////////////////////////////////////////////
void print(int* arr,int length){
    for(int i = 0; i < length; i++)
    {
        cout<<*(arr+i)<<" ";
    }
}
/////////////////////////////////////////////////////////////
int binaryToDecimal(int* temp,int length){
    int sum = 0;
    for(int i=0; i <length ; i++)
    {
        *(temp+i) = *(temp+i) * pow(2,length-1-i);
        sum += *(temp + i);
    }
    return sum;
}
////////////////////////////////////////////////////////////
void directMapping(int *arr,int length){
        int buffer[8],tag[2],block[3],word[3];
        for(int i=0; i < length; i++){
            buffer[i] = *(arr+i);
        }
        for(int i=0; i<2;i++)
        {
            tag[i] = buffer[i];
        }
        int size = sizeof(tag)/sizeof(tag[0]);
        cout<<"\nTag is : "<<binaryToDecimal(tag,size)<<"\n";
        for(int i=2; i<5;i++)
        {
            block[i-2] = buffer[i];
        }
        size = sizeof(block)/sizeof(block[0]);
        cout<<"\nBlock is : "<<binaryToDecimal(block,size)<<"\n";
        for(int i=5; i<8;i++)
        {
            word[i-5] = buffer[i];
        }
        size = sizeof(word)/sizeof(word[0]);
        cout<<"\nWord is : "<<binaryToDecimal(word,size)<<"\n";
}
//////////////////////////////////////////////////////////////////////
void setAssociativeMapping(int* arr, int length){
        int buffer[8],tag[5],word[3];
        for(int i=0; i < length; i++){
            buffer[i] = *(arr+i);
        }
        for(int i=0; i<5;i++)
        {
            tag[i] = buffer[i];
        }
        int size = sizeof(tag)/sizeof(tag[0]);
        cout<<"\nTag is : "<<binaryToDecimal(tag,size)<<"\n";
        for(int i=5; i<8;i++)
        {
            word[i-5] = buffer[i];
        }
        size = sizeof(word)/sizeof(word[0]);
        cout<<"\nWord is : "<<binaryToDecimal(word,size)<<"\n";

}
