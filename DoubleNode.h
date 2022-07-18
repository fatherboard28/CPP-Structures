#pragma once

namespace Structure {
	template <typename T>
	class DoubleNode {
	public:
		DoubleNode* next;
		DoubleNode* prev;
		T element;
	};
}