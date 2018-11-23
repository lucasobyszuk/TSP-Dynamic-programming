#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>
#include "vertex.h"


class Edge : public QGraphicsItem {

    private:

        // Atributos
        Vertex *source, *dest;
        QPointF sourcePoint;
        QPointF destPoint;
        unsigned int lenght;
        QString color;

        // Métodos privados
        QRectF boundingRect() const;                                    // Define los límites de donde se dibujará el arco
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // Dibuja el arco

    public:

        // Constructor
        Edge(Vertex *sourceVertex, Vertex *destVertex, QString color);

        // Destructor
        ~Edge();

        // Método modificador
        void adjust();                                                  // ajusta la longitud del arco cuando un vértice es arrastrado


        // Métodos observadores
        Vertex *sourceVertex() const;                                   // Retorna el vertice de origen
        Vertex *destVertex() const;                                     // Retorna el vertice de destino
        unsigned int getLenght() const;                                 // retorna la longitud del arco


};

#endif // EDGE_H
