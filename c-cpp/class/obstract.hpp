#include <iostream>
#ifndef _OBSTRACT_H
#define _OBSTRACT_H
class Cobstract
{
public:
	virtual void func1() = 0;
	virtual void func2() = 0;
};

class CC : public Cobstract
{
public:
	void func1() override;
	void func2() override;
};
#endif
