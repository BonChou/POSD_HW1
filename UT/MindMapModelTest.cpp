#include "MindMapModelTest.h"


MindMapModelTest::MindMapModelTest()
{
}
MindMapModelTest::~MindMapModelTest()
{
}
void MindMapModelTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
}

void MindMapModelTest::TearDown()
{
	delete Mindmapmodel;
}

TEST_F(MindMapModelTest, getMindMap)
{
	Mindmapmodel->createMindMap("Root");
	ASSERT_EQ(Mindmapmodel->getMindMap()[0]->getDescription(), "Root");
}
TEST_F(MindMapModelTest, createMindMap)
{
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 0);
	Mindmapmodel->createMindMap("Root");
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 1);
}
TEST_F(MindMapModelTest, createNode)
{
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 0);
	Mindmapmodel->createNode("Node1");
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 1);
}
TEST_F(MindMapModelTest, insertNodeChild)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), Mindmapmodel->MindMap[0]->getID());
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[0]->getID(), Mindmapmodel->MindMap[1]->getID());
}
TEST_F(MindMapModelTest, insertNodeSibling)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->insertNodeSibling(1, 2);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->ParentNode->getID(), Mindmapmodel->MindMap[0]->getID());
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[1]->getID(), Mindmapmodel->MindMap[2]->getID());
}
TEST_F(MindMapModelTest, insertNodeParent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->insertNodeParent(1, 2);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->ParentNode->getID(), Mindmapmodel->MindMap[0]->getID());
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), Mindmapmodel->MindMap[2]->getID());
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[0]->getID(), Mindmapmodel->MindMap[2]->getID());
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[0]->getID(), Mindmapmodel->MindMap[1]->getID());
}
TEST_F(MindMapModelTest, stringToInt)
{
	int StringToInt = Mindmapmodel->stringToInt("123");
	ASSERT_EQ(StringToInt,123);
}
TEST_F(MindMapModelTest, intTostr)
{
	int Integer = 123;
	string IntToString = Mindmapmodel->intTostr(Integer);
	ASSERT_EQ(IntToString, "123");
}
TEST_F(MindMapModelTest, getRootDescription)
{
	Mindmapmodel->createMindMap("Root");
	ASSERT_EQ(Mindmapmodel->getRootDescription(), "Root");
}
TEST_F(MindMapModelTest, checkNodeExist)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->createNode("Node2");
	ASSERT_TRUE(Mindmapmodel->checkNodeExist("1"));
	ASSERT_FALSE(Mindmapmodel->checkNodeExist("3"));
}
TEST_F(MindMapModelTest, checkMindMapExist)
{
	ASSERT_FALSE(Mindmapmodel->checkMindMapExist());
	Mindmapmodel->createMindMap("Root");
	ASSERT_TRUE(Mindmapmodel->checkMindMapExist());
}
TEST_F(MindMapModelTest, checkInsertNode)
{
	ASSERT_FALSE(Mindmapmodel->checkInsertNode(INSER_NODE_PARENT,0));
	Mindmapmodel->createMindMap("Root");
	ASSERT_FALSE(Mindmapmodel->checkInsertNode(INSER_NODE_PARENT, 0));
	ASSERT_FALSE(Mindmapmodel->checkInsertNode(INSER_NODE_SIBLING, 0));
	ASSERT_TRUE(Mindmapmodel->checkInsertNode(INSER_NODE_CHILD, 0));
	ASSERT_FALSE(Mindmapmodel->checkInsertNode(INSER_NODE_PARENT, 1));
	Mindmapmodel->createNode("Node1");
	ASSERT_TRUE(Mindmapmodel->checkInsertNode(INSER_NODE_PARENT, 1));
	ASSERT_TRUE(Mindmapmodel->checkInsertNode(INSER_NODE_SIBLING, 1));
	ASSERT_TRUE(Mindmapmodel->checkInsertNode(INSER_NODE_CHILD, 1));
	ASSERT_FALSE(Mindmapmodel->checkInsertNode(INSER_NODE_PARENT, 2));
	TearDown();
	SetUp();
	ASSERT_TRUE(Mindmapmodel->loadMindMap("..\\test_file.mm"));
}
TEST_F(MindMapModelTest, displayMap)
{
	ASSERT_EQ(Mindmapmodel->displayMap(), "MindMap is not exist!!\n");
	Mindmapmodel->createMindMap("Root");
	ASSERT_EQ(Mindmapmodel->displayMap(), "+-Root(Root,ID:0)\n");
}
TEST_F(MindMapModelTest, displayNodeList)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->displayMap();
	ASSERT_EQ(Mindmapmodel->CoutString, "+-Root(Root,ID:0)\n  +-Node1(Node,ID:1)\n  | +-Node2(Node,ID:2)\n  +-Node3(Node,ID:3)\n");
}
TEST_F(MindMapModelTest, saveLevelLineList)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
}
TEST_F(MindMapModelTest, saveMindMap)
{
	ASSERT_EQ(Mindmapmodel->saveMindMap(),"No MindMap!\n");
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_EQ(Mindmapmodel->saveMindMap(), "Save success!\n");
}
TEST_F(MindMapModelTest, loadMindMap)
{
	ASSERT_FALSE(Mindmapmodel->loadMindMap("C:\\MindMap\\file_not_exist.mm"));
	ASSERT_TRUE(Mindmapmodel->loadMindMap("..\\test_file.mm"));
}

