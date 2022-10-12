#include<iostream>
using namespace std;

void selectionSort(int arr[],int length){
    for(int i = 0; i < length-1; i++){
        for(int  j = i+1;j < length; j++){
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
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
    int arr[] = {2,5,4,7,8,9};
    int length = sizeof(arr)/sizeof(arr[0]);
    print(arr,length);
    selectionSort(arr,length);
    print(arr,length);
}
