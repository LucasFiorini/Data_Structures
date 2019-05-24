#include "../../include/graph/graph_entity/graph.hpp"

Graph::Graph() {
    this->adjacencyMatrix = NULL;
}

Graph::Graph(bool **adjacencyMatrix) {

}

Graph::Graph(std::string filePath) {
    
}

Graph::~Graph() {

}

bool** Graph::getAdjacencyMatrix() {
    return this->adjacencyMatrix;
}

void Graph::setAdjacencyMatrix() {

}

Graph::STATUS Graph::addEdge(unsigned v1, unsigned v2) {

}

Graph::STATUS Graph::addVertex(unsigned amount) {

}