

void print(int arr[], int len){
    for(int i = 0; i < len; i++){ cout<<arr[i]<<" "; }
}

int main()
{
    int arr[6] = {6,5,4,3,2,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, len - 1);
    print(arr,len);

    return 0;
}