//Code By: AMULYA MAURYA
//2023-01-26


//////HW 58.57 last node jab delete karte hai to tail ko kese handle karenge

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    //constructor  
    Node(int data){
        this->data = data;
        this->next=NULL;
    }

    //destructor
    ~Node(){
      
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            next=NULL;
    }

        cout<<"memory is free for node with data "<<value<<endl;
    }
};

void inserthed(Node *&head, int d){


    //new node
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;//return temp;

}

/*
void inserttail(Node *&head,int d){
    Node *temp=new Node(d);
    if(head==NULL){
        head=temp;

    }
    Node *curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    curr->next=temp;
    return;
}

}
*/

void inserttail(Node *&tail,int d){

    Node *temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void insertatpos(Node *&head,Node*&tail,int pos,int data){

     Node *Nodetoinsert=new Node(data);
    //insert at start
    if(pos==1)
    {
        inserthed(head,data);
        return;
        /*
        Nodetoinsert->next=head;
        head=Nodetoinsert;
        */


    }

    



    Node*temp= head;
    int c=1;

    //inset at middle
    while(c<pos-1){
        temp=temp->next;
        c++;
    }


    //insert at tail
    if(temp->next==NULL){
        inserttail(tail,data);
        return;
    }
    //create a node for data
   
    Nodetoinsert->next=temp->next;
    temp->next=Nodetoinsert;


}


int search(Node *&head,int x){


    //TIME COMPLEXXITY O(N)
    //AUX SPACE=ITERATIVE O(1)
    //AUX SPACE=RECURSIVE O(n)
    Node *curr=head;
    int pos=1;
    while(curr!=NULL)
    {
        if(curr->data==x)
            return pos;
        else{
            pos++;
            curr=curr->next;
        }
    }

    return -1;
    /*
    //RECURSIVE SOLUTION OF SEARCHING IN A SINGLY LL
    if(head==NULL)
    return -1;
    if(head->data==x)
    return 1;
    else
    {
        int res=search(head->next,x);
        if(res==-1)
        return -1;
        else
        return(res+1);
    }
    
    
    
    */
}

int length(Node *head){
    Node *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    } 

    return len;
}




void print(Node *&head)
{

    //make a copy of head so that original head remains at the same position
    Node* temp = head;
     while(temp!=NULL)
     {
        cout<<temp->data<<" ";
        temp=temp->next;
     }

     cout<<endl;
}



void deletenode(int pos,Node *&head){

    if( pos==1)
    {
        //deleting first node
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
       
         //deleting middle or last node
        Node* curr=head;
        Node *prev=NULL;

        int c=1;
        while(c<pos)
        {
            prev=curr;
            curr=curr->next;
            c++;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;   

    }

}











int main()
{ 
    Node * node1=new Node(10);
    Node * head=node1;
    Node *tail=node1;

    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    //head pointed to node1;
    inserthed(head,12);
    print(head);
    inserthed(head,2);
    print(head);
    inserthed(head,33);
    
    print(head);


    inserttail(tail, 14);
    print(head);


    insertatpos(head,tail,3,46);
    print(head);

    deletenode(1,head);
    
    print(head);
    deletenode(3,head);
    print(head);

    cout<<"SEARCH 46 and found at pos "<<search(head,46)<<endl;
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    cout<<"length of LL is "<<length(head)<<endl;

    return 0;

}