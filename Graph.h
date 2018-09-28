//
// Created by Sebastian on 28/09/2018.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
#include <cstdlib>
using namespace std;

/*El archivo que lee este grafo sigue el formato:
 * 11 1
 * 1 2 3
 * 1 3 5
 * O sea, hay 11 vertices, es True (1) que sea direccionado, el 1 conecta con 2 con un peso 3, con 3 con un peso 5.
*/

struct Edge
{
    int data;
    int weight;
    struct Edge* next;
};

struct List
{
    struct Edge* head;
    struct Edge* tail;
};


class Graph
{
private:

public:
    int vertices;
    bool dir;
    List* array;

    Graph(int n, bool d)
    {
        vertices = n;
        dir= d;
        array = new List [n];
        for (int i = 0; i < n; ++i) {
            array[i].head = nullptr;
            array[i].tail= nullptr;
        }
    }

    void addEdge(int src, int dest, int w)
    {
        auto newNode = new Edge;
        newNode->data= dest;
        newNode->weight= w;
        newNode->next= nullptr;


        if(array[src].head== nullptr) {
            array[src].head = newNode;
            array[src].tail= newNode;
        } else {
            array[src].tail->next= newNode;
            array[src].tail= newNode;
        }

        if(!dir){
            auto newNode2 = new Edge;
            newNode2->data= dest;
            newNode2->weight= w;
            newNode2->next= nullptr;


            if(array[src].head== nullptr) {
                array[src].head = newNode2;
                array[src].tail= newNode2;
            } else {
                array[src].tail->next= newNode2;
                array[src].tail= newNode2;
            }

        }

    }
    /*
     * Print the graph
     */
    void printGraph()
    {
        int v;
        for (v = 0; v < vertices; ++v)
        {
            Edge* tmp = array[v].head;		//tmp has the address of (0,1..)vertex head
            cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
            while (tmp)
            {
                cout<<"-> "<<tmp->data;
                tmp = tmp->next;
            }
            cout<<endl;
        }
    }
};

#endif //GRAPH_GRAPH_H
