#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>
#include "edge.h"
#include "vertex.h"
#include "graph.h"


// Constructor
Vertex::Vertex(QString id)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    this->id=id;
}


// Destructor
Vertex::~Vertex() {

}


// Método modificador
void Vertex::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}


// Métodos observadores
QString Vertex::getID() const
{
    return id;
}

QList<Edge *> Vertex::getEdges() const
{
    return edgeList;
}


// Métodos privados
QRectF Vertex::boundingRect() const
{
    qreal adjust = 2;
    return QRectF( -10 - adjust, -10 - adjust, 33 + adjust, 33 + adjust);
}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    QRadialGradient gradient(-3, -3, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, QColor(Qt::yellow).light(120));
        gradient.setColorAt(0, QColor(Qt::darkYellow).light(120));
    } else {
        gradient.setColorAt(0, Qt::red);
        gradient.setColorAt(1, Qt::darkRed);
    }
    painter->setBrush(gradient);

    painter->setPen(QPen(Qt::black, 0));                                                // Dibuja el borde de la elipse
    painter->drawEllipse(-10, -10, 20, 20);
    painter->setPen(QPen(Qt::white, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setFont(QFont("Arial", 12, QFont::Bold));
    painter->drawText(QPointF(-4, 6),this->id);                                         // Dibuja el ID del vertice
}

QVariant Vertex::itemChange(GraphicsItemChange change, const QVariant &value)
{
    switch (change) {
    case ItemPositionHasChanged:
        foreach (Edge *edge, edgeList)
            edge->adjust();
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}

void Vertex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Vertex::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
