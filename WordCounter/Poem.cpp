#include "stdafx.h"


void Poem::GetTitle(const wstring & str)
{
	wstring s = str;
	if (s.substr(0,3) != _T("标题："))
		throw runtime_error("Title error!");
	else 
		title.assign(s, 3);
}

void Poem::GetText(const wstring & str)
{
	text = str;
}

void Poem::clear()
{
	title.clear();
	text.clear();
	time.clear();
	annotation.clear();
}

bool Poem::isTitle(const wstring & str)
{
	wstring s = str;
	
	if (s.length() <= 3) return false;
	if (s.substr(0, 3) != _T("标题：")) return false;

	return true;
}

bool Poem::isTime(const wstring & str)
{
	return false;
}

bool Poem::isAnnotation(const wstring & str)
{
	return false;
}


vector<Poem> Poem::GetVec(wifstream & in, const int EndNum)
{
	/*
	vector<Message> vm;
	Message m;
	wstring text, state, str; //默认为空

							  //第一条消息
	do
		if (!getline(in, str)) return vm;
	while (!Message::isInfo(str));


	while (true) {
		m.clear();

		//获得时间、昵称，如：yyyy-mm-dd (h)h:mm:ss 甲
		try {
			m.GetInfo(str);
		}
		catch (runtime_error err) {
			cout << err.what();
			wcout << str << endl << m.day << endl << m.time << endl
				<< m.name << endl << m.text << endl;
			system("pause");
		}

		//判断结束日期
		if (m.day == EndDate)
			return vm;

		//输出状态
		if (m.day != state) {
			state = m.day;
			wcout << state << endl;
		}

		//读取消息文本
		str.clear();
		do {
			text += str;
			//读取字符串，循环结束条件
			if (!getline(in, str)) {
				m.GetText(text);
				vm.push_back(m);
				return vm;
			}
		} while (!Message::isInfo(str));

		//获得消息文本
		m.GetText(text);
		vm.push_back(m);
		text.clear();

	}
	*/

	return vector<Poem>();
}

