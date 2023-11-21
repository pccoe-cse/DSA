#include <bits/stdc++.h>
using namespace std;

// #define V 5
int minVertex(int V,int vertex[], bool mstSet[])
{
int min = INT_MAX, min_index;
for (int v = 0; v < V; v++)
if (mstSet[v] == false && vertex[v] < min)
min = vertex[v], min_index = v;

return min_index;
}
void printMST(int V,int parent[], int** graph)
{
cout << "Edge \tWeight\n";
for (int i = 1; i < V; i++)
cout << parent[i] << " - " << i << " \t"
<< graph[i][parent[i]] << " \n";

}

void primMST(int V,int** graph)
{
int parent[V];
int vertex[V];
bool mstSet[V];
for (int i = 0; i < V; i++)
vertex[i] = INT_MAX, mstSet[i] = false;

vertex[0] = 0;
parent[0] = -1;
for (int count = 0; count < V - 1; count++) {
int u = minVertex(V,vertex, mstSet);

mstSet[u] = true;

for (int v = 0; v < V; v++)
if (graph[u][v] && mstSet[v] == false
&& graph[u][v] < vertex[v])
parent[v] = u, vertex[v] = graph[u][v];

}
printMST(V,parent, graph);
}
int main()
{
int V;
cout<<"Enter the number of vertex : ";
cin>>V;
int** graph = new int* [V];
for (int i = 0; i < V; i++)
{
graph[i] = new int[V];
}
int E;
cout<<"Enter the number of Edges : ";
cin>>E;
for (int i = 0; i < V; i++)
{
for (int j = 0; j < V; j++)
{
graph[i][j] = 0;
}
}
for (int i = 0; i < E; i++)

{
cout<<"Enter the relation between two vertices : "<<endl;
int u,v,w;
cout<<"Vertex 1 : ";
cin>>u;
cout<<"Vertex 2 : ";
cin>>v;
cout<<"Weight of edge : ";
cin>>w;
graph[u][v] = w;
graph[v][u] = w;
}

primMST(V,graph);
return 0;
}