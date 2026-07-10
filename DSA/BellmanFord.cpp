#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <climits>
using namespace std;

class Edge{
public:
int v; int wt;

Edge(int v,int wt)
{
    this->v = v;
    this->wt= wt;
}
};

void bellmanFord(int V, int src, vector<vector<Edge>> g)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for(int i=0;i<V-1;i++)
    {
        for(int u=0;u<V;u++)
        {
            for(auto e:g[u])
            {
                if(dist[u]!=INT_MAX && dist[u]+e.wt<dist[e.v])
                {
                    dist[e.v] = dist[u]+e.wt;
                }
            }
        }
    }

    for(int u=0;u<V;u++)
    {
        for(auto e:g[u])
        {
            if(dist[u]!=INT_MAX && dist[u]+e.wt<dist[e.v])
            {
                cout<<"Negative weight cycle detected!"<<endl;
                return;
            }
        }
    }

    cout<<"Vertex Distance from Source"<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
}

int main()
{
    int V = 5;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 2));
    g[0].push_back(Edge(2, 4));

    g[1].push_back(Edge(4, -1));
    g[1].push_back(Edge(2, -4));

    g[2].push_back(Edge(3, 2));

    g[3].push_back(Edge(4, 4));

    bellmanFord(V, 0, g);
    return 0;
}
