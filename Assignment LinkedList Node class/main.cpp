#include <iostream>

using namespace std;
class Node
{
    Node *next;
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
    Node *getNext ()
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
    Node * head;
public:
    LinkedList ()
    {
        head = NULL;
    }
    void setHead (Node * head)
    {
        this->head = head;
    }
    bool isEmpty ()
    {
        return (head == NULL) ? true : false;
    }
    Node *getFirstElement ()
    {
        if (isEmpty ())
        {
            cout << "LinkedList is Empty";
        }
        else
        {
            return head;
        }
    }
    Node *getLastElement ()
    {
        if (isEmpty ())
        {
            cout << "LinkedList is Empty";
        }
        else
        {
            Node *temp = head;
            while (temp->getNext () != NULL)
            {
                temp = temp->getNext ();
            }
            return temp;
        }
    }
    void print ()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->getData () << endl;
            temp = temp->getNext ();
        }
    }
    int getLength ()
    {
        int count = 0;
        if (!isEmpty ())
        {
            Node *temp = head;

            while (temp != NULL)
            {
                temp = temp->getNext ();
                count++;
            }
            return count;
        }
        return count;
    }
    void insert (int val)
    {
        Node *newNode = new Node (val);
        if (isEmpty ())
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->getNext () != NULL)
            {
                temp = temp->getNext ();
            }
            temp->setNext (newNode);

        }

    }
    Node *getNthElement (int pos)
    {
        if(!isEmpty())
        {
            Node *temp = head;
            for (int i = 1; i < pos; i++)
            {

                if(temp->getNext() !=NULL)
                {
                    temp = temp->getNext ();
                }
                else
                {
                    //cout<<"Position Invalid";
                    return NULL;
                }
            }
            return temp;
        }
    }
};

int
main ()
{

    Node *n1 = new Node (1);
    Node *n2 = new Node (2);
    Node *n3 = new Node (3);
    Node *n4 = new Node (4);
    Node *n5 = new Node (5);
    Node *n6 = new Node (6);
    Node *n7 = new Node (7);
    Node *n8 = new Node (8);
    Node *n9 = new Node (9);
    Node *n10 = new Node (10);
    Node *n11 = new Node (11);
    Node *n12 = new Node (12);
    Node *n13 = new Node (13);
    Node *n14 = new Node (14);
    Node *n15 = new Node (15);
    Node *n16 = new Node (16);
    Node *n17 = new Node (17);
    Node *n18 = new Node (18);
    Node *n19 = new Node (19);
    Node *n20 = new Node (20);
    n1->setNext (n2);
    n2->setNext (n3);
    n3->setNext (n4);
    n4->setNext (n5);
    n5->setNext (n6);
    n6->setNext (n7);
    n7->setNext (n8);
    n8->setNext (n9);
    n9->setNext (n10);
    n10->setNext (n11);
    n11->setNext (n12);
    n12->setNext (n13);
    n13->setNext (n14);
    n14->setNext (n15);
    n15->setNext (n16);
    n16->setNext (n17);
    n17->setNext (n18);
    n18->setNext (n19);
    n19->setNext (n20);


    LinkedList l1;
    l1.setHead (n1);
    l1.isEmpty ()? cout << "List is Empty" : cout << "Not Empty";

    Node *temp;
    temp = l1.getFirstElement ();
    cout << endl << temp->getData () << endl;
    temp = l1.getLastElement ();
    cout << temp->getData () << endl;
    l1.print ();

    l1.insert (21);
    cout << endl << endl;
    l1.print ();
    cout << endl;
    Node *nthNode = l1.getNthElement(2);  // If position is invalid then function return NULL value
    {
        cout<<"invalid position";
    }
    else
    {
        cout<<nthNode->getData();
    }

    return 0;
}
