#include <gtest/gtest.h>
#include "../detect_cycles.h"

TEST(DetectCyclesTest, GraphWithoutArcs) {
    Graph graph;
    graph.add_node(0);
    graph.add_node(1);
    DetectCycle detect_cycle;
    detect_cycle.run(graph);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(0)->second);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(1)->second);
    ASSERT_FALSE(detect_cycle.has_cycle());
}

TEST(DetectCyclesTest, GraphWithOneCycle) {
    Graph graph;
    graph.add_arc(0, 1);
    graph.add_arc(1, 0);
    list<map<int, int> > expected;
    map<int, int> cycle;
    cycle[0] = 1;
    cycle[1] = 0;
    expected.push_back(cycle);

    DetectCycle detect_cycle;
    detect_cycle.run(graph);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(0)->second);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(1)->second);
    ASSERT_TRUE(detect_cycle.has_cycle());
    EXPECT_EQ(expected, detect_cycle.cycles);
}
