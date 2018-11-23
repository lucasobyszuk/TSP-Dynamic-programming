#ifndef TSPGRAPH_H
#define TSPGRAPH_H

#include <QVector>
#include <QString>
#include <QList>
#include "vertex.h"

// Esta clase representa a un Grafo el cual es siempre completamente conexo y no dirigido.
// Es el que implementa la solución al problema
class TSPGraph {

    private:

        struct Ciclo {
            unsigned int costo;
            QVector<unsigned int> camino; // Comienza y termina en el nodo 0 (implícito)
        };

        // Atributos
        unsigned int N;             // Cantidad de nodos en el grafo
        unsigned int** Distancias;  // Representa la matriz de distancias
        Ciclo CicloHamiltoniano;

        // Métodos privados
        void CalcularCiclo();
        QList<QString> KeysDeCardinal(unsigned int s);
        void Keys(unsigned int s, QString key, unsigned int posI, QList<QString> & lista);


    public:

        // Constructor
        TSPGraph(unsigned int n, QVector<Vertex *> V);

        // Destructor
        ~TSPGraph();

        // Métodos observadores
        unsigned int costoCiclo() const;
        QVector<unsigned int> recorrido() const;
        unsigned int distancia(unsigned int i, unsigned int j) const;

};

#endif // TSPGRAPH_H
