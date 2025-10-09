
#include <iostream>
 
using namespace std;

class Node{
    public:
    Node* next;
    int data;
    Node* prev;
    
    
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }

};

class LL{
    Node* head;
    //Node* next;
    public:
    LL(){
        head=NULL;
        
    }

    void InsertAtEnd(int data){
        Node* newnode=new Node(data);
        if (head==NULL){  //head was just created so it should not have  next
            head=newnode;  //simple an straighforward assign
            newnode->next=NULL;
            newnode->prev=NULL;
            return;
        }
        
        if(head !=NULL){
            Node* temp;
            temp=head;
            while(temp->next != NULL){
                  temp=temp->next;
            }                              //traverse till end and assign lasts next to newnode
            temp->next=newnode;
            newnode->next=NULL;
            newnode->prev=temp;
             
        }
    }

    void InsertAtBeg(int data){
        Node* newnode=new Node(data);
            newnode->next=head; //first newnode nexr val assigned
            head=newnode;     //head as newnode
            newnode->prev=NULL;
        
    }

    void deletenode(int data){
         
        
        if(head!=NULL && head->data==data){
            
            Node* temp=head;
            head=head->next;//have to update the next head as well
            if(head != NULL)
            head->prev=NULL;
            delete temp;
            cout<<"deleted"<<data<<endl;
        }
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL && temp->data != data){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"value not in list\n";
            return;
        }
            
        if (temp->next !=NULL)
        {
            temp->next->prev=prev;
            prev->next=temp->next;
            delete temp;
        }
        

        

    }

    void Display(){
        if(head==NULL){
            cout<<"list is empty\n";

        }
        if(head!=NULL){
            Node* temp;
            temp=head;
            while(temp !=NULL){   //dont print temp->next!=NULL bc then last node wont print
                cout<<temp->data<<"->";
                temp=temp->next;
            }
        }
    }

    void DisplayReverese(){
        if(head ==NULL){
            cout<<"list is empty \n";
        }
         //traverse till the lst node
        Node* temp= head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        //reverse
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->prev;
        }
        cout<<"NULL\n";
    }


};
 

 
int main() {
 
    LL l1;
    l1.InsertAtBeg(4);
     
    l1.InsertAtEnd(5);
    l1.InsertAtEnd(6);
    l1.InsertAtEnd(7);
    l1.InsertAtEnd(8);
    l1.InsertAtEnd(9);
     
    l1.deletenode(8);
    l1.Display();

}


