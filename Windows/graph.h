#ifndef GRAPH_H
#define GRAPH_H

#include <QtWidgets/QGraphicsView>
#include "edge.h"

class Vertex;

class Graph : public QGraphicsView
{
    Q_OBJECT

private:

    // Atributos
    QGraphicsScene *Scene;
    unsigned int nVertex;
    QVector <Vertex*> V;
    QList<Edge*> EdgesPainted;

    // Método privado
    void addEdge(Vertex *source, Vertex *dest);         // Agrega un arco entre dos vértices

public:

    // Constructor del grafo el cual recibe la escena a la que pertenece y la cantidad de vertices
    Graph(QGraphicsScene *scene,int n);

    // Destructor
    ~Graph();

    // Métodos modificadores
    void addVertex(QGraphicsScene *scene);              // Agrega los vértices a la escena en posiciones aleatorias
    void allocateEdges();                               // Partiendo de los vértices, asigna los arcos
    void drawPath(QVector<unsigned int> array);         // Dibuja un camino dado un vector

    // Métodos observadores
    QRectF boundingRect() const;                        // Límites del grafo
    unsigned int getNVertex() const;                    // Retorna la cantidad de vértices
    QVector <Vertex*> getVector() const;                // Retorna el vector que contiene todos los vértices


};

#endif // GRAPH_H
