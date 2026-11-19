#include <iostream>
#include <vector>
using namespace std;

class Graph
{

    public:
        int vertices,edges;
        vector<vector<int>> adjMatrix;
        vector<vector<int>> adjList;
        // undirected and un-weighted graph
        void createGraphAdjacencyMatrix()
        {   
            int i,j;
            cout << "ENTER THE NUMBER OF VERTICESIN THE GRAPH : "<<endl;
            cin >> vertices;
            adjMatrix.resize(vertices,vector<int>(vertices));
            cout << "ENTER THE NUMBER OF EDGES : ";
            cin >> edges;
            for(int k = 0; k < edges;k++)
            {
                cout << "ENTER THE TWO VERTICES : ";
                cin >> i >> j;
                adjMatrix[i][j] = 1;
                adjMatrix[j][i] = 1;
            }

        }

        // from here display the adj matrix
        void displayAdjMatrix()
        {
            for(int i = 0; i < vertices;i++)
            {
                for(int j = 0; j < vertices; j++)
                {
                    cout << adjMatrix[i][j] << "  ";
                }
                cout << endl;
            }
        }

    // VREAT THE GRAPH USING ADJENCY LIST
    void createGraphAdjencyList()
    {
        cout << "ENTER THE NUMBER OF VERTICIES : ";
        cin >> vertices;
        cout << "ENTER THE NUMBER OF EDGES : ";
        cin >> edges;
        adjList.resize(vertices);

        for(int i = 0; i < edges;i++)
        {
            int k,j;
            cout << "ENTER THE TWO VERTICE FOR EDGE : ";
            cin >> k >> j;
            adjList[k].push_back(j);
            adjList[j].push_back(k);
        }
    }

    // dispaly the adjency list
    void displayAdjList()
    {
        for(int i = 0; i< vertices;i++)
        {
            cout << i << " --> ";
            for(int j = 0; j < adjList[i].size();j++)
            {
                cout << adjList[i][j] << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph* gr = new Graph();
    gr->createGraphAdjencyList();
    gr->displayAdjList();
    return 0;
}