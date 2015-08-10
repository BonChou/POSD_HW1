#include "ChangeParentCommand.h"


ChangeParentCommand::ChangeParentCommand(int NodeID, int ParentNodeID, MindMapModel *Mindmapmodel)
{
	this->NodeID = NodeID;
	this->ParentNodeID = ParentNodeID;
	this->Mindmapmodel = Mindmapmodel;
}
void ChangeParentCommand::execute()
{
	CheckChangeParentType = Mindmapmodel->changeParent(NodeID, ParentNodeID);
	if (CheckChangeParentType == true)//眖ㄠт璶传克
		OldComponentChild = Mindmapmodel->changeParentInChild(NodeID, ParentNodeID);
	else
		ParentNodeID = Mindmapmodel->changeParentInAnother(NodeID, ParentNodeID);
}
void ChangeParentCommand::unexecute()
{ 
	if (CheckChangeParentType == true)//眖ㄠт璶传克
		Mindmapmodel->undoChangeParentInChild(NodeID, ParentNodeID, OldComponentChild);
	else
		ParentNodeID = Mindmapmodel->changeParentInAnother(NodeID, ParentNodeID);
}