#ifndef SCOPETABLE_H
#define SCOPETABLE_H
#include<bits/stdc++.h>
#include "hashfunc.h"
#include "SymbolInfo.h"
using namespace std;
class ScopeTable
{
public:
	SymbolInfo** buckets;
	ScopeTable* parentScope;
	string id;
	int childNum, n;
	ScopeTable(int n): n(n)
	{
		//cout<<n<<"\n";
		buckets=new SymbolInfo*[n];
		for(int i=0;i<n;i++) buckets[i]=nullptr;
		childNum=0;

	}

	SymbolInfo* lookup(string name)
	{
		int x, y;
		unsigned long idx=sdbm(name)%n;
		x=idx;
		//cout<<idx<<"\n";
		SymbolInfo* cur=buckets[idx];
		y=0;
		while(cur!=nullptr){
			if(cur->name==name) return cur;
			cur=cur->next;
			y++;
		}
		//cout<<"lookup\n";
		return nullptr;
	}

	SymbolInfo* insert(string name, string type)
	{
		int x, y;
		if(lookup(name)==nullptr){
			unsigned long idx=sdbm(name)%n;
			x=idx, y=0;
			//cout<<idx<<"\n";
			SymbolInfo* newSymbol=new SymbolInfo(name, type);
			newSymbol->next=buckets[idx];
			buckets[idx]=newSymbol;
			return newSymbol;
		}
		return nullptr;
		//cout<<"insert\n";
	}

	bool del(string name)
	{
		int x, y;
		unsigned long idx=sdbm(name)%n;
		x=idx;
		//cout<<idx<<"\n";
		SymbolInfo* cur=buckets[idx], *prev=nullptr;
		y=0;
		while(cur!=nullptr){
			if(cur->name==name){
				if(cur==buckets[idx]){
					buckets[idx]=cur->next;
				}
				else {
					prev->next=cur->next;
				}
				delete cur;
				return true;
			}
			prev=cur;
			cur=cur->next;
			y++;
		}
		return false;
	}

	void print()
	{
        //fstream enlog("log.txt", std::ofstream::out | std::ofstream::trunc);
        //ofstream of("1805016_log.txt");
		enlog<<"ScopeTable# "<<this->id<<"\n";
		for(int i=0;i<n;i++){

			SymbolInfo* cur=buckets[i];
			if(cur==nullptr) continue;
			enlog<<i<<" --> ";
			while(cur!=nullptr){
				enlog<<"<"<<cur->name<<": "<<cur->type<<"> ";
				cur=cur->next;
			}
			enlog<<"\n";

		}
	}
	string getScope()
	{
		return this->id;
	}
	~ScopeTable()
	{
		for(int i=0;i<n;i++){
			SymbolInfo* cur=buckets[i];
			while(cur!=nullptr){
				SymbolInfo* next=cur->next;
				delete cur;
				cur=next;
			}
		}
		delete[] buckets;
	}
};
#endif
