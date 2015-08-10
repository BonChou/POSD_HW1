#include "InsertNodeChildCommand.h"


InsertNodeChildCommand::InsertNodeChildCommand(string Description, int NodeID, MindMapModel* Mindmapmodel)
{
	this->NodeID = NodeID;
	this->Mindmapmodel = Mindmapmodel;
	this->Description = Description;
}
void InsertNodeChildCommand::execute()
{
	//cout << "InsertNodeChildCommand" << endl;
	CreateNodeID = Mindmapmodel->createNode(Description);
	Mindmapmodel->insertNodeChild(NodeID, CreateNodeID);
	Mindmapmodel->initialPosition();
}
void InsertNodeChildCommand::unexecute()
{
	//cout << "UndoInsertNodeChildCommand" << endl;
	Mindmapmodel->deleteComponent(CreateNodeID);
	Mindmapmodel->CreateNewNodeID--;
	Mindmapmodel->initialPosition();
}
