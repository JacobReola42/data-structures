/* ************************************************************************
Name: Jacob Reola
Assignment: 07
Purpose: source file for graph2
 ************************************************************************ */


#include "graph2.h"


/**
* make a dijkstra algorithm to get shorest path from given node to all other node
* using Priority queue and use parent array for each node to get it's shortest path
* to start node
*/

//void reverse(int,int)

void graph2::shorest_path(int start_node)
{

    // make a Priority queue to the minimum cost every time.
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > >pq;

    // initiliaze the shortest distance to everynode as big value
    int distance[7] = {10000000,10000000, 10000000, 10000000, 10000000, 10000000, 10000000 };

    // make a parent for each node as -1, assuming position is 0.
    int parent_path[7] = { -1,-1,-1,-1,-1,-1,-1 };

    // push the start node to priority queue
    distance[start_node] = 0;
    pq.push(std::make_pair(0, start_node));
    while (!pq.empty()) {
        // pop the top node from Priority queue

        int parent = pq.top().second;
        int parent_cost = pq.top().first;
        pq.pop();

        // if this cost is bigger than the shortest path ignore it
        if (parent_cost > distance[parent])continue;

        // for each child of this node
        for (int i = 0; i < _adj[parent].size(); ++i) {
            int child = _adj[parent][i].first;
            int child_cost = _adj[parent][i].second;
            int total_cost = parent_cost + child_cost;

            // check if whether's if visit the next node using this path make it shortest path
            if (distance[child] > total_cost) {
                distance[child] = total_cost;

                // push the next node and the cost so far to Priority queue
                pq.push(std::make_pair(total_cost, child));

                // mark the parent of this next node as it's parent
                parent_path[child] = parent;
            }
        }
    }
    for (int current_node = 0; current_node <= 6; ++current_node) {

        // if there's no path
        if (distance[current_node] == 10000000) {
            std::cout << "There's No Path between Node " << start_node << " TO Node " << current_node << "\n\n";
        }

            // if current to equal the given node
        else if (current_node != start_node) {

            // get the  path using parent
            std::cout << "Shortest Path From Start Node " << start_node << " To Node " << current_node << std::endl;
            std::vector<int>path;

            // start from the this node go to it's parent and it's parent go to it's parent so on until reach
            // the start node
            path.push_back(current_node);
            int cur = parent_path[current_node];
            while (cur != -1) {
                path.push_back(cur);
                cur = parent_path[cur];
            }
            //std::vector<int>path;
            std::reverse(path.begin(), path.end()); // reverse the path to get the path from start node to current node

            // print the path
            std::cout << "Node " << start_node << " ";
            for (int i = 1; i < path.size(); ++i) {
                std::cout << "-> Node " << path[i] << " ";
            }
            std::cout << "   *****  with total weight = " << distance[current_node] << "\n\n";

        }
    }
}

/*
* making a directed edge between start_node and goal_node with given weight
*/

void graph2::add_direct_edge(int start_node, int goal_node, int weight)
{
    // put  directed edge between start_node and goal_node 2 with given weight
    _adj[start_node].push_back(std::make_pair(goal_node, weight));
}

