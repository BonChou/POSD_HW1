#pragma once
#include "../QT/InsertNodeSiblingCommand.h"
#include "../QT/MindMapModel.h"
#include "gtest/gtest.h"

class InsertNodeSiblingCommandTest :
	public::testing::Test
{
public:
	InsertNodeSiblingCommandTest();
	~InsertNodeSiblingCommandTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	InsertNodeSiblingCommand* Insertnodesiblingcommand;
};
