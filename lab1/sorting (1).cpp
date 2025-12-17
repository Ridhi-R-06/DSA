//menu driven program for sorting an array
#include<iostream>

void bubble_sort(int arr[],int);
void selection_sort(int arr[],int);
void insertion_sort(int arr[],int);

int main(){
    int size;
    std::cout<<"enter the size of the array:";
    std::cin>>size;
    int arr[size];

    for(int i=0;i<size;i++){
        std::cout<<"\nenter the number you want to insert in the array at position "<<i+1<<":";
        std::cin>>arr[i];
    }

    int choice;
    
    while(1){
        std::cout<<"enter your choice\n"<<"1.bubble sort\n"<<"2.selection sort\n"<<"3.insertion sort\n"<<"4.Display Elements\n"<<"5.exit\n";
        std::cin>>choice;
        if(choice==1){
            bubble_sort(arr,size);
        }
        else if(choice==2){
            selection_sort(arr,size);
       }
       else if(choice==3){
        insertion_sort(arr,size);
       }
       else if(choice==4){
            std::cout<<"the array elements are\n";
            for(int i=0;i<size;i++){
        
            std::cout<<arr[i]<<" ";
            }
            std::cout<<"\n";
       }
        else if(choice==5){
            break;
        }
        else{
            std::cout<<"\nInvalid choice.Please try again\n\n";
        }
    }
    
    

}

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