
Code
DFS
#include<iostream>
#include<stack>
using namespace std;
class graph
{
public:
int v;
int vectorArr[50][50];
int count = 0;
graph(int vertices)
{
this->v = vertices;
}
void addEdge(int s,int d)
{
vectorArr[s][d]=1;
vectorArr[d][s]=1;
}
void DFS(int start)
{
int visited[v]={0};
stack<int> s;
s.push(start);
visited[start]=1;
while(!s.empty())
{
int m = s.top();
s.pop();
cout<<" "<<m;
for(int i=0;i<v;i++)
{

if(vectorArr[m][i]==1 && visited[i]==0)
{
s.push(i);
visited[i]=1;
}
}
}
}
};
int main()
{
graph g(6);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(0,3);
g.addEdge(1,4);
g.addEdge(1,5);
cout<<"DFS....."<<endl;
g.DFS(3);
}

Output

/tmp/qxO1jULMoP.o
DFS.....
3 0 2 1 5 4

Code
BFS

#include<iostream>
#include<queue>
using namespace std;
class graph
{
public:
int v;
int vectorArr[50][50];
int count = 0;
graph(int vertices)
{
this->v = vertices;
}
void addEdge(int s,int d)
{
vectorArr[s][d]=1;
vectorArr[d][s]=1;
}
void BFS(int start)
{
int visited[v]={0};
queue<int> q;
q.push(start);
visited[start]=1;
while(!q.empty())
{
int m = q.front();
q.pop();
cout<<" "<<m;
for(int i=0;i<v;i++)
{
if(vectorArr[m][i]==1 && visited[i]==0)
{
q.push(i);
visited[i]=1;
}
}
}
}

};
int main()
{
graph g(6);
g.addEdge(0,1);
g.addEdge(0,2);
g.addEdge(0,3);
g.addEdge(1,4);
g.addEdge(1,5);
cout<<"BFS....."<<endl;
g.BFS(1);
}

Output

/tmp/qxO1jULMoP.o
BFS.....
1 0 4 5 2 3