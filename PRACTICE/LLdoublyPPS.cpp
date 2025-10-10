 /*  solve this with a doubly linked list.
 suppose there are 2 mathematical expressions as the 2 separate inner linked lists like:
 Node1: 12->+->13->- ->5      this yeilds 12+13-5=20
 Node2: 12->/->2->*->3        this yeilds 18, and ANOTHER OUTER LINKED LIST THAT GOES LIKE:
 Node1->Node2->NULL; and yeild sthe sum of both the nodes as a result. write teh code for this 



 */
#include <iostream>
 
 using namespace std;

 class Node{
   public:
   Node* next;
   Node* prev;
   string data;
   Node(string d){
    next=NULL;
    prev=NULL;
    data=d;
   }
 };

 class InnerLL{
    Node* head;
    float answer;
    public:
    InnerLL(){
        head=NULL;
        answer=0;
    }

    void Insert(string exp){
         Node* newnode=new Node(exp);
         if(head==NULL){
            head=newnode;
         }
         Node* temp=head;
         while(temp->next!=NULL){
            temp=temp->next;
         }
         temp->next=newnode;
         newnode->next=NULL;
         newnode->prev=temp;
    }

    float evaluate(){
        if(head==NULL){
            cout<<"list is empty\n";
        }
        Node*temp=head;
        float result= stoi(temp->data);
        temp=temp->next;
        while(temp && temp->next){
            string op= temp->data;
            float val=stoi(temp->next->data);
            if(op=="+"){
                result=result + val;
            }
            if(op=="-"){
                result=result - val;
            }
            if(op=="*"){
                result=result*val;
            }
            if(op=="/"){
                result=result/val;
            }
            return result;
        }
    }
     
 };

 class OuterLL{
    public:
      InnerLL* n1;
      InnerLL* n2;
      OuterLL(InnerLL* a,InnerLL* b){
        n1=a;
        n2=b;
      }

      float total(){
        float t1=n1->evaluate();
        float t2=n2->evaluate();
        return t1+t2;
      }

       

 };
  
int main(){

    InnerLL* expr1=new InnerLL();
    expr1->Insert("12");
    expr1->Insert("+");
    expr1->Insert("13");
    expr1->Insert("-");
    expr1->Insert("5");

    // Expression 2: 12 / 2 * 3 = 18
    InnerLL* expr2 = new InnerLL();
    expr2->Insert("12");
    expr2->Insert("/");
    expr2->Insert("2");
    expr2->Insert("*");
    expr2->Insert("3");

    OuterLL outer(expr1, expr2);

    cout << "Expression 1 result: " << expr1->evaluate() << endl;
    cout << "Expression 2 result: " << expr2->evaluate() << endl;
    cout << "Sum of both expressions: " << outer.total() << endl;



      
}

