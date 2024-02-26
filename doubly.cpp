#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node  *prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;

    }
};

void printLinkList(Node *head){
    Node *tmp=head;
    while(tmp!=NULL){
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
}

void ReverseLinkList(Node *tail){
    Node *tmp=tail;
    while(tmp!=NULL){
        cout<<tmp->val<<" ";
        tmp=tmp->prev;
    }
}

void insert_at_any_Position( Node *head,int pos,int val){
    Node * NewNode=new Node(val);
    Node *tmp=head;
    for(int i=1;i<=pos-1;i++){
        tmp=tmp->next;
    }
    NewNode->next=tmp->next;
    tmp->next=NewNode;
     NewNode->prev=tmp;
     NewNode->next->prev=NewNode;
}

void Insert_at_Tail(Node *&tail,int val){
    Node *NewNode=new Node(val);
    tail->next=NewNode;
    NewNode->prev=tail;
    NewNode->next=NULL;
    tail=NewNode;
}
void Insert_at_Head(Node *&head,Node *&tail,int val){
    Node *newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    newNode->prev=NULL;
}

void DeleteFrom_at_any_Position(Node *head,int pos){
    Node *tmp=head;
    for(int i=1;i<=pos-1;i++){
        tmp=tmp->next;
    }
    Node *DeleteNode=tmp->next;
    tmp->next=tmp->next->next;
    tmp->next->prev=tmp;
    delete DeleteNode;
}


int main(){
    Node *head=new Node(10);
    Node *a=new Node(20);
    Node *b=new Node(30);
    Node *tail=b;

    head->next=a;
    a->prev=head;
    a->next=b;
    b->prev=a;

    Insert_at_Head(head,tail,500);
   insert_at_any_Position(head,2,100);
   Insert_at_Tail(tail,200);

   printLinkList(head);
   cout<<endl;
   ReverseLinkList(tail);
   cout<<endl;
  
   
   cout<<" after Deleting "<<endl;
   DeleteFrom_at_any_Position(head ,2);
   printLinkList(head);
   cout<<endl;
   ReverseLinkList(tail); 
 

}