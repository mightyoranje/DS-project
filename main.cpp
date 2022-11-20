#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    struct nodeType{
    string info;                    
    nodeType *link;
    };
    string str;
    string lineFromFile;
    ifstream myfile("./file.txt");
    string line;
    nodeType *first, *last, *newNode;
    first = NULL;
    last = NULL;
    int n;
    int count=0;
    cout<<"Enter the number of lines in the file that you want to insert: ";
    cin >> n;
    while(getline(myfile,lineFromFile) && count <= n){
        str = lineFromFile;
        newNode = new nodeType;
        newNode->info = str;
        newNode->link = NULL;
        cout << "line " << count << " inserted in the node."<<endl;
        if(first == NULL){
            first = newNode;
            last = newNode;
        }
        else{
            last->link = newNode;
            last = newNode;
        }
        count=count + 1;
    }
    cout<<"\n";
    cout<< "Output: ";
    while(first != NULL){
        cout<<first->info<<" ";
        first = first->link;
    }
    return 0;
}
