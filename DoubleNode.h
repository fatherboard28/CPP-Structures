#pragma once

namespace Structure {
	template <typename T>
	class DoubleNode {
	private:
		DoubleNode* next, prev;
		T element;
	public:
		// Constructors / Destructors
		DoubleNode() 
		{
			next = nullptr;
			prev = nullptr;
		}

		DoubleNode(T& e)
		{
			element = e;
			next = nullptr;
			prev = nullptr;
		}

		~DoubleNode()
		{

		}

		// Mutators
		void SetElement(T& e)
		{
			element = e;
		}

		void SetNext(DoubleNode& node)
		{
			next = &node;
		}

		void SetPrev(DoubleNode& node)
		{
			prev = &node;
		}

		// Accessors
		T GetElement() const
		{
			return this->element;
		}

		DoubleNode* GetNext() const
		{
			return this->next;
		}

		DoubleNode* GetPrev() const
		{
			return this->prev;
		}
	};
}