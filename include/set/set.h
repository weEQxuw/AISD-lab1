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

		Node* get_root()
		{
			return _root;
		}

		int get_size()
		{
			return size(_root);
		}

		Set() : _root(nullptr) {};

		Node* copy_set(Node* ptr) 
		{
			if (ptr == nullptr)
				return nullptr;
			
			Node* new_node = new Node(ptr->_value);
			new_node->_left = copy_set(ptr->_left);
			new_node->_right = copy_set(ptr->_right);
			return new_node;

		}

		Set(Set& another) 
		{
			_root = copy_set(another._root);
		}

		void print_set()
		{
			return print(_root);
		}

		bool contains(int key)
		{
			Node* ptr = _root;

			while (ptr != nullptr || ptr->_value == key)
			{
				if (key < ptr->_value)
					ptr = ptr->_left;
				else
					ptr = ptr->_right;


			}
			return ptr != nullptr;

		}

	};

}