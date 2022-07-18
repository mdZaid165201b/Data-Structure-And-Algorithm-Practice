#include <iostream>

using namespace std;

const int arraySize = 100;
class MyArray
{
private:
    int arr[arraySize];
    int length;
public:
    MyArray()
    {
        length = 0;
        for(int i = 0; i< arraySize; i++)
        {
            arr[i] = -1;
        }
    }
    //getLength
    int getLength()
    {
        return length;
    }
    //isFull method
    bool isFull()
    {
        return length == arraySize ? true : false;
    }
    //isEmpty() method
    bool isEmpty()
    {
        return length == arraySize ? true: false;
    }

    //insertAtLast method
    bool insertAtLast(int val)
    {
        if(!isFull())
        {
            arr[length] = val;
            length++;
            return true;
        }
        return false;
    }

    //print method
    void print()
    {
        int i = 0;
        while(i<length)
        {
            cout<<arr[i]<<endl;
            i++;
        }

    }
    //rightShift() method
    void rightShift(int pos)
    {
        if(!isFull())
        {
            int i = getLength();
            while(i>=pos)
            {
                arr[i] = arr[i-1];
                i--;
            }
        }
        else
        {
            int i = getLength();
            while(i>pos)
            {
                arr[i-1] = arr[i-2];
                i--;
            }
            arr[i-1] = -1;
        }
    }

    //insertElementAtPosition method
    bool insertElemAtPos(int pos,int val)
    {

        //int i = getLength();
        //while(i>=pos)
        //{
        //    arr[i] = arr[i-1];
        //    i--;
        //}
        //  arr[pos-1] = val;
        //  length++;
        //   return true;

        // }
        rightShift(pos);
        arr[pos-1] = val;
        length++;
        return true;


    }
    //getElemAtPosition method
    int getElemAtPos(int pos)
    {
        return !isEmpty() ? arr[pos-1] : -1;

    }
    //doesExist() method
    bool doesExist(int val)
    {
        int i = 0;
        if(!isEmpty())
        {
            while(i<getLength())
            {
                return (arr[i] == val) ? true : false;
                i++;
            }
        }
        return false;

    }
    //find() method
    int find(int val){
        for(int i = 0;i<length;i++){
            return arr[i] == val ? i: -1;
        }
    }
    //shiftLeft() method
    void leftShift(int pos){
        for(int i = pos-1;i<getLength();i++){
            arr[i] = arr[i+1];
        }
        arr[getLength()] = -1;
    }
    //removeElemAtPosition method
    bool removeElemAtPos(int pos){
        if(!isEmpty()){
            leftShift(pos);
            length--;
            return true;
        }
        return false;
    }
    // removeFirstElem() method
    bool removeFirstElem(){
        if(!isEmpty()){
            removeElemAtPos(1);
            return true;
        }
        return false;
    }

    //remove lastElem() method
    bool removeLastElem(){
        if(!isEmpty()){
            arr[getLength()-1] = -1;
            length--;
            return true;
        }
        return false;
    }
    //removeElem() method
    bool removeElem(int val){
        if(doesExist(val)){
            arr[find(val)] = -1;
            length--;
            return true;
        }
    }
    //getFirstElem() method
    int getFirstElem(){
        return !isEmpty() ? arr[0] : -1;
    }
    //getLastElem() method
    int getLastElem(){
        if(!isEmpty()){
            return arr[getLength()-1];
        }
    }
};

class Stack{
private:
    MyArray ma;
public:
    bool push(int val){
        if(!ma.isFull()){
            ma.insertAtLast(val);
            return true;
        }
        return false;
    }
    int pop(){
        if(!ma.isEmpty()){
            int lastValue = ma.getLastElem();
            ma.removeLastElem();
            return lastValue;
        }
    }
    //top() method
    int top(){
        if(!ma.isEmpty()){
            return ma.getLastElem();
        }
    }
    //print() method
    void print(){
        ma.print();
    }
};

int main()
{
    Stack s1;
    s1.push(40);
    s1.push(50);
    s1.push(80);
    s1.print();
    s1.pop();
    s1.print();

    return 0;
}
