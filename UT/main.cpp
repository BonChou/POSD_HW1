#include<gtest/gtest.h>
#include "../QT/Component.cpp"
#include "../QT/ComponentFactory.cpp"
#include "../QT/CommandManager.cpp"
#include "../QT/MindMapModel.cpp"
#include "../QT/ChangeParentCommand.cpp"
#include "../QT/Command.cpp"
#include "../QT/Composite.cpp"
#include "../QT/DeleteComponentCommand.cpp"
#include "../QT/EditComponentCommand.cpp"
#include "../QT/InsertNodeChildCommand.cpp"
#include "../QT/InsertNodeParentCommand.cpp"
#include "../QT/InsertNodeSiblingCommand.cpp"
#include "../QT/PasteNodeCommand.cpp"
#include "../QT/CutNodeCommand.cpp"
#include "../QT/Node.cpp"
#include "../QT/Root.cpp"
#include "../QT/Presentation.cpp"
#include "../QT/Observer.cpp"
#include "../QT/Subject.cpp"
#include "../QT/Circle.cpp"
#include "../QT/Rectangle.cpp"
#include "../QT/Triangle.cpp"
#include "../QT/Decorator.cpp"
#include "../QT/NodeVisitor.cpp"
#include "../QT/SaveNodeVisitor.cpp"
#include "../QT/DisplayNodeVisitor.cpp"
#include "../QT/Constants.h"
void main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("pause");
}