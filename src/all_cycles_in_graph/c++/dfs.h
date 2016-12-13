#ifndef DFS_H
#define DFS_H

#include <list>
#include <map>

#include "graph.h"

class DFS{
    public:
        const int BLACK=0;
        const int GREY=1;
        const int WHITE=2;
        map<int, int> colors;
        map<int, int> time_start;
        map<int, int> time_close;
        map<int, int> predecessor;
        int time;
        void run(Graph *);
        void dfs(Graph *, int);
        void clear();
};

#endif
