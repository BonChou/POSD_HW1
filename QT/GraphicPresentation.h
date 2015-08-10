#pragma once
#include "MindMapModel.h"
#include "Component.h"
#include "GraphicComponent.h"
#include "CommandManager.h"
#include "EditComponentCommand.h"
#include "ChangeParentCommand.h"
#include "DeleteComponentCommand.h"
#include "InsertNodeChildCommand.h"
#include "InsertNodeSiblingCommand.h"
#include "CutNodeCommand.h"
#include "InsertNodeParentCommand.h"
#include "PasteNodeCommand.h"
#include <QtWidgets/QWidgetAction>
#include "CreateGraphicCommand.h"
#include "NodeVisitor.h"
#include "DisplayNodeVisitor.h"
#include "SaveNodeVisitor.h"
class GraphicPresentation
{
public:
	GraphicPresentation(MindMapModel*);
	~GraphicPresentation();
	void loadMindMap(string);
	bool createRoot(string);
	void createChildNode(string);
	void createSilbing(string);
	void createParent(string);
	void deleteNode();
	string saveMindMap(string);
	void editDecription(string);
	void setGraphicAction(QVector<QAction*>);
	void Paste();
	void cutComponent();
	void clonComponent();
	bool redoCommand();
	bool undoCommand();
	int getModelUndoCommands();
	int getModelRedoCommands();
	void initialCommand();
	bool getClonFlag();
	QVector<GraphicComponent*> getGraphicComponentVector();
	QVector<GraphicComponent*> loadGraphicMindMap();
	void setGrphicComponent(Component*);
	void createGraphic(string);
	bool upGraphic();
	bool downGraphic();
	void expandGraphic();
	void collapseGraphic();
	void expandOneGraphic();
	void collapseOneGraphic();
	void clearGraphic();
private:
	QVector<GraphicComponent*> GraphicComponentVector;
	GraphicComponent* Graphiccomponent;
	MindMapModel *Mindmapmodel;
	QVector<QAction*> GraphicAction;
	CommandManager Commandmanager;
	Component* Last_ComponentPoint;
	Component* ChangedParenteNode;
	int CountY = ROOT_NODE; //計算Y的距離
	bool BoolCutOrCopy; //判斷是剪下還是貼上
};

