/*
Find the middle of a given linked list in C
For Odd: Mid is n+1/2
For Even: Higher of the the two mid values
*/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)
{
    Node* fast_ptr = head;
    Node* slow_ptr = head;
    while(fast_ptr != NULL && fast_ptr -> next != NULL){
        fast_ptr = fast_ptr -> next -> next;
        slow_ptr = slow_ptr -> next;
    }
    cout<<slow_ptr->data<<endl;
}
void printMiddle_2(Node* head){
    int count = 0;
    Node* mid = head;
    if(head != NULL){
        while(head != NULL){
            if(count&1)
                mid = mid->next;
            count++;
            head = head->next;
        }
    }
    if(mid != NULL){
        cout<<mid->data<<endl;
    }
}
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

// A utility function to print a given linked list
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
    int i;

    for (i=5; i>0; i--)
    {
        push(&head, i);
        printList(head);
        printMiddle_2(head);
    }
    return 0;
}