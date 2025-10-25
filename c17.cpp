// Linked List
// singly linked list
#include <iostream>
using namespace std;

class Node{
    public:
     int data;
     Node* next;

     // constructor
     Node(int data){
        this->data =data;
        this->next =NULL;
     }

     // destrucotr
     ~Node(){
        int value=this->data;
        // memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
     }
};

// to add a node at the front/start
void insertAtHead(Node* &head, int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}


// Tail ma ending node k agay new node add krain gay
void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next = temp;
    tail=temp;

}


// insert in middle
// insert at any position
void insertAtPosition(Node* &tail, Node* &head, int position, int d){

    // insert at the start
  if(position==1){
    insertAtHead(head,22);
    return;
  }

     // for traversing
     Node*temp=head;
     int cnt=1;
     while(cnt<position-1){
        temp=temp->next;
        cnt++;
     }
 
     // inserting at the last position
     if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
     }



     Node* nodeToInsert= new Node(d);
      nodeToInsert -> next = temp -> next;
      temp -> next = nodeToInsert;


}


// deleting first or start node
void deleteNode(Node* &head, int position){
      if(position==1){
        Node*temp=head;
        head=head-> next;
        // memory free of start node
        temp->next=NULL;
        delete temp;
      }

      else{
        // deleting any middle or last node
        Node*curr=head;
        Node*prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
      }

}


void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<< temp-> data <<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(10);
    // cout<< node1->data << endl;
    // cout<< node1->next << endl;

    // head pointed to node1             head is a pointer variable that now points to the same node as node1.
    Node* head=node1;
    Node* tail=node1;

    print(head);
    // insertAtHead(head,12);
    insertAtTail(tail,12);
    print(head);
    // insertAtHead(head,15);
    insertAtTail(tail,15);
    print(head);

    // insertAtPosition(tail, head,3,22);
    // insertAtPosition(head,2,22);
    // insertAtPosition(head,4,22);
    // insertAtPosition(head,1,22);      // -- This will not work ---Now will work becoz we put condition here!

    insertAtPosition(tail,head,4,22);

    print(head);

    deleteNode(head,1);
    print(head);

    

    cout << head->data <<endl;
    cout << tail->data <<endl;

return 0;
}