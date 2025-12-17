//header file which includes sorting functions
#include<iostream>

//sorting the elements in array though bubble sort
void bubble_sort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}

//sorting the elements in array though selection sort
void selection_sort(int arr[],int size){
    for(int i=0;i<size;i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
       std::swap(arr[min],arr[i]);
    }

}

//sorting the elements in array though insetion sort
void insertion_sort(int arr[],int size){
    for(int i=1;i<size;i++){
        int j=i-1;
        while(j>=0 && arr[j]>arr[j+1]){
            std::swap(arr[j],arr[j+1]);
            j--;
        }
    }
}