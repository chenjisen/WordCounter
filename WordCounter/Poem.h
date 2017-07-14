#pragma once

using std::wstring;
using std::vector;
using std::wifstream;

class Poem
{
public:

	wstring title;      //标题：### 
	wstring text;       //正文：###
	wstring time;       //时间：###，丢弃
	wstring annotation; //注释：###，丢弃

	static vector<Poem> GetVec(wifstream& in, const int EndNum = -1);
 
private:

	void GetTitle(const wstring& str);
	void GetText(const wstring& str);
	void clear();
	static bool isTitle(const wstring& str);
	static bool isTime(const wstring& str);
	static bool isAnnotation(const wstring& str);
};
