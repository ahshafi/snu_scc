#ifndef HASH_FUNC_H
#define HASH_FUNC_H
#include<bits/stdc++.h>
using namespace std;

static unsigned long sdbm(string &str)
{
	unsigned long hash = 0;
	int c;
	auto p=str.begin();
	while (c = *p++)
		hash = c + (hash << 6) + (hash << 16) - hash;
	return hash;
}
#endif
