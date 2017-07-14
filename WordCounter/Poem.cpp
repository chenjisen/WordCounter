#include "stdafx.h"


void Poem::GetTitle(const wstring & str)
{
	wstring s = str;
	if (s.substr(0,3) != _T("���⣺"))
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
	/*
	if (s.length() <= 19 || s[0] != _T('2')) {
		return false;
	}
	else {
		//����ʱ���ʽ���� (h)h:mm:ss
		if (s[12] == _T(':'))
			s.insert(11, _T("0"));
		wstring day, time, name;
		day.assign(s, 0, 10);
		bool isDay = day[4] == _T('-') && day[7] == _T('-');
		time.assign(s, 11, 8);
		bool isTime = time[2] == _T(':') && time[5] == _T(':');
		return isDay && isTime;
	}*/

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
	wstring text, state, str; //Ĭ��Ϊ��

							  //��һ����Ϣ
	do
		if (!getline(in, str)) return vm;
	while (!Message::isInfo(str));


	while (true) {
		m.clear();

		//���ʱ�䡢�ǳƣ��磺yyyy-mm-dd (h)h:mm:ss ��
		try {
			m.GetInfo(str);
		}
		catch (runtime_error err) {
			cout << err.what();
			wcout << str << endl << m.day << endl << m.time << endl
				<< m.name << endl << m.text << endl;
			system("pause");
		}

		//�жϽ�������
		if (m.day == EndDate)
			return vm;

		//���״̬
		if (m.day != state) {
			state = m.day;
			wcout << state << endl;
		}

		//��ȡ��Ϣ�ı�
		str.clear();
		do {
			text += str;
			//��ȡ�ַ�����ѭ����������
			if (!getline(in, str)) {
				m.GetText(text);
				vm.push_back(m);
				return vm;
			}
		} while (!Message::isInfo(str));

		//�����Ϣ�ı�
		m.GetText(text);
		vm.push_back(m);
		text.clear();

	}
	*/

	return vector<Poem>();
}

