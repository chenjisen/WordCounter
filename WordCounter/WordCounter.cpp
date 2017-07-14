#include "stdafx.h"

bool OpenInFile(wifstream& in, const char ifName[]);
bool OpenOutFile(wofstream& out, const char ofName[]);
template<class T>
void GetFPeak(vector<pair<wstring, int>>& vecFPeak, const vector<T>& vecMsg, int i);
long long GetFileSize(wifstream& in);
int LLToInt(long long n);

//export template<class T> vector<pair<wstring, int>> Frequency::Count
//(const vector<Message>& vm, const map<wstring, int>& FPeakShort);

const int MaxLength = 20;
const vector<unsigned int> Frequency::WordNumber(MaxLength + 1, 1000);
const vector<int> LimitCount(MaxLength + 1, 4);

/*void GetLimitCount(int n, long long fileSize)
{
	for (int& an : LimitCount) an = 2;
	//LimitCount[i] = max(LLToInt(fileSize / (long long)(2000 * pow(sqrt(10), n))), 2);
	//n=1:(fileSize / 6000) n=2:(fileSize / 20000) n=3:(fileSize / 60000) n=4:(fileSize / 200000)
}*/

const char ifName[] = "d:\\testR.txt";
const char ofName[] = "d:\\testOutcome.txt";
const wstring EndDate = _T("2017-01-01");//
typedef Message TextType;

int main()
{

	//���ļ���ע�⣺ʹ��ANSI��ǰ�漸��ɾ��
	wifstream in;
	wofstream out;
	if (!OpenInFile(in, ifName)) {
		cerr << "In file error!\n";
		system("pause");
		return 1;
	}
	if (!OpenOutFile(out, ofName)) {
		cerr << "Out file error!\n";
		system("pause");
		return 1;
	}


	//��ȡ�ļ�
	cout << "���ڶ�ȡ��Ϣ��¼����\n";



	vector<TextType> vecText;
	TimingBegin;
	{
		vecText = TextType::GetVec(in, EndDate);
		cout << "��Ϣ������" << size(vecText) << endl;
		out << _T("��Ϣ������") << size(vecText) << endl;
		//for (auto m : vecText) wcout << m.text << endl;
	} 
	TimingEnd;


	long long fileSize = GetFileSize(in);
	cout << "�ļ���С:" << fileSize << "Bytes" << endl;
	out << _T("�ļ���С:") << fileSize << "Bytes" << endl;
	//GetLimitCount(MaxLength + 1, fileSize);
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

bool OpenInFile(wifstream& in, const char ifName[])
{
	wcout.imbue(locale("chs"));
	in = wifstream(ifName);
	in.imbue(locale("chs"));
	return (bool)in;
}
bool OpenOutFile(wofstream& out, const char ofName[])
{
	out = wofstream(ofName);
	out.imbue(locale("chs"));
	return (bool)out;
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

long long GetFileSize(wifstream& in)
{
	long long fileSize = in.tellg();
	if (fileSize < 0) {
		OpenInFile(in, ifName);
		in.seekg(0, ios::end);
		fileSize = in.tellg();
	}
	return fileSize;
}

int LLToInt(long long n)
{
	return (int)min(n, (long long)INT_MAX);
}

