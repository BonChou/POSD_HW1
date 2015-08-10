#include "DeleteComponentCommand.h"

DeleteComponentCommand::DeleteComponentCommand(int NodeID, MindMapModel* Mindmapmodel)
{
	this->NodeID = NodeID;
	this->Mindmapmodel = Mindmapmodel;
}

void DeleteComponentCommand::execute()
{
	//cout << "DeleteComponentCommand" << endl;
	BufferComponent = Mindmapmodel->deleteComponent(NodeID);
	Mindmapmodel->initialPosition();
}
void DeleteComponentCommand::unexecute()
{
	//cout << "UndoDeleteComponentCommand" << endl;
	NodeID = Mindmapmodel->createComponent(BufferComponent);
	Mindmapmodel->initialPosition();
} 
