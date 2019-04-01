#ifndef ZAD2_H
#define ZAD2_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

std::vector<int> filterVector(std::vector<int> v1, std::vector<int> v2)
{
	bool exists=false;
	std::vector<int> v;
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	for (std::vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
	{
		if (std::binary_search(v2.begin(), v2.end(), *it))
			exists = true;
		else exists = false;
		if (!exists)
			v.push_back(*it);
	}
	return v;
}

#endif