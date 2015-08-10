#pragma once
#include "../QT/InsertNodeChildCommand.h"
#include "../QT/MindMapModel.h"
#include "gtest/gtest.h"

class InsertNodeChildCommandTest :
	public::testing::Test
{
public:
	InsertNodeChildCommandTest();
	~InsertNodeChildCommandTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	InsertNodeChildCommand* Insertnodechildcommand;
};
