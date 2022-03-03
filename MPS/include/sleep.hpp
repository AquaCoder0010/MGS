#pragma once
#include <ctime>

namespace aq{
    void sleep(const double secs) 
    {
	    clock_t delay = secs * CLOCKS_PER_SEC;
	    clock_t start = clock();
	    while (clock() - start < delay);
    }
};