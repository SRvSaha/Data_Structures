#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* reverse_ll_iter(Node** head_ref){
    //Name head as head_ref when passed by reference for clarity
    Node* next;
    Node* curr = *head_ref;
    Node* prev = NULL;
    while(curr != NULL){
        next = curr->next; // Next is pointing to Current's Next
        curr->next = prev; // Pointer of Current pointing NULL
        prev = curr; // Prev is now current
        curr = next;
    }
    *head_ref = prev;
    return *head_ref;
}
int main(){

    return 0;
}
