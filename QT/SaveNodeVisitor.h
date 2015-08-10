#pragma once
#include "NodeVisitor.h"
#include "Constants.h"
#include <string>
#include "Node.h"
#include "Root.h"
using namespace std;
class SaveNodeVisitor :
	public NodeVisitor
{
public:
	SaveNodeVisitor();
	~SaveNodeVisitor();
	void visitor(Root*);
	void visitor(Node*);
	string getCoutString();
	string intTostr(int &);
private:
	string CoutString;
};

