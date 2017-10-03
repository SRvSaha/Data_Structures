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
int nth_node_from_end(Node* head, int n){
    Node* ref_ptr = head;
    Node* main_ptr = head;
    if(head != NULL){
        int count = 0;
        while(count < n){
            if(ref_ptr == NULL)
                return -1;
            ref_ptr = ref_ptr -> next;
            count++;
        }
        while(ref_ptr != NULL){
            main_ptr = main_ptr -> next;
            ref_ptr = ref_ptr -> next;
        }
        return main_ptr->data;
    }
    return 0;
}
int main(){
    Node* head = NULL;
    head = insert_at_beginning(head, 1);
    head = insert_at_beginning(head, 2);
    head = insert_at_beginning(head, 3);
    head = insert_at_beginning(head, 4);
    head = insert_at_beginning(head, 5);
    head = insert_at_beginning(head, 6);
    head = insert_at_beginning(head, 7);
    head = insert_at_beginning(head, 8);
    print_list(head);
    cout<<nth_node_from_end(head, 6);
    return 0;
}