#ifndef DETECT_CYCLES_H
#define DETECT_CYCLES_H

#include <list>
#include <map>

#include <graph.h>
#include "dfs.h"

using namespace std;

class DetectCycle{
    map<int, int> path;
    public:
        list<map<int, int> > cycles;
        void run(Graph *);
        int number_cycles();
        void transposed(Graph*, Graph*);
        void clear();
};

#endif
