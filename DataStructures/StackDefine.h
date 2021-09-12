class Stack
{
    private:
        int size;
        int top;
        int* elements;

    public:
        Stack (int sz);
        ~Stack ();
        bool push (int value);
        int pop ();
        bool isEmpty ();
        int maxSize ();
        int entries ();
        int atTop ()
        {
            return elements[top - 1];
        }
        void printContent ()
        {
            cout << "Stack contents: " ;
            for (int i = 0; i < top; i++)
                cout << elements[i] << " ";
            cout << endl;
        }
};

Stack::Stack (int sz): size (sz),
                       top (0)
{
    elements = new int[size]();

    if (!elements)
    {
        cout << "Stack initialization failed" << endl;
    }
}

Stack::~Stack ()
{
    if (elements)
    {
        delete [] elements;
    }
}

bool Stack::push (int value)
{
    if (!elements)
    {
        cout << "Stack initialization failed" << endl;
        return false;
    }

    if (top == size)
    {
        cout << "Stack full, unable to PUSH !!!" << endl;
        return false;
    }

    elements [top++] = value;
    return true;
}

bool Stack::isEmpty ()
{
    return !top;
}

int Stack::maxSize ()
{
    return size;
}

int Stack::entries ()
{
    return top;
}

int Stack::pop ()
{
    if (!elements)
    {
        cout << "Stack initialization failed" << endl;
        return -1;
    }

    if (!top)
    {
        cout << "Stack empty, unable to POP !!!" << endl;
        return -1;
    }

    return elements[--top];
}

template <typename T>
class StackGeneric
{
    private:
        int size;
        int top;
        T* elements;

    public:
        StackGeneric (int sz);
        ~StackGeneric ();
        bool push (T value);
        T pop ();
        bool isEmpty ();
        int maxSize ();
        int entries ();
        T* atTop ();
};

template <typename T>
T* StackGeneric<T>::atTop ()
{
    return &elements[top-1];
}

template <typename T>
StackGeneric<T>::StackGeneric(int sz): size(sz), top (0)
{
    elements = new T[size]();

    if (!elements)
    {
        cout << "Stack initialization failed" << endl;
    }
}

template <typename T>
StackGeneric<T>::~StackGeneric()
{
    if (elements)
    {
        delete [] elements;
    }
}

template <typename T>
bool StackGeneric<T>::push (T value)
{
    if (!elements)
    {
        cout << "StackGeneric initialization failed" << endl;
        return false;
    }

    if (top == size)
    {
        cout << "StackGeneric full, unable to PUSH !!!" << endl;
        return false;
    }

    elements [top++] = value;
    return true;
}

template <typename T>
bool StackGeneric<T>::isEmpty ()
{
    return !top;
}

template <typename T>
int StackGeneric<T>::maxSize ()
{
    return size;
}

template <typename T>
int StackGeneric<T>::entries ()
{
    return top;
}

template <typename T>
T StackGeneric<T>::pop ()
{
    if (!elements)
    {
        cout << "StackGeneric initialization failed" << endl;
        return -1;
    }

    if (!top)
    {
        cout << "StackGeneric empty, unable to POP !!!" << endl;
        return -1;
    }

    return elements[--top];
}

bool check_balanced_symbols (char* exp)
{
    StackGeneric<char> s(100);
    char* temp = exp;
    while (*temp != '\0')
    {
        if (*temp == '{' || *temp == '(' || *temp == '[')
        {
            s.push(*temp);
        }
        else if (*temp == ')')
        {
            char x = s.pop();
            if (x != '(')
            {
                cout << "Symbol is not balanced" << endl;
                return false;
            }
        }
        else if (*temp == '}')
        {
            char x = s.pop();
            if (x != '{')
            {
                cout << "Symbol is not balanced" << endl;
                return false;
            }
        }
        else if (*temp == ']')
        {
            char x = s.pop();
            if (x != '[')
            {
                cout << "Symbol is not balanced" << endl;
                return false;
            }
        }
        temp++;
    }
    if (s.entries() > 0)
    {
        cout << "Symbol is not balanced" << endl;
        return false;
    }
    cout << "Symbol is balanced" << endl;
    return true;
}

int return_operator_precedence (char* oper)
{
    if (*oper == '^')
        return 3;
    else if (*oper == '*' || *oper == '/')
        return 2;
    else if (*oper == '+' || *oper == '-')
        return 1;
    else
        return -1;
}

void convert_infix_to_postfix (char* exp)
{
    StackGeneric<char> oper (100);
    char* temp = exp;
    char postfix[100] = "";
    int postfix_index = 0;

    while (*temp != '\0')
    {
        if ((*temp >= 'a' && *temp <= 'z') || (*temp >= 'A' && *temp <= 'Z'))
        {
            postfix[postfix_index++] = *temp;
        }
        else if (*temp == ')')
        {
            char c = oper.pop ();
            while (c != '(')
            {
                postfix[postfix_index++] = c;
                c = oper.pop ();
            }
        }
        else if (*temp == '(')
        {
            oper.push (*temp);
        }
        else
        {
            if (oper.isEmpty ())
            {
                oper.push (*temp);
            }
            else if (return_operator_precedence (temp) <= return_operator_precedence (oper.atTop ()))
            {
                postfix[postfix_index++] = oper.pop ();
                oper.push (*temp);
            }
            else
            {
                oper.push (*temp);
            }
        }
        temp++;
    }
    while (!oper.isEmpty ())
    {
        postfix[postfix_index++] = oper.pop ();
    }
    postfix[postfix_index++] = '\0';
    cout << "Infix expression: " << exp << " Postfix expression: " << postfix << endl;
}

