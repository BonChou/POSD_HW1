#pragma once
#include <QGraphicsItem>
#include <QPainter>
#include "Component.h"
#include "Constants.h"
#include <QtWidgets/QWidgetAction>
class GraphicComponent : public QGraphicsItem
{
public:
	GraphicComponent(Component*, QVector<QAction*>);
	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
	QRectF boundingRect() const;
	Component* component;
	QPainterPath path;
	QPainterPath shape() const;
	void selectState(QPainter*);
	void mouseMoveEvent(QGraphicsSceneMouseEvent*);
	void wheelEvent(QGraphicsSceneWheelEvent*);
	void mousePressEvent(QGraphicsSceneMouseEvent*);
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent*);
	void changeQActionState();
	void nodeResizing();
	void drawGraphic(string);
	string changeLine(string);
	string GraphicDescription;
	bool sortMindMapCopyState(Component* component);
private:
	QVector<QAction*> GraphicAction;
	QPen pen;
	QFont font;
	QPainter* painter;
	int GraphicCount = 0;
};