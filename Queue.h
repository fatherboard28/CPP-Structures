#pragma once
#include "LinearNode.h"
#include <iostream>

namespace Structure {
	template <typename T>
	class Queue {
	private:
		LinearNode<T>* pHead;
		LinearNode<T>* pTail;
		int count;
	public:
		Queue() {
			count = 0;
			pHead = NULL;
			pTail = NULL;
		}

		void Enqueue() {
			//create new node pointer
			LinearNode<T>* node = new LinearNode<T>();

			//set new node element
			node->element = e;

			//set new node pointer
			node->next = pHead;

			//set new head
			pHead = node;

			//itterate count
			count++;
		}

		void Dequeue() {
			//check empty
			if (IsEmpty()) {
				std::cout << "ERROR: List empty. Connot Pop." << std::endl;
				return NULL;
			}
			else {
				//Temp node to pop
				LinearNode<T>* pTemp = pTail;

				//set tail to node before current tail
				pTail = GoTo(count - 2);

				T returnVal = pTemp->element;

				free(pTemp);

				//decrement count
				count--;

				return returnVal;
			}
		}

		//isEmtpy
		bool IsEmpty() {
			return count == 0;
		}

		//go-to
		LinearNode<T>* GoTo(int index) {
			if (IsEmpty())
				return NULL;
			if (count < index)
				return NULL;

			LinearNode<T>* node = pHead;
			LinearNode<T>** dpNode = &node;

			if (node == NULL)
				return NULL;

			int counter = 0;
			while (counter != index) {
				if (node->next != NULL)
					break;
				*dpNode = node->next;
				counter++;
			}
			return node;
		}

		//count
		int Size() {
			return count;
		}
	};
}