#include "grafo.h"

grafo::grafo(){
    p_start=nullptr;
    num_nod=0;
}

void grafo::addNode(string name){
    if(num_nod==0){
        node temp(num_nod,name);
        nodes.push_back(temp);
        num_nod++;
    }else{
        int aux;
        for(int i(0);i<nodes.size();i++){
            if(i!=nodes.at(i).getID()){
                aux=i;break;
            }
            if(i==nodes.size()-1){
                aux=num_nod;
            }
        }
        node temp(aux,name);
        nodes.insert(nodes.begin()+aux,temp);
        if(aux==num_nod)num_nod++;
    }
}

void grafo::delete_Node(int n){
    if(nodes.size()==0){
        cout<<"No hay nodos existentes";
    }else{
        bool st(true);
        for(int i(0);i<nodes.size();i++){
                nodes.at(i).delete_conx(n);
        }
        for(int i(0);i<nodes.size();i++){
            if(nodes.at(i).getID()==n){
                nodes.at(i).delete_all();
                nodes.erase(nodes.begin()+i);
                if(n==num_nod-1){
                    if(nodes.size()==0){
                        num_nod=0;
                    }else{
                        num_nod=nodes.at(nodes.size()-1).getID()+1;
                    }
                }
                st=0;
            }
        }
        if(st){cout<<"No existe este nodo"<<endl;}
    }
}

void grafo::add_edge(int new_a,int new_b){
    node*temp1,*temp2;
    bool a(0),b(0);
    if(nodes.size()!=0){
        for(int i(0);i<nodes.size();i++){
            if(nodes.at(i).getID()==new_a){a=true;temp1=&nodes.at(i);}
            if(nodes.at(i).getID()==new_b){b=true;temp2=&nodes.at(i);}
        }
    }
    if(!a||!b){
        cout<<"Nodo no existente(s)"<<endl;
    }else{
        for(int i(0);i<nodes.size();i++){
            if(nodes.at(i).getID()==new_a){
                nodes.at(i).addNeighbour(temp2);
            }
            if(nodes.at(i).getID()==new_b){
                nodes.at(i).addNeighbour(temp1);
            }
        }
    }
}

void grafo::delete_edge(int old_a, int old_b){
    bool a(0),b(0);
    for(auto elem:nodes){
        if(elem.getID()==old_a)a=true;
        if(elem.getID()==old_b)b=true;
    }
    if(!a||!b){
        cout<<"Nodo no existente(s)"<<endl;
    }else{
        for(int i(0);i<nodes.size();i++){
            if(nodes.at(i).getID()==old_a){
                nodes.at(i).delete_conx(old_b);
            }
            if(nodes.at(i).getID()==old_b){
                nodes.at(i).delete_conx(old_a);
            }
        }
    }
}

void grafo::printGraph(){
    for(auto elem:nodes){
        cout<<"ID:"<<elem.getID()<<"|Nombre: "<<elem.getName()<<endl;
    }
}

void grafo::setEntryPoint(node node){
p_start=&node;
}

void grafo::printAdjMatrix(){
    updateAdjMatrix();
    cout<<"Matriz:"<<endl;
    cout<<"  ";
    for(int i(0);i<num_nod;i++){
        cout<<i<<"|";
    }
    cout<<endl;
    for(int i(0);i<adjMatrix.size();i++){
        cout<<i<<"|";
        for(auto elem:adjMatrix.at(i)){
            cout<<elem<<"|";
        }
        cout<<endl;
    }
}

void grafo::updateAdjMatrix(){
    if(nodes.size()!=0){
        vector<vector<int>> al;
        al.resize(num_nod);
        for(int u(0);u<num_nod;u++){for(int j(0);j<num_nod;j++){al.at(u).push_back(0);}}
        for(int i(0);i<nodes.size();i++){
            if(nodes.at(i).getNeighbour().size()!=0){
                for(auto elem:nodes.at(i).getNeighbour()){
                    al.at(nodes.at(i).getID()).at(elem->getID())=1;
                }
            }
        }
        adjMatrix=al;
    }
}

void grafo::get_adlist(){
    if(nodes.size()!=0){
        vector<vector<int>> al;
        al.resize(num_nod);
        for(int i(0);i<nodes.size();i++){
            if(nodes.at(i).getNeighbour().size()!=0){
                for(auto elem:nodes.at(i).getNeighbour()){
                    al.at(nodes.at(i).getID()).push_back(elem->getID());
                }
            }
        }
        for(int i(0);i<al.size();i++){
            cout<<i<<": ";
            for(auto elem:al.at(i)){
                cout<<elem<<",";
            }
            cout<<endl;
        }
    }
}

void grafo::end(){
   if(nodes.size()!=0){
    for(int i(nodes.size()-1);i>=0;i--){
            nodes.at(i).delete_all();
            nodes.pop_back();
        }
    }
}
