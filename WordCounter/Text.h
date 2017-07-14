#pragma once

using std::wstring;
using std::vector;

class Text
{
public:
	wstring text;


	static vector<Text> GetVec();

protected:

	virtual void GetText(const wstring& str) = 0;

	virtual void clear() = 0;


};

