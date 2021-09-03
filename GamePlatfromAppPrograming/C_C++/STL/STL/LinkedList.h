#pragma once

namespace demo
{
	template <typename Type>
	class list
	{
		class iterator* pBegin;
		class iterator* pEnd;
	public :
		class iterator
		{
			Type data;
		public:
			iterator(Type data)
			{
				this->data = data;
			}
			iterator* operator++()
			{

			}
			iterator* operator--()
			{

			}
			iterator* operator++(int)
			{

			}
			iterator* operator--(int)
			{

			}
		};
	public:
		list(int size = 0)
		{

		}
		void resize(int size)
		{

		}
		int size()
		{
			return 0;
		}
		public iterator* begin()
		{
			return pBegin;
		}
		public iterator* end()
		{
			return pEnd;
		}
		public void push_back(Type data)
		{

		}
		public iterator* insert(iterator& it, Type insert)
		{
			iterator* pInsert;
			return pInsert;
		}
		public iterator* eraser(iterator& it)
		{

		}
		void pop_back()
		{

		}
	public:
		
	};
}