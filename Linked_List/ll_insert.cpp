#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* insert_at_beginning(Node* head, int val){
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    temp->next = head;
    head = temp;
    return head;
}
Node* insert_at_end(Node* head, int val){
    Node* temp = new Node();
    temp->data = val;
    temp->next = NULL;
    Node* curr;
    if(head == NULL){
        temp->next = head;
        head = temp;
    }
    else{
        curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    return head;
}
Node* insert_after_kth_node(Node* head, int val, int k){
    Node* temp = new Node();
    Node* curr = head;
    temp->data = val;
    temp->next = NULL;
    int count = 1;
    while(count != k){
        curr = curr->next;
        count++;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
Node* reverse_ll(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
void print_list(Node* head){
    Node* curr;
    curr = head;
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
    head = insert_at_beginning(head, 1);
    print_list(head);
    // head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 3);
    head = insert_at_beginning(head, 4);
    head = insert_at_beginning(head, 5);
    head = insert_at_beginning(head, 6);
    head = insert_at_end(head, 2);
    head = insert_at_end(head, 3);
    head = insert_at_end(head, 4);
    head = insert_at_end(head, 5);
    head = insert_at_end(head, 6);
    head = insert_at_end(head, 7);
    print_list(head);
    head = reverse_ll(head);
    print_list(head);
    head = insert_after_kth_node(head, 100, 12);
    print_list(head);
    return 0;
}