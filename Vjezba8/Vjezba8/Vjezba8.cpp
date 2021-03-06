#include "stdafx.h"
#include <iostream>
#include "ZooAnimal.h"
#include <vector>

int main()
{
	using namespace OSS;
	Tiger t("Tigi", 2000, 7, 2, 20, 1025);
	Monkey m("Miki", 2000, 7, 2, 20, 500);
	Elephant e("Luka", 2000, 7, 2, 20, 4025);
	GriffonVulture g("Grifi", 2000, 7, 2, 20, 712);
	Owl o("Luka", 2000, 7, 2, 20, 163);
	Crocodile c("Luka", 2000, 7, 2, 20, 1342);
	Turtle slow("Korni", 2000, 7, 2, 20, 512);
	std::cout << t;
	std::cout << m;
	std::cout << e;
	std::cout << g;
	std::cout << o;
	std::cout << c;
	std::cout << slow;
	t.print();
	m.print();
	e.print();
	g.print();
	o.print();
	c.print();
	slow.print();
	return 0;
}

