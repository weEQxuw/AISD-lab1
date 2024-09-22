#pragma once
#include <iostream>

using namespace std;

namespace set 
{
	struct Node 
	{
		int _value;
		Node* _left;
		Node* _right;

		Node() : _left(nullptr), _right(nullptr) {};

		Node(int value) : _value(value), _left(nullptr), _right(nullptr) {};

	};



	int size(Node* ptr)
	{
		if (ptr == nullptr)
			return 0;

		return 1 + size(ptr->_left) + size(ptr->_right);

	}


	void print(Node* root)
	{
		if (root != nullptr)
		{
			print(root->_left);
			cout << root->_value << " ";
			print(root->_right);

		}
	}

	


	class Set
	{
	private:

		Node* _root;

	public: 

		Node* get_root() const
		{
			return _root;
		}

		int get_size()
		{
			return size(_root);
		}

		Set() : _root(nullptr) {};

		Set(const Set& another)
		{
			_root = copy_set(another._root);
		}

		void delete_node(Node*& ptr)
		{
			if (ptr == nullptr)
				return;

			delete_node(ptr->_left);
			delete_node(ptr->_right);
			delete ptr;
			ptr = nullptr;
		}

		~Set()
		{
			delete_node(_root);
		}

		Node* copy_set(Node* ptr) 
		{
			if (!ptr)
				return nullptr;
			
			Node* new_node = new Node(ptr->_value);
			new_node->_left = copy_set(ptr->_left);
			new_node->_right = copy_set(ptr->_right);
			return new_node;

		}

		void print_set()
		{
			return print(_root);
		}

		bool contains(int key) const
		{
			Node* ptr = _root;

			while (ptr != nullptr && ptr->_value == key)
			{
				if (key < ptr->_value)
					ptr = ptr->_left;
				else
					ptr = ptr->_right;
			}

			return ptr != nullptr;

		}

		bool insert(int value)
		{
			if (_root == nullptr)
			{
				_root = new Node(value);
				return true;
			}

			if (contains(value) == true)
				return false;

			Node* ptr = _root;

			while (ptr != nullptr)
			{
				if (value < ptr->_value && ptr->_left == nullptr)
				{
					ptr->_left = new Node(value);
					return true;
				}

				if (value > ptr->_value && ptr->_right == nullptr)
				{
					ptr->_right = new Node(value);
					return true;
				}

				if (value < ptr->_value)
					ptr = ptr->_left;
				else
					ptr = ptr->_right;
			}
		}

		bool erase(int value)
		{

			Node* ptr = _root;
			Node* pre_ptr = nullptr;

			while (ptr && ptr->_value != value)
			{
				pre_ptr = ptr;

				if (value < ptr->_value)
					ptr = ptr->_left;
				else
					ptr = ptr->_right;

				
			}

			if (ptr == nullptr)
				return false;

			if (ptr->_left == nullptr && ptr->_right == nullptr)
			{
				if (ptr != _root)
				{
					if (pre_ptr->_left == ptr)
						pre_ptr->_left == nullptr;
					else
						pre_ptr->_right == nullptr;
				}
				else
					_root = nullptr;

				delete ptr;
				return true;

			}

			if (ptr->_left == nullptr)
			{
				if (ptr == _root)
				{
					_root = _root->_right;
					delete ptr;
					return true;
				}

				if (pre_ptr->_left == ptr)
				{
					pre_ptr->_left = ptr->_right;
				}

				if (pre_ptr->_right == ptr)
				{
					pre_ptr->_right == ptr->_right;
				}

				delete ptr;
				return true;
			}

			if (ptr->_right == nullptr)
			{
				if (ptr == _root)
				{
					_root = _root->_left;
					delete ptr;
					return true;
				}

				if (pre_ptr->_left == ptr)
				{
					pre_ptr->_left = ptr->_left;
				}

				if (pre_ptr->_right == ptr)
				{
					pre_ptr->_right = ptr->_left;
				}

				delete ptr;
				return true;

			}

			Node* extra_ptr = ptr->_right;
			pre_ptr = ptr;

			while (extra_ptr->_left)
			{
				pre_ptr = extra_ptr;
				extra_ptr = extra_ptr->_left;
			}

			ptr->_value = extra_ptr->_value;

			if (pre_ptr == ptr)
				ptr->_right = extra_ptr->_right;
			else
				pre_ptr->_left = extra_ptr->_right;

			delete extra_ptr;
		}

	};

	void sub_union(Node* ptr, Set& c) {
		if (ptr == nullptr) {
			return;
		}
		c.insert(ptr->_value);
		sub_union(ptr->_left, c);
		sub_union(ptr->_right, c);
	};

	Set uni(const Set& a, const Set& b) {
		Set c(b);
		sub_union(a.get_root(), c);
		return c;
	}

	void sub_symmetrical_difference(Node* ptr, const Set& b, Set& c) {
		if (ptr == nullptr) {
			return;
		}
		if (!b.contains(ptr->_value)) {
			c.insert(ptr->_value);
		}
		sub_symmetrical_difference(ptr->_left, b, c);
		sub_symmetrical_difference(ptr->_right, b, c);
	};

	Set symmetrical_difference(const Set& a, const Set& b) {
		Set c;
		sub_symmetrical_difference(a.get_root(), b, c);
		sub_symmetrical_difference(b.get_root(), a, c);
		return c;
	}

	size_t lcg() {
		static size_t x = 0;
		x = (1021 * x + 24631) % 116640;
		return x;
	}

}