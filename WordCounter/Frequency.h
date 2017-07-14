#pragma once

using std::vector;
using std::map;
using std::pair;
using std::wstring;


class Frequency
{
private:
	enum WordSide { Left, Right };

	template<class T>
	static bool CmpPair(const pair<T, int>& left, const pair<T, int>& right);

	template<class T>
	static void SortTop(vector<pair<T, int>>& vec, const unsigned int n);

	static vector<pair<wstring, int>> SortMap(const map<wstring, int>& m);
	static vector<pair<wstring, int>> SortTopMap(const map<wstring, int>& m, const unsigned int n);


public:

	static const vector<unsigned int> WordNumber;

	template<class T>
	static vector<pair<wstring, int>> Count
	(const vector<T>& vm, const int LimitCount,
		const map<wstring, int>& FPeakShort, const unsigned int Length);

	template<class T>
	static vector<pair<wstring, int>> Frequency::ChCount
	(const vector<T>& vm, const int LimitCount);


	static map<wstring, int> VecToMapNo(const vector<pair<wchar_t, int>>& vec);
	static map<wstring, int> VecToMapNo(const vector<pair<wstring, int>>& vec);
};



template<class T>
static vector<pair<wstring, int>> Frequency::Count(const vector<T>& vm, const int LimitCount,
	const map<wstring, int>& FPeakShort, const unsigned int Length)
{

	const unsigned int shortLength = Length - 1;
	vector<map<wchar_t, int>> mapCount[2];
	mapCount[Left].resize(WordNumber[shortLength]);
	mapCount[Right].resize(WordNumber[shortLength]);

	for (auto m : vm) {
		wstring text = m.text;
		if (text.length() >= Length) {

			for (auto ch_iter = text.begin();
				ch_iter != text.end() - shortLength + 1;
				++ch_iter) {
				int pos = ch_iter - text.begin();
				auto findShort = FPeakShort.find(text.substr(pos, shortLength));
				if (findShort != FPeakShort.end()) {  //找到高频字
													  //防止越界			
					if (ch_iter >= text.begin() + 1)
						++(mapCount[Left][findShort->second])[*(ch_iter - 1)];
					if (ch_iter <= text.end() - 1 - shortLength)
						++(mapCount[Right][findShort->second])[*(ch_iter + shortLength)];
				}
			}

		}

	}

	map<wstring, int> mapFPeakLong;
	for (auto chPair : FPeakShort) {
		for (WordSide side : {Left, Right}) {
			for (auto chSidePair : mapCount[side][chPair.second]) {
				if (chSidePair.second > LimitCount) {
					wstring longString;
					if (side == Left)
						longString = wstring({ chSidePair.first }) + chPair.first;
					else
						longString = chPair.first + wstring({ chSidePair.first });

					mapFPeakLong.insert(make_pair(longString, chSidePair.second));
				}
			}
		}
	}

	return SortTopMap(mapFPeakLong, WordNumber[Length]);

}

template<class T>
static vector<pair<wstring, int>> Frequency::ChCount(const vector<T>& vm, int LimitCount)
{
	vector<int> vecF(65535);
	vector<pair<wstring, int>> vecFPeak;
	vecFPeak.reserve(WordNumber[1]);

	for (auto m : vm) {
		for (wchar_t ch : m.text) {
			++vecF[(int)ch];  //用map的时间是用vector的2~3倍
		}
	}

	for (size_t i = 0; i < vecF.size(); ++i) {
		if (vecF[i] > LimitCount) {   //提高效率
			vecFPeak.push_back(make_pair(wstring({ (wchar_t)i }), vecF[i]));
		}
	}

	SortTop(vecFPeak, WordNumber[1]);
	return vecFPeak;
}

