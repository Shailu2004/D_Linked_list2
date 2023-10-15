#include <iostream>
using namespace std;

struct Node{
    Node *next;
    Node *pre;
    int data;
    
};

//display from first
void display(Node *head)
{
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}


// display from back side
void displayreverse(Node *last)
{
    Node *temp=last;
    while(temp!=NULL){
        cout<<temp->data<<" "; 
        temp=temp->pre;
    }
}


Node *insertAtfirst(Node *head){
    Node *new_node=new Node();
    new_node->data=0;

    new_node->next=head;
    head->pre=new_node;
    new_node->pre=NULL;

    return new_node;

}


Node *insertAtlast(Node *head){
     Node *new_node=new Node();
     new_node->data=5;
     Node *temp=head;

     while(temp->next!=NULL){
        temp=temp->next;
     }

     temp->next=new_node;
     new_node->pre=temp;
     new_node->next=NULL;

    return head;
}


//delete first
Node * deletefirst(Node *head){
  Node* temp=head;
  head=head->next;
  head->pre=NULL;
  delete(temp);
  return head;
}



// delete last
Node *deletelast(Node *head){
    Node* temp=new Node();
    Node *t=new Node();
    t=head;
    temp=head->next;
    while(temp->next!=NULL){
        t=t->next;
        temp=temp->next;
    }
    t->next=NULL;
    temp->pre=NULL;
    delete(temp);
    return head;
}


// delete between
Node * deletebetween(Node *head){

   Node *temp=new Node();
   temp=head;
   int index;
   cout<<"Enter the index of node which is to be deleted: ";
   cin>>index;
   
    for(int i=1;i<index;i++){
     temp=temp->next;
   }
   temp->next->pre=temp->pre;
   temp->pre->next=temp->next;
   delete(temp);
   return head;

}


// searching data
int searchdata(Node *head,int element){
  Node *temp=new Node();
  temp=head;
  int i=1;
  while (temp->data !=element){
    temp=temp->next;
    i++;
  }
  return i;

}


Node *insertAtbetween(Node *head){
   Node *p=head;
   Node *q=head->next;
   int index;
   cout<<"Enter index at which u want to insert: ";
   cin>>index;
   if(index ==1){
    cout<<"Invalid...."<<endl;
    return head;
   }else{
   for(int i=1;i<index-1;i++){
    p=p->next;
    q=q->next;
   }
   Node* new_node=new Node();
   new_node->data=0;
   new_node->next=q;
   p->next=new_node;
   q->pre=new_node;
   new_node->pre=p;

   return head;
   }

}







int main(){
    Node *first=new Node();
    Node *second=new Node();
    Node *third=new Node();
    Node *fourth=new Node();

    first->data=1;
    second->data=2;
    third->data=3;
    fourth->data=4;

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    first->pre=NULL;
    second->pre=first;
    third->pre=second;
    fourth->pre=third;


    Node *head=first;
    Node *last=fourth;

    // display(head);
    // displayreverse(last);

    // head=insertAtfirst(head);
    // display(head);
    // head=insertAtlast(head);
    // display(head);
    // head=deletefirst(head);
    // display(head);
    // head=deletelast(head);
    // display(head);
    // head=deletebetween(head);
    // cout<<"Element found at "<<searchdata(head,1)<<" node";
    display(head);
    head= deletebetween(head);
    display(head);
    

}