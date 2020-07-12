namespace test1
{
#include <iostream>
	using namespace std;

	// 动态数组
	struct Array
	{
	private:
		// header
		int* m_data;
		// size
		int m_size;
		//cap
		int m_capacity;
	public:
		Array(int cap = 0)
		{
			if (cap <= 0)
			{
				cap = 10;
			}
			this->m_capacity = cap;

			this->m_data = new int[this->m_capacity];
			this->m_size = 0;
		}
		~Array()
		{
			if (m_data == NULL) return;
			delete[] m_data;
		}
		void add(int val)
		{
			if (this->m_size >= this->m_capacity)
			{
				// 扩容
				// 1.申请一块更大的存储空间
				// 2.将旧空间的数据拷贝到新空间
				// 3.释放旧空间

				cout << "开始扩容 当前size: " << this->m_size << " 当前 cap: " << this->m_capacity << endl;
				return;
			}
			m_data[m_size++] = val;
		}
		int get(int idx)
		{
			if (idx < 0 || idx >= this->m_size)
			{
				//return -1;
				throw "数组下标越界";
			}
			return this->m_data[idx];
		}

		int cap()
		{
			return this->m_capacity;
		}

		int len()
		{
			return this->len();
		}
	};

	int main()
	{
		Array ar = Array();
		for (int i = 0; i < 11; i++)
		{
			ar.add(1212121212);
		}
		cout << "0: " << ar.get(1) << endl;

		return 0;
	}
}
