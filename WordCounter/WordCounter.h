#pragma once

#include <fstream>
using namespace std;

wifstream OpenInFile(const string& WorkingPath, const string& FileName)
{
	wcout.imbue(locale("chs"));

	string strInFilePath = WorkingPath + FileName + string(".txt");
	wifstream file(strInFilePath.c_str());
	if (!file)
		throw runtime_error("Open in file error!");
	file.imbue(locale("chs"));

	return file;
}

wofstream OpenOutFile(const string& WorkingPath, const string& FileName)
{

	string strOutFilePath = WorkingPath + FileName + string("_Outcome.txt");
	wofstream file(strOutFilePath.c_str());
	if (!file)
		throw runtime_error("Open out file error!");
	file.imbue(locale("chs"));
	return file;
}

template <class T>
void GetFPeak(vector<pair<wstring, int>>& vecFPeak, const vector<T>& vecMsg, int i)
{
	map<wstring, int> FPeakShort = Frequency::VecToMapNo(vecFPeak);
	if (i == 1)
		vecFPeak = Frequency::ChCount<TextType>(vecMsg, LimitCount[i]);
	else
		vecFPeak = Frequency::Count<TextType>(vecMsg, LimitCount[i], FPeakShort, i);
}
