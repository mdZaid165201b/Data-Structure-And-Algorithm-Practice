/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

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


};

int main()
{
    LinkedList l1;
    l1.insertAtLast(2);
    l1.insertAtLast(5);
    l1.insertAtLast(7);
    l1.insertAtLast(9);
    l1.print();
    cout<<endl<<endl;
    cout<<l1.getElementFromIndex(0)->getData();

    return 0;
}
