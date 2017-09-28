#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
int main(){
    Node *ptr = new Node(2);
    cout<<ptr->data<<endl;
    cout<<ptr->next<<endl;
    Node *ptr1 = new Node(3);
    ptr->next = ptr1;
    cout<<ptr1->data<<endl;
    cout<<ptr1->next<<endl;
    cout<<ptr->next<<endl;
    cout<<ptr1<<endl;
    return 0;
}
