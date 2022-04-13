#include<iostream>
#include<climits>
#include<string.h>

using namespace std;

struct Edge
{
	int src, weight, target;
};

class Graph
{
	int V, E;

	Edge *edge;

public:
	Graph();

	Graph(int, int);

	//create graph func
	Graph* Create(int, int);

	void Bellmanford(int, Graph*);

	void print_result(int[], int);
};

//defaultive constructor
Graph::Graph():
	V(0),
	E(0),
	edge(NULL) {};

//parameterized constructor
Graph::Graph(int v_val, int e_val)
{
	V = v_val;
	E = e_val;
	edge = NULL;
}

//Create graph
Graph* Graph::Create(int _V, int _E)
{
	Graph *g;
	g->V = _V;
	g->E = _E;
	g->edge = new Edge[E];

	//hardcoded vertex,edge,weight - > TODO: make it as program input;
	//v0-->v1
	g->edge[0].src = 0;
	g->edge[0].target = 1;
	g->edge[0].weight = 9;
	//v0-->v2
	g->edge[1].src = 0;
	g->edge[1].target = 2;
	g->edge[1].weight = 3;
	//v1-->v2
	g->edge[2].src = 1;
	g->edge[2].target = 2;
	g->edge[2].weight = 6;
	//v2-->v1
	g->edge[3].src = 2;
	g->edge[3].target = 1;
	g->edge[3].weight = 4;
	//v1-->v4
	g->edge[4].src = 1;
	g->edge[4].target = 4;
	g->edge[4].weight = 2;
	//v2-->v3
	g->edge[5].src = 2;
	g->edge[5].target = 3;
	g->edge[5].weight = 1;
	//v3-->v2
	g->edge[6].src = 3;
	g->edge[6].target = 2;
	g->edge[6].weight = 2;
	//v3-->v4
	g->edge[7].src = 3;
	g->edge[7].target = 4;
	g->edge[7].weight = 1;
	//v4-->v5
	g->edge[8].src = 4;
	g->edge[8].target = 5;
	g->edge[8].weight = 2;
	//v5-->v6
	g->edge[9].src = 5;
	g->edge[9].target = 6;
	g->edge[9].weight = 2;
	//v6-->v0
	g->edge[10].src = 6;
	g->edge[10].target = 0;
	g->edge[10].weight = 3;


	/**
	 * current graph:
	 * src,target = distance
	 * v0,v1 = 9
	 * v0,v2 = 3
	 * v1,v2 = 6
	 * v2,v1 = -4
	 * v1,v4 = 2
	 * v2,v3 = 1
	 * v3,v2 = 2
	 * v3,v4 = -1
	 * v4,v5 = 2
	 * v5,v6 = 2
	 * v6,v0 = -3
	 * */


	return g;
}

//printing the result of bellman ford -> the distance of V [V is the id of the vertex] from V0.
void Graph::print_result(int dist[], int n)
{
	cout<<"V   	 Distance from source"<<endl;
	for (int i = 0; i < n; ++i)
		printf("%d \t|\t %d\n", i, dist[i]);
}
//Run bellmanford
void Graph::Bellmanford(int source, Graph *g)
{
	int n;

	int target[g->V];
	int predecessor[g->V];



	//initializing the distances with inf
	for (int i = 1; i <= g->V; i++)
	{
		target[i] = INT_MAX;
	}
	predecessor[source] = 0;


	//relax edges repeatedly
	for (int i = 1; i <= g->V - 1; i++)
	{
		for (int j = 0; j < g -> E; j++)
		{
			int u = g->edge[j].src;
			int v = g->edge[j].target;
			int weight = g->edge[j].weight;

			if (target[u] + weight < target[v] and target[u] != INT_MAX)
			{
				target[v] = target[u] + weight;

			}

		}
	}

	//check for negative-weight cycles
	for (int i = 0; i < g->E; i++)
	{
		int u = g->edge[i].src;
		int v = g->edge[i].target;
		int weight = g->edge[i].weight;

		if (target[u] + weight < target[v] and target[u] != INT_MAX)
		{
			cout << "Graph has negative cycle" << endl;
			return;
		}
	}

	g->print_result(target, V);

}
int main(int argc, char const *argv[])
{
	Graph g, *_g;

	_g = g.Create(7, 11);
	g.Bellmanford(0, _g);



	return 0;
}