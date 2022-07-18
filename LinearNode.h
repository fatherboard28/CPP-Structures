#pragma once

namespace Structure {
	template <typename T>
	class LinearNode {
	public:
		LinearNode<T>* next;
		T element;
	};
}