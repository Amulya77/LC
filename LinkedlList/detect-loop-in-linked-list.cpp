//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
#include<bits/stdc++.h>
class Solution
{
    public:
    
    
    
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        //slow pointer fast pointer
        
        ////FLOYD CYCYLE
        
        /*
        Node *slow=head;
        Node *fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
            return true;
        }
        
        return false;
        */
        
        /////method 2 hashmap;
        /*
        unordered_set<Node *>s;
        
        for(Node *curr=head;curr!=NULL;curr=curr->next)
        {
            if(s.find(curr)!=s.end())
            return true;
            
            s.insert(curr);
            
        }
        
        return false;
        */
        
        //Method 3 temp node and point to it;
        
        
        Node *temp=new Node(0);
        Node *curr=head;
        
        while(curr!=NULL)
        {
            if(curr->next==NULL)
            return false;
            if(curr->next==temp)
            return true;
            
            
            Node *next=curr->next;
            curr->next=temp;
            curr=next;
            
            
            
        }
        
        return false;
        
        
        
    }
};
