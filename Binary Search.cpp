#include <iostream>

using namespace std;

bool search(int arr[], int start, int end, int num) {
  if (start < end) {
    int middle = (start + end) / 2;
    if (num == arr[middle]) {
      return true;
    }
    if (num < arr[middle]) {
      search(arr, start, middle, num);
    }
    if (num > arr[middle]) {
      search(arr, middle, end, num);
    }
  }
  return false;
}

int main() {
  int arr[] = {10,20,30,40,50,60,70,80,90};
  int len = sizeof(arr) / sizeof(arr[0]);
  
  if(search(arr,0,len-1,50)){ cout<<"Found"; }
  else{ cout<<"Not Found"; }
  return 0;
}
