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

	//打开文件，注意：使用ANSI；前面几行删掉
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


	//读取文件
	cout << "正在读取消息记录……\n";



	vector<TextType> vecText;
	TimingBegin;
	{
		vecText = TextType::GetVec(in, EndDate);
		cout << "消息数量：" << size(vecText) << endl;
		out << _T("消息数量：") << size(vecText) << endl;
		//for (auto m : vecText) wcout << m.text << endl;
	} 
	TimingEnd;


	long long fileSize = GetFileSize(in);
	cout << "文件大小:" << fileSize << "Bytes" << endl;
	out << _T("文件大小:") << fileSize << "Bytes" << endl;
	//GetLimitCount(MaxLength + 1, fileSize);
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

