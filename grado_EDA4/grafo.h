#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include <iostream>
#include "node.h"

using namespace std;

class grafo{
public:
    grafo();
    void addNode(string name);
    void delete_Node(int n);
    void add_edge(int new_a,int new_b);
    void delete_edge(int old_a, int old_b);
    void printGraph();
    void setEntryPoint(node node);
    void printAdjMatrix();
    void get_adlist();
    void end();
private:
    vector<node> nodes;
    node*p_start;
    int num_nod;
    vector<vector<int>> adjMatrix;
    void updateAdjMatrix();

};

#endif // GRAFO_H
