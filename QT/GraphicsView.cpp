#include "GraphicsView.h"
#include <QDebug>
GraphicsView::GraphicsView(QGraphicsScene* Scene, QVector<QAction*> GraphicAction, GraphicPresentation* Gui_presentation)
{
	this->Gui_presentation = Gui_presentation;
	this->GraphicAction = GraphicAction;
	this->Scene = Scene;
	this->setMouseTracking(true);
	this->setAlignment(Qt::AlignCenter);
	setScene(Scene);
}

GraphicsView::~GraphicsView(void)
{
	delete Scene;
}

void GraphicsView::wheelEvent(QWheelEvent* Event)
{
	QGraphicsView::wheelEvent(Event);
	QList<QGraphicsItem*> AllGraphicsItems = Scene->items();
	cout << " There are " << AllGraphicsItems.size() << " items." << endl;
	Scene->update();
}

void GraphicsView::mouseMoveEvent(QMouseEvent* Event)
{
	QGraphicsView::mouseMoveEvent(Event);
	Scene->update();
}

void GraphicsView::mousePressEvent(QMouseEvent* Event)
{
	QGraphicsView::mousePressEvent(Event);
	GraphicAction[DELETE_NUMBER]->setDisabled(true);
	GraphicAction[INSERT_CHILD_NUMBER]->setDisabled(true);
	GraphicAction[INSERT_SIBLING_NUMBER]->setDisabled(true);
	GraphicAction[INSERT_PARENT_NUMBER]->setDisabled(true);
	GraphicAction[EDIT_NUMBER]->setDisabled(true);
	GraphicAction[CUT_NUMBER]->setDisabled(true);
	GraphicAction[COPY_NUMBER]->setDisabled(true);
	QList<QGraphicsItem*> AllGraphicsItems = Scene->items();
	cout << " There are " << AllGraphicsItems.size() << " items." << endl;
}

void GraphicsView::drawDiagram(QVector<GraphicComponent*> GraphicComponentVector)
{
	if (Gui_presentation->getClonFlag())
		GraphicAction[PASTE_NUMBER]->setDisabled(false);
	

	clearScene();
	for (unsigned int index = ZERO; index < GraphicComponentVector.size(); index++)
	{
		Scene->addItem(GraphicComponentVector[index]);
		Scene->update();
	}
	this->update();
}
void GraphicsView::clearScene()
{
	QList<QGraphicsItem*> AllGraphicsItems = Scene->items();
	for (int count = ZERO; count < AllGraphicsItems.size(); count++)
	{
		QGraphicsItem *GraphicItem = AllGraphicsItems[count];
		Scene->removeItem(GraphicItem);
	}
} 