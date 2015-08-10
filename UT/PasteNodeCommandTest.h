#pragma once
#include "../QT/PasteNodeCommand.h"
#include "../QT/MindMapModel.h"
#include "gtest/gtest.h"

class PasteNodeCommandTest:
	public::testing::Test
{
public:
	PasteNodeCommandTest();
	~PasteNodeCommandTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	PasteNodeCommand* Command;
};