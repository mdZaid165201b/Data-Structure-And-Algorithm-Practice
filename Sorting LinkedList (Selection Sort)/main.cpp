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
            cout<<temp->getData()<<endl;
            temp = temp->getNext();
        }
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
            else
            {
                return NULL;
            }
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

};

int main()
{
    LinkedList l1;
    l1.insertAtLast(8);
    l1.insertAtLast(5);
    l1.insertAtLast(7);
    l1.insertAtLast(1);
    l1.print();
    cout<<endl<<endl;
    l1.sort();
    l1.print();

    return 0;
}
