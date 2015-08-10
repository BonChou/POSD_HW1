#include "InsertNodeSiblingCommand.h"


InsertNodeSiblingCommand::InsertNodeSiblingCommand(string Description, int NodeID, MindMapModel* Mindmapmodel)
{
	this->NodeID = NodeID;
	this->Mindmapmodel = Mindmapmodel;
	this->Description = Description;
}
void InsertNodeSiblingCommand::execute()
{
	//cout << "InsertNodeSiblingCommand" << endl;
	DeleteNodeID = Mindmapmodel->createNode(Description);
	Mindmapmodel->insertNodeSibling(NodeID, DeleteNodeID);
	Mindmapmodel->initialPosition();
}
void InsertNodeSiblingCommand::unexecute()
{
	//cout << "UndoInsertNodeSiblingCommand" << endl;
	Mindmapmodel->deleteComponent(DeleteNodeID);
	Mindmapmodel->CreateNewNodeID--;
	Mindmapmodel->initialPosition();
}
