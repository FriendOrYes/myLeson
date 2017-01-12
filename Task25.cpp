#include <iostream>
#include <cassert>
#include <cstring>
#include <cmath>

using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

template<class T>
class Stack
{
    size_t m_maxSize;
    T* m_stackPtr;
    int m_top;
public:
    Stack(const int& size = 10)
        : m_maxSize(size)
        , m_stackPtr(new T[m_maxSize])
        , m_top(0)
    {

    }
    Stack(const Stack& obj)
        : m_maxSize(obj.m_maxSize)
        , m_stackPtr(new T[m_maxSize])
        , m_top(obj.m_top)
    {
        for(size_t i = 0; i < m_top; ++i)
        {
            m_stackPtr[i] = obj.m_stackPtr[i];
        }
    }
    ~Stack()
    {
        delete []m_stackPtr;
    }

    inline void Push(const T& elem)
    {
        if(m_top > m_maxSize)
        {
            return;
        }

        m_stackPtr[m_top++] = elem;
    }
    inline const T& Pop()
    {
        if(m_top < 1)
        {
            return 0;
        }

        return m_stackPtr[m_top--];
    }
    inline const T &Peek(const int &index)
    {
        if(index >= top)
        {
            return 0;
        }

        return m_stackPtr[top - index];
    }
    void PrintStack()const
    {
        for(size_t i = 0; i < m_top; i++)
        {
            cout << m_stackPtr[i] << endl;
        }
    }
    const size_t& GetStackSize()const
    {
        return m_maxSize;
    }
    T *GetPtr()const
    {
        return m_stackPtr;
    }
    const int& GetTop()const
    {
        return m_top;
    }

    void ChangeStackValue(const T* array, const int& size)
    {
        delete []m_stackPtr;
        m_maxSize = size;
        m_stackPtr = new T[m_maxSize];
        m_top = 0;
        for(int i = 0; i < size; ++i)
        {
            m_stackPtr[i] = array[i];
            m_top++;
        }
    }
    const Stack& operator = (const Stack& obj)
    {
        delete []m_stackPtr;
        m_maxSize = obj.m_maxSize;
        m_stackPtr = new T[m_maxSize];
        m_top = obj.m_top;

        for(size_t i = 0; i < top; ++i)
        {
            m_stackPtr[i] = obj.m_stackPtr[i];
        }
    }
    const T & operator[](const size_t& index)
    {
        if(index >= top)
        {
            return 0;
        }

        return m_stackPtr[top - index];
    }
};
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
template<>
class Stack<bool>
{
    size_t m_maxSize;
    char* m_stackPtr;
    int m_top;

    void SizeСalculation(int size)
    {
        m_maxSize = 1;

        while((size - 8) > 0)
        {
            m_maxSize++;
            size -= 8;
        }
    }
public :
    Stack(int size = 15)
        : m_maxSize(1)
        , m_stackPtr(new char[m_maxSize])
        , m_top(0)
    {
        SizeСalculation(size);

        m_stackPtr = new char[m_maxSize];
    }

    Stack(const Stack& obj)
        : m_maxSize(obj.m_maxSize)
        , m_stackPtr(new char[m_maxSize])
        , m_top(obj.m_top)
    {
        cout << "Stack(copy) " << endl;
        strcpy(m_stackPtr,obj.m_stackPtr);
    }

    ~Stack()
    {
        delete []m_stackPtr;
    }
//-------------------------------------------------------------------------
    inline void Push(const bool& elem)
    {
        cout << __FUNCTION__ << endl ;
        if(m_top > m_maxSize * 8)
        {
            cout << " Overflow Stack" << endl;
            return ;
        }

        int numElem = m_top / 8;
        int offsetElem = m_top % 8;

        m_stackPtr[numElem] ^= (-elem ^ m_stackPtr[numElem])
                & (1 << (7 - offsetElem));
        m_top++;
        cout << m_top << endl;
    }
//-------------------------------------------------------------------------
    const char& Pop()
    {
        if(m_top > 0)
        {
            return 0;
        }

        int numElemet = m_top / 8;
        int offsetElem = m_top % 8;

        m_top--;

        return (1 & (m_stackPtr[numElemet] >> offsetElem));
    }
//-------------------------------------------------------------------------
    const bool &Peek(const int &index)
    {
        if(index >= m_top)
        {
            return 0;
        }
        int i = index / 8;
        int offsetElem = abs(7 - index);
        return (1 & (m_stackPtr[i] >> offsetElem));
    }
//-------------------------------------------------------------------------
    void PrintStack()const
    {
        cout << __FUNCTION__ << endl ;

        int i = 0, k = 7;
        int offsetElem = k % 8, top = m_top;

        while(top--)
        {
            cout << (1 & (m_stackPtr[i] >> offsetElem)) << " | ";

            if(k-- == 0)
            {
                k = 7;
            }
            i = (m_top - top) / 8;
            offsetElem = k % 8;
        }
        cout << endl;
    }
//-------------------------------------------------------------------------
    void ChangeStackValue(const bool* array,const int& size)
    {
        cout << __FUNCTION__ << " const bool " << endl;

        delete []m_stackPtr;
        SizeСalculation(size);

        m_top = 0;
        m_stackPtr = new char[m_maxSize];

        int numElem = m_top / 8;
        int offsetElem = m_top % 8;

        for(int i = 0; i < size; ++i )
        {
            m_stackPtr[numElem] ^= ( -array[i] ^ m_stackPtr[numElem])
                &(1 << (7 - offsetElem));
            m_top++;
            numElem = m_top / 8;
            offsetElem = m_top % 8;
        }
    }
//-------------------------------------------------------------------------
    const size_t& GetStackSize()const
    {
        return m_maxSize;
    }
    size_t GetStackLenght()const
    {
        return m_maxSize * 8;
    }
    char *GetPtr()const
    {
        return m_stackPtr;
    }
    const int& GetTop()const
    {
        return m_top;
    }
//-------------------------------------------------------------------------
    const Stack& operator = (const Stack& obj)
    {
        cout << __FUNCTION__ << endl;
        delete []m_stackPtr;

        m_maxSize = obj.m_maxSize;
        m_stackPtr = new char[m_maxSize];
        m_top = obj.m_top;

        for(size_t i = 0; i < m_maxSize; ++i)
        {
            m_stackPtr[i] = obj.m_stackPtr[i];
        }
    }
//-------------------------------------------------------------------------
    const bool & operator[](const int& index)
    {
        if(index >= m_top)
        {
            return 0;
        }
        int i = index / 8;
        int offsetElem = abs(7 - index);
        return (1 & (m_stackPtr[i] >> offsetElem));
    }
//-------------------------------------------------------------------------
};

int main(int argc, char *argv[])
{
    const int size = 10;

    bool elem[size] =  {
         1,0,0,1,0,0,0,1,0,0
    };

    Stack<bool> st;

    st.Push(1);
    st.Push(1);
    st.Push(1);
    st.Push(0);
    st.Push(1);
    st.Push(1);
    st.Push(0);
    st.Push(0);

    st.PrintStack();
    st.ChangeStackValue(elem,size);

    st.PrintStack();

    cout << st[0] << endl;

    Stack<double> stD(8);

    stD.Push(5);
    stD.Push(3.4);
    stD.Push(2.3);
    stD.Push(1.4);
    stD.Push(-6.1);

    stD.PrintStack();

    return 0;
}
