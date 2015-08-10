#include "PasteNodeCommand.h"


PasteNodeCommand::PasteNodeCommand(int NodeID, MindMapModel *Mindmapmodel)
{
	this->NodeID = NodeID;
	this->Mindmapmodel = Mindmapmodel;
}

void PasteNodeCommand::execute()
{
	this->PasteNode = Mindmapmodel->pasteComponent(NodeID);
	Mindmapmodel->initialPosition();
}
void PasteNodeCommand::unexecute()
{
	//cout << "UndoPasteNodeCommand" << endl;
	Mindmapmodel->undoPasteComponent(PasteNode);
	Mindmapmodel->initialPosition();
}