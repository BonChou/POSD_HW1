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
	if (CheckChangeParentType == true)//從自己兒子找到你要換的父親
		OldComponentChild = Mindmapmodel->changeParentInChild(NodeID, ParentNodeID);
	else
		ParentNodeID = Mindmapmodel->changeParentInAnother(NodeID, ParentNodeID);
}
void ChangeParentCommand::unexecute()
{ 
	if (CheckChangeParentType == true)//從自己兒子找到你要換的父親
		Mindmapmodel->undoChangeParentInChild(NodeID, ParentNodeID, OldComponentChild);
	else
		ParentNodeID = Mindmapmodel->changeParentInAnother(NodeID, ParentNodeID);
}