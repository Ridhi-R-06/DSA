//program to implement graph ADT using adjacency matrix
#include<iostream>
#define MAX 100
using namespace std;

class Graph{
    private:
    int** adjmatrix;
    int vertices;
    public:
    Graph(int);
    void insert_edge(int,int);
    void delete_edge(int,int);
    void search_edge(int,int);
    void display();
};

int main(){
    int verts;
    cout << "\nEnter the number of vertices:";
    cin  >> verts;
    Graph g(verts);
    int ch;
    int u,v;
    while(true){
        cout << "\nMENU\n";
        cout << "1.Insert\n";
        cout << "2.Delete\n";
        cout << "3.Search\n";
        cout << "4.Display\n";
        cout << "5.Exit\n";
        cout << "Enter your choice(1-5):";
        cin  >> ch;

        if(ch == 5){
            cout << "\nExiting Program...";
            break;
        }

        switch(ch){
            case 1:
               cout << "\nEnter the source:";
               cin  >>  u;
               cout <<  "\nEnter the destination:";
               cin  >>  v;
               g.insert_edge(u,v);
               break;

            case 2:
               cout << "\nEnter the source:";
               cin  >>  u;
               cout << "\nEnter the destination:";
               cin  >>  v;
               g.delete_edge(u,v);
               break;

            case 3:
               cout  << "\nEnter the source:";
               cin   >> u;
               cout  <<  "\nEnter the destination:";
               cin   >> v;
               g.search_edge(u,v);
               break;

            case 4:   
                  g.display();
                  break;
                   
            default:
                cout << "\nEnter a valid choice(1-5)!!"; 
                break; 
        }
    }
}

Graph::Graph(int vert){
     vertices = vert;
     adjmatrix = new int* [vertices];
     for(int i=0;i<vertices;i++){
          adjmatrix[i] = new int[vertices];
          for(int j=0;j<vertices;j++){
               adjmatrix[i][j] = 0;
          }

     }
}

void Graph::insert_edge(int u,int v){
     if(u >= 0 && v >= 0 && u < vertices && v <vertices){
          adjmatrix[u][v] = 1;
          cout << "\nEdge Inserted Sucessfully!!";
     }
     else{
         cout << "\nInvalid Edge!!";
     }
}

void Graph::delete_edge(int u,int v){
    if(u >= 0 && v >= 0 && u < vertices && v <vertices){
         if(adjmatrix[u][v] == 1){
              adjmatrix[u][v] = 0;
              adjmatrix[v][u] = 0;
              cout << "\nThe Edge Was Deleted Sucessfully!!";
              return;
         }
         cout << "\nThe Edge was Not Found!!";
         return;
     }
     else{
          cout << "\nInvalid Edge!!";
     }
}

void Graph::search_edge(int u,int v){
    if( u >= 0 && v >= 0 && u < vertices && v < vertices){
        if(adjmatrix[u][v] == 1){
            cout << "\nThe edge has been found sucessfully!!";
        }
        else{
             cout << "\nThe edge was not found!!";
        }
    }
    else{
         cout << "\nInvalid Edge!!";
    }
}

void Graph::display(){
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout << adjmatrix[i][j] << " ";
        }
        cout << "\n";
    }
}


