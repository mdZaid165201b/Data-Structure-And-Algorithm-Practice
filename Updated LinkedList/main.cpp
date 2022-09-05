#include <iostream>

using namespace std;

class Node
{
    Node * next;
    int data;
public:
    Node ()
    {
        data = -1;
        next = NULL;
    }
    Node (int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node (Node * next)
    {
        this->next = next;
        this->data = -1;
    }
    Node (int data, Node * next)
    {
        this->data = data;
        this->next = next;
    }
    //Getters and Setters
    int getData ()
    {
        return data;
    }
    Node * getNext ()
    {
        return this->next;
    }
    void setData (int data)
    {
        this->data = data;
    }
    void setNext (Node * next)
    {
        this->next = next;
    }
};
//  --------------LinkedList Class-------------------------
class LinkedList
{
private:
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(int val)
    {
        insertAtLast(val);
    }
    bool isEmpty()
    {
        return (head == NULL) ? true : false;
    }
    int getLength()
    {
        int count = 0;


        Node * temp = head;
        while (temp != NULL)
        {
            temp = temp->getNext ();
            count++;
        }
        return count;


    }
    void insertAtBegin(int val)
    {
        Node *newNode = new Node(val);
        if(isEmpty())
        {
            head = newNode;
        }
        else
        {
            newNode->setNext(head);
            head = newNode;

        }

    }
    void insertAtLast(int val)
    {
        Node *newNode = new Node(val);

        if(isEmpty())
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while(temp->getNext() != NULL)
            {
                temp = temp->getNext();
            }
            temp->setNext(newNode);
        }
    }
    bool removeFromBegin()
    {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            if(getLength() == 1)
            {
                delete head;
                head = NULL;
            }
            else
            {
                Node *temp = head;
                head = temp->getNext();
                delete temp;
                return true;
            }
        }
    }
    bool removeFromLast()
    {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            Node *temp,*prevNode;
            temp = head;
            while(temp->getNext() != NULL)
            {
                prevNode = temp;
                temp = temp->getNext();
            }
            delete temp;
            prevNode->setNext(NULL);
            return true;
        }
    }
    Node *getFirstElement()
    {
        return head;
    }
    Node *getLastElement()
    {
        Node *temp;
        temp = head;
        while(temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        return temp;
    }
    void print()
    {
        Node *temp;
        temp = head;
        while(temp != NULL)
        {
            cout<<temp->getData()<<"->";
            temp = temp->getNext();
        }
        cout<<"NULL"<<endl;
    }

    Node *getElementFromIndex(int index)
    {
        if(isEmpty())
        {
            return NULL;
        }
        else
        {
            Node *temp = head;
            if(index >=0 && index <=getLength())
            {
                for(int i = 0; i<=index; i++)
                {
                    if(i == index)
                    {
                        return temp;
                    }
                    else
                    {
                        temp= temp->getNext();
                    }
                }
            }
            return NULL;
        }
    }
    void reverseLinkedList()
    {
        Node *temp = head;
        int *arr = new int(getLength());
        int i  = 0;
        while(temp!= NULL)
        {
            arr[i] = temp->getData();
            temp = temp->getNext();
            i++;
        }
        temp = head;
        for(int i = getLength()-1; i>=0; i--)
        {
            temp->setData(arr[i]);
            temp = temp->getNext();

        }
        print();

    }
    void swap(int index1,int index2)
    {
        Node *firstElem = getElementFromIndex(index1);
        Node *secondElem = getElementFromIndex(index2);
        int temp = firstElem->getData();
        firstElem->setData(secondElem->getData());
        secondElem->setData(temp);
    }

    void sort()
    {
        Node  *temp = head;
        Node *temp2 = head;
        int i = 0;
        int j = 0;
        while(i<getLength()-1)
        {
            while(j<getLength()-1)
            {
                if(temp2->getData()<temp2->getNext()->getData())
                {
                    // no swap
                    temp2 = temp2->getNext();
                    j++;
                }
                else
                {
                    swap(j,j+1);
                    temp2 = temp2->getNext();
                    j++;
                }
            }
            temp2 = head;
            temp = temp->getNext();
            j = 0;
            i++;
        }
    }

    // Second method for sorting
    void secondSort(){
        Node *temp = head;
        Node *temp2 = head;
        int index1 = 0;
        int index2 = 0;
        while(temp!=NULL){
            while(temp2!=NULL){
                if(temp2->getData()<temp->getData()){
                    swap(index1,index2);
                    temp2 = temp2->getNext();
                    index2++;
                }
                else{
                    index2++;
                    temp2 = temp2->getNext();
                }
            }
            index1++;
            index2 = index1;
            temp = temp->getNext();
            temp2 = temp;
        }
    }

    void mergeLinkedList(LinkedList l2){

        if(isEmpty()){
            if(!l2.isEmpty()){
                head = l2.getFirstElement();
            }
            else{
                return;
            }

        }
        else{
            if(l2.isEmpty()){
                return;
            }
            else{
                Node *temp = getLastElement();
                temp->setNext(l2.getFirstElement());
            }
        }
    }

    void copyLinkedList(LinkedList l2){
        Node *temp = l2.getFirstElement();
        Node *prev = getLastElement();
        while(temp!=NULL){
            Node *newNode = new Node(temp->getData());
            prev->setNext(newNode);
            prev = newNode;
            temp = temp->getNext();
        }

    }
    
    // insert in sorted way
    bool insertInSort(int val)
    {
        if(isEmpty())
        {
            insertAtLast(val);
            return true;
        }
        else
        {
            if(head->getNext() == NULL)
            {
                if(val<head->getData())
                {
                    insertAtBegin(val);
                }
                else
                {
                    insertAtLast(val);
                }
            }
            else
            {
                Node *temp = head;
                if(val<head->getData())
                {
                    insertAtBegin(val);
                    return true;
                }
                else
                {
                    while(temp->getNext() != NULL)
                    {
                        if(val>temp->getData() && val<temp->getNext()->getData())
                        {
                            Node *newNode = new Node(val);
                            newNode->setNext(temp->getNext());
                            temp->setNext(newNode);
                            return true;
                            break;
                        }
                        temp = temp->getNext();
                    }
                    Node *newNode = new Node(val);
                    temp->setNext(newNode);
                    return true;
                }
            }
        }
    }
    
    void insertAtNthPosition(int value,int position){
        Node *temp = head;
        Node *prev = head;
        if(isEmpty()) return;
        else{
            for(int i = 0;i<position;i++){
                prev = temp;
                temp =temp->getNext();
            }
            cout<<"prev Data ->"<<prev->getData()<<endl;
            cout<<"curr Data ->"<<temp->getData()<<endl;
            Node * newNode = new Node(value);
            prev->setNext(newNode);
            newNode->setNext(temp);
        }
    }
    
    // remove Duplicates from LinkedList from Sorted Array method
    void removeDuplicates(){
        sort();
        Node *temp = head;
        Node *temp2 = temp->getNext();
        while(temp!=NULL){
            while(temp2!=NULL){
                if(temp->getData() == temp2->getData()){
                    Node *forDeleteNode = temp2;
                    if(temp2->getNext() == NULL){
                        // cout<<"forDeleteNode =>"<<forDeleteNode->getNext()<<endl;
                        // cout<<"if part when temp2->getNext => NULL"<<endl;
                        // cout<<"temp2->getData()"<<temp2->getData()<<endl;
                        // cout<<"temp2->getNext()"<<temp2->getNext()<<endl;
                        // cout<<"temp->getData()"<<temp->getData()<<endl;

                        temp = NULL;
                        temp2 = NULL;
                        removeFromLast();
                        break;
                        
                    }
                    else{
                        temp->setNext(temp2->getNext());
                        temp2 = temp->getNext();
                        delete forDeleteNode;
                        forDeleteNode = NULL;
                        continue;
                    }
                }
                    temp = temp->getNext();
                    temp2 = temp->getNext();
            }
        }
    }
    
    Node* getMiddleNode(Node* head){
        if(isEmpty()){ return NULL; }
        else{
            cout<<"Length of LinkedList "<<getLength()<<endl;
            int middle = getLength() / 2;
            // cout<<middle;
            Node* temp = this->head;
            for(int i = 0; i < middle; i++ ){
                temp = temp->getNext();
            }
            return temp;
        }
    }
    Node* getMiddleNode(){
        return getMiddleNode(this->head);
    }
    
    /*---------Testing Swap Nodes------------*/
    bool swapNodes(int index1,int index2){
        Node* prev1;
        Node* curr1;
        Node* prev2;
        Node* curr2;
        curr1 = this->head;
        for(int i = 0;i<index1;i++){
            prev1 = curr1;
            curr1= curr1->getNext();
        }
        for(int i = 0;i<index2;i++){
            prev2 = curr2;
            curr2 = curr2->getNext();
        }
        
        cout<<"curr1 "<<curr1->getData()<<endl;
        cout<<"prev1 "<<prev1->getData()<<endl;
        cout<<"curr2 "<<curr2->getData()<<endl;
        cout<<"prev2 "<<prev2->getData()<<endl;
        
    }

};

int main()
{
    LinkedList l1;
    l1.insertAtLast(8);
    l1.insertAtLast(5);
    l1.insertAtLast(7);
    l1.insertAtLast(1);

    LinkedList l2;
    l2.insertAtLast(10);
    l2.insertAtLast(20);
    l2.insertAtLast(30);
    l2.insertAtLast(80);
    l2.insertAtLast(40);
    l1.print();
    l2.print();
    cout<<endl<<endl;
    // l1.mergeLinkedList(l2);

    l1.copyLinkedList(l2);
    cout<<"After Merge"<<endl;
    l1.print();
    // l2.insertAtLast(100);
    l2.insertAtLast(200);
    l1.sort();

    cout<<"After Sorting"<<endl;
    l1.print();
    cout<<"L2"<<endl;
    l2.print();

    return 0;
}
