#include "stdafx.h"

template<class T>
static bool Frequency::CmpPair(const pair<T, int>& left, const pair<T, int>& right)
{
	return left.second > right.second;
}

template<class T>
static void Frequency::SortTop(vector<pair<T, int>>& vec, const unsigned int n)
{
	unsigned int mapsize = min(n, vec.size());
	partial_sort(vec.begin(), vec.begin() + mapsize, vec.end(), CmpPair<T>);
	vec.resize(mapsize);
}

vector<pair<wstring, int>> Frequency::SortMap(const map<wstring, int>& m)
{
	vector<pair<wstring, int>> vp;
	for (auto p : m) {
		vp.push_back(p);
	}
	sort(vp.begin(), vp.end(), CmpPair<wstring>);
	return vp;
}

vector<pair<wstring, int>> Frequency::SortTopMap(const map<wstring, int>& m, const unsigned int n)
{
	vector<pair<wstring, int>> vp;
	vp.reserve(m.size());
	for (auto p : m) {
		vp.push_back(p);
	}
	SortTop(vp, n);
	return vp;
}

map<wstring, int> Frequency::VecToMapNo(const vector<pair<wchar_t, int>>& vec)
{
	map<wstring, int> m;
	for (auto iterP = vec.begin(); iterP != vec.end(); ++iterP) {
		m.insert(make_pair(wstring({ iterP->first }), iterP - vec.begin()));
	}
	return m;
}

map<wstring, int> Frequency::VecToMapNo(const vector<pair<wstring, int>>& vec)
{
	map<wstring, int> m;
	for (auto iterP = vec.begin(); iterP != vec.end(); ++iterP) {
		m.insert(make_pair(iterP->first, iterP - vec.begin()));
	}
	return m;
}


