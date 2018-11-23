#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graph.h"
#include "vertex.h"
#include "edge.h"
#include <QMessageBox>
#include <QTimer>


// Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(400,400);
    Scene = new QGraphicsScene(0,0,300,300);
    View = new QGraphicsView(Scene);
    View->scale(qreal(0.9), qreal(0.9));
    Timer = new QTimer();
    connect(Timer, SIGNAL(timeout()),this, SLOT(myTimer()));
    Timer->start(0);
    ui->statusBar->showMessage(trUtf8("Ingrese un número de vértices y presione Generar"),0);
    graph  = NULL;
    solutionGraph = NULL;
    createInterface();
}


// Destructor
MainWindow::~MainWindow()
{
    delete View;
    delete Timer;
    if (graph != NULL)
        delete graph;
    delete centralLayout;
    delete Scene;
    delete ui;
}


// Método modificador
void MainWindow::createInterface()
{
    View->setRenderHint(QPainter::Antialiasing);
    View->setMinimumSize(380, 200);
    centralLayout = new QHBoxLayout();
    centralLayout->addWidget(View);
    centralLayout->addStretch();
    ui->viewContentLayout->addLayout(centralLayout);
}


// Método observador
void MainWindow::startWindow() const
{
    QMessageBox ventanaInicio;
    ventanaInicio.setContentsMargins(0,10,20,10);
    ventanaInicio.setWindowTitle("El Problema del Vendedor Viajero");
    ventanaInicio.setText(trUtf8("<b>El problema del Vendedor Viajero<br/>(<i>Travel Salesman Problem</i> o <i>TSP</i> en inglés)</b><br/><br/>Se trata de un vendedor viajero que intenta hallar el camino de menor costo que lo hace pasar por todas las ciudades de un mapa, exactamente una vez, partiendo de una ciudad determinada y retornando a la misma al finalizar su recorrido.<br/> En pocas palabras, debe encontrar un ciclo hamiltoniano.<br/><br/>En este programa se pretende llegar la solución modelando el mapa como un grafo, donde:<br/>+Los vértices representan ciudades.<br/>+Los arcos que unen vértices, representan la existencia de un camino directo entre las ciudades alcanzadas por el arco.<br/>+Los rótulos de los arcos representan el costo de atravesar ese camino. Puede tomarse como un costo en kilómetros, costo de un pasaje en avión, etc.<br/><br/>En este programa, tratamos específicamente el TSP Simétrico (es decir, que modelaremos el mapa con un grafo no dirigido).<br/>Además, aplicamos la restricción de que cada ciudad contará con un camino directo a todas las otras ciudades (es decir, que nuestro grafo será completamente conexo).<br/><br/>Sin más que decir, de click en OK y podrá comenzar con las pruebas."));
    ventanaInicio.exec();
}


// Método privado
void MainWindow::scaleView(qreal scaleFactor)
{
    View->scale(scaleFactor, scaleFactor);
}


// Métodos relacionados a las acciones de los botones
void MainWindow::myTimer()
{
    Scene->update();
}

void MainWindow::on_pushButton_clicked()
{
   if (graph != NULL) {
        delete graph;
        graph = NULL;
   }

   Scene->clear();
   if((ui->nVertex->text().toInt())>0)
    {
        graph = new Graph(Scene, ui->nVertex->text().toInt());
        graph->addVertex(Scene);
        graph->allocateEdges();
        ui->statusBar->showMessage("Presione y arrastre los nodos para modelar el grafo",0);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(graph != NULL)
    {
        solutionGraph = new TSPGraph(graph->getNVertex(),graph->getVector());
        ui->statusBar->showMessage("Costo total del ciclo Hamiltoniano: " + QString::number(solutionGraph->costoCiclo()));
        if(graph->getNVertex() > 1)
            graph->drawPath(solutionGraph->recorrido());

        delete solutionGraph;
        solutionGraph = NULL;
    }
}

void MainWindow::on_zoomIn_clicked()
{
    scaleView(qreal(1.2));
}

void MainWindow::on_zoomOut_clicked()
{
    scaleView(1 / qreal(1.2));
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionAbout_2_triggered()
{
    QMessageBox About;
    About.setContentsMargins(0,10,20,10);
    About.setWindowTitle("Acerca del TSP Solver");
    About.setText(trUtf8("Este es un trabajo práctico de promoción para la cátedra Análisis y Diseño de Algoritmos I de la Universidad Nacional del Centro de la Provincia de Buenos Aires, realizado por Mirko Hrubik y Lucas Obyszuk.<br/><br/>Desarrollado con:<br/><br/>Qt 5.1.0<br/>Qt Creator 2.8.0<br/>MinGW 4.8 32 bits / GCC 4.8.1<br/><br/>Aquí puede descargar el programa o su código fuente:<br/><a href='http://sourceforge.net/projects/tspqt/'>http://sourceforge.net/projects/tspqt/</a>"));
    About.exec();
}

void MainWindow::on_actionInicio_triggered()
{
    startWindow();
}
