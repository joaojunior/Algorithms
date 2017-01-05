#include <gtest/gtest.h>

#include <graph.h>
#include "../dfs.h"

TEST(DFSTest, GraphExampleCormen){
    Graph graph;
    DFS dfs;
    map<int, int> colors;
    map<int, int> time_start;
    map<int, int> time_close;
    map<int, int> predecessor;
    graph.add_arc(0, 1);
    graph.add_arc(0, 3);
    graph.add_arc(1, 2);
    graph.add_arc(2, 3);
    graph.add_arc(3, 1);
    graph.add_arc(4, 2);
    graph.add_arc(4, 5);
    graph.add_arc(5, 5);
    colors[0] = dfs.BLACK;
    colors[1] = dfs.BLACK;
    colors[2] = dfs.BLACK;
    colors[3] = dfs.BLACK;
    colors[4] = dfs.BLACK;
    colors[5] = dfs.BLACK;
    time_start[0] = 1;
    time_start[1] = 2;
    time_start[2] = 3;
    time_start[3] = 4;
    time_start[4] = 9;
    time_start[5] = 10;
    time_close[0] = 8;
    time_close[1] = 7;
    time_close[2] = 6;
    time_close[3] = 5;
    time_close[4] = 12;
    time_close[5] = 11;
    predecessor[0] = -1;
    predecessor[1] = 0;
    predecessor[2] = 1;
    predecessor[3] = 2;
    predecessor[4] = -1;
    predecessor[5] = 4;
    dfs.run(&graph);

    ASSERT_EQ(colors, dfs.colors);
    ASSERT_EQ(time_start, dfs.time_start);
    ASSERT_EQ(time_close, dfs.time_close);
    ASSERT_EQ(predecessor, dfs.predecessor);
}
