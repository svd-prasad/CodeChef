// Program for Floyd Warshall Algorithm
#include <iostream>
#include <cstdlib>
using namespace std;
/* Define Infinite as a large enough value. This value will be used
  for vertices not connected to each other */
#define INF 1000001
void printSolution(long int **dist, long int V);
 
// Solves the all-pairs shortest path problem using Floyd Warshall algorithm
void floydWarshell (long int **graph, long int V)
{
    
    long int **dist, i, j, k;
	dist = (long int **)malloc((V+1) * sizeof(long int *));
	for(i = 1 ; i <= V; i++)
		dist[i] = (long int *)malloc((V+1) * sizeof(long int));
    
    for (i = 1; i <= V; i++)
        for (j = 1; j <= V; j++)
            dist[i][j] = graph[i][j];
 
    
    for (k = 1; k <= V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 1; i <= V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 1; j <= V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    // Print the shortest distance matrix
   printSolution(dist, V);
   for(i = 1 ; i <= V; i++)
		free(dist[i]);
	free(dist);
}
 

void printSolution(long int **dist, long int V)
{
    for (long int i = 1; i <= V; i++)
    {
        for (long int j = 1; j <= V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF";
            else
                cout<< dist[i][j];
        }
        cout<<endl;
    }
}
// driver program to test above function
int main()
{
    long int **graph, i, V, *arr, j;
	int cases;
	cin >> cases;
	while(cases > 0)
	{
		cin >> V;
		arr = (long int *)malloc((V + 1) * sizeof(long int));
		for(i = 1 ; i <= V; i++)
			cin >> arr[i];
		graph = (long int **)malloc((V + 1)* sizeof(long int *));
		for(i = 1 ; i <= V; i++)
			graph[i] = (long int *)malloc((V + 1) * sizeof(long int));
		for(i = 1 ;i <= V ;i++)
			for(j = 1 ;j <= V ;j++)
				graph[i][j] = INF;
		for(i = 1; i <= V;i++ )
			graph[i][arr[i]] = 1;
		floydWarshell(graph, V);
		for(i = 1 ; i <= V; i++)
			free(graph[i]);
		free(graph);
		free(arr);
		--cases;
	}
    return 0;
}