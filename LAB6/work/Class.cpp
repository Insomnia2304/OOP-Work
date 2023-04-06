#include "Class.h"

Class* Class::GetInstance()
{
	if (Instance == 0)
		Instance = new Class;
	return Instance;
}

void Class::DestroyInstance()
{
	if (Instance)
		delete Instance;
}

Class::Class() : Path("")
{

}

Class::~Class() {}

void Class::Write(string mesaj)
{
	ofstream fout(Path);
	fout << mesaj << '\n';
	fout.close();
}

void Class::ChangePath(string path)
{
	Path = path;
	transform(Path.begin(), Path.end(), Path.begin(), [](char c) {return tolower(c);});
}