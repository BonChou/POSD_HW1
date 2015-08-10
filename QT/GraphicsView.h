#pragma once
#include <QGraphicsView>
#include <QMouseEvent>
#include "QInputDialog.h"
#include "Component.h"
#include "Constants.h"
#include "GraphicComponent.h"
#include "GraphicPresentation.h"

class GraphicsView : public QGraphicsView
{
public:
	GraphicsView(QGraphicsScene*, QVector<QAction*> ,GraphicPresentation*);
	~GraphicsView();
	void drawDiagram(QVector<GraphicComponent*>);
	void clearScene();
private:
	GraphicPresentation* Gui_presentation;
	QGraphicsScene* Scene;
	QVector<QAction*> GraphicAction;
	void mouseMoveEvent(QMouseEvent* );
	void wheelEvent(QWheelEvent*);
	void mousePressEvent(QMouseEvent*);
};

