#include <iostream>
using namespace std;
class Stack
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
    Node *lastNode;
public:
    Stack()
    {
        head = NULL;
        lastNode = NULL;
    }
    bool isEmpty()
    {
        return (head == NULL) ? true: false;
    }
    void push(int val)
    {
        Node *newNode = new Node(val);
        if(isEmpty())
        {
            head = newNode;
            lastNode = head;

        }
        else
        {

            newNode->setNext(lastNode);
            lastNode = newNode;
        }
    }
    bool pop()
    {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            if(lastNode->getNext() == NULL)
            {
                Node *temp;
                temp = head;
                lastNode = NULL;
                head = NULL;
                delete temp;
                return true;
            }
            else
            {
                Node *temp;
                temp = lastNode;
                lastNode = temp->getNext();
                delete temp;
                return true;
            }
        }
    }
    int top()
    {
        return isEmpty() ? -1 : lastNode->getData();
    }
    void print()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty!!!";
        }
        else
        {
            Node *temp;
            temp = lastNode;
            while(temp->getNext() != NULL)
            {
                cout<<temp->getData()<<endl;
                temp = temp->getNext();
            }
            cout<<temp->getData();
        }
    }
};
int main()
{
    Stack s1;
    s1.push(2);
    s1.push(4);
    s1.push(6);
    s1.print();
    cout<<endl<<endl<<s1.top();
    cout<<endl<<endl;

    s1.pop();
    s1.print();
    cout<<endl<<endl;
    s1.pop();
    s1.print();
    cout<<endl<<endl;
    s1.pop();
    s1.print();
}
