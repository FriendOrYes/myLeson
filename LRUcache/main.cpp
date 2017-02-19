#include <list>
#include <unordered_map>
#include <assert.h>
#include <iostream>

using namespace std;



template <class KEY_T, class VAL_T> class LRUCache
{
private:
    mutable list< pair<KEY_T,VAL_T> > m_itemList;
    unordered_map<KEY_T, decltype(m_itemList.begin())> m_itemMap;
    size_t m_cache_size;

    void Clean(void)
    {
        while(m_itemMap.size() > m_cache_size)
        {
            auto last_it = m_itemList.end();
            last_it--;
            m_itemMap.erase(last_it->first);
            m_itemList.pop_back();
        }
    }

public:
    LRUCache(int cache_size)
        : m_cache_size(cache_size)
    {
    }

    void Put(const KEY_T &key, const VAL_T &val)
    {
        auto it = m_itemMap.find(key);
        if(it != m_itemMap.end())
        {
            m_itemList.erase(it->second);
            m_itemMap.erase(it);
        }

        m_itemList.push_front(make_pair(key,val));
        m_itemMap.insert(make_pair(key, m_itemList.begin()));
        Clean();
    }

    bool Exist(const KEY_T &key)const
    {
        return (m_itemMap.count(key) > 0);
    }

    const VAL_T& Get(const KEY_T &key)const
    {
        if(!Exist(key))
        {
            throw runtime_error("key not exist");
        }

        auto it = m_itemMap.find(key);
        m_itemList.splice(m_itemList.begin(), m_itemList, it->second);
        return it->second->second;
    }

    void Clear()
    {
        m_itemList.clear();
        m_itemMap.clear();
    }
    size_t GetSize()const
    {
        return m_itemList.size();
    }
};


int main()
{
    LRUCache<int, string> cache(3);

    cache.Put(1, "1");
    cache.Put(2, "2");
    cache.Put(3, "3");

    cache.Put(4, "4");

    cout << cache.Get(3) << endl;

    cache.Put(5,"5");

    cout << cache.Get(5) << endl;

    cout << cache.Get(4) << endl;
    cache.Put(3, "3");

    //cout << cache.get(1) << endl;

    cache.Clear();
    cout << "cache.get(4)" << endl;

    try
    {
        cout << cache.Get(4) << endl;
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }

    cache.Put(1, "1");
    cache.Put(2, "2");
    cache.Put(3, "3");

    assert(cache.Get(1) == "1");
    assert(cache.Get(2) == "2");
    assert(cache.Get(3) == "3");
    return 0;
}
