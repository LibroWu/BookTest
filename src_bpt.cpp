#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<algorithm>
#include"BPT.hpp"

using namespace std;

struct Key{
    char str[64];
    bool operator==(const Key & other) const{
        return strcmp(str,other.str)==0;
    }
};

class IndexNode{
public:
    Key key;
    int offset;

    IndexNode() = default;

    IndexNode(const char* s,int offset): offset(offset) {
        strcpy(key.str,s);
    }

    bool operator<(const IndexNode & other) const{
        int flag = strcmp(key.str,other.key.str);
        if (flag==0) return offset<other.offset;
        return flag<0;
    }

    bool operator==(const IndexNode & other) const{
        return strcmp(key.str,other.key.str)==0 && offset==other.offset;
    }
    
};

BPT<IndexNode,int,400,400> ull("a.file","b.file");

void create_file(std::string file_name) {
    std::fstream file(file_name, std::fstream::out);
    file.close();
}
int main(){
    //initialization
    std::fstream file("a.file", std::fstream::in);
    if (!file.is_open()) {
        create_file("a.file");
        create_file("b.file");
        ull.initialise();
    }
    int n;
    cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        string s,index;
        int value;
        cin>>s>>index;
        if (s=="insert")
        {
            cin>>value;
            ull.insert(IndexNode(index.c_str(),-1),-1);
            ull.insert(IndexNode(index.c_str(),value),value);
        } else if (s=="delete") {
            cin>>value;
            ull.Delete(IndexNode(index.c_str(),value));
        } else {
            vector<int> * vet = ull.multipleFind(IndexNode(index.c_str(),-1));
            if (vet==nullptr)
            {
                cout<<"null\n";
            } else {
                if (vet->size()==1) cout<<"null\n";
                else {
                    sort(vet->begin()+1,vet->end());
                    for (size_t i = 1; i < vet->size(); i++)
                    {
                        cout<<vet->operator[](i)<<((i==vet->size()-1)?'\n':' ');
                    }
                }
            }
            delete vet;
        }
    }
    
}