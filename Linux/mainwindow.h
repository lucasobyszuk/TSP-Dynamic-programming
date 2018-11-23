#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "qwindowdefs.h"
#include <QHBoxLayout>
#include <QMainWindow>
#include "graph.h"
#include "tspgraph.h"


namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:

        // Atributos
        QHBoxLayout *centralLayout;
        Ui::MainWindow *ui;
        Graph *graph;
        TSPGraph * solutionGraph;         // El grafo que implementa la resolución del problema
        QGraphicsScene *Scene;            // Escena donde se dibujará el grafo
        QGraphicsView *View;
        QTimer *Timer;


        // Método privado
        void scaleView(qreal scaleFactor);          // Asigna un factor de zoom

    public:

        // Constructor
        explicit MainWindow(QWidget *parent = 0);

        // Destructor
        ~MainWindow();

        // Método modificador
        void createInterface();                     // Inicializa los componentes de la escena y el view

        // Método observador
        void startWindow() const;

    private slots:

        // Métodos relacionados a las acciones de los botones

        void myTimer(void);                         // actualiza la escena
        void on_pushButton_clicked();               // genera el grafo
        void on_pushButton_2_clicked();             // calcula el camino de menor costo (tsp)
        void on_zoomIn_clicked();                   // hace un zoom en la escena
        void on_zoomOut_clicked();                  // saca zoom en la escena
        void on_actionQuit_triggered();             // cierra la aplicacion
        void on_actionAbout_2_triggered();          // muestra una ventana con informacion acerca de la aplicacion
        void on_actionInicio_triggered();


};

#endif // MAINWINDOW_H
