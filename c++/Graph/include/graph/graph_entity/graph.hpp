#ifndef GRAPH_H
#define GRAPH_H

class Graph {

    public:
        Graph();
        ~Graph();
        bool** getAdjacencyMatrix();
    
    private:
        bool **adjacencyMatrix;
        void setAdjacencyMatrix();
        
};

#endif