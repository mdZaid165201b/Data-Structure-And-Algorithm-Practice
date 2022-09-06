#include<iostream>
using namespace std;

void insertionSort(int arr[], int length){
    for(int  i = 1; i < length; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
                j--;
            }
            else{ break; }
        }
        arr[j+1] = temp;
    }
}

void print(int arr[], int length){
    for(int  i = 0; i < length; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {2,1,10,7,8,9};
    int length = sizeof(arr)/sizeof(arr[0]);
    print(arr,length);
    insertionSort(arr,length);
    print(arr,length);
    
}
