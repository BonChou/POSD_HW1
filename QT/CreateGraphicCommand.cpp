#include "CreateGraphicCommand.h"


CreateGraphicCommand::CreateGraphicCommand(MindMapModel* Mindmapmodel,string Type,int NodeID)
{
	this->NodeID = NodeID;
	this->Mindmapmodel = Mindmapmodel;
	this->Type = Type;
}
void CreateGraphicCommand::execute()
{
	//cout << "CreateGraphicCommand" << endl;
	Mindmapmodel->createGrahic(Type, NodeID);
	Mindmapmodel->initialPosition();
}
void CreateGraphicCommand::unexecute()
{
	//cout << "UndoInsertNodeChildCommand" << endl;
	Mindmapmodel->deleteGrahic(NodeID);
	Mindmapmodel->initialPosition();
}
