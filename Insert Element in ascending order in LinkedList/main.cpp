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

class LinkedList
{
private:
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
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

    // This function insert element in ascending order in linkedList
    // For Example : 5,10,15
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
};

int main()
{
    LinkedList l1;
    l1.isEmpty() ? cout<<"List is Empty"<<endl : cout<<"List is not Empty"<<endl;
    // l1.insertAtLast(20);
    // l1.insertAtLast(25);
    // l1.insertAtBegin(10);
    // l1.insertInSort(5);
    // l1.insertInSort(30);

    l1.insertInSort(10);
    l1.insertInSort(5);
    l1.insertInSort(15);
    // l1.insertAtLast(15);
    // l1.insertAtLast(20);
    cout<<l1.getFirstElement()->getData()<<endl;
    cout<<l1.getLastElement()->getData()<<endl;
    cout<<endl<<l1.getLength()<<endl<<endl;
    l1.print();
    cout<<endl<<endl;
    // l1.removeFromBegin();
    // l1.print();
    // cout<<endl<<endl;
    // l1.removeFromLast();
    // l1.print();
    return 0;
}
