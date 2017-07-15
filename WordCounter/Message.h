#pragma once

using std::wstring;
using std::vector;
using std::wifstream;


class Message
{

public:

	wstring day; //yyyy-mm-dd
	wstring time; //hh:mm:ss 
	wstring name;
	wstring text;

	static vector<Message> GetVec(wifstream& in, int& charNum, const unsigned int& MaxSize = UINT_MAX);

private:



	void GetInfo(const wstring& str);
	void GetText(const wstring& text);
	void clear();
	static bool isInfo(const wstring& str);

};
