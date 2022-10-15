#include <iostream>

using namespace std;

const int size = 10;
class Hash{
    int arr[size];
    public:
    Hash(){
        for(int i = 0; i < size; i++){
            arr[i] = -1;
        }
    }
    void print(){
        for(int i = 0; i < size; i++){
            if(arr[i] != -1){ cout<<arr[i]<<" "; }
        }
        cout<<endl;
    }
    
    int hashFunction(int key){
        return key % size;
    }
    
    void insert(int val){
        int index = hashFunction(val);
        if(arr[index] == -1){
            arr[index] = val;
        }
        else{
            int i = index;
            while(i < size){
                if(arr[i] == -1){
                    arr[i] = val;
                    return;
                }
                i++;
            }
            i = 0;
            while(i < index){
                if(arr[i] == -1){
                    arr[i] = val;
                    return;
                }
                i++;
            }
        }
    }
    
};

int main()
{
    Hash h1;
    h1.insert(5);
    h1.insert(10);
    h1.insert(15);
    h1.insert(20);
    h1.print();

    return 0;
}
