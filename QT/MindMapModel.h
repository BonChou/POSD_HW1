#pragma once
#include<string>
#include<vector>
#include "Component.h"
#include "Constants.h"
#include "ComponentFactory.h"
#include "CommandManager.h"
#include "DisplayNodeVisitor.h"
#include "SaveNodeVisitor.h"
#include "NodeVisitor.h"
#include <fstream>
#include "gtest/gtest.h"
#include "Subject.h"
#include<sstream>
using namespace std;
class MindMapModel :public Subject
{
	friend class MindMapModelTest;
	FRIEND_TEST(MindMapModelTest, createMindMap);
	FRIEND_TEST(MindMapModelTest, createNode);
	FRIEND_TEST(MindMapModelTest, insertNodeChild);
	FRIEND_TEST(MindMapModelTest, insertNodeSibling);
	FRIEND_TEST(MindMapModelTest, insertNodeParent);
	FRIEND_TEST(MindMapModelTest, displayNodeList);
	FRIEND_TEST(MindMapModelTest, saveLevelLineList);
	FRIEND_TEST(MindMapModelTest, deleteComponent);
	FRIEND_TEST(MindMapModelTest, createComponent);
	FRIEND_TEST(MindMapModelTest, sortChangeParent);
	FRIEND_TEST(MindMapModelTest, changeParentInChild);
	FRIEND_TEST(MindMapModelTest, changeParentInAnother);
	FRIEND_TEST(MindMapModelTest, undoChangeParentInChild);
	FRIEND_TEST(MindMapModelTest, pasteComponent);

	friend class ChangeParentCommandTest;
	FRIEND_TEST(ChangeParentCommandTest, execute);
	FRIEND_TEST(ChangeParentCommandTest, unexecute);

	friend class DeleteComponentCommandTest;
	FRIEND_TEST(DeleteComponentCommandTest, execute);
	FRIEND_TEST(DeleteComponentCommandTest, unexecute);

	friend class EditComponentCommandTest;
	FRIEND_TEST(EditComponentCommandTest, execute);
	FRIEND_TEST(EditComponentCommandTest, unexecute);

	friend class InsertNodeChildCommandTest;
	FRIEND_TEST(InsertNodeChildCommandTest, execute);
	FRIEND_TEST(InsertNodeChildCommandTest, unexecute);

	friend class InsertNodeParentCommandTest;
	FRIEND_TEST(InsertNodeParentCommandTest, execute);
	FRIEND_TEST(InsertNodeParentCommandTest, unexecute);

	friend class InsertNodeSiblingCommandTest;
	FRIEND_TEST(InsertNodeSiblingCommandTest, execute);
	FRIEND_TEST(InsertNodeSiblingCommandTest, unexecute);

	friend class CommandManagerTest;
	FRIEND_TEST(CommandManagerTest, execute);
	FRIEND_TEST(CommandManagerTest, unexecute);
	FRIEND_TEST(CommandManagerTest, redo);
	FRIEND_TEST(CommandManagerTest, undo);

	friend class CompositeTest;
	FRIEND_TEST(CompositeTest, addChild);

	friend class PresentationTest;
	FRIEND_TEST(PresentationTest, createEditCommand);
	FRIEND_TEST(PresentationTest, createChangeParentCommand);
	FRIEND_TEST(PresentationTest, createDeleteCommand);
	FRIEND_TEST(PresentationTest, createInsertNodeChildCommand);
	FRIEND_TEST(PresentationTest, createInsertNodeSiblingCommand);
	FRIEND_TEST(PresentationTest, createInsertNodeParentCommand);

	friend class IntegrationTest;
	FRIEND_TEST(IntegrationTest, testLoadFileNotExist);
	FRIEND_TEST(IntegrationTest, testUndoDeleteNode);
	FRIEND_TEST(IntegrationTest, testRedoDeleteNode);
	FRIEND_TEST(IntegrationTest, testChangeNodeParent);

	friend class RootTest;
	FRIEND_TEST(RootTest, addParent);

	friend class NodeTest;
	FRIEND_TEST(NodeTest, addParent);
public:
	MindMapModel();
	~MindMapModel();
	void createMindMap(string);
	string saveMindMap();
	int createNode(string);
	bool checkNodeExist(string);
	bool checkMindMapExist();
	bool checkInsertNode(string,int);
	int stringToInt(string);
	string intTostr(int &);
	string displayMap();
	string getRootDescription();
	vector<Component*> changeParentInChild(int, int);
	void displayNodeList(vector<Component*>, unsigned int);
	void saveLevelLineList(Component*);
	bool checkCommandChoice(string, int);
	string editComponent(string,int);
	bool changeParent(int, int);
	bool sortChangeParent(vector<Component*>, unsigned int, int);
	Component* deleteComponent(int);
	int changeParentInAnother(int, int);
	int createComponent(Component*);
	void undoChangeParentInChild(int, int, vector<Component*>);
	int getRealNodeID(int);
	void insertNodeChild(int, int);
	void insertNodeSibling(int, int);
	void insertNodeParent(int, int);
	int CreateNewNodeID = NODE_NODE;
	vector<Component*> getMindMap();
	string saveMindMap(string);
	bool loadMindMap(string );
	void buildTree(vector<string> );
	void cutIdLine(vector<string> );
	void bulidChild(int , string );

	void setClonNodeID(Component*);
	void deleteClonNodeID(Component*);
	void initialPosition();
	void setPositionX(Component*);
	void setIsExpandPosition(Component*);
	void setPositionY(Component*);
	int sortChoiceNodeID();
	void editDecription(string);
	void cutComponent(int);
	void changeCopyComponentState(Component*);
	void clonComponent(int);
	void sortClonNode(Component* );
	void undoDeleteGraphicComponent(int);
	Component* PasteNode;
	Component* pasteComponent(int);
	void undoPasteComponent(Component*);
	bool ClonFlag = false;
	bool PasteFlag = false;
	void copyGraphicComponent(int);
	void createGrahic(string,int);
	void deleteGrahic(int);
	int sortNodeList(int);
	void changeNodeListPosition(int, int, Component*);
	void expandGraphic(int);
	void collapseGraphic(int);
	void changeIsExpandState(Component*,bool);
	void expandOneGraphic(int);
	void collapseOneGraphic(int);
	void cutGraphicLine(vector<string>);
	void bulidGraphic(int, string);

private:
	int CountX = ZERO;
	int ClonCount = ZERO;
	int DeleteNodeIndex;
	int PosCountY = ZERO;
	int NegCountY = ZERO;
	NodeVisitor *Visitor;
	vector<Component*>MindMap;
	ComponentFactory CreatMap;
	Component* PointNode;
	Component* OldPointer;
	string CoutString;
	int Level = ZERO;
	vector<bool>LevelLineList;
};

