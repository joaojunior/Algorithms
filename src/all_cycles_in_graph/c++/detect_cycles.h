#ifndef DETECT_CYCLES_H
#define DETECT_CYCLES_H

#include <list>
#include <map>

#include "graph.h"

using namespace std;

class DetectCycle{
    map<int, int> path;
    public:
        map<int, int> colors;
        list<map<int, int> > cycles;
        const int BLACK=0;
        const int GREY=1;
        const int WHITE=2;
        void run(Graph *);
        void dfs(Graph *, int);
        int number_cycles();
};

#endif
