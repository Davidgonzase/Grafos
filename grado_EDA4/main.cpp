#include <iostream>
#include "grafo.h"

using namespace std;

int main(){
    grafo G1;
    G1.addNode("Opera"); //node 0
    G1.addNode("Sol"); //node 1
    G1.addNode("Opera"); //node 2
    G1.addNode("Arguelles"); //node 3
    G1.add_edge(0,1);
    G1.add_edge(0,2);
    G1.add_edge(1,3);
    G1.add_edge(2,3);
    G1.addNode("Delicias");
    G1.add_edge(2,4);
    G1.printGraph();
    G1.get_adlist();
    G1.printAdjMatrix();
    G1.delete_Node(4);
    cout<<endl;
    G1.printGraph();
    G1.get_adlist();
    G1.printAdjMatrix();
    G1.end();
}
