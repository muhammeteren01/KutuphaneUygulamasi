#pragma once
#ifndef IOperations_HEADER

#endif // !IOperations_HEADER
#include <map>
#include <iostream>
#include <string>

using namespace std;

__interface IOperations
{
public:
	virtual map<string, string> add(map<string, string>) = 0;
	virtual map<string, string> update(map<string, string>) = 0;
	virtual map<string, string> remove(map<string, string>) = 0;
	virtual void printAll(map<string, string>) = 0;
	virtual void printOne(map<string, string>)=0;
};