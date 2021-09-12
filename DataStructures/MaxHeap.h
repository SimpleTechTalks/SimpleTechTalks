#include "iostream"

#define MAX_PRIORITY_QUEUE_SIZE 100
class MaxHeap
{
	private:
		int m_size;
		int m_data[MAX_PRIORITY_QUEUE_SIZE];
		int get_parent (int child_node_id);
		int left_child (int parent_id);
		int right_child (int parent_id);

	public:
		MaxHeap ();
		int get_size ();
		void insert (int data);
		bool isEmpty ();
		int find_maximum ();
		int delete_maximum ();
		void percolate_down (int hole);
		void percolate_up (int hole);
		void print_content ()
		{
			for (int i = 0; i < m_size; i++)
			{
				std::cout << m_data[i] << "  ";
			}
			std::cout << std::endl;
		}
};

MaxHeap::MaxHeap (): m_size(0)
{}

int MaxHeap::get_size ()
{
	return m_size;
}

int MaxHeap::get_parent (int child_node_id)
{
	if (child_node_id <= 0 || child_node_id >= m_size)
		return -1;
	return (child_node_id - 1)/2;
}

int MaxHeap::left_child (int parent_id)
{
	int left = 2 * parent_id + 1;
	if (left >= m_size)
		return -1;
	return left;
}

int MaxHeap::right_child (int parent_id)
{
	int right = 2 * parent_id + 2;
	if (right >= m_size)
		return -1;
	return right;
}

bool MaxHeap::isEmpty ()
{
	return (m_size == 0);
}

int MaxHeap::find_maximum ()
{
	return m_data[0];
}

void MaxHeap::insert (int data)
{
	int hole = m_size++;
    	m_data[hole] = data;
	percolate_up (hole);
}

void MaxHeap::percolate_up (int hole)
{
	int parent = get_parent (hole);
	if (parent == -1)
		return;
	if (m_data[parent] < m_data[hole])
	{
		int temp = m_data[parent];
		m_data[parent] = m_data[hole];
		m_data[hole] = temp;
		percolate_up (parent);
	}
}

int MaxHeap::delete_maximum ()
{
	int min_val = m_data[0];
	m_data[0] = m_data[--m_size];
	percolate_down (0);
	return min_val;
}

void MaxHeap::percolate_down (int hole)
{
	int left = left_child (hole);
	int right = right_child (hole);
	int min = hole;
	if (left != -1 && m_data[left] > m_data[min])
		min = left;
	if (right != -1 && m_data[right] > m_data[min])
		min = right;
	if (min != hole)
	{
		int temp = m_data[min];
		m_data[min] = m_data[hole];
		m_data[hole] = temp;
		percolate_down (min);
	}
}
