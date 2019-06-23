// Copyright 2018 Jacob Reola

#include "graph1.h"

const int maxChar = 26;

/*
 * Making Breadth First Search utilizing queue as datastructure to keep track of next nodes
 * and boolean array to avoid visit node more than one.
 *
 */

graph1::graph1() {
    // make vector of vector of pairs for 26 charactes
    _adj.vector::assign(_N, std::vector<std::pair<int,int>>());
}

void graph1::bfs(char st)
{
    // getting the node as integer scale from 0 to 25, this is just easier to do than just doing  A - I.

    int start = st - 'a';

    // boolean array to avoid visiting node more than once.
    bool vis[maxChar] = {false}; //list initializer

    // push start node in queue
    vis[start] = true;
    std::queue<int>q;
    q.push(start);

    std::cout << "Node " << st << " ";

    // while there's a node still unvisited
    while (!q.empty()) {
        // pop the node from queue
        int parent = q.front();
        q.pop();

        // for each child of this node
        for (int i = 0; i < _adj[parent].size(); ++i) {
            int child = _adj[parent][i].first;
            int weight = _adj[parent][i].second;

            // check if whether's is not visited using boolean array
            if (vis[child] == false) {
                vis[child] = true; // mark it as visit
                char current_node = 'a' + child;
                std::cout << "-> Node " << current_node << " ";

                // put next node in queue
                q.push(child);
            }
        }

    }
    std::cout << std::endl;

}

/**
* Making Depth First Search  start from given node
* and use boolean array to avoid visit node more than one.
*/
void graph1::dfs(int parent, bool * vis)
{
    // check if this node visited before
    if (vis[parent] == true) {
        return;
    }
    vis[parent] = true;  // mark it as visit
    char current_node = 'a' + parent;
    std::cout << "Node " << current_node;

    // for each child of this node
    for (int i = 0; i < _adj[parent].size(); ++i) {
        int child = _adj[parent][i].first;
        int weight = _adj[parent][i].second;

        // check if whether's is not visited using boolean array
        if (vis[child] == false) {
            std::cout << " -> ";

            // call dfs function with next node
            dfs(child, vis);
        }

    }

}


/*
* making a undirected edge between node1 and node2
*/

void graph1::add_undirected_edge(char node1, char node2,int weight)
{
    // getting the node as integer scale from 0 to 25
    int first_node = (node1 - 'a');
    int second_node = (node2 - 'a');

    // put  edge between node1 and node 2 with given weight
    _adj[first_node].push_back(std::make_pair(second_node, weight));

    // put edge between node2 and node 1 with given weight
    _adj[second_node].push_back(std::make_pair(first_node, weight));
}
