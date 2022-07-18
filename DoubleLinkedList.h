#pragma once
#include "DoubleNode.h"
#include <iostream>
#include <string>


namespace Structure {
	template <typename T>
	class DoubleLinkedList {
	private:
		DoubleNode<T>* pHead;
		DoubleNode<T>* pTail;
		int count;
	public:
		//Constructors & destructor----------------
		DoubleLinkedList() {
			count = 0;
			pHead = NULL;
			pTail = NULL;
		}
		//Mutators---------------------------------

		//add-to-head
		void AddToHead(T e) {
			//create new node pointer
			DoubleNode<T>* node = new DoubleNode<T>();

			//set new node element
			node->element = e;

			//Making links
			node->next = pHead;
			pHead->prev = node;

			//set new head
			pHead = node;

			//itterate count
			count++;

		}

		//add-to-tail
		void AddToTail(T e) {
			//New node
			DoubleNode<T>* node = new DoubleNode<T>();

			//set new node element
			node->element = e;

			//Making Links
			pTail->next = node;
			node->prev = pTail;

			//set tail to new node
			pTail = node;

			//increment count
			count++;
		}

		//remove-from-head
		T RemoveFromHead() {
			//check empty
			if (IsEmpty()) {
				std::cout << "ERROR: List empty. Connot Pop." << std::endl;
				return NULL;
			}
			else {
				//Temp node to pop
				DoubleNode<T>* pTemp = pHead;

				//set head to current head next
				pHead = pHead->next;

				T returnVal = pTemp->element;

				free(pTemp);

				//decrement count
				count--;

				return returnVal;
			}
		}

		//remove-from-tail
		T RemoveFromTail() {
			//check empty
			if (IsEmpty()) {
				std::cout << "ERROR: List empty. Connot Pop." << std::endl;
				return NULL;
			}
			else {
				//Temp node to pop
				DoubleNode<T>* pTemp = pTail;

				//set tail to node before current tail
				pTail = pTail->prev;

				T returnVal = pTemp->element;

				free(pTemp);

				//decrement count
				count--;

				return returnVal;

			}
		}


		//Accessors--------------------------------

		//isEmtpy
		bool IsEmpty() {
			return count == 0;
		}

		//go-to
		DoubleNode<T>* GoTo(int index) {
			if (IsEmpty())
				return NULL;
			if (count < index)
				return NULL;

			DoubleNode<T>* node = pHead;
			DoubleNode<T>** dpNode = &node;

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