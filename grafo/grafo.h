#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <iostream>
#include "node.h"

using namespace std;

class grafo{
public:
    grafo();
    grafo(int num);
    grafo(grafo const & copy);
    void add_node();
    void add_edge(int new_a,int new_b);
    void delete_edge(int a, int b);
    void delete_node(int n);
    void get_adlist();
    void get_admatrix();
    int getNum_nod() const;
    const vector<node> &getNodes() const;
    void setEntryPoint(node node);
    void end();
private:
    vector<node> nodes;
    node*p_start;
    int num_nod;
};

#endif // GRAFO_H
