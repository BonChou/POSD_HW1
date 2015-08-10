#pragma once
#include "../QT/EditComponentCommand.h"
#include "../QT/MindMapModel.h"
#include "gtest/gtest.h"

class EditComponentCommandTest :
	public::testing::Test
{
public:
	EditComponentCommandTest();
	~EditComponentCommandTest();
	void SetUp();
	void TearDown();
protected:
	MindMapModel* Mindmapmodel;
	EditComponentCommand* Editcomponentcommand;
};

