#include "Component.h"
Component::Component()
{
	setX(0);
	setY(0);
}
void Component::setDescription(string Description)
{
	this->Description = Description;
}
string Component::getDescription()
{
	return Description;
}
string Component::getType()
{
	return Type;
}
void Component::setType(string Type)
{
	this->Type = Type;
}
int Component::getID()
{
	return this->ID;
}

void Component::setID(int ID)
{
	this->ID = ID;
}
void Component::setX(int X)
{
	this->X = X;
}

void Component::setY(int Y)
{
	this->Y = Y;
}

int Component::getX()
{
	return X;
}

int Component::getY()
{
	return Y;
}

void Component::clearGraphic()
{
	GraphicList.clear();
}
