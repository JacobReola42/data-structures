/* ************************************************************************
Name: Jacob Reola
Assignment: 07
Purpose: test file for graph2
 ************************************************************************ */

#include "graph2.h"


int main(int argc, char** argv) {

    graph2 second_graph;

    // add graph edges as in figure 20-39
    second_graph.add_direct_edge(0, 1, 2);
    second_graph.add_direct_edge(0, 2, 4);
    second_graph.add_direct_edge(0, 3, 6);

    second_graph.add_direct_edge(1, 2, 5);
    second_graph.add_direct_edge(1, 4, 3);

    second_graph.add_direct_edge(2, 3, 2);
    second_graph.add_direct_edge(2, 4, 2);

    second_graph.add_direct_edge(3, 4, 5);
    second_graph.add_direct_edge(3, 5, 3);
    second_graph.add_direct_edge(3, 2, 1);

    second_graph.add_direct_edge(4, 2, 3);
    second_graph.add_direct_edge(4, 5, 5);
    second_graph.add_direct_edge(4, 6, 1);

    second_graph.add_direct_edge(5, 4, 1);

    second_graph.add_direct_edge(6, 5, 2);

    // get shortest path from node 1 as start

    second_graph.shorest_path(1);

}
