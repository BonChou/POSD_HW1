#include "InsertNodeChildCommandTest.h"


InsertNodeChildCommandTest::InsertNodeChildCommandTest()
{
}


InsertNodeChildCommandTest::~InsertNodeChildCommandTest()
{
}

void InsertNodeChildCommandTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Insertnodechildcommand = new InsertNodeChildCommand("", NULL, Mindmapmodel);
}
void InsertNodeChildCommandTest::TearDown()
{
	delete Mindmapmodel;
	delete Insertnodechildcommand;
}

TEST_F(InsertNodeChildCommandTest, execute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Insertnodechildcommand->Description = "Node2";
	Insertnodechildcommand->NodeID = 1;
	Insertnodechildcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getNodeList()[0]->getDescription(), "Node2");
}

TEST_F(InsertNodeChildCommandTest, unexecute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Insertnodechildcommand->Description = "Node2";
	Insertnodechildcommand->NodeID = 1;
	Insertnodechildcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getNodeList()[0]->getDescription(), "Node2");
	Insertnodechildcommand->unexecute();
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 2);
}