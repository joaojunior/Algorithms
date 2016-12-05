#include "detect_cycles.h"
#include <iostream>


void Graph::add_arc (int source, int destination){
    add_node(source);
    add_node(destination);
    arcs[source].push_back(destination);
    for(auto arc : arcs){
        cout << arc.first << "\nNodes:\n";
        for (auto node : arc.second)
            cout << node << "\n";
    }
}

void Graph::add_node (int node){
    nodes.insert(node);
}


void DetectCycle::run (Graph graph){
    colors.clear();
    for(auto node : graph.nodes)
        colors[node] = WHITE;
    for(auto node : graph.nodes){
        if(colors[node] == WHITE)
            dfs(graph, node);
   }
}

void DetectCycle::dfs (Graph graph, int source){
    colors[source] = GREY;
    for(auto destination: graph.arcs[source])
        if(colors[destination] == WHITE)
            dfs(graph, destination);
    colors[source] = BLACK;
}
