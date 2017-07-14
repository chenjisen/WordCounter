#include "stdafx.h"

void Sentence::GetText(const wstring & str)
{
	text = str;
}

void Sentence::clear()
{
	text.clear();
}

vector<Sentence> Sentence::GetVec(wifstream& in, const unsigned int EndNum)
{

	vector<Sentence> vs;
	Sentence sent;
	wstring str; //默认为空


	while (!getline(in, str)) {

		//判断结束数量

		sent.GetText(str);
		vs.push_back(sent);

		if (vs.size() == EndNum)
			return vs;
	}



	return vs;
}


