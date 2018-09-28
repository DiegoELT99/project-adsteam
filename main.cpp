#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Graph.h"

using namespace std;

Graph* Read() {

        ifstream file("C:\\Users\\Sebastian\\Desktop\\2018-2\\ADS\\Graph\\test.txt");
        int x;
        bool d;
        int y, w;
        file >> x;
        file >> d;
        auto ptr= new Graph(x, d);
        cout << x;
        cout << d;
        cout << ptr->vertices<< ptr->dir;
        while (file >> x) {
                file >> y >> w;
                cout << "AAAAAAAAH" << x << y << w;
                ptr->addEdge(x, y, w);
        }

        return ptr;
}

int main() {

        Read()->printGraph();

        /*FUNCIONA
        Graph gh(5, false);
        gh.addEdge(0, 1, 3);
        gh.addEdge(0, 4, 4);
        gh.addEdge(1, 2, 2);
        gh.addEdge(1, 3, 3);
        gh.addEdge(1, 4, 3);
        gh.addEdge(2, 3, 1);
        gh.addEdge(3, 4, 1);
        // print the adjacency list representation of the above graph
         gh.printGraph();
         */

        return 0;
}