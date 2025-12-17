//list adt array functions
#include<iostream>

class list{

    int current;
    int arr[5];

public:
    list(){
        current=-1;
    }

void insert_begin(int num);

void insert_end(int num);

void display();

void insert_pos(int num,int pos);

int del_beg();

int del_end();

int del_pos(int);

void rotate(int);

int search(int);



};


int main(){
    list l1;
    int choice;
    while(1){
        std::cout<<"\nEnter 1. to insert at beginning\n";
        std::cout<<"Enter 2. to insert at the end\n";
        std::cout<<"Enter 3. to insert at a position\n";
        std::cout<<"Enter 4. to delete at beggining\n";
        std::cout<<"Enter 5. to delete at end\n";
        std::cout<<"Enter 6. to delete at a position\n";
        std::cout<<"Enter 7. to search for a number\n";
        std::cout<<"Enter 8. to display the elements\n";
        std::cout<<"Enter 9. to rotate an array by k position\n";
        std::cout<<"Enter 10. to exit\n\n";
        std::cout<<"Enter your choice:";
        std::cin>>choice;

        if(choice==1){
            int num;
            std::cout<<"Enter the number you want to input:";
            std::cin>>num;
            l1.insert_begin(num);
        }
        else if(choice==2){
            int num;
            std::cout<<"Enter the number you want to input:";
            std::cin>>num;
            l1.insert_end(num);
        }
        else if(choice==3){
            int num;
            int pos;
            std::cout<<"Enter the number you want to input:";
            std::cin>>num;
            std::cout<<std::endl;
            std::cout<<"Enter the position where you want to input:";
            std::cin>>pos;
            std::cout<<std::endl;
            l1.insert_pos(num,pos);
        }
        else if(choice==4){
            int ans=l1.del_beg();
            if(ans==0){
                std::cout<<"The list is empty\n";
            }
            else{
            std::cout<<"The number "<<ans<<" is deleted\n";
            }
        }
        else if(choice==5){
            int ans=l1.del_end();
            if(ans==0){
                std::cout<<"The list is empty\n";
            }
            else{

            std::cout<<"The number "<<ans<<" is deleted\n";
            }
        }
        else if(choice==6){
            int choice;
            std::cout<<"Enter the position at which you want to delete:";
            std::cin>>choice;
            int ans=l1.del_pos(choice);
            if(ans==0){
                std::cout<<"The deletion is not possible\n";
            }
            else{

            std::cout<<"The number "<<ans<<" is deleted\n";
            }



        }
        else if(choice==7){
            int check;
            std::cout<<"Enter the number you want to search:";
            std::cin>>choice;
            int ans=l1.search(choice);
            if(ans==-1){
                std::cout<<"The number is not found";
            }
            else{
                std::cout<<"The number is found at the position: "<<ans+1<<std::endl;
            }
        }
        else if(choice==8){
            l1.display();
        }
        else if(choice==9){
            int rot;
            std::cout<<"Enter the no of steps by which you want to rotate:";
            std::cin>>rot;
            l1.rotate(rot);

        }

        else if(choice==10){
            std::cout<<"Exiting...";
            break;
        }
        else{
            std::cout<<"Invalid choice.Try again";
        }


    }


    return 0;
}

//function to insert a number at the first position
void list::insert_begin(int num){
    if(current==-1){
        arr[0]=num;
        current++;
        std::cout<<current;
    }
    else if(current==4){
        std::cout<<"Cannot insert more elements.The list is full";
    }
    else{
        for(int i=current;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0]=num;
        current++;
        printf("ok");
    }
}

//function to insert a number at the end
void list::insert_end(int num){
    if(current==-1){
        list::insert_begin(num);
    }
    else if(current==4){
        arr[current]=num;
    }
    else{
        arr[current+1]=num;
        current++;
    }
}


//function to insert a number at a position
void list::insert_pos(int num,int pos){
    if(pos>current+2){
        std::cout<<"Insert the other elements first";
    }
    else if(current==4){
        std::cout<<"Cannot insert more elements";
    }
    else if(pos==1){
        list::insert_begin(num);
    }
    else if(pos==5){
        list::insert_end(num);
    }
    else if(pos-1<=current){
        for(int i=current;i>=pos-1;i--){
            arr[i+1]=arr[i];
        }
        current++;
        arr[pos-1]=num;
    }
}

//function to delete a number at the beginning
int list::del_beg(){
    if(current==-1){
        return 0;
    }
    int temp=arr[0];
    for(int i=0;i<current;i++){
        arr[i]=arr[i+1];
    }
    arr[current]=0;
    current--;
    return temp;
}
//function to delete a number at the end
int list::del_end(){
    if(current==-1){
        return 0;
    }

    int temp=arr[current];
    arr[current]=0;
    current--;
    return temp;    
}

//function to delete a number at the given position
int list::del_pos(int pos){
    if(current==-1){
        return 0;
    }
    else if(pos==1){
        return list::del_beg();
    }
    else if(pos-1==current){
        return list::del_end();
    }
    else if(pos>current+1){
        return 0;
    }
    else{
        int temp=arr[pos-1];
        for(int i=pos;i<=current;i++){
            arr[i-1]=arr[i];
        }
        arr[current]=0;
        current--;
        return temp;
    }
}




//function to search for a number
int list::search(int check){
    if(current==-1){
        return -1;
    }
    for(int i=0;i<=current;i++){
        if(arr[i]==check){
            return i;
        }
    }
    current--;
    return -1;
}


//function to rotate an array by k steps
void list::rotate(int k){
    k=k%5;
    int ans[current+1];
    int j=0;
    for(int i=current-k+1;i<=current;i++){
        ans[j]=arr[i];
        j++;
    }
    for(int i=0;i<=current-k;i++){
        ans[j]=arr[i];
        j++;
    }

    for(int i=0;i<=current;i++){
        arr[i]=ans[i];
    }


}

//funtion to display the elements in the array
void list::display(){
    if(current==-1){
        std::cout<<"There are no elements present in the array";
        return;
    }
    std::cout<<std::endl;
    for(int i=0;i<=current;i++){
        std::cout<<"The element at position "<<i+1<<" is:";
        std::cout<<arr[i]<<"\n";
    }
}



