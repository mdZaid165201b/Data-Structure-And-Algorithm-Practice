
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

class LinkedList{
    protected:
    Node *head;
    Node *last;
    int length;
    public:
    LinkedList():head(NULL), last(NULL), length(0) {}
    
    
    
    int getLength(){ return length; }
    Node* getHead(){ return this->head; }
    
    
    
    // virtual void insertAtBegin(int value) = 0;
    // virtual void insertAtLast(int value) = 0;
    // virtual void removeAtBegin() = 0;
    // virtual void removeAtLast() = 0;
        
    
    
    bool isEmpty(){ return this->length == 0 ? true : false; }
    
    void print(Node* head){
        while(head != NULL){
            cout<<head->getData()<<"->";
            head = head->getNext();
        }
        cout<<"NULL"<<endl;
    }
    void print(){
        print(this->head);
    }
};

class SinglyLinkedList: public LinkedList{
    public:
    void insertAtBegin(int value){
        Node* newNode = new Node(value);
        if(isEmpty()){
            this->head = newNode;
            this->last = newNode;
        }
        else{
            newNode->setNext(this->head);
            this->head = newNode;
        }
        this->length++;
    }
    
    void insertAtLast(int value){
        if(isEmpty()){
            insertAtBegin(value);
        }
        else{
            Node* newNode = new Node(value);
            this->last->setNext(newNode);
            this->last = newNode;
            this->length++;
        }
    }
    
    bool removeAtBegin(){
        if(isEmpty()){ return false; }
        else{
            Node* temp = this->head;
            this->head = this->head->getNext();
            delete temp;
            this->length--;
            return true;
        }
    }
    
    bool removeAtLast(){
        if(isEmpty()){ return false; }
        else{
            Node* temp = this->head;
            while(temp->getNext()->getNext() != NULL){
                temp = temp->getNext();
            }
            Node* temp2 = temp->getNext();
            temp->setNext(NULL);
            delete temp2;
            this->length--;
            return true;
        }
    }
    
    
    
    
};


int main()
{
    SinglyLinkedList s1;
    s1.insertAtBegin(5);
    s1.insertAtBegin(10);
    s1.insertAtLast(15);
    s1.print();
    s1.removeAtLast();
    s1.print();

    return 0;
}
