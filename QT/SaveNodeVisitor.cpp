#include "SaveNodeVisitor.h"


SaveNodeVisitor::SaveNodeVisitor()
{
}


SaveNodeVisitor::~SaveNodeVisitor()
{
}

void SaveNodeVisitor::visitor(Root* Component)
{
	int IntToStrNode = Component->getID();
	CoutString = intTostr(IntToStrNode) + " \"" + Component->getDescription() + "\" ";
	for (unsigned int IndexList = ZERO; IndexList < Component->getNodeList().size(); IndexList++)
	{
		IntToStrNode = Component->getNodeList()[IndexList]->getID();
		CoutString += intTostr(IntToStrNode) + " ";
	}
	CoutString += "/";
	for (unsigned int IndexList = ZERO; IndexList < Component->GraphicList.size(); IndexList++)
		CoutString += Component->GraphicList[IndexList]->getType() + "/";

	
}
void SaveNodeVisitor::visitor(Node* Component)
{
	int IntToStrNode = Component->getID();
	CoutString = "\n";
	CoutString += intTostr(IntToStrNode) + " \"" + Component->getDescription() + "\" ";
	for (unsigned int IndexList = ZERO; IndexList < Component->getNodeList().size(); IndexList++)
	{
		IntToStrNode = Component->getNodeList()[IndexList]->getID();
		CoutString += intTostr(IntToStrNode) + " ";
	}
	CoutString += "/";
	for (unsigned int IndexList = ZERO; IndexList < Component->GraphicList.size(); IndexList++)
		CoutString += Component->GraphicList[IndexList]->getType() + "/";

}
string SaveNodeVisitor::getCoutString()
{ 
	return CoutString;
}
string SaveNodeVisitor::intTostr(int &Index)
{
	string String;
	stringstream Convert(String);
	Convert << Index;
	return Convert.str();
}