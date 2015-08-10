#pragma once
#include "../QT/DeleteComponentCommand.h"
#include "../QT/MindMapModel.h"
#include "gtest/gtest.h"

class DeleteComponentCommandTest:
	public::testing::Test
{
public:
	DeleteComponentCommandTest();
	~DeleteComponentCommandTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	DeleteComponentCommand* Deletecomponentcommand;
};

