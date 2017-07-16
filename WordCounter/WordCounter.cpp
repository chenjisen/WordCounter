#include "stdafx.h"


const unsigned int MaxLength = 5;
const vector<unsigned int> Frequency::WordNumber(MaxLength + 1, 1000);
const vector<int> LimitCount(MaxLength + 1, 4);
const unsigned int MaxSize = UINT_MAX;
//const unsigned int MaxSize = 1000;
typedef Sentence TextType;

const string WorkingPath = "d:\\WordCounter\\";
const string FileName = "�˳�";


int main()
{
	
	//���ļ���ע�⣺ʹ��ANSI��ǰ�漸��ɾ��
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

		TimingBegin;
		{
			
			GetFPeak<TextType>(vecF, vecText, i);
			if (!vecF.empty()) {
				out << _T("����Ƶ�ʽϸߵ�") << i << _T("�ִʣ�\n");
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




