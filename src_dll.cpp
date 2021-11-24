#include<iostream>
#include<fstream>
#include<vector>
#include"ull.h"

using namespace std;

//Ull ull("a.file");

int main(){
    //initialization}
    int n;
    cin>>n;
    Ull ull("a.file");
    for (size_t i = 0; i < n; i++)
    {
        string s,index;
        int value;
        cin>>s>>index;
        if (s=="insert")
        {
            cin>>value;
            ull.addNode(UllNode(value,index));
        } else if (s=="delete") {
            cin>>value;
            ull.deleteNode(UllNode(value,index));
        } else {
            vector<int> * vet = new vector<int>(0);
            ull.findNode(index,*vet);
            if (vet->empty())
            {
                cout<<"null\n";
            } else {
                for (size_t i = 0; i < vet->size(); i++)
                {
                    cout<<vet->operator[](i)<<((i==vet->size()-1)?'\n':' ');
                }
            }
            delete vet;
        }
    }
    
}
