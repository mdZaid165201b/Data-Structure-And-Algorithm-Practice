

void merge(int arr[],int left, int middle, int right){
    int tempArray[right] = {-1};
    int i = left;
    int j = middle + 1;
    int k = left;
    
    while(i <= middle && j <= right){
        if(arr[i] < arr[j]){
            tempArray[k] = arr[i];
            i++;
        }
        else{
            tempArray[k] = arr[j];
            j++;
        }
        ++k;
    }
    if(i > middle){
        while(j <= right){
            tempArray[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= middle){
            tempArray[k] = arr[i];
            i++;
            k++;
        }
    }
    for(int i = left; i <= right; i++){
        arr[i] = tempArray[i];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int middle = (left + right) / 2;
        mergeSort(arr,left,middle);
        mergeSort(arr,middle + 1,right);
        merge(arr,left, middle, right);
    }
}

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
