#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <map>
#include <set>

using namespace std;

class Graph{
    public:
        map<int, list<int> > arcs;
        set<int> nodes;
        void add_arc(int, int);
        void add_node(int);
        void clear();
        void print();
};


#endif
