#include "stdafx.h"

void Message::GetInfo(const wstring& str)
{
	wstring s = str;
	if (s[0] != _T('2'))
		throw runtime_error("Day error!");
	else {
		//处理时间格式问题 (h)h:mm:ss
		if (s[12] == _T(':'))
			s.insert(11, _T("0"));

		day.assign(s, 0, 10);
		bool isDay = day[4] == _T('-') && day[7] == _T('-');
		time.assign(s, 11, 8);
		bool isTime = time[2] == _T(':') && time[5] == _T(':');
		name.assign(s, 20, s.length() - 20);

		if (!isDay || !isTime)
			throw runtime_error("Info error!");
	}

}

void Message::GetText(const wstring& text)
{
	this->text = text;
}

void Message::clear()
{
	day.clear();
	time.clear();
	name.clear();
	text.clear();
}

bool Message::isInfo(const wstring& str)
{
	wstring s = str;
	if (s.length() <= 19 || s[0] != _T('2')) {
		return false;
	}
	else {
		//处理时间格式问题 (h)h:mm:ss
		if (s[12] == _T(':'))
			s.insert(11, _T("0"));
		wstring day, time, name;
		day.assign(s, 0, 10);
		bool isDay = day[4] == _T('-') && day[7] == _T('-');
		time.assign(s, 11, 8);
		bool isTime = time[2] == _T(':') && time[5] == _T(':');
		return isDay && isTime;
	}
}

vector<Message> Message::GetVec(wifstream& in, const wstring& EndDate = _T(""))
{
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

}

