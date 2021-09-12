class Sorting {
    private:
        int *m_array;
        int m_size;

    public:
        Sorting (int *arr, int siz): m_array (arr),
                                     m_size (siz) {
        }

        ~Sorting () {
        }
        void print_array ();
        void bubble_sort ();
};
void Sorting::print_array () {
    for (int i = 0; i < m_size; i++) {
        cout << " " << m_array[i];
    }
    cout << endl;
}

void Sorting::bubble_sort () {
    for (auto i = 0; i < m_size; i++) {
        for (int j = 0; j < m_size - i - 1; j++) {
            if (m_array[j] > m_array[j+1]) {
                int temp = m_array[j];
                m_array[j] = m_array[j+1];
                m_array[j+1] = temp;
            }
        }
    }
}
