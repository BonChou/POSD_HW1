#pragma once
#include <string>
using namespace std;

class Node;
class Root;
class NodeVisitor
{
public:
	NodeVisitor();
	~NodeVisitor();
	virtual void visitor(Root*) = 0;
	virtual void visitor(Node*) = 0;
	virtual string getCoutString() = 0;

};