void evaluate (char* postfix)
{
    StackGeneric<int> oper (100);
    char* temp = postfix;

    while (*temp != '\0')
    {
        if (*temp >= '0' && *temp <= '9')
        {
            oper.push (int (*temp - 48));
        }
        else
        {
            int x = oper.pop ();
            int y = oper.pop ();
            switch (*temp)
            {
                case '+':
                    oper.push(x + y);
                    break;
                case '-':
                    oper.push(y - x);
                    break;
                case '*':
                    oper.push(x * y);
                    break;
                case '/':
                    oper.push(y / x);
                    break;
            }
        }
        temp++;
    }
    cout << "Final value: " << oper.pop () << endl;
}

void evaluate_postfix_expression (char* exp)
{
    StackGeneric<char> oper (100);
    char* temp = exp;
    char postfix[100] = "";
    int postfix_index = 0;

    while (*temp != '\0')
    {
        if (*temp >= '0' && *temp <= '9')
        {
            postfix[postfix_index++] = *temp;
        }
        else if (*temp == ')')
        {
            char c = oper.pop ();
            while (c != '(')
            {
                postfix[postfix_index++] = c;
                c = oper.pop ();
            }
        }
        else if (*temp == '(')
        {
            oper.push (*temp);
        }
        else
        {
            if (oper.isEmpty ())
            {
                oper.push (*temp);
            }
            else if (return_operator_precedence (temp) <= return_operator_precedence (oper.atTop ()))
            {
                postfix[postfix_index++] = oper.pop ();
                oper.push (*temp);
            }
            else
            {
                oper.push (*temp);
            }
        }
        temp++;
    }
    while (!oper.isEmpty ())
    {
        postfix[postfix_index++] = oper.pop ();
    }
    postfix[postfix_index++] = '\0';
    cout << "Infix expression: " << exp << " Postfix expression: " << postfix << endl;
    evaluate (postfix);
}

class StackMinimum
{
    private:
        Stack m_value;
        Stack m_min;
    public:
        StackMinimum (int size): m_value (size),
                                 m_min (size)
        {}

        bool push (int value)
        {
            if (!m_value.push (value))
                return false;

            if (!m_min.isEmpty() && m_min.atTop () < value)
            {
                return m_min.push (m_min.atTop ());
            }
            else
            {
                return m_min.push (value);
            }
        }

        int pop ()
        {
            m_min.pop ();
            return m_value.pop ();
        }

        int getMinimum ()
        {
            if (m_min.isEmpty ())
            {
                cout << "Stack is empty returning error: ";
                return -1;
            }
            return m_min.atTop ();
        }

        int entries ()
        {
            return m_value.entries ();
        }

        bool push_modified (int value)
        {
            if (!m_value.push (value))
                return false;

            if (m_min.isEmpty() || m_min.atTop () >= value)
            {
                return m_min.push (value);
            }
        }

        int pop_modified ()
        {
            if (m_value.atTop () == m_min.atTop ())
            {
                m_min.pop ();
            }
            return m_value.pop ();
        }

        void size ()
        {
            cout << "Main Stack size: " << m_value.entries () << endl;
            cout << "Minimum Stack size: " << m_min.entries () << endl;
        }
};

void insert_at_bottom (Stack* s, int data)
{
    if (s -> isEmpty ())
    {
        s -> push (data);
        return;
    }
    int temp = s -> pop ();
    insert_at_bottom (s, data);
    s -> push (temp);
}

void reverse_stack_data (Stack* s)
{
    if (s->isEmpty ())
        return;
    int data = s -> pop ();
    reverse_stack_data (s);
    insert_at_bottom (s, data);
}

/* Programs to write
 * 7. Implement 2 stacks using one single array
 */

class DoubleStack
{
    private:
        int size;
        int top_left;
        int top_right;
        int* elements;

    public:
        DoubleStack (int sz): size (sz),
                            top_left (0),
                            top_right (sz - 1)
        {
            elements = new int[size] ();
            if (!elements)
            {
                cout << "Stack initialization failed" << endl;
            }
        }
        ~DoubleStack ()
        {
            delete []elements;
        }
        bool push (int value, bool first)
        {
            if (top_left >= top_right)
            {
                cout << "Stack full" << endl;
                return false;
            }
            if (first)
            {
                elements[top_left++] = value;
                return true;
            }
            elements[top_right--] = value;
            return true;
        }
        int pop (bool first)
        {
            if (first)
            {
                if (!top_left)
                {
                    cout << "Stack is empty" << endl;
                    return -1;
                }
                return elements[--top_left];
            }
            if (top_right == size - 1)
            {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return elements[++top_right];
        }
        bool isEmpty (bool first)
        {
            if (first)
            {
                return !top_left;
            }
            return (top_right == (size - 1));
        }
        int entries (bool first)
        {
            if (first)
                return top_left;
            return (size - top_right);
        }

        void printContent ()
        {
            cout << "First Stack contents: " ;
            for (int i = 0; i < top_left; i++)
                cout << elements[i] << " ";
            cout << endl;

            cout << "Second Stack contents: " ;
            for (int i = size - 1; i > top_right; i--)
                cout << elements[i] << " ";
            cout << endl;
        }
};