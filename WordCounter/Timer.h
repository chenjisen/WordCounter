#pragma once

#include <ctime>

static double timer;

#define TimingBegin TimingBegin()
#define TimingEnd TimingEnd()

inline void TimingBegin
{
	timer = clock(); 
}

inline void TimingEnd
{
	std::cout << "��ʱ" << (clock() - timer) / (double)CLOCKS_PER_SEC << "��\n";
}



