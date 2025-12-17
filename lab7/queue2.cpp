//To implement queue adt using singly linked list
#include<iostream>
#include<stdlib.h>
using namespace std;
class queue{
    struct node{
        int data;
        struct node*next;
    };
    struct node*start;
    struct node*end;
    public:
        queue(){
            start=end=NULL;
        }
        void enqueue(int num);
        void dequeue();
        void front();
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
                cout<<"Dequeuing element in queue..."<<endl;
                
                q.dequeue();
                break;
            }
            case 3:{
                q.front();
                break;
            }
            case 4:{
                cout<<"Exiting the program...\n";
                exit(0);
            }
        }
    }
    return 0;
}

void queue::enqueue(int num){
    struct node*Newnode=(struct node*)malloc(sizeof(struct node));
    Newnode->data=num;
    if(end==NULL){
        start=end=Newnode;
        Newnode->next=NULL;
    }
    else{
        end->next=Newnode;
        end=Newnode;
    }

}
void queue::dequeue (){

    if(start==NULL){
        cout<<"Queue is empty"<<endl;
        return;
    }
    else{
        struct node*temp=start;
        start=start->next;
        cout<<"The dequed element is "<<temp->data;
        free(temp);
    }

}

void queue::front(){
    if(start==NULL){
        cout<<"The queue is empty";
        return;
    }
    else{
        cout<<"The front element of the queue is: "<<start->data;
    }
}