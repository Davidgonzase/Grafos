#ifndef NODE_H
#define NODE_H
#include <vector>
#include <iostream>
using namespace std;

class node{
public:
    node(int new_ID,string new_Name);
    void addNeighbour(node* temp);
    vector<node*> getNeighbour() const;
    int getID() const;
    const string &getName() const;
    void delete_conx(int i);
    void delete_all();

private:
    int ID;
    string Name;
    vector<node*>neighbour;
};

#endif // NODE_H
