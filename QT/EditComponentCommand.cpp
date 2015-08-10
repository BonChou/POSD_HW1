#include "EditComponentCommand.h"


EditComponentCommand::EditComponentCommand(string NewDescription, int EditNodeID, MindMapModel *Mindmapmodel)
{
	this->NewDescription = NewDescription;
	this->EditNodeID = EditNodeID;
	this->Mindmapmodel = Mindmapmodel;
}
void EditComponentCommand::execute()
{
	OldDescription = Mindmapmodel->editComponent(NewDescription, EditNodeID);
	Mindmapmodel->initialPosition();
}
void EditComponentCommand::unexecute()
{
	NewDescription = Mindmapmodel->editComponent(OldDescription, EditNodeID);
	Mindmapmodel->initialPosition();
}