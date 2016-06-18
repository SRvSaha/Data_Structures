/*
 * @author     : SRvSaha
 * Filename    : charPointer.cpp
 * Timestamp   : 17:31 18-June-2016 (Saturday)
 * Description : Some experimentations done to understand Pointers & Char Pointers in
 * Depth.
 *
 */

#include <iostream> // For cout and endl
#include <cstring> // For strlen
using namespace std;
int main(){
    char* ptr = "Saurav";
    char* newptr;
    int *in; // This pointer is pointing to any random memory : May or May not give
    // SEGMENTATION FAULT
    cout<<in<<endl;
    cout<<*in<<endl;//Error / No error but any garbage value will be printed
    int* myptr= NULL;
    cout<<myptr<<endl; // The address is null : ZERO
    //cout<<*myptr; // SEGMENTATION CORE DUMPED since it's trying to point the value at NULL
    // Dereferencing any NULL pointer (pointer pointing to null) will give this error as
    // location from which value to be fetched is not defined. Pointing to null means pointing nowhere in memory , 0x0

    cout<<"Character Pointer is : "<<ptr<<endl;
    cout<<strlen(ptr)<<endl;
    //cout<<*newptr; // This will give segmentation fault since we are trying to access
    // memory that is not assigned to it
     // Program breaks here. WHY???? Because newptr points to NULL and can't be dereferenced.
    cout<<newptr;
    newptr = ptr; // Pointers can be assigned as both are of the same type
    cout<<"New pointer is : "<<newptr<<endl;
    ptr = "Saha";
    cout<<"Modified Pointer is :"<<ptr<<endl;
    cout<<sizeof(ptr)<<" "<<sizeof(newptr)<<endl;
    return 0;
}
