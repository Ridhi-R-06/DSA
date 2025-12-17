#include<iostream>
class Area{
    int leng, bre, height;
public:
    Area(){
        leng=1;
        bre=1;
        height=1;
    }
    Area(int l, int b, int h){
        leng=l;
        bre=b;
        height=h;
    }
    void setleng(int l);
    void setbre(int b);
    void setheight(int h);
    int square(){
        return leng*leng;
    }
    int rectangle(){
        return leng*leng;
    }
    int cube(){
        int ans=6*leng*leng;
        return ans;
    }
    int cuboid(){
        int calc=(leng*bre)+(bre*height)+(leng*height);
        int ans=2*calc;
        return ans;
    }
};

int main(){
    Area obj1;
    int length, breadth, height;
    int choice;
    printf("Enter the length:");
    scanf("%d",&length);
    printf("Enter the breadth:");
    scanf("%d",&breadth);
    printf("Enter the height:");
    scanf("%d",&height);
     while(1){
        printf("\n1.AREA OF A SQUARE\n");
        printf("2.AREA OF A CUBOID\n");
        printf("3.AREA OF A RECTANGLE\n");;
        printf("4.AREA OF A CUBE\n");
        printf("5.TO CHANGE DIMENSIONS\n");
        scanf("%d",&choice);
        
     
        if(choice==1){
            obj1.setleng(length);
            printf("The area of square is %d",obj1.square());
        }
        else if(choice==2){
            obj1.setleng(length);
            obj1.setbre(breadth);
            obj1.setheight(height);
            printf("The area of cuboid %d \n",obj1.cuboid());
        }
        else if(choice==3){
            obj1.setleng(length);
            obj1.setbre(breadth);
            printf("The area of rectangle is %d\n", obj1.rectangle());
        }
        else if(choice==4){
            obj1.setleng(length);
            printf("The area of the cube is %d\n", obj1.cube());
        }
        else if(choice==5){
            printf("Enter the length:");
            scanf("%d",&length);
            printf("\nEnter the breadth:");
            scanf("%d",&breadth);
            printf("Enter the height:");
            scanf("%d",&height);
        }
        else if(choice==6){
            break;
        }
        else{
            printf("Invalid choice");
        }
    }
        return 0;

}
void Area::setleng(int l){
    leng=l;
}
void Area::setbre(int b){
    bre=b;
}
void Area::setheight(int h){
    height=h;
}