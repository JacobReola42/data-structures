// Copyright 2018 Jacob Reola

#include "graph1.h"

int main(int argc, char** argv) {

	graph1 first_graph;

	// creating graph edges similar to figure 20-36
	first_graph.add_undirected_edge('a', 'b', 2);
	first_graph.add_undirected_edge('a', 'd', 6);
	first_graph.add_undirected_edge('a', 'c', 4);

	first_graph.add_undirected_edge('b', 'c', 5);

	first_graph.add_undirected_edge('c', 'd', 1);
	first_graph.add_undirected_edge('c', 'e', 2);

	first_graph.add_undirected_edge('d', 'f', 3);
	first_graph.add_undirected_edge('d', 'h', 4);


	first_graph.add_undirected_edge('e', 'f', 1);
	first_graph.add_undirected_edge('e', 'g', 5);
	first_graph.add_undirected_edge('e', 'i', 3);

	first_graph.add_undirected_edge('f', 'g', 4);

	// make a bfs from node a
    std::cout << "*** Graph1 BFS From Node a ***" << std::endl;
	char start = 'a';
	first_graph.bfs(start);
	

	std::cout << std::endl;

	// make a dfs from node a 

    std::cout << "*** Graph1 DFS From Node a ***" << std::endl;
	bool vis[26] = { false };
	start = 'a';
	int current_node = start - 'a';
	first_graph.dfs(0, vis);
    std::cout << std::endl;
}
