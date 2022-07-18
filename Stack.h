#pragma once
#include "LinearNode.h"
#include <iostream>

namespace Structure {
	template <typename T>
	class Stack {
	private:
		LinearNode<T>* pTop;
		int count;
	public:
		//Constructors / Destructors
		Stack()
		{
			pTop = nullptr;
			count = 0;
		}

		~Stack()
		{

		}

		//Mutators
		T Pop()
		{
			if (IsEmpty()) {
				std::cout << "ERROR: Stack Empty!" << std::endl;
				exit(1);
			}
			else {

				LinearNode<T>* pTemp = pTop;

				pTop = pTop->next;

				T returnVal = pTemp->element;

				free(pTemp);

				count--;

				return returnVal;
			}
		}

		void Push(T e)
		{
			LinearNode<T>* pNode = new LinearNode<T>();
			

			pNode->element = e;

			pNode->next = pTop;

			pTop = pNode;
			
			count++;
		}

		//Accessors
		T Peek()
		{
			if (IsEmpty())
				exit(1);
			return pTop->element;
		}

		bool IsEmpty()
		{
			return pTop == NULL;
		}

		int Size() {
			return count;
		}
	};
}
