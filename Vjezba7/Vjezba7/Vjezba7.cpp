#include "stdafx.h"
#include "vehicle.h"

int main()
{
	using namespace oss;
	Counter c;
	Vehicle* v[] = { new Bike(), new Car(), new Catamaran(30), new Ferry(10, 5, 3), new Seaplane(15)};
	size_t sz = sizeof v / sizeof v[0];
	for (unsigned i = 0; i < sz; ++i)
	{
		c.add(v[i]);
	}

	std::cout<< "ukupno " << c.total() << " putnika\n";
	for (unsigned i = 0; i < sz; ++i)
	{
		delete v[i];
	}
	return 0;
}

