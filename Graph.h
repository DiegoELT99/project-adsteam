//
// Created by Sebastian on 28/09/2018.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

/*El archivo que lee este grafo sigue el formato:
 * 11 1
 * 1 2 3
 * 1 3 5
 * O sea, hay 11 vertices, es True (1) que sea direccionado, el 1 conecta con 2 con un peso 3, con 3 con un peso 5.
*/

struct Edge
{
    char start;
    char final;
    int weight;

};


//asume que el grafo es direccionado

class Graph
{
private:
    typedef map<char, vector<Edge>> adjList;
    adjList graphmap;
    int vertices;
    int edges;
    bool dir;
public:

    Graph()
    {
        vertices= 0;
        edges=0;
        dir= true;

    };
    //Primero insertas nodos, luego los conectas. No es simultáneo.

    void insertNode(char start){

        vector<Edge> edges;
        auto pair= make_pair(start, edges);
        graphmap.insert(pair);
        vertices++;

    };

    void addEdge(char start, char final, int weight) {
        Edge edge{start, final, weight};

        //asume que es direccionado
        if (graphmap.count( start ) && graphmap.count( final )) {

            if (graphmap[start].empty()) {
                graphmap[start].push_back(edge);
            } else {
                graphmap[start].push_back(edge);
            }

            edges++;
        }
        else{
            cout << "Primero debe insertar los nodos";
        }
    };

    void removeEdge(char start, char final){
        int i=0;
        for (auto f: graphmap[start]){
            if(f.final==final) graphmap[start].erase(graphmap[start].begin()+i);
            i++;
        }
        edges--;
    };

    void removeNode(char start){
        //para grafo no direccionado, saca todas las conexiones con un set y buscalas. No es necesario
        //buscar en cada key si es no direccionado.
        //asumiendo un grafo direccionado
        graphmap.erase(start);
        vertices--;
        //borrando todos los edges que estén conectados a start

        /*int j;
        for (auto f: graphmap){
            j=0;
            for (auto i: f.second){
                if(i.final == start) f.erase(f.begin()+j);
                j++;
            }
        }*/
        //revisar con ejemplo en el main, pero puedes obviarlo porque no hay multiples conexiones.
        //revisar con ejemplo en el main, pero puedes obviarlo porque no hay multiples conexiones.
        //revisar con ejemplo en el main, pero puedes obviarlo porque no hay multiples conexiones.
        //revisar con ejemplo en el main, pero puedes obviarlo porque no hay multiples conexiones.
        for (auto f: graphmap){
        removeEdge(f.first, start);
        }



    };


    bool findVertex(char start){
        for (auto f : graphmap){
            if (f.first== start){
                return true;
            }
        }
        return false;

    };
    bool findEdge(char start, char final){

        if (findVertex(start)){
            for (auto f: graphmap[start]){
                if (f.final== final) return true;
            }
        }
        return false;

    };




    float density(){
        //asumiendo dirigido
        return (edges/(vertices*(vertices-1)));
    }
    bool isDense(float x){
        return density()>x;
    }
    bool isDisperse(float x){
        return density()<x;
    }

    int vertex_grade(char start){
        return graphmap[start].size();
    }

    //no sé los nombres correctos
    bool is_root(char start){

        //busca por todos los vectores. Si start no aparece como final ni una vez, retorna true
        for (auto f: graphmap){
            for (auto i: f.second){
                if(i.final == start) return false;
            }
        }
        return true;
    }

    bool is_leaf(char start){
        return graphmap[start].empty();
    }

    //saber si es conexo, fuertemente conexo y bipartito

    ~Graph(){
        vertices=0;
        edges=0;
        graphmap.clear();
    }

};

#endif //GRAPH_GRAPH_H
