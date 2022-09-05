
#include <iostream>

using namespace std;

class Node{
    int data;
    Node* next;
    Node* prev;
    public:
    Node():data(-1),next(NULL), prev(NULL) {}
    Node(int data,Node* next = NULL){ this->data = data; }
    
    // setters
    void setData(int data){ this->data = data; }
    void setNext(Node* next){ this->next = next; }
    void setPrev(Node* prev){ this->prev = prev; }
    
    // getters
    int getData() { return this->data; }
    Node* getNext() { return this->next; }
    Node* getPrev() { return this->prev; }
};

class LinkedList(){
    Node *head;
    Node *last;
    int length;
    public:
    LinkedList():head(NULL), last(NULL), length(0) {}
    
    int getLength(){ return length; }
    Node* getHead(){ return this->head; }
    
    
    
    virtual void insertAtBegin(int value){
        
    }
    
    
    void print(Node* head){
        while(head != NULL){
            cout<<head->getData()<<"->";
            head = head->getNext();
        }
        cout<<"NULL"<<endl;
    }
};

class SinglyLinkedList: public LinkedList{
    public:
    
};


int main()
{
    Node n1;
    n1.setData(5);
    cout<<n1.getNext();

    return 0;
}
