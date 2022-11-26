#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    struct nodeType{                            //Define a node and its structure.
    string info;                    
    nodeType *link;
    };

    string str;
    string line;
    string lineFromFile;
    string filePath;

    cout << "enter file location: " ;
    cin >> filePath;

    nodeType *first;
    nodeType *last;
    nodeType *newNode;

    // ifstream myfile("./file.txt");

    ifstream myfile(filePath);

    int n , count=0;

    first = NULL;
    last = NULL;
    cout<<"Enter the number of lines in the file that you want to insert: ";
    cin >> n;
    cout<< endl;

    while(getline(myfile,lineFromFile) && count <= n - 1){
        
        str = lineFromFile;
        newNode = new nodeType;
        newNode->info = str;
        newNode->link = NULL;

        cout << "line " << count + 1 << " inserted in the node "<< count + 1 <<"."<<endl;

        if(first == NULL){
            first = newNode;
            last = newNode;
        }

        else{
            last->link = newNode;
            last = newNode;
        }
        count ++;
    }

    cout<<"\n" << "Output: ";
    cout << "\n" << "\n";
    while(first != NULL){
        cout<<first->info<<"\n";
        first = first->link;
    }

    return 0;
}
