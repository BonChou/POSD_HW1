#include "InsertNodeParentCommand.h"


InsertNodeParentCommand::InsertNodeParentCommand(string Description, int NodeID, MindMapModel* Mindmapmodel)
{
	this->NodeID = NodeID;
	this->Mindmapmodel = Mindmapmodel;
	this->Description = Description;
}
void InsertNodeParentCommand::execute()
{
	//cout << "InsertNodeParentCommand" << endl;
	CreateNodeID = Mindmapmodel->createNode(Description);
	Mindmapmodel->insertNodeParent(NodeID, CreateNodeID);
	Mindmapmodel->initialPosition();

}
void InsertNodeParentCommand::unexecute()
{
	//cout << "UndoInsertNodeParentCommand" << endl;
	Mindmapmodel->deleteComponent(CreateNodeID);
	Mindmapmodel->CreateNewNodeID--;
	Mindmapmodel->initialPosition();
}

