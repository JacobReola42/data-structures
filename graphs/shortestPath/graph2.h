/* ************************************************************************
Name: Jacob Reola
Assignment: 07
Purpose: header for graph1
 ************************************************************************ */


#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>
#include <functional>
#include <utility>

//#include <string>
//using namespace std;


class graph2 {

private:
    /*
    *  make a Graph as adjaceny matrix graph
    *	so using vector of pair of vectors
    *  as each vector corresponding to certain node
    *  and pair of 2 integer :
    *  - first one for the node that has edge with
    *  - second is the weight of the edge
    **/
    std::vector< std::vector<std::pair<int, int> > >_adj;

    // we have 10 number maximum
    const int _N = 10;

public :
    graph2() {
        // make vector of vector of pairs for 10 number maximum
        _adj.vector::assign(_N, std::vector<std::pair<int, int> >());
    }

    // make decleration for these method
    void shorest_path(int start_node);  // Function to get shortest path from given node to all other node
    void add_direct_edge(int start_node, int goal_node, int weight); // function to add direct edge from start node to goal node

};



