#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

void insert(Node** head_ref, int val){
    Node* temp = new Node();
    Node* curr = *head_ref;
    temp->data = val;
    temp->next = NULL;
    if(*head_ref == NULL){
        *head_ref = temp;
        return;
    }
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next= temp;
    return;
}
int length(Node* head){
    int count = 0;
    Node* curr = head;
    while(curr != NULL){
        count++;
        curr = curr->next;
    }
    return count;
}
int length_recursive(Node* head){
    if(head == NULL){
        return 0;
    }
    return 1 + length_recursive(head->next);
}
int main(){
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 8);
    cout<<length(head)<<endl;
    cout<<length_recursive(head)<<endl;
    return 0;
}