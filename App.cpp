#include "Stack.h"
#include "LinkedList.h"
#include <iostream>

using namespace Structure;

int main() {
	LinkedList<int> list;

	list.AddToHead(1);
	std::cout << "Expect: 1. Got: " << (list.GoTo(0)->element) << std::endl;
	//after: 1

	list.AddToTail(2);
	std::cout << "Expect: 2. Got: " << (list.GoTo(1)->element) << std::endl;
	//after: 1 - 2

	int x = list.RemoveFromHead();
	std::cout << "Expect: 1. Got: " << x << std::endl;
	//after: 2


	list.AddToHead(3);
	std::cout << "Expect: 3. Got: " << (list.GoTo(0)->element) << std::endl;
	//after: 3 - 2


	int y = list.RemoveFromTail();
	std::cout << "Expect: 2. Got: " << y << std::endl;
	//after: 3

	int z = list.RemoveFromHead();
	std::cout << "Expect: 3. Got: " << z << std::endl;
	//after: 

	int g = list.RemoveFromHead();
	//after err



	system("pause");
}
