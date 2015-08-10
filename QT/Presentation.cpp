#include "Presentation.h"


Presentation::Presentation(MindMapModel* Mindmapmodel)
{
	this->Mindmapmodel = Mindmapmodel;
}
void Presentation::createEditCommand(string NewDescription, int EditNodeID)
{
	Commandmanager.execute(new EditComponentCommand(NewDescription, EditNodeID, Mindmapmodel));
}
void Presentation::createChangeParentCommand(int NodeID, int ParentNodeID)
{
	Commandmanager.execute(new ChangeParentCommand(NodeID, ParentNodeID, Mindmapmodel));
}
void Presentation::createDeleteCommand(int NodeID)
{
	Commandmanager.execute(new DeleteComponentCommand(NodeID, Mindmapmodel));
}
void Presentation::createInsertNodeChildCommand(string Description, int NodeID)
{
	Commandmanager.execute(new InsertNodeChildCommand(Description, NodeID, Mindmapmodel));
}
void Presentation::createInsertNodeSiblingCommand(string Description, int NodeID)
{
	Commandmanager.execute(new InsertNodeSiblingCommand(Description, NodeID, Mindmapmodel));
}
void Presentation::createInsertNodeParentCommand(string Description, int NodeID)
{ 
	Commandmanager.execute(new InsertNodeParentCommand(Description, NodeID, Mindmapmodel));
}
bool Presentation::redo()
{
	return Commandmanager.redo();
}
bool Presentation::undo()
{
	return Commandmanager.undo();
}
void Presentation::initialCommand()
{
	CommandManager NewCommandmanager;
	Commandmanager = NewCommandmanager;
}
string Presentation::displayMap()
{
	return Mindmapmodel->displayMap();
}
void Presentation::createMap(string Description)
{
	Mindmapmodel->createMindMap(Description);
}

bool Presentation::checkMindMapExist()
{
	return Mindmapmodel->checkMindMapExist();
}

string Presentation::getRootDescription()
{
	return Mindmapmodel->getRootDescription();
}
string Presentation::saveMindMap()
{
	return Mindmapmodel->saveMindMap();
}

bool Presentation::checkNodeExist(string StringID)
{
	return Mindmapmodel->checkNodeExist(StringID);
}
int Presentation::stringToInt(string String)
{
	return Mindmapmodel->stringToInt(String);
}
bool Presentation::checkCommandChoice(string CommandChoice, int NodeID)
{
	return Mindmapmodel->checkCommandChoice(CommandChoice, NodeID);
}
bool Presentation::loadMindMap(string Path)
{
	return Mindmapmodel->loadMindMap(Path);
}
bool Presentation::checkInsertNode(string ChoiceNode, int NodeID)
{
	return Mindmapmodel->checkInsertNode(ChoiceNode, NodeID);
}