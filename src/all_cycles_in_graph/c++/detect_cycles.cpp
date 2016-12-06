#include "detect_cycles.h"
#include <iostream>


void Graph::add_arc (int source, int destination){
    add_node(source);
    add_node(destination);
    arcs[source].push_back(destination);
}

void Graph::add_node (int node){
    nodes.insert(node);
}


void DetectCycle::run (Graph graph){
    colors.clear();
    for(auto node : graph.nodes)
        colors[node] = WHITE;
    for(auto node : graph.nodes){
        if(colors[node] == WHITE){
            path.clear();
            dfs(graph, node);
        }
   }
}

void DetectCycle::dfs (Graph graph, int source){
    colors[source] = GREY;
    for(auto destination: graph.arcs[source]){
        path[source] = destination;
        if(colors[destination] == WHITE)
            dfs(graph, destination);
        else{
            cycles.push_back(path);
        }
    }
    colors[source] = BLACK;
}

bool DetectCycle::has_cycle(){
    if(cycles.size() > 0)
       return true;
    return false; 
}
