#pragma once
#include "LinearNode.h"
#include <iostream>
#include <string>


namespace Structure {
	template <typename T>
	class LinkedList {
	private:
		LinearNode<T>* pHead;
		LinearNode<T>* pTail;
		int count;
	public:
		//Constructors & destructor----------------
		LinkedList() {
			count = 0;
			pHead = NULL;
			pTail = NULL;
		}
		//Mutators---------------------------------

		//add-to-head
		void AddToHead(T e) {
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

		//add-to-tail
		void AddToTail(T e) {
			//New node
			LinearNode<T>* pNode = new LinearNode<T>();

			//set new node element
			pNode->element = e;

			//set prev node next to new node
			LinearNode<T>* pTemp = GoTo(count - 1);
			pTemp->next = pNode;
			//free(pTemp);

			//set tail to new node
			pTail = pNode;

			//increment count
			count++;
		}
		
		//remove-from-head
		T RemoveFromHead() {
			//check empty
			if (IsEmpty()) {
				std::cout << "ERROR: List empty. Connot Pop." <<std::endl;
				return NULL;
			}
			else {
				//Temp node to pop
				LinearNode<T>* pTemp = pHead;

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
			if (IsEmpty()){
				std::cout << "ERROR: List empty. Connot Pop." <<std::endl;
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


		//Accessors--------------------------------

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