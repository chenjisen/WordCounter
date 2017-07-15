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

	//打开文件，注意：使用ANSI；前面几行删掉
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

	//读取文件
	vector<TextType> vecText;
	int charNum;

	TimingBegin;
	{
		cout << "正在读取消息记录……\n";
		vecText = TextType::GetVec(in, charNum, MaxSize);
		cout << "消息数量：" << size(vecText) << endl;
		out << _T("消息数量：") << size(vecText) << endl;
		cout << "字数:" << charNum << endl;
		out << _T("字数:") << charNum << endl;

		//for (auto m : vecText) wcout << m.text << endl;
	} 
	TimingEnd;

	in.close();
	
	//统计频率
	vector<pair<wstring, int>> vecF;
	for (int i = 1; i <= MaxLength; ++i) {
		cout << "正在统计出现频率较高的" << i << "字词……\n";
		out << _T("正在统计出现频率较高的") << i << _T("字词……\n");
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
				cout <<"找不到频率较高的" << i << "字词！\n";
				out << _T("找不到频率较高的") << i << _T("字词！\n");
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


