#pragma once
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Class
{
	Class();
	~Class();
	static Class* Instance;
	string Path;
public:
	static Class* GetInstance();
	static void DestroyInstance();
	void Write(string mesaj);
	void ChangePath(string path);
};

