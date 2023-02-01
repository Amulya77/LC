/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
      
       ///time O(N)  space =O(N/k)
       
       //////////////////
       node *curr=head;
       node*prev=NULL;
       node *next=NULL;
       
       int c=0;
       while(curr!=NULL&&c<k)
       {
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
         c++;
       }
       
       if(next!=NULL)
       {
           node *resthead=reverse(next,k);
           head->next=resthead;
           
       }
       return prev;
       
       
       
       //iterative  OP SOLUTTION time THETA(N) and THETA(1) space
       
       ///firstpass wali bakchodi
       
      /* node *curr=head;

       node *prevfirst=NULL;
       bool isfirstpass=true;
       
       while(curr!=NULL)
       {
           node *first=curr;
           node *prev=NULL;
           int c=0;
           
           while(curr!=NULL&&c<k)
           {
            node *next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            c++;     
           }
           
           
           if(isfirstpass)
           {
               head=prev;
               isfirstpass=false;
           }
           else{
               prevfirst->next=prev;///head of the next pass is stored in  prev;
               prevfirst=first;///changing prev first to the first node of the next pass;
           }
           
           
           
       }
       
       return head;
       */
       
       
       
       
       
       
       
       
       
       
    }
    
    
};
