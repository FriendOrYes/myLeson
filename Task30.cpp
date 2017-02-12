#include <iostream>
#include <array>
#include <cassert>
#include <vector>
#include <memory>
#include <condition_variable>
#include <thread>
#include <future>
#include <pthread.h>
#include <mutex>
#include <unistd.h>
#include <chrono>

using namespace std;

template<typename T, size_t N>
class RingBuffer
{
    array<T, N> m_data;

    typedef unsigned long long tSize;

    unsigned long long m_start = 0;
    unsigned long long m_end = 0;

    std::condition_variable cond;
    mutable std::mutex mtx;

    bool unsafeEmpty() const
    {
        return (m_start == m_end);
    }

    bool unsafeFull() const
    {
        return (N == m_start - m_end);
    }

public:

    size_t size() const
    {
        return N;
    }

    size_t count() const
    {
        return m_start - m_end;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(mtx);

        return unsafeEmpty();
    }

    bool full() const
    {        
        std::lock_guard<std::recursive_mutex> lock(mtx);

        return unsafeFull();
    }

    void push_back(const T& elem)
    {
        unique_lock<std::mutex> lock{mtx};
        while(unsafeFull())
        {
            cond.wait(lock);
        }
        tSize start = m_start%N;
        m_data[start] = elem;
        ++m_start;
        cond.notify_one();
    }

    T& front()
    {
        std::unique_lock<std::mutex> lock{mtx};

        while(unsafeEmpty())
        {
            cond.wait(lock);
        }

        return m_data[m_end%N];
    }

    void pop_front()
    {
        std::unique_lock<std::mutex> lock(mtx);
        if(!unsafeEmpty())
        {
            ++m_end;
            cond.notify_one();
        }
    }

};
namespace  TestBlockingEmpty
{
    void RunEmptyBlock(RingBuffer<int,20>& ringBuffer)
    {
        std::cout << __FUNCTION__ << std::endl;
        thread threadMy{[&]()
        {
            int count = 200;
            while(count)
            {
                ringBuffer.push_back(count--);
                std::chrono::milliseconds timeout(100);
                std::this_thread::sleep_for(timeout);
                cout << "push_value" << endl;
            }
        }};

        thread threadMy2{[&]()
        {
            int value;
            while(value != 1)
            {
                value = ringBuffer.front();
                ringBuffer.pop_front();
                cout << "read value : " <<value << endl;
                // count++;
            }
         }};

        threadMy2.join();
        threadMy.join();
    }
}
///////////
/// \brief RunFullBlock
/// \param ringBuffer
namespace  TestBlockingFull
{

    void RunFullBlock(RingBuffer<int,20>& ringBuffer)
    {
        std::cout << __FUNCTION__ << std::endl;

        thread threadMy{[&]()
        {
                int count = 200;
                while(count)
                {
                    ringBuffer.push_back(count--);
                    cout << "push_value" << endl;
                }
        }};

        thread threadMy2{[&]()
        {
                int value;
                while(value != 1)
                {
                    value = ringBuffer.front();
                    ringBuffer.pop_front();
                    cout << "read value :" << value  << endl;
                    std::chrono::milliseconds timeout(100);
                    std::this_thread::sleep_for(timeout);
                }
         }};

        threadMy2.join();
        threadMy.join();
    }
}
int main(int argc, char *argv[])
{
//    cout << sizeof(unsigned long long) << endl;
//    return 0;

    const size_t N = 20;
    RingBuffer<int, N> ringBuffer;

    cout << "PASSED" << endl;
    using namespace TestBlockingEmpty;
    {
        RunEmptyBlock(ringBuffer);
    }

    using namespace TestBlockingFull;
    {
        RunFullBlock(ringBuffer);
    }
    return 0;
/////////////////////////////////////////////////////////////////////////

//    {
//        // initial state
//        assert(ringBuffer.empty()==true);
//        assert(ringBuffer.full()==false);
//        assert(ringBuffer.count()==0);
//    }

//    {
//        // one push
//        ringBuffer.push_back(42);
//        assert(ringBuffer.empty()==false);
//        assert(ringBuffer.full()==false);
//        assert(ringBuffer.count()==1);
//    }

//    {
//        // one pop
//        ringBuffer.pop_front();
//        assert(ringBuffer.empty()==true);
//        assert(ringBuffer.full()==false);
//        assert(ringBuffer.count()==0);
//    }

//    {
//        // N push, N pop
//        for(size_t i = 0; i < N/2 ; ++i)
//        {
//            ringBuffer.push_back(42);
//        }
//        assert(ringBuffer.count()==N/2);

//        for(size_t i = 0; i < N/2 ; ++i)
//        {
//            ringBuffer.pop_front();
//        }

//        assert(ringBuffer.empty()==true);
//        assert(ringBuffer.full()==false);
//        assert(ringBuffer.count()==0);
//    }

//    {
//        // cross over buffer boundaries
//        for(size_t i = 0; i < N ; ++i)
//        {
//            ringBuffer.push_back(42);
//        }
//        assert(ringBuffer.full()==true);
//        assert(ringBuffer.count()==N);

//        bool exception_thrown = false;
//        try
//        {
//            ringBuffer.push_back(42);
//        }
//        catch (exception& ex)
//        {
//            exception_thrown = true;
//        }
//        assert(exception_thrown==true);
//        assert(ringBuffer.count()==N);
//    }
}
