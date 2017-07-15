#pragma once



using std::wstring;
using std::vector;
using std::wifstream;

class Sentence
{
public:
	wstring text;

	static vector<Sentence> GetVec(wifstream& in, int& charNum, const unsigned int& MaxSize = UINT_MAX);

private:

	void GetText(const wstring& str);
	void clear();

};


