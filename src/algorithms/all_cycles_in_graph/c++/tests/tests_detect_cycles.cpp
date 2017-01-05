#include <gtest/gtest.h>

#include <graph.h>
#include "../detect_cycles.h"

TEST(DetectCyclesTest, GraphExampleCormen) {
    Graph graph;
    list<map<int, int> > expected;
    map<int, int> cycle;
    graph.add_arc(0, 1);
    graph.add_arc(1, 2);
    graph.add_arc(1, 4);
    graph.add_arc(1, 5);
    graph.add_arc(2, 3);
    graph.add_arc(2, 6);
    graph.add_arc(3, 2);
    graph.add_arc(3, 7);
    graph.add_arc(4, 0);
    graph.add_arc(4, 5);
    graph.add_arc(5, 6);
    graph.add_arc(6, 5);
    graph.add_arc(6, 7);
    graph.add_arc(7, 7);
    cycle[0] = 1;
    cycle[1] = 4;
    cycle[4] = 0;
    expected.push_back(cycle);
    cycle.clear();
    cycle[2] = 3;
    cycle[3] = 2;
    expected.push_back(cycle);
    cycle.clear();
    cycle[5] = 6;
    cycle[6] = 5;
    expected.push_back(cycle);
    cycle.clear();
    cycle[7] = 7;
    expected.push_back(cycle);

    DetectCycle detect_cycle;
    detect_cycle.run(&graph);
    ASSERT_EQ(4, detect_cycle.number_cycles());
    EXPECT_EQ(expected, detect_cycle.cycles);
}
