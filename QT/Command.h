#pragma once
#include <string>
using namespace std;
class Command
{
public:
	Command();
	virtual ~Command();
	virtual void execute() = 0;
	virtual void unexecute() = 0;
};

