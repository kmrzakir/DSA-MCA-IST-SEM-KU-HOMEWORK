#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    public:
        int vertices,edges;
        vector<vector<int>> adjMatrix;
        vector<vector<int>> adjList;
        void createAdjMatrix()
        {
            cout << "ENTER THE NUMBER OF VERTICIES : " << endl;
            cin >> vertices;
            adjMatrix.resize(vertices,vector<int>(vertices));
            cout << "ENTER THE NUMBER OF EDGES : " << endl;
            cin >> edges;
            for(int i = 0;i<edges;i++)
            {
                int v,u;
                cin >> v >> u;
                adjMatrix[v][u] = 1;
                adjMatrix[u][v] = 1;
            }

        }

        void displayAdjMatrix()
        {
            for(int i = 0; i < vertices;i++)
            {
                cout << i << " -> ";
                for(int j = 0;j < vertices;j++)
                {
                    cout << adjMatrix[i][j] << "  ";
                }
                cout << endl;
            }
        }
        
        void createAdjList()
        {
            cout << "ENTER THE NUMBER OF VERTICES : "<< endl;
            cin >> vertices;
            adjList.resize(vertices);
            cout << "ENTER THE NUMBER OF EDGES : "<< endl;
            cin >> edges;
            for(int i = 0; i < edges;i++)
            {
                int v,u;
                cout<< "ENTER THE TWO  EDGE VERTICES : "<<endl;
                cin >> v >> u;
                adjList[v].push_back(u);
                adjList[u].push_back(v);
            }
        }

        void displayAdjList()
        {
            for(int i = 0; i < vertices; i++)
            {
                cout << i << " -> ";
                for(int j = 0;j<adjList[i].size();j++)
                {
                    cout<<adjList[i][j] <<"  ";
                }
                cout<< endl;
            }
        }

};

int main()
{
    Graph* gr = new Graph();
    gr->createAdjList();
    gr->displayAdjList();
    return 0;
}