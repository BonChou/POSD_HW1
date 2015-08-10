#include "DeleteComponentCommandTest.h"


DeleteComponentCommandTest::DeleteComponentCommandTest()
{
}


DeleteComponentCommandTest::~DeleteComponentCommandTest()
{
}
void DeleteComponentCommandTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Deletecomponentcommand = new DeleteComponentCommand(NULL, Mindmapmodel);
}
void DeleteComponentCommandTest::TearDown()
{
	delete Mindmapmodel;
	delete Deletecomponentcommand;
}
TEST_F(DeleteComponentCommandTest, execute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Deletecomponentcommand->NodeID = 1;
	Deletecomponentcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 1);
}
TEST_F(DeleteComponentCommandTest, unexecute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Deletecomponentcommand->NodeID = 1;
	Deletecomponentcommand->execute();
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 1);
	Deletecomponentcommand->unexecute();
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 2);
}