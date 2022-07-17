#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include<bits/stdc++.h>
#include "ScopeTable.h"
#include "SymbolInfo.h"
using namespace std;

class SymbolTable
{
public:
	int n;
	ScopeTable* curScope;
	stack<ScopeTable*> scopes;
	SymbolTable(int n): n(n)
	{
		curScope=nullptr;

	}
	void enter()
	{
		ScopeTable* newScope=new ScopeTable(n);
		scopes.push(newScope);
		newScope->parentScope=curScope;
		if(curScope!=nullptr) curScope->childNum++;
		if(curScope!=nullptr) newScope->id=curScope->id+"."+to_string(curScope->childNum);
		else newScope->id="1";
		curScope=newScope;
		//cout<<"New ScopeTable with id# "<<newScope->id<<" is created\n";

	}

	void exit()
	{
		if(curScope==nullptr){
			//cout<<"NO CURRENT SCOPE\n";
			return;
		}
		ScopeTable* delScope=curScope;
		//cout<<"ScopeTable with id "<<delScope->id<<" is removed\n";
		curScope=delScope->parentScope;
		delete delScope;
		scopes.pop();
	}

	ScopeTable* lookup(string name)
	{
		ScopeTable* cur=curScope;
		SymbolInfo* symbol=nullptr;
		while(cur){
			symbol=cur->lookup(name);
			if(symbol!=nullptr) break;
			cur=cur->parentScope;
		}
		return cur;
	}

	SymbolInfo* insert(string name, string type)
	{
		//cout<<name<<" "<<type<<"\n";
		return curScope->insert(name, type);
	}
	bool del(string name)
	{
		return curScope->del(name);
	}
	void printCur()
	{
		if(curScope==nullptr) cout<<"NO CURRENT SCOPE\n";
		else curScope->print();
	}

	void printAll()
	{
		if(curScope==nullptr) cout<<"NO CURRENT SCOPE\n";
		ScopeTable* cur=curScope;
		while(cur!=nullptr) cur->print(), cur=cur->parentScope;
	}

	~SymbolTable()
	{
		while(!scopes.empty()){
			delete scopes.top();
			scopes.pop();
		}
	}
};
#endif
