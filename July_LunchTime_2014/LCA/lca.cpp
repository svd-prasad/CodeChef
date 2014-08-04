#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct 
{
	 long long int root;
	 long long int node1;
	 long long int node2;
}MyStruct;
MyStruct make_Pair(const long long int& num1, const  long long int& num2, const  long long int& num3)
{
    MyStruct pair;
    pair.root = num1;
    pair.node1 = num2;
	pair.node2 = num3;
    return pair;
}
struct myclass
{
  bool operator() (const MyStruct & s1, const MyStruct & s2)
  {
	return (s1.root < s2.root);
  }
}myobject;

// A structure to represent an adjacency list node
struct AdjListNode
{
    long long  int dest;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency liat
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    long long  int V;
    struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(long long int dest)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(long long int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    long long int i;
    for (i = 1; i <= V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph,long long int src,long long  int dest)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
// A utility function to print the adjacenncy list representation of graph
void printGraph(struct Graph* graph)
{
    long long int v;
    for (v = 1; v <= graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        cout<<"\n Adjacency list of vertex  head "<< v;
        while (pCrawl)
        {
            cout<<"-> "<<pCrawl->dest;
            pCrawl = pCrawl->next;
        }
       cout<<endl;
    }
}
int main()
{
	long long int n, Q, n1, n2, i, root, size;
	std::vector<MyStruct> vec;
	cin >> n;
	struct Graph* graph = createGraph(n);
	while(n > 1)
	{
		cin >> n1 >> n2;
		addEdge(graph, n1, n2);
		--n;
	}
	printGraph(graph);
	cin >> Q;
	while(Q > 0)
	{
		cin >> root >> n1 >> n2;
		vec.push_back(make_Pair(root, n1, n2));
		--Q;
	}
	std::sort(vec.begin(), vec.end(), myobject);
	for (i = 0, size = vec.size(); i < size; ++i)
	{
		cout<< vec[i].root<<" "<<vec[i].node1<<" "<<vec[i].node2<<endl;
		//Fill parents
		parent = (long long int)calloc((n+1),sizeof(long long int));
		parent[vec[i].root] = vec[i].root;
		struct AdjListNode* pCrawl = graph->array[vec[i].root].head;
        while (pCrawl)
        {
            parent[pCrawl->dest]= vec[i].root;
            pCrawl = pCrawl->next;
        }
		free(parent);
	}
	return 0;
}




















