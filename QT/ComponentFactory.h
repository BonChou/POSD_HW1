#pragma once
#include "Root.h"
#include "Node.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Constants.h"
#include "gtest/gtest.h"
class ComponentFactory
{
public:
	ComponentFactory();
	Component *createNode(string, int);
	Component *createRoot(string, int);
	Component *createRectangle();
	Component *createCircle();
	Component *createTrinagle();
};

