#ifndef DEMO_H_
#define DEMO_H_

#include<fstream>
#include<ios>
#include<tuple>
#include<array>
#include"FolderStructure.h"
#include"FileNameRetrieval.h"

using std::tuple;
using std::ios;
using std::fstream;
using std::cout;
using std::endl;
using std::get;
using std::array;

template<typename S = string>
class Demo
{
	vector<S> passwordFilenames;
	vector<tuple<int,int,int>> dates;
	vector<array<int, 3>> grass;

public:
	Demo();
	~Demo();

	void fuckingDoShit();
	void doFuckingOtherShit();

	vector<S> retrievePasswordFilenames() const;
	vector<array<int,3>> retrieveGrass() const;
};

template<typename S>
Demo<S>::Demo()
{
	fuckingDoShit();

}
template<typename S>
Demo<S>::~Demo()
{

}

template<typename S>
void Demo<S>::fuckingDoShit()
{
	FileNameRetrieval fnr{};
	fnr.retrievePasswordNames();
	vector<string> stupidBitch{fnr.passwordNameContainer()};

	for (auto sb : stupidBitch)
	{
		passwordFilenames.push_back(sb);
	}
	doFuckingOtherShit();
}
template<typename S>
void Demo<S>::doFuckingOtherShit()
{
	fstream metaShit;

	for (auto shit : passwordFilenames)
	{
		metaShit.open(FolderStructure::passwordDirectory+shit.c_str(), std::ios::in);
		auto year = 0, month = 0, dayOfMonth = 0;
		metaShit >> year;
		metaShit >> month;
		metaShit >> dayOfMonth;

		grass.push_back(array<int,3>{year, month, dayOfMonth});

		metaShit.close();

	}
}

template<typename S>
vector<S> Demo<S>::retrievePasswordFilenames() const { return passwordFilenames; }
template<typename S>
vector<array<int,3>> Demo<S>::retrieveGrass() const { return grass; }

#endif
