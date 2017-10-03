/*
Find the middle of a given linked list in C
For Odd: Mid is n+1/2
For Even: Lower of the the two mid values
*/
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

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
void middle_element_method1(Node** head_ref){
    Node* slow_ptr = *head_ref;
    Node* fast_ptr = *head_ref;
    if(*head_ref != NULL){
        while(fast_ptr->next != NULL && fast_ptr->next->next != NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
    }
    cout<<"Middle Element is : "<<slow_ptr->data<<endl;
}
void middle_element_method2(Node* head){
    int count = 0;
    Node* mid = head;
    if(head != NULL){
        while(head!= NULL){
            if((count & 1) == 0 && count > 0)
                mid = mid -> next;
            head = head -> next;
            count++;
        }
    }
    cout<<"Middle Element is : "<<mid->data<<endl;
}

int main(){
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    print_ll(head);
    middle_element_method1(&head);
    middle_element_method2(head);
    return 0;
}