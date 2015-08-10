#include "CommandManagerTest.h"


CommandManagerTest::CommandManagerTest()
{
}

CommandManagerTest::~CommandManagerTest()
{
}

void CommandManagerTest::SetUp()
{
	Mindmapmodel = new MindMapModel();
	Commandmanager = new CommandManager();
}
void CommandManagerTest::TearDown()
{
	delete Commandmanager;
}
TEST_F(CommandManagerTest, execute)
{
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Command* CommandExecute = new EditComponentCommand("RootGX", 0, Mindmapmodel);
	Commandmanager->execute(CommandExecute);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getDescription(),"RootGX");
	CommandExecute = new EditComponentCommand("Node1GX", 1, Mindmapmodel);
	Commandmanager->execute(CommandExecute);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getDescription(), "Node1GX");
}
TEST_F(CommandManagerTest, redo)
{
	ASSERT_FALSE(Commandmanager->redo());
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Command* CommandExecute = new EditComponentCommand("RootGX", 0, Mindmapmodel);
	Commandmanager->execute(CommandExecute);
	CommandExecute = new EditComponentCommand("Node1GX", 1, Mindmapmodel);
	Commandmanager->execute(CommandExecute);
	ASSERT_TRUE(Commandmanager->undo());
	ASSERT_TRUE(Commandmanager->redo());
	ASSERT_TRUE(Commandmanager->undo());
	CommandExecute = new EditComponentCommand("Node2GX", 2, Mindmapmodel);
	Commandmanager->execute(CommandExecute); 
	ASSERT_FALSE(Commandmanager->redo());
}
TEST_F(CommandManagerTest, undo)
{
	ASSERT_FALSE(Commandmanager->undo());
	Mindmapmodel->createMindMap("Root");
	Mindmapmodel->createNode("Node1");
	Mindmapmodel->insertNodeChild(0, 1);
	Mindmapmodel->createNode("Node2");
	Mindmapmodel->insertNodeChild(1, 2);
	Mindmapmodel->createNode("Node3");
	Mindmapmodel->insertNodeSibling(1, 3);
	Command* CommandExecute = new EditComponentCommand("RootGX", 0, Mindmapmodel);
	Commandmanager->execute(CommandExecute);
	CommandExecute = new EditComponentCommand("Node1GX", 1, Mindmapmodel);
	Commandmanager->execute(CommandExecute);
	ASSERT_TRUE(Commandmanager->undo());
}