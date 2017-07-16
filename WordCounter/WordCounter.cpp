#include "stdafx.h"
#include "WordCounter.h"

const unsigned int MaxLength = 5;
const vector<unsigned int> Frequency::WordNumber(MaxLength + 1, 1000);
const vector<int> LimitCount(MaxLength + 1, 4);

const int LimitPrintNumber = 100;
//const unsigned int MaxSize = UINT_MAX;
//const unsigned int MaxSize = 1000;
typedef Sentence TextType;

const string WorkingPath = "d:\\WordCounter\\";
const string FileName = "顾城";


int main()
{

	//打开文件，注意：使用ANSI；前面几行删掉
	wifstream in;
	wofstream out;
	try {
		in = OpenInFile(WorkingPath, FileName);
		out = OpenOutFile(WorkingPath, FileName);
	}
	catch (runtime_error err) {
		cerr << err.what() << endl;
		system("pause");
		return 1;
	}
	
	//输出相关信息
	out << "Time : " << GetStrTime() << endl
		<< Rule << endl
		<< "MaxLength = " << MaxLength << endl
		<< "WordNumber = " << Frequency::WordNumber[0] << endl
		<< "LimitCount = " << LimitCount[0] << endl
		<< "LimitPrintNumber = " << LimitPrintNumber << endl
		<< "TextType : " << typeid(TextType).name() << endl
		<< "WorkingPath : " << _w(WorkingPath) << endl 
		<< Rule << endl
		<< "FileName : " << _w(FileName) << endl;
	
	//读取文件
	vector<TextType> vecText;
	int charNum;

	TimingBegin;
	{
		cout << "正在读取消息记录……\n";
		vecText = TextType::GetVec(in, charNum);
		//out << _T("消息数量：") << size(vecText) << endl;
		out << _T("CharNum : ") << charNum << endl;

		//for (auto m : vecText) wcout << m.text << endl;
	}
	TimingEnd;

	in.close();


	//统计频率
	vector<pair<wstring, int>> vecF;
	for (int i = 1; i <= MaxLength; ++i) {
		cout << "正在统计出现频率较高的" << i << "字词……\n";

		TimingBegin;
		{

			GetFPeak<TextType>(vecF, vecText, i);
			if (!vecF.empty()) {
				out << Rule << endl
					<< _T("出现频率较高的") << i << _T("字词：") << endl << endl;
				PrintOutcome(vecF, LimitPrintNumber, charNum, out, wcout);

			}
			else {
				cout << "找不到频率较高的" << i << "字词！\n";
				out << _T("找不到频率较高的") << i << _T("字词！") <<endl;
				break;
			}

		}
		TimingEnd;

	}

	out.close();


	//system("pause");
	return 0;
}




