#include "iostream"

#define MAX_PRIORITY_QUEUE_SIZE 100
class PriorityQueue
{
	private:
		int m_size;
		int m_data[MAX_PRIORITY_QUEUE_SIZE];
		int get_parent (int child_node_id);
		int left_child (int parent_id);
		int right_child (int parent_id);

	public:
		PriorityQueue ();
		int get_size ();
		void insert (int data);
		bool isEmpty ();
		int find_minimum ();
		int delete_minimum ();
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

/* Constructor */
PriorityQueue::PriorityQueue (): m_size(0)
{}

/* Return current size of the Heap */
int PriorityQueue::get_size ()
{
	return m_size;
}

/* Return parent node index of a given node,
 * In case of root node, this will return -1 */
int PriorityQueue::get_parent (int child_node_id)
{
	if (child_node_id <= 0 || child_node_id >= m_size)
		return -1;
	return (child_node_id - 1)/2;
}

/* Return left child index of a node */
int PriorityQueue::left_child (int parent_id)
{
	int left = 2 * parent_id + 1;
	if (left >= m_size)
		return -1;
	return left;
}

/* Return right child index of a node */
int PriorityQueue::right_child (int parent_id)
{
	int right = 2 * parent_id + 2;
	if (right >= m_size)
		return -1;
	return right;
}

/* Check if heap is empty */
bool PriorityQueue::isEmpty ()
{
	return (m_size == 0);
}

/* Find minimum value in Heap */
int PriorityQueue::find_minimum ()
{
	return m_data[0];
}

void PriorityQueue::insert (int data)
{
	int hole = m_size++;
    m_data[hole] = data;
	percolate_up (hole);
}

void PriorityQueue::percolate_up (int hole)
{
	int parent = get_parent (hole);
	if (parent == -1)
		return;
	if (m_data[parent] > m_data[hole])
	{
		int temp = m_data[parent];
		m_data[parent] = m_data[hole];
		m_data[hole] = temp;
		percolate_up (parent);
	}
}

int PriorityQueue::delete_minimum ()
{
	int min_val = m_data[0];
	m_data[0] = m_data[--m_size];
	percolate_down (0);
	return min_val;
}

void PriorityQueue::percolate_down (int hole)
{
	int left = left_child (hole);
	int right = right_child (hole);
	int min = hole;
	if (left != -1 && m_data[left] < m_data[min])
		min = left;
	if (right != -1 && m_data[right] < m_data[min])
		min = right;
	if (min != hole)
	{
		int temp = m_data[min];
		m_data[min] = m_data[hole];
		m_data[hole] = temp;
		percolate_down (min);
	}
}
