//program to implement functions of singly linked list
#include<iostream>
#include<cstdlib>
using namespace std;

class singlelink
{
    struct node{
        int data;
        struct node *next;
    };
    struct node *head;

    public:

    singlelink();
    void insert_beg(int);
    void insert_end(int);
    void insert_pos(int,int);
    int size();
    int del_beg();
    int del_end();
    int del_pos(int);
    int search(int);
    void display();
    void reverse();
    void display_rev();
    void display_rev_recursive(struct node* head);


};

int main()
{

    singlelink l1;

    int choice;
    while(1){
        cout<<"1.To insert at beginning\n";
        cout<<"2.To insert at end\n";
        cout<<"3.To insert at a specified position\n";
        cout<<"4.To delete at beginning\n";
        cout<<"5.To delete at end\n";
        cout<<"6.To delete at a given position\n";
        cout<<"7.To search for an element\n";
        cout<<"8.To display the elements\n";
        cout<<"9.To display the elements in reverse order\n";
        cout<<"10.To reverse the list\n";
        cout<<"11.To exit\n\n";
        cout<<"Enter your choice:";
        cin>>choice;

        if(choice==1)
        {
            int num;
            cout<<"Enter the number to be inserted:";
            cin>>num;
            l1.insert_beg(num);
        }

        else if(choice==2)
        {
            int num;
            cout<<"Enter the number to be inserted:";
            cin>>num;
            l1.insert_end(num);
        }

        else if(choice==3)
        {
            int num;
            int pos;
            cout<<"Enter the number to be inserted:";
            cin>>num;
            cout<<"\n";
            cout<<"Enter the position you want to insert the number in:";
            cin>>pos;
            l1.insert_pos(num,pos);
        }

        else if(choice==4)
        {
            int ans=l1.del_beg();
            if(ans==0)
            {
                cout<<"The list is empty\n\n";
            }
            else
            {
            cout<<"The number "<<ans<<" is deleted.\n\n";
            }
        }

        else if(choice==5)
        {
            int ans=l1.del_end();
            if(ans==0)
            {
                cout<<"The list is empty\n\n";
            }
            else
            {
            cout<<"The number "<<ans<<" is deleted.\n\n";
            }
        }

        else if(choice==6)
        {
            int pos;
            cout<<"Enter the position where the number has to be deleted:";
            cin>>pos;
            int ans=l1.del_pos(pos);
            if(ans==0)
            {
                cout<<"The list is empty\n\n";
            }
            else
            {
            cout<<"The number "<<ans<<" is deleted.\n\n";
            }


        }

        else if(choice==7)
        {
            int num;
            cout<<"Enter the number to be searched:";
            cin>>num;
            int index=l1.search(num);
            if(index==-1)
            {
                cout<<"The number "<<num<<" is not present";
                cout<<"\n\n";
            }
            else
            {
                cout<<"The number "<<num<<" is found at position "<<index;
                cout<<"\n\n";
            }


        }



        else if(choice==8)
        {
            l1.display();
        }

        else if(choice==9)
        {
            l1.display_rev();
        }

        else if(choice==10)
        {
            l1.reverse();
        }


        else if(choice==11)
        {
            break;
        }

        else
        {
            cout<<"Invalid choice.Please try again\n\n";
        }
        
    }





    return 0;
}


singlelink::singlelink()
{
    head=NULL;
}

//function to insert a number at the beginning
void singlelink::insert_beg(int num)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
    }

    else
    {
        newnode->next=head;
        head=newnode;
    }

}

//Function to insert a number at the end
void singlelink::insert_end(int num)
{
    if(head==NULL)
    {
        insert_beg(num);
    }

    else
    {
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    struct node *temp=head;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=newnode;

    }
}

//Function to insert a number at a given position
void singlelink::insert_pos(int num,int pos){
    int size1=size();
    
    if(pos>=size1+2){
        cout<<"Invalid position.Insert the other elements first\n\n";
        return;
    }

    else if(pos==1)
    {
        insert_beg(num);
    }
    else if(pos==size1+1){
        insert_end(num);
    }
    else if(pos==size1)
    {
        struct node *newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=num;
        struct node *temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;

    }
    else
    {
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    struct node *temp=head;
    pos--;
    while(pos!=1)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }
}




//Function to display the elements in the list
void singlelink::display(){
    if(head==NULL)
    {
        cout<<"The list is empty\n\n";
        return;
    }

    else
    {
        struct node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"\n\n";
    }
}


//function to delete the number at the beginning
int singlelink::del_beg(){
    if(head==NULL)
    {
        return 0;
    }
    else
    {
        struct node *temp=head;
        head=head->next;
        return temp->data;
        free(temp);


    }
}


//function to delete the number at the end
int singlelink::del_end()
{   
    int size1=size();
    if(head==NULL)
    {
        return 0;
    }
    else if(size1==1)
    {
        return del_beg();
    }
    else
    {
        struct node *temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        int ans=temp->next->data;
        free(temp->next);
        temp->next=NULL;
        return ans;


    }
}

 
//function to delete a number at the specified position
int singlelink::del_pos(int pos){
    struct node* temp=head;
    if(pos==1){
        return del_beg();
    }
    else if(pos==size()){
        return del_end();
    }
    else if(head==NULL){
        return 0;
    }
    else if(pos>size()){
        return 0;
    }
    else{
    pos--;
    while(pos!=1){
        temp=temp->next;
        pos--;
    }
    int store=temp->next->data;
    struct node* temp2=temp->next;
    temp->next=temp->next->next;
    free(temp2);
    return store;

}

}




//function to search a number
int singlelink::search(int num)
{
    int size=1;
    struct node *temp=head;
    while(temp!=NULL){
        if(temp->data==num){
            return size;
        }
        size++;
        temp=temp->next;
    }

    return -1;
}


//function to find the size of the list
int singlelink::size()
{
    int size=0;
    struct node *temp=head;
    while(temp!=NULL)
    {
        size++;
        temp=temp->next;
    }
    return size;
}

// void singlelink::print_reverse(){

// }


void singlelink::reverse()
{
    struct node *temp1=NULL;
    struct node *temp2=NULL;
    while(head!=NULL){
        temp2=head->next;
        head->next=temp1;
        temp1=head;
        head=temp2;
    }
    
    head=temp1;
}


void singlelink::display_rev()
{
    if(head==NULL){
        cout<<"The list is empty\n\n";
        return;
    }
    display_rev_recursive(head);
    cout<<"\n";

}


void singlelink::display_rev_recursive(struct node* head) {
    if (head == NULL) {
        return;
    }
    display_rev_recursive(head->next); 
    cout << head->data << "->"; 
}