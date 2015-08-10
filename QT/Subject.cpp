#include "Subject.h"


Subject::Subject()
{
}


Subject::~Subject()
{
}

void Subject::attatch(Observer* observer)
{
	this->observer = observer;
}
void Subject::detatch()
{
	delete this->observer;
}
void Subject::notify()
{
	if (this->observer != nullptr)
		this->observer->update();
}