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
	if (CheckChangeParentType == true)//�q�ۤv��l���A�n��������
		OldComponentChild = Mindmapmodel->changeParentInChild(NodeID, ParentNodeID);
	else
		ParentNodeID = Mindmapmodel->changeParentInAnother(NodeID, ParentNodeID);
}
void ChangeParentCommand::unexecute()
{ 
	if (CheckChangeParentType == true)//�q�ۤv��l���A�n��������
		Mindmapmodel->undoChangeParentInChild(NodeID, ParentNodeID, OldComponentChild);
	else
		ParentNodeID = Mindmapmodel->changeParentInAnother(NodeID, ParentNodeID);
}