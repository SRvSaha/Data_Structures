#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void delete_node(Node** head, int key){
    Node* curr = *head;
    Node* prev;
    if(curr != NULL && curr->data == key){
        // The case when the key is in the node pointed by head node
        *head = curr->next;
        free(curr);
        return;
    }
    while(curr != NULL && curr->data != key){
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL)
        return;
    prev->next = curr->next;
    free(curr);
}
void delete_at_position(Node** head, int pos){
    Node* prev, *curr;
    curr = *head;
    if(*head == NULL)
        return;
    if(pos == 0){
        // If we need to delete the node pointed by head
        *head = curr->next;
        free(curr);
        return;
    }
    for(int i = 0; i < pos && curr != NULL; i++){
        //incrementing the current pointer
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL)
        // If position is more than the number of nodes
        return;
    prev->next = curr->next;
    free(curr);
}
void push(Node** head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}
void print_ll(Node* curr){
    while(curr != NULL){
        if(curr->next == NULL)
            cout<<curr->data<<endl;
        else
            cout<<curr->data<<"->";
        curr = curr->next;
    }
}
int main(){
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    print_ll(head);
    delete_node(&head, 7);
    print_ll(head);
    delete_at_position(&head, 1);
    print_ll(head);
    delete_at_position(&head, 0);
    print_ll(head);
    delete_at_position(&head, 9);
    print_ll(head);
    delete_at_position(&head, 2);
    print_ll(head);
    delete_at_position(&head, 5);
    return 0;
}