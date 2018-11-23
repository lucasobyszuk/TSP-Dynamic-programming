#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsItem>
#include <QList>
#include <QGraphicsSceneMouseEvent>

class Edge;
class Graph;


class Vertex : public QGraphicsItem
{

private:

    // Atributos
    QList<Edge *> edgeList;
    QString id;

    // Métodos privados
    QRectF boundingRect() const;                                // Define los límites de dibujo del vértice
    QVariant itemChange(GraphicsItemChange change, const QVariant &value); // Mantiene actualizado el cambio de posición del vértice
    void mousePressEvent(QGraphicsSceneMouseEvent *event);      // Cuando se clickea un vértice cambia de color
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);    // Cuando se suelta el click en un vértice cambia de color
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // Dibuja al vértice

public:

    // Constructor
    Vertex(QString id);                                         // Se le pasa un ID para identificar el vertice

    // Destructor
    ~Vertex();

    // Método modificador
    void addEdge(Edge *edge);


    // Métodos observadores
    QString getID() const;                                      // Retorna el ID del vértice
    QList <Edge*> getEdges() const;                             // Devuelve una lista de los arcos a los que esté asociado el vértice

};
#endif // VERTEX_H
