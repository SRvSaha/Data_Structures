#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
void insert(Node** head_ref, int data){
    Node* temp = new Node();
    Node* curr = *head_ref;
    temp->data = data;
    temp->next = NULL;
    if(*head_ref == NULL){
        *head_ref = temp;
        return;
    }
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = temp;
    return;
}
void print_list(Node* head){
    Node* curr = head;
    while(curr != NULL){
        if(curr->next == NULL)
            cout<<curr->data<<endl;
        else
            cout<<curr->data<<"->";
        curr = curr->next;
    }
}
int search(Node* head, int val){
    int index = 1;
    Node* curr = head;
    while(curr != NULL){
        if(curr->data == val)
            return index;
        index++;
        curr = curr->next;
    }
    return -1;
}
bool search_recursive(Node* head, int val){
    if(head == NULL)
        return false;
    else if(head->data == val)
        return true;
    return search_recursive(head->next, val);
}
int main(){
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    print_list(head);
    int val = 9;
    search(head, val) == -1 ? cout<<"Not Found"<<endl : cout<<search(head, val)<<endl;
    cout<<search_recursive(head, val);
    return 0;
}