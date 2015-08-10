#include "GraphicPresentation.h"

GraphicPresentation::GraphicPresentation(MindMapModel *Mindmapmodel)
{
	this->Mindmapmodel = Mindmapmodel;
}
GraphicPresentation::~GraphicPresentation()
{

}
QVector<GraphicComponent*> GraphicPresentation::getGraphicComponentVector()
{
	return loadGraphicMindMap();
}
QVector<GraphicComponent*> GraphicPresentation::loadGraphicMindMap()
{
	QVector<GraphicComponent*> InitialGraphicComponentVector;
	GraphicComponentVector = InitialGraphicComponentVector;
	if (Mindmapmodel->PasteFlag == true)
		Mindmapmodel->getMindMap()[ROOT_NODE]->PasteState = true;
	Graphiccomponent = new GraphicComponent(Mindmapmodel->getMindMap()[ROOT_NODE], GraphicAction);
	Graphiccomponent->setPos(Mindmapmodel->getMindMap()[ROOT_NODE]->getX(), Mindmapmodel->getMindMap()[ROOT_NODE]->getY());
	GraphicComponentVector.push_back(Graphiccomponent);
	setGrphicComponent(Mindmapmodel->getMindMap()[ROOT_NODE]);
	return GraphicComponentVector;
}
void GraphicPresentation::setGrphicComponent(Component* ComponentPoint)
{
	int Index = ZERO;
	while (Index < ComponentPoint->getNodeList().size())
	{
		if (Mindmapmodel->PasteFlag == true)
			ComponentPoint->getNodeList()[Index]->PasteState = true;
		if (ComponentPoint->getNodeList()[Index]->IsExpand == true)
		{
			Graphiccomponent = new GraphicComponent(ComponentPoint->getNodeList()[Index], GraphicAction);
			Graphiccomponent->setPos(ComponentPoint->getNodeList()[Index]->getX(), ComponentPoint->getNodeList()[Index]->getY());
			GraphicComponentVector.push_back(Graphiccomponent);
		}
		setGrphicComponent(ComponentPoint->getNodeList()[Index]);
		Index++;
	}
}
void GraphicPresentation::loadMindMap(string Path)
{
	Mindmapmodel->loadMindMap(Path);
	Mindmapmodel->initialPosition();
}
string GraphicPresentation::saveMindMap(string Path)
{
	return Mindmapmodel->saveMindMap(Path);
}

bool GraphicPresentation::createRoot(string Description)
{
	if (Mindmapmodel->getMindMap().size() == ZERO)
	{
		Mindmapmodel->createMindMap(Description);
		Mindmapmodel->initialPosition();
		return true;
	}
	return false;
}

void GraphicPresentation::editDecription(string NewDescription)
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Commandmanager.execute(new EditComponentCommand(NewDescription, ChoiceNodeID, Mindmapmodel));
	Mindmapmodel->initialPosition();
}

void GraphicPresentation::createChildNode(string Description)
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Commandmanager.execute(new InsertNodeChildCommand(Description, ChoiceNodeID, Mindmapmodel));
	Mindmapmodel->initialPosition();
}

void GraphicPresentation::createSilbing(string Description)
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Commandmanager.execute(new InsertNodeSiblingCommand(Description, ChoiceNodeID, Mindmapmodel));
	Mindmapmodel->initialPosition();
}
void GraphicPresentation::createParent(string Description)
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Commandmanager.execute(new InsertNodeParentCommand(Description, ChoiceNodeID, Mindmapmodel));
	Mindmapmodel->initialPosition();
}

void GraphicPresentation::deleteNode()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Commandmanager.execute(new DeleteComponentCommand(ChoiceNodeID, Mindmapmodel));
	Mindmapmodel->initialPosition();
}

void GraphicPresentation::setGraphicAction(QVector<QAction*> GraphicAction)
{
	this->GraphicAction = GraphicAction;
}
void GraphicPresentation::cutComponent()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Commandmanager.execute(new CutNodeCommand(ChoiceNodeID, Mindmapmodel));
	Mindmapmodel->initialPosition();
}

void GraphicPresentation::Paste()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Commandmanager.execute(new PasteNodeCommand(ChoiceNodeID, Mindmapmodel));
	Mindmapmodel->initialPosition();
}

void GraphicPresentation::clonComponent()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Mindmapmodel->clonComponent(ChoiceNodeID);
	Mindmapmodel->initialPosition();
}

bool GraphicPresentation::redoCommand()
{
	return Commandmanager.redo();
}
bool GraphicPresentation::undoCommand()
{
	return Commandmanager.undo();
}

int GraphicPresentation::getModelUndoCommands()
{
	return Commandmanager.getModelUndoCommands();
}
int GraphicPresentation::getModelRedoCommands()
{
	return Commandmanager.getModelRedoCommands();
}

void GraphicPresentation::initialCommand()
{
	CommandManager NewCommandmanager;
	Commandmanager = NewCommandmanager;
}

bool GraphicPresentation::getClonFlag()
{
	return Mindmapmodel->ClonFlag;
}

void GraphicPresentation::createGraphic(string Type)
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Commandmanager.execute(new CreateGraphicCommand(Mindmapmodel, Type, ChoiceNodeID));
	Mindmapmodel->initialPosition();
}
bool GraphicPresentation::upGraphic()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	int ChoiceNodeListIndex = Mindmapmodel->sortNodeList(ChoiceNodeID);
	int ChoiceNodeIndex = Mindmapmodel->getRealNodeID(ChoiceNodeID);
	Component* ParentNode = Mindmapmodel->getMindMap()[ChoiceNodeIndex]->ParentNode;
	if (ChoiceNodeListIndex - 1 >= 0)
		Mindmapmodel->changeNodeListPosition(ChoiceNodeListIndex - 1, ChoiceNodeListIndex, ParentNode);
	else
		return false;
	Mindmapmodel->initialPosition();
	return true;
}
bool GraphicPresentation::downGraphic()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	int ChoiceNodeListIndex = Mindmapmodel->sortNodeList(ChoiceNodeID);
	int ChoiceNodeIndex = Mindmapmodel->getRealNodeID(ChoiceNodeID);
	Component* ParentNode = Mindmapmodel->getMindMap()[ChoiceNodeIndex]->ParentNode;
	if (ChoiceNodeListIndex + 1 < ParentNode->getNodeList().size())
		Mindmapmodel->changeNodeListPosition(ChoiceNodeListIndex, ChoiceNodeListIndex + 1, ParentNode);
	else
		return false;
	Mindmapmodel->initialPosition();
	return true;
}
void GraphicPresentation::expandGraphic()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Mindmapmodel->expandGraphic(ChoiceNodeID);
	Mindmapmodel->initialPosition();
}
void GraphicPresentation::collapseGraphic()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Mindmapmodel->collapseGraphic(ChoiceNodeID);
	Mindmapmodel->initialPosition();
}

void GraphicPresentation::expandOneGraphic()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Mindmapmodel->expandOneGraphic(ChoiceNodeID);
	Mindmapmodel->initialPosition();
}
void GraphicPresentation::collapseOneGraphic()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	Mindmapmodel->collapseOneGraphic(ChoiceNodeID);
	Mindmapmodel->initialPosition();
}
void GraphicPresentation::clearGraphic()
{
	int ChoiceNodeID = Mindmapmodel->sortChoiceNodeID();
	int ChoiceNodeIndex = Mindmapmodel->getRealNodeID(ChoiceNodeID);
	Mindmapmodel->getMindMap()[ChoiceNodeIndex]->clearGraphic();
	Mindmapmodel->initialPosition();

}
