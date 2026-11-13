#include <iostream>
#include <vector>
using namespace std;


class Graph
{
    public:
    vector<vector<int>> adjmatrix;
    int vertices,edges;
    void createGraph()
    {
        cout << "Enter the number of vertices : ";
        cin >> vertices;
        cout << "Enter the number of edges : ";
        cin >> edges;
        adjmatrix.resize(vertices, vector<int>(vertices, 0));
        for(int i = 0; i < edges; i++)
        {
            int u, v,w;
            cout << "Enter the edge (u, v) and weight w : ";
            cin >> u >> v >> w;
            adjmatrix[u][v] = w;
            adjmatrix[v][u] = w;
        }
    }
    void displayGraph()
    {
        cout << "Adjacency Matrix : " << endl;
        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                cout << adjmatrix[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void adjListCreate()
    {
        int vertex,edges;
        int u , v;
        cout << "Enter the number of vertex : ";
        cin >> vertex;
        vector<int> adjList[vertex];
        cout << "Enter the number of edges : ";
        cin >> edges;

        for(int i = 0; i < edges; i++)
        {
            
            cout << "Enter the edges (u,v) : ";
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // diplay the adjvectore

         for(int i = 0; i < vertex; i++)
        {
            cout << i << "--> ";
            for(int j = 0; j < adjList[i].size(); j++)
            {
                cout<< adjList[i][j] << "  ";
            }
            cout << endl;
        }
    }

    // void adjListDisplay(vectore<int> v, int v)
    // {
    //     for(int i = 0; i < v; i++)
    //     {
    //     for(int j = 0; j < adjList[i].size; i++)
    //     {
    //         cout<< adjList[i][j];
    //     }
    //     cout << endl;
    //     }
    // }
};

int main()
{
    Graph *gf = new Graph();
    // gf->createGraph();
    // gf->displayGraph();

    gf->adjListCreate();
    return 0;
}
