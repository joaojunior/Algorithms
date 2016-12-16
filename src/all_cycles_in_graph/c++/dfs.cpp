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
            path.clear();
            dfs(graph, node);
        }
   }
}

void DFS::dfs(Graph *graph, int source){
    time += 1;
    time_start[source] = time;
    colors[source] = GREY;
    for(auto destination: graph->arcs[source]){
        path[source] = destination;
        if(colors[destination] == WHITE){
            predecessor[destination] = source;
            dfs(graph, destination);
        } else if(colors[destination] == GREY){
            cycles.push_back(path);
            path.clear();
        }
    }
    colors[source] = BLACK;
    time += 1;
    time_close[source] = time;
    if(colors[source] == GREY)
        colors[source] = BLACK;
}

void DFS::clear(){
    cycles.clear();
    colors.clear();
    time_start.clear();
    time_close.clear();
    predecessor.clear();
}
