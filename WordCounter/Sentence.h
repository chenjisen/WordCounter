#pragma once



using std::wstring;
using std::vector;
using std::wifstream;

class Sentence
{
public:
	wstring text;

	static vector<Sentence> GetVec(wifstream& in, const unsigned int EndNum = 0);

private:

	void GetText(const wstring& str);
	void clear();

};


