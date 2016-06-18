/*
 * @author     : SRvSaha
 * Filename    : lnked_list_head_by_value.c
 * Timestamp   : 16:14 18-June-2016 (Saturday)
 * Description : The Program is basically Insertion in a Linked List at the end and the
 *               head of the linked list is "passed by value" as an argument. So everytime
 *               we have to return the update head.
 */

#include <stdio.h>
#include <stdlib.h> //Used for Malloc

/* Here Node type Pointer Head is returned because Head is sent by value from the main function. So if the updated value of head is not returned so the value of head will always be null as in the main function.
ADVANTAGE :
    1. No need to write *head everywhere instead of head.
    2. Code is more readable and intuitive since directly head is used and not *head. In case of Call by Reference we have to do *head, that is comparatively a tough concept of POINTER to POINTER
DISADVANTAGE :
    1. Since it is call by value so the value just gets copied to the arguments and the changes done through any of the function is not reflected until and unless the updated value of head is returned from the functions.

*/
typedef struct Node Node; /* To get rid of writing struct Node everytime, directly Node would do the same thing now. Increases Readability and unifies the implementation with Cpp implementation where we can use Node instead of struct Node by default (OOPs).*/
struct Node{
    int data;
    Node* link;
};
Node* add(Node* head,int data){
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = data;
    temp->link = NULL;
    if(head == NULL)
        head = temp;
    else{
        Node* ptr = head;
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
    return head;
}
Node* display(Node* head){
    if(head == NULL){
        printf("List Empty\n");
    }
    else{
        Node* ptr = head;
        while(ptr != NULL){
            printf("%d->",ptr->data);
            ptr = ptr->link;
        }
        printf("NULL\n");
    }
    return head;
}
int main()
{
    Node* head = NULL;
    int data, choice;
    // TODO: Change into Switch-Case taking care of Exit condition.
    while(1){
        printf("\nEnter your choice : \n1.Add Node\n2.Display List\n3.Any other key to exit\n\n");
        scanf("%d",&choice);
        if(choice == 1){
            printf("Enter the data : ");
            scanf("%d",&data);
            head = add(head,data); //Head is sent by value not by reference.
        }
        else if (choice ==2){
            head = display(head);
        }
        else
            break;
    }
    return 0;
}
