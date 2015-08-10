#include "DisplayNodeVisitor.h"


DisplayNodeVisitor::DisplayNodeVisitor()
{
}


DisplayNodeVisitor::~DisplayNodeVisitor()
{
}

void DisplayNodeVisitor::visitor(Root* Component)
{
	int IntToStrNode = Component->getID();
	CoutString = "+-" + Component->getDescription() + "(" + Component->getType() + ",ID:" + intTostr(IntToStrNode) + ")\n";
}
void DisplayNodeVisitor::visitor(Node* Component)
{
	int IntToStrNode = Component->getID();
	CoutString = "+-" + Component->getDescription() + "(" + Component->getType() + ",ID:" + intTostr(IntToStrNode) + ")\n";
}

string DisplayNodeVisitor::getCoutString()
{
	return CoutString;
}

string DisplayNodeVisitor::intTostr(int &Index)
{
	string String;
	stringstream Convert(String);
	Convert << Index;
	return Convert.str();
}