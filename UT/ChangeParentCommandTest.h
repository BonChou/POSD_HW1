#pragma once
#include "../QT/ChangeParentCommand.h"
#include "../QT/MindMapModel.h"

#include "gtest/gtest.h"

class ChangeParentCommandTest:
	public::testing::Test
{
public:
	ChangeParentCommandTest();
	~ChangeParentCommandTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	ChangeParentCommand* Changeparentcommand;
};

