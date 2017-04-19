#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#define MaxVNumber 9

int minDistance(int ShortestDistTo[], bool IncludedInShortestPath[])
{
	int min = 0x7FFFFFFF;
	int min_index;

	for (int Vertice = 0; Vertice < MaxVNumber; Vertice++)
	{
		if ((IncludedInShortestPath[Vertice] == false) &&
			(ShortestDistTo[Vertice] <= min))
		{
			min = ShortestDistTo[Vertice];
			min_index = Vertice;
		}
	}

	return min_index;
}

void Algorithm_Dijkstras(int graph[MaxVNumber][MaxVNumber], int src, int ShortestDistTo[MaxVNumber])
{
	//int ShortestDistTo[MaxVNumber];    
	bool IncludedInShortestPath[MaxVNumber]; 

	int Max = 0x7FFFFFFF;
	for (int Vertice = 0; Vertice < MaxVNumber; Vertice++)
	{
		ShortestDistTo[Vertice] = Max;
		IncludedInShortestPath[Vertice] = false;
	}

	ShortestDistTo[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < MaxVNumber - 1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int VerticeChoice = minDistance(ShortestDistTo, IncludedInShortestPath);

		IncludedInShortestPath[VerticeChoice] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int Vertice = 0; Vertice < MaxVNumber; Vertice++)

			// Update dist[v] only if is not in IncludedInShortestPath, there is an edge from 
			// u to v, and total weight of path from src to  v through u is 
			// smaller than current value of dist[v]
			if ((!IncludedInShortestPath[Vertice]) && // not in shortest path yet
				(graph[VerticeChoice][Vertice]) && // has an edge with current choice
				(ShortestDistTo[VerticeChoice] != Max) // not a max value choice????
				&& ((ShortestDistTo[VerticeChoice] + // dont over write already chosen smaller paths
					graph[VerticeChoice][Vertice]) < ShortestDistTo[Vertice]))
			{
				ShortestDistTo[Vertice] = 
					ShortestDistTo[VerticeChoice] + graph[VerticeChoice][Vertice];
			}
	}
}

void Algorithm_Prims()
{

}

//euler traverse
//traveling salesman problem
// shortest path (least cost) between two vertices
// minimal spanning tree

#endif
