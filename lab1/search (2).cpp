//program for searching an element in an array
#include<iostream>
#include"header.h"

int linear_search(int arr[],int size,int element);

int binary_search(int arr[],int size,int element);

int main(){

    int size;
    std::cout<<"enter the size of the array:";
    std::cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        std::cout<<"\nenter the number you want to insert in the array at position"<<i+1<<":";
        std::cin>>arr[i];
    }
    int choice;
    while(1){
        int element;
        int index;
        std::cout<<"\nenter your choice\n"<<"1.linear search\n"<<"2.binary search\n"<<"3.exit\n";
        std::cin>>choice;
        if(choice==1){
            std::cout<<"enter the element to be searched:\n";
            std::cin>>element;
            index=linear_search(arr,size,element);
            if(index==-1){
                std::cout<<"The element is not present in the array\n";

            }
            else{
                std::cout<<"The first occurunce of the element"<<" "<<element<<" "<< "is present at position:"<<index+1<<std::endl;
            }
        }
        else if(choice==2){
            std::cout<<"enter the element to be searched:\n";
            std::cin>>element;
            index=binary_search(arr,size,element);
            if(index==-1){
                std::cout<<"The element is not present in the array\n";
            }
            else{
                std::cout<<"The first occurunce of the  element"<<" "<<element<<" "<<"is present at position:"<<index+1<<std::endl;
            }
        }
        else if(choice==3){
            break;
        }
        else{
            std::cout<<"\nInvalid choice.Please try again";
        }

    }
}

//finding the element through linear search
int linear_search(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}


//finding the element through binary search
int binary_search(int arr[],int size,int element){
    bubble_sort(arr,size);
    int start=0;
    int end=size-1;
    while(start<=end){
        int mid=(((start+end))/2);
        if(element<arr[mid]){
            end=mid-1;
        }

        else if(element>arr[mid]){
            start=mid+1;
        }
        else if(element==arr[mid]){
            return mid;
        }
    }
    return -1;
}