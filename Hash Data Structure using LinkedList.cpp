
#include <iostream>

using namespace std;
class Node{
    int data;
    Node *next;
    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    
    // setters and getters
    void setData(int data){ this->data = data; }
    void setNext(Node *next){ this->next = next; }
    
    int getData(){ return this->data; }
    Node *getNext(){ return this->next; }
};

class LinkedList{
    Node *head;
    public:
    LinkedList(){ this->head = NULL; }
    void insertAtLast(int val){
        if(head == NULL){
            head = new Node(val);
        }
        else{
            Node *temp = head;
            while(temp->getNext() != NULL){
                temp = temp->getNext();
            }
            temp->setNext(new Node(val));
        }
    }
    void print(){
        Node *temp = head;
        while(temp){
            cout<<temp->getData()<<" ";
            temp = temp->getNext();
        }
    }
    
    bool deleteSpecificValue(int val){
        if(head == NULL){ return false; }
        else if(head->getData() == val){
            if(head->getNext() != NULL){
                Node *temp = head->getNext();
                this->head = temp;\
            }
            else{
                delete(head);
                head = NULL;
            }
            return true;
        }
        else{
            Node *temp = head;
            Node *prev;
            while(temp){
                prev = temp;
                temp = temp->getNext();
                if(temp->getData() == val){
                    Node *tempNext = temp->getNext();
                    delete(temp);
                    prev->setNext(tempNext);
                    
                    return true;
                }
            }
            return false;
        }
    }
    
    bool isEmpty(){ return head == NULL; }
    
};

class Hash{
    int HashSize;
    LinkedList **arr;
    public:
    Hash(int size){
        HashSize = size;
        arr = new LinkedList*[HashSize];
        for(int i = 0; i < HashSize; i++){
            arr[i] = new LinkedList();
        }
    }
    
    int hashFunction(int key){
        return key % HashSize;
    }
    
    void insert(int val){
        int index = hashFunction(val);
        arr[index]->insertAtLast(val);
    }
    
    bool deleteVal(int val){
        int index = hashFunction(val);
        return arr[index]->deleteSpecificValue(val);
    }
    
    void display(){
        for(int i = 0; i< HashSize; i++){
            if(!arr[i]->isEmpty()){
                arr[i]->print();
            }
        }
        cout<<endl;
    }
    
    
};