TEST_F(MindMapModelTest, getRealNodeID)
{
	ASSERT_EQ(Mindmapmodel->getRealNodeID(0), NOTEXISTNODE);
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->createNode("Node2");
	ASSERT_EQ(Mindmapmodel->getRealNodeID(0), 0);
}
TEST_F(MindMapModelTest, checkCommandChoice)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	ASSERT_FALSE(Mindmapmodel->checkCommandChoice(CHANGE_PARENT,0));
	ASSERT_FALSE(Mindmapmodel->checkCommandChoice(DELETE_COMPONENT, 0));
	ASSERT_TRUE(Mindmapmodel->checkCommandChoice(DELETE_COMPONENT, 1));
}
TEST_F(MindMapModelTest, editComponent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	ASSERT_EQ(Mindmapmodel->editComponent("NewNode1", 1), "Node1");
}
TEST_F(MindMapModelTest, deleteComponent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->insertNodeSibling(1, 2);
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 3);
	Mindmapmodel->deleteComponent(1);
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 2);
}
TEST_F(MindMapModelTest, createComponent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeChild(1, 3);
	Mindmapmodel->createComponent(Mindmapmodel->deleteComponent(1));
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 4);
}
TEST_F(MindMapModelTest, changeParent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_FALSE(Mindmapmodel->changeParent(1, 3));
	TearDown();
	SetUp();
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_TRUE(Mindmapmodel->changeParent(1, 2));
}
TEST_F(MindMapModelTest, sortChangeParent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_FALSE(Mindmapmodel->sortChangeParent(Mindmapmodel->MindMap[1]->getNodeList(), FIRST_NODE, 3));
	TearDown();
	SetUp();
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_TRUE(Mindmapmodel->sortChangeParent(Mindmapmodel->MindMap[1]->getNodeList(), FIRST_NODE, 2));
	TearDown();
	SetUp();
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeChild(2, 3);
	ASSERT_TRUE(Mindmapmodel->sortChangeParent(Mindmapmodel->MindMap[1]->getNodeList(), FIRST_NODE, 3));
}
TEST_F(MindMapModelTest, changeParentInAnother)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->changeParentInAnother(1, 3);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->ParentNode->getID(), 1);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), 3);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->ParentNode->getID(), 0);
}
TEST_F(MindMapModelTest, changeParentInChild)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->changeParentInAnother(1, 3);
	Mindmapmodel->changeParentInChild(3, 2);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->ParentNode->getID(), 2);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->ParentNode->getID(), 1);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), 0);
}
TEST_F(MindMapModelTest, undoChangeParentInChild)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->changeParentInAnother(1, 3);
	Mindmapmodel->undoChangeParentInChild(3, 2, Mindmapmodel->changeParentInChild(3, 2));
	ASSERT_EQ(Mindmapmodel->MindMap[2]->ParentNode->getID(), 1);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getID(), 3);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->ParentNode->getID(), 0);
}

TEST_F(MindMapModelTest, setClonNodeID)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->setClonNodeID(Mindmapmodel->getMindMap()[1]->clon());
	ASSERT_EQ(Mindmapmodel->getMindMap()[4]->getID(), 4);
}

