#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>


using edge_id = unsigned;
using node_id = unsigned;

typedef struct edge
{
	node_id tail;
	node_id head;
} edge;

typedef struct node
{
	std::vector<edge_id> edge_ids;
} node;

class Graph
{
	public:
	
	Graph(const char *filename);
	bool graph_scan(node_id start, node_id end, std::vector<node_id> &P) const;
	
	private:
	
	std::vector<node> _nodes;
	std::vector<edge> _edges;
	node_id _num_nodes;
};

Graph::Graph(const char *filename)
{
	std::ifstream file(filename);
	std::string line;
	
	std::getline(file, line);
	std::stringstream ss(line);
	ss >> _num_nodes;
	
	_nodes = std::vector<node>(_num_nodes);
	
	for(edge_id i = 0; std::getline(file,line); ++i)
	{
		node_id a,b;
		ss = std::stringstream(line);
		ss >> a >> b;
		_edges.push_back({a,b});
		_nodes[a].edge_ids.push_back(i);
		_nodes[b].edge_ids.push_back(i);
	}
}

bool Graph::graph_scan(node_id start, node_id end, std::vector<node_id> &P) const // expects P to be empty
{
	std::vector<bool> visited(_num_nodes, false);
	visited[start] = true;
	
	std::vector<node_id> queue;
	queue.reserve(_num_nodes);
	queue.push_back(start);
	
	std::vector<node_id> prev(_num_nodes, _num_nodes);
	prev[start] = start;
	
	for(unsigned i = 0; i < queue.size(); ++i)
	{
		node_id curr_node_id = queue[i];
		for(auto curr_edge_id : _nodes[curr_node_id].edge_ids)
		{
			edge curr_edge = _edges[curr_edge_id];
			node_id other;
			if(curr_edge.tail == curr_node_id)
			{
				other = curr_edge.head;
			}
			else
			{
				other = curr_edge.tail;
			}
			
			if(visited[other])
			{
				continue;
			}
			else
			{
				queue.push_back(other);
				visited[other] = true;
				prev[other] = curr_node_id;
			}
		}
	}
	
	if(visited[end])
	{
		P.clear();
		
		node_id curr_node_id = end;
		P.push_back(end);
		
		while(curr_node_id != start)
		{
			curr_node_id = prev[curr_node_id];
			P.push_back(curr_node_id);
		}
	}
	
	return visited[end];
}

int main(int argc, char** argv)
{
	if(argc > 1)
	{
		Graph G(argv[1]);
		std::vector< node_id > P;
		bool is_reachable = G.graph_scan(0,1,P);
		std::cout << "is_reachable = " << is_reachable << std::endl;
		for(auto it = P.rbegin(); it != P.rend(); ++it)
		{
			std::cout << (*it) << " ";
		}
	}
}







