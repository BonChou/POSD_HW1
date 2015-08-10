#pragma once
#include "../QT/CutNodeCommand.h"
#include "../QT/MindMapModel.h"
#include "gtest/gtest.h"

class CutNodeCommandTest :
	public::testing::Test
{
public:
	CutNodeCommandTest();
	~CutNodeCommandTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	CutNodeCommand* Command;
};

