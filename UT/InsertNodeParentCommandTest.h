#pragma once
#include "../QT/InsertNodeParentCommand.h"
#include "../QT/MindMapModel.h"
#include "gtest/gtest.h"

class InsertNodeParentCommandTest :
	public::testing::Test
{
public:
	InsertNodeParentCommandTest();
	~InsertNodeParentCommandTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	InsertNodeParentCommand* Insertnodeparentcommand;
};
