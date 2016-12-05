#include <gtest/gtest.h>
#include "../detect_cycles.h"

TEST(DetectCyclesTest, GraphWithoutArcs) {
    Graph graph;
    graph.add_node(0);
    graph.add_node(1);
    DetectCycle detect_cycle;
    detect_cycle.run(graph);
    EXPECT_EQ (detect_cycle.BLACK, detect_cycle.colors.find(0)->second);
    EXPECT_EQ (detect_cycle.BLACK, detect_cycle.colors.find(1)->second);
}
