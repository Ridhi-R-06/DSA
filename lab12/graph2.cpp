//program to implement graph ADT using adjacency list
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
   private:
     vector<list<int>> adjlist;
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
    cout << "Enter The Number of Vertices:";
    cin  >>  verts;
    int ch;
    Graph g(verts);
    int u;
    int v;
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
            cout << "\nExiting Program..";
            break;
        }

        switch(ch){
            case 1:
                cout << "\nEnter the Source:";
                cin  >> u;
                cout << "\nEnter the destination:";
                cin  >> v;
                g.insert_edge(u,v);
                break;

            case 2:
               cout << "\nEnter the source:";
               cin  >> u;
               cout << "\nEnter the destination:";
               cin  >> v;
               g.delete_edge(u,v);
               break;
               
            case 3:
               cout << "\nEnter the source:";
               cin  >> u;
               cout << "\nEnter the destination:";
               cin  >> v;  
               g.search_edge(u,v);
               break;
               
            case 4:
               g.display();
               break;


            default:
               cout << "\nEnter a valid choice(1-5):";
               break;   
        }
    }
}

Graph::Graph(int vert){
    vertices = vert;
    adjlist.resize(vertices);
}

void Graph::insert_edge(int u,int v){
    if(u >= 0 && v >=0 && u < vertices && v < vertices){
         adjlist[u].push_back(v);
         adjlist[v].push_back(u);
         cout << "\nEdge has been inserted sucessfully!!";
    }
    else{
        cout << "\nInvalid Edge!!";
    }
}

void Graph::delete_edge(int u,int v){
    if(u >= 0 && v >=0 && u < vertices && v < vertices){
        adjlist[u].remove(v);
        adjlist[v].remove(u);
        cout << "\nEdge has been deleted sucessfully!!";
   }
   else{
       cout << "\nInvalid Edge!!";
   }
}

void Graph::search_edge(int u,int v){
    if(u >= 0 && v >=0 && u < vertices && v < vertices){
        for(int neighbour : adjlist[u]){
            if(neighbour == v){
                cout << "\nThe edge was found sucessfully!!";
                return;
            }
        }
        cout << "\nThe edge was not found!!";
        return;  
    }
    else{
        cout << "\nInvalid edge!!";
    }
}

void Graph::display(){
    for(int i=0;i<vertices;i++){
        cout << i << "->";
        for(int v : adjlist[i]){
            cout << v << " ";
        }
        cout << "\n";
    }
}
