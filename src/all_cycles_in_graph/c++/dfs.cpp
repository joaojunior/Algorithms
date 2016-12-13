#include "dfs.h"

void DFS::run(Graph *graph){
    this->clear();
    for(auto node : graph->nodes){
        colors[node] = WHITE;
        predecessor[node] = -1;
    }
    time = 0;
    for(auto node : graph->nodes){
        if(colors[node] == WHITE){
            dfs(graph, node);
        }
   }
}

void DFS::dfs(Graph *graph, int source){
    time += 1;
    time_start[source] = time;
    colors[source] = GREY;
    for(auto destination: graph->arcs[source]){
        if(colors[destination] == WHITE){
            predecessor[destination] = source;
            dfs(graph, destination);
        }
    }
    colors[source] = BLACK;
    time += 1;
    time_close[source] = time;
    if(colors[source] == GREY)
        colors[source] = BLACK;
}

void DFS::clear(){
    colors.clear();
    time_start.clear();
    time_close.clear();
    predecessor.clear();
}
