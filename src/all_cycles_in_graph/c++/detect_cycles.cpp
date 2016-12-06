#include "detect_cycles.h"

void DetectCycle::run(Graph graph){
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

void DetectCycle::dfs(Graph graph, int source){
    colors[source] = GREY;
    for(auto destination: graph.arcs[source]){
        path[source] = destination;
        if(colors[destination] == WHITE)
            dfs(graph, destination);
        else{
            cycles.push_back(path);
            path.clear();
        }
    }
    colors[source] = BLACK;
}

int DetectCycle::number_cycles(){
    return cycles.size();
}
