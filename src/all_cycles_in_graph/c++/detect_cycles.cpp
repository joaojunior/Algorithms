#include "detect_cycles.h"

void DetectCycle::run(Graph *graph){
    this->clear();
    for(auto node : graph->nodes)
        colors[node] = WHITE;
    for(auto node : graph->nodes){
        if(colors[node] == WHITE){
            path.clear();
            dfs(graph, node);
        }
   }
}

void DetectCycle::dfs(Graph *graph, int source){
    for(auto destination: graph->arcs[source]){
        colors[source] = GREY;
        path[source] = destination;
        if(colors[destination] == WHITE)
            dfs(graph, destination);
        else{
            cycles.push_back(path);
            path.clear();
        }
    }
    if(colors[source] == GREY)
        colors[source] = BLACK;
}

int DetectCycle::number_cycles(){
    return cycles.size();
}

void DetectCycle::clear(){
    colors.clear();
    cycles.clear();
}
