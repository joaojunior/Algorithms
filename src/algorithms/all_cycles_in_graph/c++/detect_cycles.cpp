#include "detect_cycles.h"
#include <algorithm>

void DetectCycle::run(Graph *graph){
    DFS dfs;
    Graph graph_transposed;
    map<int, int> nodes;
    this->clear();
    dfs.run(graph);
    transposed(graph, &graph_transposed);
    for(auto node : graph->nodes)
        nodes[dfs.time_close[node]] = node;
    //dfs in graph transposed
    dfs.clear();
    for(auto node : graph->nodes){
        dfs.colors[node] = dfs.WHITE;
        dfs.predecessor[node] = -1;
    }
    dfs.time = 0;

    for (auto arc=nodes.rbegin(); arc!=nodes.rend(); ++arc){
        if(dfs.colors[arc->second] == dfs.WHITE){
            dfs.dfs(&graph_transposed, arc->second);
        }
    }

    //copy cycles found with dfs
    for(auto cycle: dfs.cycles){
        path.clear();
        for(auto arc: cycle)
            path[arc.second] = arc.first;
        cycles.push_back(path);
    }
}


void DetectCycle::transposed(Graph *source, Graph *destination){
    for(auto node_source: source->nodes)
        for(auto node_destination: source->arcs[node_source])
            destination->add_arc(node_destination, node_source);
}
int DetectCycle::number_cycles(){
    return cycles.size();
}

void DetectCycle::clear(){
    cycles.clear();
}