TEST_F(MindMapModelTest, initialPosition)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->initialPosition();
	ASSERT_EQ(Mindmapmodel->getMindMap()[0]->getX(), 0);
}

TEST_F(MindMapModelTest, sortChoiceNodeID)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_EQ(PLUS_ONE, Mindmapmodel->sortChoiceNodeID());
	Mindmapmodel->getMindMap()[1]->Select = true;
	ASSERT_EQ(1, Mindmapmodel->sortChoiceNodeID());
}

TEST_F(MindMapModelTest, cutComponent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->cutComponent(1);
	ASSERT_EQ(Mindmapmodel->displayMap(), "+-Root(Root,ID:0)\n");
}

TEST_F(MindMapModelTest, deleteClonNodeID)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->deleteClonNodeID(Mindmapmodel->getMindMap()[1]);
	ASSERT_EQ(Mindmapmodel->getMindMap().size(), 1);
}

TEST_F(MindMapModelTest, pasteComponent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->cutComponent(1);
	Mindmapmodel->pasteComponent(0);
	ASSERT_EQ(Mindmapmodel->displayMap(), "+-Root(Root,ID:0)\n  +-Node1(Node,ID:1)\n");
	Mindmapmodel->clonComponent(1);
	Mindmapmodel->pasteComponent(0);
	ASSERT_EQ(Mindmapmodel->displayMap(), "+-Root(Root,ID:0)\n  +-Node1(Node,ID:1)\n  +-Node1(Node,ID:2)\n");
}

TEST_F(MindMapModelTest, clonComponent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->clonComponent(1);
	Mindmapmodel->pasteComponent(0);
	ASSERT_EQ(Mindmapmodel->getMindMap().size(),6);
}

TEST_F(MindMapModelTest, copyGraphicComponent)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->copyGraphicComponent(1);
	Mindmapmodel->clonComponent(1);
	Mindmapmodel->pasteComponent(0);
	ASSERT_EQ(Mindmapmodel->getMindMap().size(), 6);
}
TEST_F(MindMapModelTest, createGrahic)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createGrahic(CIRCLE, 0);
	Mindmapmodel->createGrahic(RECTANGLE, 0);
	Mindmapmodel->createGrahic(TRINAGLE, 0);
	ASSERT_EQ(Mindmapmodel->getMindMap()[0]->GraphicList[0]->getType(), CIRCLE);
}
TEST_F(MindMapModelTest, deleteGrahic)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createGrahic(CIRCLE, 0);
	Mindmapmodel->createGrahic(RECTANGLE, 0);
	Mindmapmodel->createGrahic(TRINAGLE, 0);
	Mindmapmodel->deleteGrahic(0);
	ASSERT_EQ(Mindmapmodel->getMindMap()[0]->GraphicList.size(), 2);
}
TEST_F(MindMapModelTest, sortNodeList)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	ASSERT_EQ(Mindmapmodel->sortNodeList(3),1);
}
TEST_F(MindMapModelTest, changeNodeListPosition)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeChild(1, 3);
	Mindmapmodel->changeNodeListPosition(0, 1, Mindmapmodel->getMindMap()[1]);
	ASSERT_EQ(Mindmapmodel->getMindMap()[1]->getNodeList()[0]->getID(), 3);

}
TEST_F(MindMapModelTest, expandGraphic)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->expandGraphic(0);
	ASSERT_EQ(Mindmapmodel->getMindMap()[1]->getX(), 0);
}
TEST_F(MindMapModelTest, collapseGraphic)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->collapseGraphic(0);
	ASSERT_EQ(Mindmapmodel->getMindMap()[1]->getX(), 0);
}
TEST_F(MindMapModelTest, changeIsExpandState)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->changeIsExpandState(Mindmapmodel->getMindMap()[0],true);
	ASSERT_EQ(Mindmapmodel->getMindMap()[1]->IsExpand, true);
}

TEST_F(MindMapModelTest, expandOneGraphic)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->expandOneGraphic(0);
	ASSERT_EQ(Mindmapmodel->getMindMap()[1]->getX(), 0);
}
TEST_F(MindMapModelTest, collapseOneGraphic)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Mindmapmodel->collapseOneGraphic(0);
	Mindmapmodel->initialPosition();
	ASSERT_EQ(Mindmapmodel->getMindMap()[1]->getX(), 0);
}