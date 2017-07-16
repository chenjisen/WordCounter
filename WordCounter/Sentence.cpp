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

	vector<Sentence> vecSent;
	Sentence sent;
	wstring str; //Ĭ��Ϊ��
	charNum = 0;

	while (getline(in, str)) {


		//�жϽ�������

		sent.GetText(str);
		charNum += str.length();
		vecSent.push_back(sent);

		if (vecSent.size() >= MaxSize)
			return vecSent;
	}

	return vecSent;
}


