#ifndef GRAPH_H
#define GRAPH_H

#include <string>

class Graph {

    public:
        enum STATUS {
            _SUCCESS_,
            _FAILURE_
        };
        Graph();
        Graph(bool **adjacencyMatrix);
        Graph(std::string filePath);
        ~Graph();
        bool** getAdjacencyMatrix();
        STATUS addEdge(unsigned v1, unsigned v2);
        STATUS addVertex(unsigned amount);
    
    private:
        bool **adjacencyMatrix;
        void setAdjacencyMatrix();
        
};

#endif