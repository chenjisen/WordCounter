#include "stdafx.h"

template<class T>
T OpenFile(const char fileName[]);
template<class T>
void GetFPeak(vector<pair<wstring, int>>& vecFPeak, const vector<T>& vecMsg, int i);

const unsigned int MaxLength = 20;
const vector<unsigned int> Frequency::WordNumber(MaxLength + 1, 1000);
const vector<int> LimitCount(MaxLength + 1, 4);
const unsigned int MaxSize = UINT_MAX;
typedef Message TextType;

const char ifName[] = "d:\\testR.txt";
const char ofName[] = "d:\\testOutcome.txt";

int main()
{

	//���ļ���ע�⣺ʹ��ANSI��ǰ�漸��ɾ��
	wifstream in;
	wofstream out;
	try {
		in = OpenFile<wifstream>(ifName);
		out = OpenFile<wofstream>(ofName);
	}
	catch (runtime_error err) {
		cerr << err.what() << endl;
		system("pause");
		return 1;
	}

	//��ȡ�ļ�
	vector<TextType> vecText;
	int charNum;

	TimingBegin;
	{
		cout << "���ڶ�ȡ��Ϣ��¼����\n";
		vecText = TextType::GetVec(in, charNum, MaxSize);
		cout << "��Ϣ������" << size(vecText) << endl;
		out << _T("��Ϣ������") << size(vecText) << endl;
		cout << "����:" << charNum << endl;
		out << _T("����:") << charNum << endl;

		//for (auto m : vecText) wcout << m.text << endl;
	} 
	TimingEnd;

	in.close();
	
	//ͳ��Ƶ��
	vector<pair<wstring, int>> vecF;
	for (int i = 1; i <= MaxLength; ++i) {
		cout << "����ͳ�Ƴ���Ƶ�ʽϸߵ�" << i << "�ִʡ���\n";
		out << _T("����ͳ�Ƴ���Ƶ�ʽϸߵ�") << i << _T("�ִʡ���\n");
		TimingBegin;
		{
			
			GetFPeak<TextType>(vecF, vecText, i);
			if (!vecF.empty()) {
				for (auto p : vecF) {
					wcout << p.first << '\t' << p.second << endl;
					out << p.first << '\t' << p.second << endl;
				}
			}
			else {
				cout <<"�Ҳ���Ƶ�ʽϸߵ�" << i << "�ִʣ�\n";
				out << _T("�Ҳ���Ƶ�ʽϸߵ�") << i << _T("�ִʣ�\n");
				break;
			}
			
		}
		TimingEnd;

		system("pause");
	}
	out.close();

	
	system("pause");
	return 0;
}

template<class T>
T OpenFile(const char fileName[])
{
	wcout.imbue(locale("chs"));
	T file(fileName);
	if (!file) {
		if (typeid(T) == typeid(wifstream))
			throw runtime_error("Open in file error!");
		else if (typeid(T) == typeid(wofstream))
			throw runtime_error("Open out file error!");
		else
			throw runtime_error("Open unknown error!");
	}
	file.imbue(locale("chs"));
	return file;
}

template <class T>
void GetFPeak(vector<pair<wstring, int>>& vecFPeak, const vector<T>& vecMsg, int i)
{
	map<wstring,int> FPeakShort = Frequency::VecToMapNo(vecFPeak);
	if (i == 1)
		vecFPeak = Frequency::ChCount<TextType>(vecMsg, LimitCount[i]);
	else
		vecFPeak = Frequency::Count<TextType>(vecMsg, LimitCount[i], FPeakShort, i);
}


