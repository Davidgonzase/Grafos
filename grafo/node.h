#ifndef NODE_H
#define NODE_H
#include <vector>

class node{
public:
    node(int new_ID);
    int getID() const;
    void insert(node* temp);
    void delete_conx(int i);
    void delete_all();
    const std::vector<node*> &getNeighbour() const;

private:
    int ID;
    std::vector<node*> neighbour;
};

#endif // NODE_H
