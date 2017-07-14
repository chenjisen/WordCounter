#pragma once


using std::wstring;

class Message
{

public:

	wstring day; //yyyy-mm-dd
	wstring time; //hh:mm:ss 
	wstring name;
	wstring text;

	static std::vector<Message> GetVec(std::wifstream& in, const wstring& EndDate);

private:



	void GetInfo(const wstring& str);
	void GetText(const wstring& text);
	void clear();
	static bool isInfo(const wstring& str);

};
