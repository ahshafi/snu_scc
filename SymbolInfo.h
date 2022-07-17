#ifndef SYMBOLINFO_H
#define SYMBOLINFO_H
#include<bits/stdc++.h>
using namespace std;
class SymbolInfo
{
public:
	string name, type;
	SymbolInfo(){}
	SymbolInfo(string name, string type): name(name), type(type) {}
	SymbolInfo *next;
	string ret;
	vector<string> param;
	vector<string> pids;
};
#endif
