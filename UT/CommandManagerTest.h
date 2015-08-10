#pragma once
#include "../QT/CommandManager.h"
#include "../QT/Command.h"
#include "../QT/MindMapModel.h"
#include "../QT/EditComponentCommand.h"
#include "../QT/InsertNodeChildCommand.h"

#include "gtest/gtest.h"
class CommandManagerTest:
	public::testing::Test
{
public:
	CommandManagerTest();
	~CommandManagerTest();
	void SetUp();
	void TearDown();
protected:
	CommandManager* Commandmanager;
	MindMapModel* Mindmapmodel;
};

