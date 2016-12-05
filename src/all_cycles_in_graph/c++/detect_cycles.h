#ifndef DETECT_CYCLES_H
#define DETECT_CYCLES_H

#include <list>
#include <set>
#include <map>
#include <math.h>

using namespace std;

class Graph{
    public:
        map<int, list<int> > arcs;
        set<int> nodes;
        void add_arc (int, int);
        void add_node (int);
};

class DetectCycle{
    public:
        map<int, int> colors;
        const int BLACK=0;
        const int GREY=1;
        const int WHITE=2;
        void run(Graph);
        void dfs(Graph, int);
};

#endif
