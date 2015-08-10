#include "InsertNodeSiblingCommandTest.h"


InsertNodeSiblingCommandTest::InsertNodeSiblingCommandTest()
{
}


InsertNodeSiblingCommandTest::~InsertNodeSiblingCommandTest()
{
}

void InsertNodeSiblingCommandTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Insertnodesiblingcommand = new InsertNodeSiblingCommand("", NULL, Mindmapmodel);
}
void InsertNodeSiblingCommandTest::TearDown()
{
	delete Mindmapmodel;
	delete Insertnodesiblingcommand;
}

TEST_F(InsertNodeSiblingCommandTest, execute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Insertnodesiblingcommand->Description = "Node2";
	Insertnodesiblingcommand->NodeID = 1;
	Insertnodesiblingcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[1]->getDescription(), "Node2");
}

TEST_F(InsertNodeSiblingCommandTest, unexecute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Insertnodesiblingcommand->Description = "Node2";
	Insertnodesiblingcommand->NodeID = 1;
	Insertnodesiblingcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[1]->getDescription(), "Node2");
	Insertnodesiblingcommand->unexecute();
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 2);
}