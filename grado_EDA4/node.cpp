#include "node.h"

node::node(int new_ID,string new_Name){
    ID=new_ID;
    Name=new_Name;
}

vector<node*> node::getNeighbour() const{
    return neighbour;
}

int node::getID() const{
    return ID;
}

const string &node::getName() const{
    return Name;
}

void node::addNeighbour(node *temp){
    if(neighbour.size()!=0){
        bool st(false);
        for(int i(0);i<neighbour.size();i++){
            if(neighbour.at(i)->ID==temp->ID)st=1;
            if(neighbour.at(i)->ID>temp->ID&&!st){neighbour.insert(neighbour.begin()+i,temp);st=1;}
        }
        if(!st)neighbour.push_back(temp);
    }else{
        neighbour.push_back(temp);
    }
}

void node::delete_conx(int i){
    if(neighbour.size()!=0){
        for(int j(0);j<neighbour.size();j++){
            if(neighbour.at(j)->ID==i){
                neighbour.at(j)=nullptr;
                delete neighbour.at(j);
                neighbour.erase(neighbour.begin()+j);
            }
        }
    }
}

void node::delete_all(){
    if(neighbour.size()!=0){
        for(int i(neighbour.size()-1);i>=0;i--){
            neighbour.at(i)=nullptr;
            delete neighbour.at(i);
            neighbour.pop_back();
        }
    }
}
