#include "IntegrationTest.h"


IntegrationTest::IntegrationTest()
{
}


IntegrationTest::~IntegrationTest()
{
}

void IntegrationTest::SetUp()
{
	Mindmapmodel = new MindMapModel;
	PresentationCommand = new Presentation(Mindmapmodel);
	_mkdir("testdata\\");
	ofstream outputFile("testdata\\test_file1.mm");
	outputFile << "0 \"Computer\" 2 7/\n";
	outputFile << "1 \"windows\" 5 6/\n";
	outputFile << "2 \"OS\" 1 3 4/\n";
	outputFile << "3 \"IOS\"/\n";
	outputFile << "4 \"Linux\"/\n";
	outputFile << "5 \"DirectX\"/\n";
	outputFile << "6 \"Microsoft Office\"/\n";
	outputFile << "7 \"Network\" 8 9/\n";
	outputFile << "8 \"Wireless\"/\n";
	outputFile << "9 \"Cable\"/";
	outputFile.close();
}

void IntegrationTest::TearDown()
{
	delete Mindmapmodel;
	remove("testdata\\test_file1.mm");
	_rmdir("testdata\\");
} 

TEST_F(IntegrationTest, testLoadFileNotExist)
{
	ASSERT_FALSE(Mindmapmodel->loadMindMap("C:\\MindMap\\file_not_exist.erd"));
	ASSERT_FALSE(Mindmapmodel->checkMindMapExist());
}
TEST_F(IntegrationTest, testUndoDeleteNode)
{
	ASSERT_TRUE(Mindmapmodel->loadMindMap("testdata\\test_file1.mm"));
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getDescription(), "Computer");
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[0]->getID(), 2);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[1]->getID(), 7);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getDescription(), "windows");
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getNodeList()[0]->getID(), 5);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getNodeList()[1]->getID(), 6);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getDescription(), "OS");
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[0]->getID(), 1);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[1]->getID(), 3);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[2]->getID(), 4);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->getDescription(), "IOS");
	ASSERT_EQ(Mindmapmodel->MindMap[4]->getDescription(), "Linux");
	ASSERT_EQ(Mindmapmodel->MindMap[5]->getDescription(), "DirectX");
	ASSERT_EQ(Mindmapmodel->MindMap[6]->getDescription(), "Microsoft Office");
	ASSERT_EQ(Mindmapmodel->MindMap[7]->getDescription(), "Network");
	ASSERT_EQ(Mindmapmodel->MindMap[7]->getNodeList()[0]->getID(), 8);
	ASSERT_EQ(Mindmapmodel->MindMap[7]->getNodeList()[1]->getID(), 9);
	ASSERT_EQ(Mindmapmodel->MindMap[8]->getDescription(), "Wireless");
	ASSERT_EQ(Mindmapmodel->MindMap[9]->getDescription(), "Cable");
	PresentationCommand->createInsertNodeChildCommand("Test", 4); 
	ASSERT_EQ(Mindmapmodel->MindMap[4]->getNodeList()[0]->getID(), 10);
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 11);
	PresentationCommand->createDeleteCommand(10);
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 10);
	PresentationCommand->undo();
	ASSERT_EQ(Mindmapmodel->MindMap[4]->getNodeList()[0]->getDescription(), "Test");
}

TEST_F(IntegrationTest, testRedoDeleteNode)
{
	ASSERT_TRUE(Mindmapmodel->loadMindMap("testdata\\test_file1.mm"));
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getDescription(), "Computer");
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[0]->getID(), 2);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[1]->getID(), 7);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getDescription(), "windows");
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getNodeList()[0]->getID(), 5);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getNodeList()[1]->getID(), 6);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getDescription(), "OS");
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[0]->getID(), 1);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[1]->getID(), 3);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[2]->getID(), 4);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->getDescription(), "IOS");
	ASSERT_EQ(Mindmapmodel->MindMap[4]->getDescription(), "Linux");
	ASSERT_EQ(Mindmapmodel->MindMap[5]->getDescription(), "DirectX");
	ASSERT_EQ(Mindmapmodel->MindMap[6]->getDescription(), "Microsoft Office");
	ASSERT_EQ(Mindmapmodel->MindMap[7]->getDescription(), "Network");
	ASSERT_EQ(Mindmapmodel->MindMap[7]->getNodeList()[0]->getID(), 8);
	ASSERT_EQ(Mindmapmodel->MindMap[7]->getNodeList()[1]->getID(), 9);
	ASSERT_EQ(Mindmapmodel->MindMap[8]->getDescription(), "Wireless");
	ASSERT_EQ(Mindmapmodel->MindMap[9]->getDescription(), "Cable");
	PresentationCommand->createInsertNodeChildCommand("Test", 9);
	ASSERT_EQ(Mindmapmodel->MindMap[9]->getNodeList()[0]->getID(), 10);
	PresentationCommand->createDeleteCommand(10);
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 10);
	PresentationCommand->undo();
	ASSERT_EQ(Mindmapmodel->MindMap[9]->getNodeList()[0]->getDescription(), "Test");
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 11);
	PresentationCommand->redo();
	ASSERT_EQ(Mindmapmodel->MindMap.size(), 10);
}
TEST_F(IntegrationTest, testChangeNodeParent)
{
	ASSERT_TRUE(Mindmapmodel->loadMindMap("testdata\\test_file1.mm"));
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getDescription(), "Computer");
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[0]->getID(), 2);
	ASSERT_EQ(Mindmapmodel->MindMap[0]->getNodeList()[1]->getID(), 7);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getDescription(), "windows");
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getNodeList()[0]->getID(), 5);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->getNodeList()[1]->getID(), 6);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getDescription(), "OS");
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[0]->getID(), 1);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[1]->getID(), 3);
	ASSERT_EQ(Mindmapmodel->MindMap[2]->getNodeList()[2]->getID(), 4);
	ASSERT_EQ(Mindmapmodel->MindMap[3]->getDescription(), "IOS");
	ASSERT_EQ(Mindmapmodel->MindMap[4]->getDescription(), "Linux");
	ASSERT_EQ(Mindmapmodel->MindMap[5]->getDescription(), "DirectX");
	ASSERT_EQ(Mindmapmodel->MindMap[6]->getDescription(), "Microsoft Office");
	ASSERT_EQ(Mindmapmodel->MindMap[7]->getDescription(), "Network");
	ASSERT_EQ(Mindmapmodel->MindMap[7]->getNodeList()[0]->getID(), 8);
	ASSERT_EQ(Mindmapmodel->MindMap[7]->getNodeList()[1]->getID(), 9);
	ASSERT_EQ(Mindmapmodel->MindMap[8]->getDescription(), "Wireless");
	ASSERT_EQ(Mindmapmodel->MindMap[9]->getDescription(), "Cable");
	PresentationCommand->createChangeParentCommand(1, 6);
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getDescription(), "Microsoft Office");
	ASSERT_EQ(Mindmapmodel->MindMap[6]->ParentNode->getDescription(), "OS");
	PresentationCommand->undo();
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getDescription(), "OS");
	ASSERT_EQ(Mindmapmodel->MindMap[6]->ParentNode->getDescription(), "windows");
	PresentationCommand->redo();
	ASSERT_EQ(Mindmapmodel->MindMap[1]->ParentNode->getDescription(), "Microsoft Office");
	ASSERT_EQ(Mindmapmodel->MindMap[6]->ParentNode->getDescription(), "OS");
}