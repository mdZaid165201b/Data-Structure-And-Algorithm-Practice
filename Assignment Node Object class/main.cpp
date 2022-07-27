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
bool isEmpty (Node *head)
{
    return (head == NULL) ? true : false;
}
Node * getFirstElement (Node * head)
{
    return head;
}
Node * getNthElement (Node * head, int pos)
{
    if (!isEmpty (head))
    {
        Node * temp = head;
        for (int i = 1; i < pos; i++)
        {
            if (temp->getNext () != NULL)
            {
                temp = temp->getNext ();
            }
            else
            {
                return NULL;
            }
        }
        return temp;
    }
}
Node * getLastElement (Node * head)
{
    if (isEmpty (head))
    {
        cout << "LinkedList is Empty";
    }
    else
    {
        Node * temp = head;
        while (temp->getNext () != NULL)
        {
            temp = temp->getNext ();
        }
        return temp;
    }
}
int getLength (Node * head)
{
    int count = 0;
    if (!isEmpty (head))
    {
        Node * temp = head;
        while (temp != NULL)
        {
            temp = temp->getNext ();
            count++;
        }
        return count;
    }
    return count;
}
void print (Node * head)
{
    Node * temp = head;
    while (temp != NULL)
    {
        cout << temp->getData () << endl;
        temp = temp->getNext ();
    }
}
void insert (Node *head,int val)
{
    Node *newNode = new Node (val);
    if (isEmpty (head))
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
int main ()
{
    Node * n1 = new Node (1);
    Node * n2 = new Node (2);
    Node * n3 = new Node (3);
    Node * n4 = new Node (4);
    Node * n5 = new Node (5);
    Node * n6 = new Node (6);
    Node * n7 = new Node (7);
    Node * n8 = new Node (8);
    Node * n9 = new Node (9);
    Node * n10 = new Node (10);
    Node * n11 = new Node (11);
    Node * n12 = new Node (12);
    Node * n13 = new Node (13);
    Node * n14 = new Node (14);
    Node * n15 = new Node (15);
    Node * n16 = new Node (16);
    Node * n17 = new Node (17);
    Node * n18 = new Node (18);
    Node * n19 = new Node (19);
    Node * n20 = new Node (20);
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

    Node * head = n1;
    isEmpty (head)? cout << "List is Empty" : cout << "Not Empty";
    Node * temp;
    temp = getFirstElement (head);
    cout << endl << temp->getData () << endl;
    temp = getLastElement (head);
    cout << temp->getData () << endl;
    print (head);
    insert (head,21);
    cout << endl << endl;
    print (head);
    cout << endl;
    Node * nthNode = getNthElement (head,2);	// If position is invalid then function return NULL value
    if (nthNode == NULL)
    {
        cout << "invalid position";
    }
    else
    {
        cout << nthNode->getData ();
    }
    return 0;
}




