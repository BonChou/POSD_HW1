#include "CutNodeCommand.h"


CutNodeCommand::CutNodeCommand(int NodeID, MindMapModel* Mindmapmodel)
{
	this->NodeID = NodeID;
	this->Mindmapmodel = Mindmapmodel;

}

void CutNodeCommand::execute()
{
	//cout << "CutNodeCommand" << endl;
	int NodeIndex = Mindmapmodel->getRealNodeID(NodeID);
	this->PasteNode = Mindmapmodel->getMindMap()[NodeIndex];
	this->ParentNode = PasteNode->ParentNode;
	Mindmapmodel->cutComponent(NodeID);
	Mindmapmodel->initialPosition();
}
void CutNodeCommand::unexecute()
{
	//cout << "UndoCutNodeCommand" << endl;
	ParentNode->addChild(PasteNode);
	PasteNode->addParent(ParentNode);
	Mindmapmodel->initialPosition();
}