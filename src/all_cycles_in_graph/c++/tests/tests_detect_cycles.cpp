#include <gtest/gtest.h>
#include "../graph.h"
#include "../detect_cycles.h"

TEST(DetectCyclesTest, GraphWithoutArcs) {
    Graph graph;
    graph.add_node(0);
    graph.add_node(1);
    DetectCycle detect_cycle;
    detect_cycle.run(&graph);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(0)->second);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(1)->second);
    ASSERT_EQ(0, detect_cycle.number_cycles());
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
    detect_cycle.run(&graph);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(0)->second);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(1)->second);
    ASSERT_EQ(1, detect_cycle.number_cycles());
    EXPECT_EQ(expected, detect_cycle.cycles);
}

TEST(DetectCyclesTest, GraphWithTwoCycle) {
    Graph graph;
    list<map<int, int> > expected;
    map<int, int> cycle;
    graph.add_arc(0, 1);
    graph.add_arc(1, 2);
    graph.add_arc(2, 0);
    graph.add_arc(1, 3);
    graph.add_arc(3, 4);
    graph.add_arc(4, 1);
    cycle[0] = 1;
    cycle[1] = 2;
    cycle[2] = 0;
    expected.push_back(cycle);
    cycle.clear();
    cycle[1] = 3;
    cycle[3] = 4;
    cycle[4] = 1;
    expected.push_back(cycle);

    DetectCycle detect_cycle;
    detect_cycle.run(&graph);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(0)->second);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(1)->second);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(2)->second);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(3)->second);
    EXPECT_EQ(detect_cycle.BLACK, detect_cycle.colors.find(4)->second);
    ASSERT_EQ(2, detect_cycle.number_cycles());
    EXPECT_EQ(expected, detect_cycle.cycles);
} 
