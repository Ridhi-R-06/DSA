#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    int t;
    cout<<"ENTER THE NUMBER OF TESTCASES:";
    cin>>t;
    while(t--){
        int n;
        cout<<"\nENTER THE LENGTH OF THE SEQUENCE :";
        cin>>n;
        vector<int>sequence(n);
        unordered_set<int>seen;
        int moves=0;
        for (int i=0;i<n;i++){
            cin>>sequence[i];
        }
        for (int i=0;i<n;i++){
            if(seen.find(sequence[n-1-i])!=seen.end()){
                moves=n-i;
                break;
            }else{
                seen.insert(sequence[n-1-i]);
            }
        }
        cout<<moves<<"\n";
    }
    return 0;
}

