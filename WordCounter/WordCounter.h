#pragma once

using namespace std;

const wstring Rule = L"\n--------------------------------------------------\n";

wstring _w(const string &str)
{
	wstring wstr(str.length(), L' ');
	int nLen = (int)str.length();
	int nResult = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)str.c_str(),
		nLen, (LPWSTR)wstr.c_str(), nLen);
	return wstr;
}

wstring GetStrTime()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	wstring strHour=to_wstring(sys.wHour), 
		strMinute=to_wstring(sys.wMinute),
		strSecond=to_wstring(sys.wSecond);

	if (strHour.length() == 1) strHour = L'0' + strHour;
	if (strMinute.length() == 1) strMinute = L'0' + strMinute;
	if (strSecond.length() == 1) strSecond = L'0' + strSecond;


	return to_wstring(sys.wYear) + wstring({ '/' })
		+ to_wstring(sys.wMonth) + wstring({ '/' })
		+ to_wstring(sys.wDay) + wstring({ '\t' })
		+ strHour + wstring({ ':' })
		+ strMinute + wstring({ ':' })
		+ strSecond;
}


wifstream OpenInFile(const string& WorkingPath, const string& FileName)
{
	wcout.imbue(locale("chs"));

	string strInFilePath = WorkingPath + FileName + string(".txt");
	wifstream file(strInFilePath.c_str());
	if (!file)
		throw runtime_error("Open in file error!");
	file.imbue(locale("chs"));

	return file;
}

wofstream OpenOutFile(const string& WorkingPath, const string& FileName)
{

	string strOutFilePath = WorkingPath + FileName + string("_Outcome.txt");
	wofstream file(strOutFilePath.c_str());
	if (!file)
		throw runtime_error("Open out file error!");
	file.imbue(locale("chs"));
	return file;
}

template <class T>
void GetFPeak(vector<pair<wstring, int>>& vecFPeak, const vector<T>& vecMsg, int i)
{
	map<wstring, int> FPeakShort = Frequency::VecToMapNo(vecFPeak);
	if (i == 1)
		vecFPeak = Frequency::ChCount<TextType>(vecMsg, LimitCount[i]);
	else
		vecFPeak = Frequency::Count<TextType>(vecMsg, LimitCount[i], FPeakShort, i);
}


void PrintOutcome(const vector<pair<wstring, int>>& vecF, const int LimitPrintNumber,
	const int charNum, wofstream& out, wostream& wcout)
{
	int PrintNumber = 0;
	bool isUseless;

	for (auto p : vecF) {

		//符号判断
		isUseless = false;
		wstring str = p.first;
		for (wchar_t ch : str) {
			if (ch == _T('，') || ch == _T('　') || ch == _T(' ')) {
				isUseless = true;
				break;
			}
		}
		if (isUseless) continue;

		//继续循环的条件
		if (PrintNumber <= LimitPrintNumber) {
			++PrintNumber;

			double count = p.second;

			wcout << setprecision(0) << str << '\t' << count
				<< '\t' << fixed << setprecision(3)
				<< count * 1000 / charNum << _T("‰\n");
			out << setprecision(0) << str << '\t' << count
				<< '\t' << fixed << setprecision(3)
				<< count * 1000 / charNum << _T("‰\n");

		}
		else
			break;




	}
}