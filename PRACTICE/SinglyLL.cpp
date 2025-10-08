//insertion & delete

#include <iostream>
 
using namespace std;

class Node{
    public:
    Node* next;
    int data;
    
    
    Node(int val){
        data=val;
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
        if (head==NULL){
            head=newnode;  //simple an straighforward assign
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
             
        }
    }

    void InsertAtBeg(int data){
        Node* newnode=new Node(data);
            newnode->next=head; //first newnode nexr val assigned
            head=newnode;     //head as newnode
            
        
    }

    void deletenode(int data){
         
        
        if(head!=NULL && head->data==data){
            
            Node* temp=head;
            head=head->next;//have to update the next head as well
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
            
             prev->next=temp->next;
            delete temp;
            cout<<"value deleted "<<data<<endl;
        
         

        

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
};
 

 
int main() {
 
    LL l1;
    l1.InsertAtBeg(4);
     
    l1.InsertAtEnd(5);
    l1.InsertAtEnd(6);
    l1.InsertAtEnd(7);
    l1.InsertAtEnd(8);
    l1.InsertAtEnd(9);
    l1.Display();

    l1.deletenode(7);
    l1.Display();

}

