#include "GraphicComponent.h"
#include <QtDebug>

const int FONT_SIZE = 20;
const int TWO = 2;
const int SELECT_FONT_SIZE = 3;
const int LENGH_MAX = 150;
const int WIDTH_MAX = 10;
const string CHANGE_LINE = "\n";
int Lengh = 90;
int Width = 60;

GraphicComponent::GraphicComponent(Component* component, QVector<QAction*> GraphicAction)
{
	this->component = component;
	GraphicDescription = changeLine(component->getDescription());
	nodeResizing();
	path.addRect(ZERO, ZERO, this->component->Lengh, this->component->Width);

	for (int GraphicIndex = 0; GraphicIndex < this->component->GraphicList.size(); GraphicIndex++)
	{
		this->component->GraphicList[GraphicIndex]->GraphicCount = GraphicIndex*10;
		drawGraphic(this->component->GraphicList[GraphicIndex]->draw());
		GraphicCount++;
	}
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	this->GraphicAction = GraphicAction;
}
void GraphicComponent::drawGraphic(string GraphicType)
{
	if (GraphicType.compare(CIRCLE) == 0)
	{
		path.addEllipse(0, 0, Lengh + GraphicCount, Lengh + GraphicCount);
	}
	if (GraphicType.compare(RECTANGLE) == 0)
	{
		path.addRect(0, 0, Lengh + 10 + GraphicCount, Width + 10 + GraphicCount);
	}
	if (GraphicType.compare(TRINAGLE) == 0)
	{
		QPointF p1(Lengh / 2, -15 - GraphicCount);
		QPointF p2(0, Width + 15 + GraphicCount);
		QPointF p3(Lengh + GraphicCount, Width + 15 + GraphicCount);
		path.addPolygon(QPolygonF() << p1 << p2 << p3 << p1);

	}
}

void GraphicComponent::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	this->painter = painter;
	this->acceptTouchEvents();
	this->component->Select = false;
	font.setPixelSize(FONT_SIZE);
	pen.setColor(Qt::black);
	painter->setFont(font);
	painter->setPen(pen);
	painter->drawPath(path);

	if (this->component->ParentNode != NULL)
	{
		int PositionX = this->component->getX() - this->component->ParentNode->getX();
		int PositionY = this->component->getY() - this->component->ParentNode->getY();
		//painter->drawLine(ZERO, Width, -PositionX + Lengh, -PositionY + Width / 2);
		painter->drawLine(ZERO, ZERO, -PositionX, -PositionY);
	}

	painter->drawText(boundingRect(), Qt::AlignCenter, QString::fromStdString(GraphicDescription));

	if (this->isSelected())
	{
		this->component->Select = true;
		changeQActionState();
		painter->setPen(QPen(Qt::green, SELECT_FONT_SIZE));
		painter->drawPath(path);
	}
	this->update();
}

void GraphicComponent::changeQActionState()
{
	if (this->component->getID() == ZERO)
	{
		GraphicAction[DELETE_NUMBER]->setDisabled(true);
		GraphicAction[INSERT_CHILD_NUMBER]->setDisabled(false);
		GraphicAction[INSERT_SIBLING_NUMBER]->setDisabled(true);
		GraphicAction[INSERT_PARENT_NUMBER]->setDisabled(true);
		GraphicAction[EDIT_NUMBER]->setDisabled(false);
		GraphicAction[RECTANGLE_NUMBER]->setDisabled(false);
		GraphicAction[CIRCLE_NUMBER]->setDisabled(false);
		GraphicAction[TRINAGLE_NUMBER]->setDisabled(false);
		GraphicAction[CUT_NUMBER]->setDisabled(true);
		GraphicAction[COPY_NUMBER]->setDisabled(true);
		GraphicAction[UP_NUMBER]->setDisabled(true);
		GraphicAction[DOWN_NUMBER]->setDisabled(true);
		GraphicAction[CLEAR_NUMBER]->setDisabled(false);
	}
	else
	{
		GraphicAction[DELETE_NUMBER]->setDisabled(false);
		GraphicAction[INSERT_CHILD_NUMBER]->setDisabled(false);
		GraphicAction[INSERT_SIBLING_NUMBER]->setDisabled(false);
		GraphicAction[INSERT_PARENT_NUMBER]->setDisabled(false);
		GraphicAction[EDIT_NUMBER]->setDisabled(false);
		GraphicAction[CUT_NUMBER]->setDisabled(false);
		GraphicAction[COPY_NUMBER]->setDisabled(false);
		GraphicAction[RECTANGLE_NUMBER]->setDisabled(false);
		GraphicAction[CIRCLE_NUMBER]->setDisabled(false);
		GraphicAction[TRINAGLE_NUMBER]->setDisabled(false);
		GraphicAction[UP_NUMBER]->setDisabled(false);
		GraphicAction[DOWN_NUMBER]->setDisabled(false);
		GraphicAction[CLEAR_NUMBER]->setDisabled(false);
	}
	if (this->component->PasteState == true)
		GraphicAction[PASTE_NUMBER]->setDisabled(false);
	else
		GraphicAction[PASTE_NUMBER]->setDisabled(true);
	if (this->component->isCollapsed == true)
		GraphicAction[EXPAND_NUMBER]->setDisabled(false);
	else
	{
		GraphicAction[COLLAPSE_NUMBER]->setDisabled(false);

		if (this->component->isCollapsedOne == true)
			GraphicAction[EXPAND_ONE_NUMBER]->setDisabled(false);
		else
			GraphicAction[COLLAPSE_ONE_NUMBER]->setDisabled(false);
	}

}
bool GraphicComponent::sortMindMapCopyState(Component* component)
{
	Component* TempComponent;
	int Index = 0;
	while (Index < component->getNodeList().size())
	{
		if (component->getNodeList()[Index]->Copystate == true)
			return true;
		TempComponent = component->getNodeList()[Index];
		if (sortMindMapCopyState(TempComponent) == true)
			return true;
		Index++;
	}
	return false;
}

QPainterPath GraphicComponent::shape() const
{
	return path;
}

QRectF GraphicComponent::boundingRect() const
{
	return path.boundingRect();
}

void GraphicComponent::wheelEvent(QGraphicsSceneWheelEvent* Event)
{
	QGraphicsItem::wheelEvent(Event);
	this->update();
}

void GraphicComponent::mouseMoveEvent(QGraphicsSceneMouseEvent* Event)
{
	QGraphicsItem::mouseMoveEvent(Event);
	this->update();
}

void GraphicComponent::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	QGraphicsItem::mousePressEvent(mouseEvent);
	cout << component->getID();
	this->update();
}

void GraphicComponent::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* mouseEvent)
{
	QGraphicsItem::mouseDoubleClickEvent(mouseEvent);
	GraphicAction[EDIT_NUMBER]->trigger();
}

void GraphicComponent::nodeResizing()
{
	this->component->Lengh = component->getDescription().size()*this->component->Lengh + this->component->Lengh;
	if (this->component->Lengh > LENGH_MAX)
		this->component->Lengh = LENGH_MAX;
}
string GraphicComponent::changeLine(string Description) 
{
	int Count = ZERO;
	if (Description.length() > WIDTH_MAX)
	{
		for (int Index = ZERO; Index < Description.length(); Index++)
		{
			if (Index % WIDTH_MAX == ZERO)
			{
				Description.insert(Index, CHANGE_LINE);
				Count++;
			}
		}
	}
	this->component->Width = Count*this->component->Width + this->component->Width;
	return Description;
}
