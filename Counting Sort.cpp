// Counting short

#include <iostream>

using namespace std;




void countingSort(int arr[], int len){
    int max = arr[0];
    for(int i = 0; i < len; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int count[max+1] = {0};

    // for(int i = 0; i < max; i++){ cout<<count[i]<<" "; }
    for(int i = 0; i < len; i++){
        ++count[arr[i]];
    }
    
    for(int i = 1; i <= max; i++){
        count[i] = count[i] + count[i - 1];
    }
    
    int sortedArr[len] = {0};
    for(int i = len-1; i >=0; i--){
        sortedArr[--count[arr[i]]] = arr[i];
    }
    
    // copy sortedArr to original array
    for(int i = 0; i < len; i++){
        arr[i] = sortedArr[i];
    }
}

void print(int *arr,int len){
    for(int i = 0; i < len; i++){ cout<<arr[i]<<" "; }
}

int main()
{
    int arr[6] = {5,0,1,7,3,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr,len);
    print(arr,len);

    return 0;
}
