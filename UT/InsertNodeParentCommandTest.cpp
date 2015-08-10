#include "InsertNodeParentCommandTest.h"


InsertNodeParentCommandTest::InsertNodeParentCommandTest()
{
}


InsertNodeParentCommandTest::~InsertNodeParentCommandTest()
{
}

void InsertNodeParentCommandTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Insertnodeparentcommand = new InsertNodeParentCommand("", NULL, Mindmapmodel);
}
void InsertNodeParentCommandTest::TearDown()
{
	delete Mindmapmodel;
	delete Insertnodeparentcommand;
}

TEST_F(InsertNodeParentCommandTest, execute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Insertnodeparentcommand->Description = "Node2";
	Insertnodeparentcommand->NodeID = 1;
	Insertnodeparentcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getDescription(), "Node2");
}

TEST_F(InsertNodeParentCommandTest, unexecute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Insertnodeparentcommand->Description = "Node2";
	Insertnodeparentcommand->NodeID = 1;
	Insertnodeparentcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getDescription(), "Node2");
	Insertnodeparentcommand->unexecute();
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 2);
}