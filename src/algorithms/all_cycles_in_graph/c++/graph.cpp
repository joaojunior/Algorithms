#include "graph.h"

void Graph::add_arc(int source, int destination){
    add_node(source);
    add_node(destination);
    arcs[source].push_back(destination);
}

void Graph::add_node(int node){
    nodes.insert(node);
}

void Graph::clear(){
    arcs.clear();
    nodes.clear();
}

void Graph::print(){
    for(auto source: arcs)
        for(auto destination: source.second)
            cout << source.first << "--" << destination << ",";
}
