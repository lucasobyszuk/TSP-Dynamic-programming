TEMPLATE = app
TARGET = TrabajoAlgoritmosI
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += edge.h graph.h mainwindow.h tspgraph.h vertex.h
FORMS += mainwindow.ui
SOURCES += edge.cpp graph.cpp main.cpp mainwindow.cpp tspgraph.cpp vertex.cpp

QT += widgets

RC_FILE = tspico.rc
