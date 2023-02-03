#include <bits/stdc++.h> 
/****************************************************************

Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
	        this->data = data;
	        this->next = NULL;
        }
    };

*****************************************************************/

Node *delAddLastNode(Node *head){


    if(head==NULL)
    return head ;
	
    if(head->next==NULL)
    return head;

    Node *curr=head;

    Node *next=curr->next;
    Node *d=NULL;

    while(curr!=NULL)
    {
        if(next->next==NULL)
        {
            Node *temp=next;
            curr->next=NULL;
            temp->next=head; ///ye hai important line temp k nxt me poori listdedi
            d=temp;   
            
        }
        next=next->next;
        curr=curr->next;
    }


    //temp->next=head;
    return d;
}
