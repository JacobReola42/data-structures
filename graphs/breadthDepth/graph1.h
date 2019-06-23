// Copyright 2018 Jacob Reola

#include <iostream>
#include <queue>


class graph1{

private:

    /*
     *  make a Graph as adjacency matrix graph
     *	so using vector of pair of vectors
     *  as each vector corresponding to certain node
     *  and pair of 2 integer:
     *
     *  - first one for the node that has edge with
     *  - second is the weight of the edge
     *
     */

    std::vector<std::vector<std::pair<int,int> > >_adj;

    // we have characters maximum 26 from 'a' to 'z'
    const int _N = 26;

public:
    graph1();

    // declaring methods

    void bfs(char);  //Breadth first search
    void dfs(int,bool*); //Depth first search
    void add_undirected_edge(char,char,int); //add undirected edge
};


