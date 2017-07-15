#include "stdafx.h"

void Sentence::GetText(const wstring & str)
{
	text = str;
}

void Sentence::clear()
{
	text.clear();
}

vector<Sentence> Sentence::GetVec(wifstream& in, int& charNum, const unsigned int& MaxSize)
{

	vector<Sentence> vs;
	Sentence sent;
	wstring str; //默认为空
	charNum = 0;

	while (!getline(in, str)) {

		//判断结束数量

		sent.GetText(str);
		charNum += str.length();
		vs.push_back(sent);

		if (vs.size() >= MaxSize)
			return vs;
	}

	return vs;
}


