#include <iostream>
#include "grafo.h"

using namespace std;

int main(){
    grafo a(5);
    a.add_edge(0,1);
    a.add_edge(0,2);
    a.add_edge(1,3);
    a.add_edge(2,3);
    a.add_edge(2,4);
    a.get_adlist();
    cout<<endl;
    a.get_admatrix();
    a.end();
}
