#pragma once
#include "NodeVisitor.h"
#include <string>
#include "Node.h"
#include "Root.h"
using namespace std;

class DisplayNodeVisitor :
	public NodeVisitor
{
public:
	DisplayNodeVisitor();
	~DisplayNodeVisitor();
	void visitor(Root*);
	void visitor(Node*);
	string getCoutString();
	string intTostr(int &);
private:
	string CoutString;
};

