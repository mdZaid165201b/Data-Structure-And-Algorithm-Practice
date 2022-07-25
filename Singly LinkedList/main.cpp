#include <iostream>
using namespace std;
class LinkedList
{
private:
    class Node
    {
        Node *next;
        int data;
    public:
        Node()
        {
            data = -1;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(Node *next)
        {
            this->next = next;
            this->data = -1;
        }
        Node(int data, Node *next)
        {
            this->data = data;
            this->next = next;
        }
        //Getters and Setters
        int getData()
        {
            return data;
        }
        Node *getNext()
        {
            return this->next;
        }
        void setData(int data)
        {
            this->data = data;
        }
        void setNext(Node *next)
        {
            this->next = next;
        }
    };
    Node *head;
public:
    LinkedList()
    {
        head = NULL;

    }
public:
    bool isEmpty()
    {
        return (head == NULL) ? true: false;
    }
    void insert(int val)
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
    void print()
    {
        if(head == NULL)
        {
            cout<<"No Data in the LinkedList";
        }
        else
        {
            Node *temp = head;
            while(temp->getNext() != NULL)
            {
                cout<<temp->getData()<<endl;
                temp = temp->getNext();
            }
            cout<<temp->getData();

        }
    }

    void insertAtPosition(int val,int pos)
    {
        if(isEmpty())
        {
            insert(val);
        }
        else
        {
            Node *temp,*newNode,*currentNode;
            newNode = new Node(val);
            temp = head;
            int i =1;
            while(i<pos)
            {
                currentNode = temp;
                temp = temp->getNext();
                i++;
            }
            newNode->setNext(currentNode->getNext());
            currentNode->setNext(newNode);
        }
    }
    bool deleteFromEnd()
    {
        if(!isEmpty())
        {
            if(head->getNext() == NULL)
            {
                Node *temp = head;
                head = NULL;
                delete temp;
                return true;
            }
            else
            {
                Node *temp, *temp2;
                temp = head;
                while(temp ->getNext() != NULL)
                {
                    temp2 = temp;
                    temp = temp->getNext();
                }
                delete temp;
                temp2->setNext(NULL);
                return true;
            }
        }
        return false;
    }



};


int main()
{
    LinkedList l1;

    l1.insert(2);
    l1.insert(6);
    l1.insert(4);
    l1.print();
    cout<<endl<<endl;

    l1.insertAtPosition(8, 2);
    l1.print();
    cout<<endl<<endl;
    l1.deleteFromEnd();
    l1.print();
}
