//To implement circular queue adt using an array
#include<iostream>
#include<stdlib.h>
using namespace std;
class queue{
    int start,end,front;
    int q[5];
    int cursize;
public:
    queue(){
        front=0;
        start=end=-1;
        cursize=0;
    }
    void enqueue(int num);
    void dequeue();
    void Front();
};
int main(){
    queue q;
    int choice;
    int num;
    while(1){
        cout<<"\nMENU"<<endl;
        cout<<"1)Enqueue"<<endl;
        cout<<"2)Dequeue"<<endl;
        cout<<"3)Front"<<endl;
        cout<<"4)Exit"<<endl;
        cout<<"Enter the operation you want to perform:"<<endl;
        cin>>choice;
        
        switch(choice){
            case 1:{
                cout<<"Enter the number you want to enqueue into the queue: ";
                cin>>num;
                q.enqueue(num);
                break;
            }
            case 2:{
                
                
                q.dequeue();
                break;
            }
            case 3:{
                q.Front();
                break;
            }
            case 4:{
                cout<<"Exiting the program...";
                exit(0);
            }
        }
    }
    return 0;
}

void queue::enqueue(int num){
    if(cursize==5){
        cout<<"Cannot enqueue anymore data"<<endl;
        return;
    }
    if(cursize==0){
        start=end=0;
        q[end]=num;
        cursize+=1;
    }
    else{
        end=(end+1)%5;
        q[end]=num;
        cursize+=1;
    }

}

void queue::dequeue(){
    
    if(cursize==0){
        cout<<"Cannot Dequeue elements"<<endl;
        
    }

    else{
        cout<<"The dequeued element is:"<<q[start]<<"\n";
       
        start=(start+1)%5;
        cursize-=1;
        
    }

}

void queue::Front(){
    if(cursize==0){
        cout<<"Queue is empty"<<endl;

    }
    else{
        cout<<"The front element is: "<<q[start];
    }
}