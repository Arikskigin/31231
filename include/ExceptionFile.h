#pragma once
#include <exception>
using std::exception;

class ExceptionFile:public exception
{
public:
	ExceptionFile();
private:
};