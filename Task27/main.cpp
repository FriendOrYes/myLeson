#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Cmp
{
    bool operator()(const int& x, const int& x2) const
    {
        return x > x2;
    }
};
struct Map
{
    Map(string nameBook)
        : m_bookName(nameBook)
    {
    }

    void CreatMap()
    {
        m_book.open(m_bookName);
        char c;
        string word = "";
        while(m_book.get(c))
        {
            c = tolower(c);
            if(c != ' ' && c != '\n' && c != ',' && c != '.' && c != '(' && c != ')')
                word += c;
            else
            {
                if(word != "" && word.length() > 3)
                {
                    auto it = find(closeWord.begin(), closeWord.end(), word);
                    if(it == closeWord.end())
                     {
                        unordetMap[word]++;
                     }
                }
                word = "";
            }
        }
//        while(m_book >> word)
//        {
//            if(word.length() < 3) continue;
//            auto it = find_if(closeWord.begin(), closeWord.end(), [&word](string &wd){return wd == word;});
//            if(it == closeWord.end())
//            {
//                word.erase(remove_if(word.begin(), word.end(),
//                                     [](const char& c)
//                {
//                    return c == ',' || c == '.';
//                }));
//                unordetMap[word]++;
//            }
//        }
    }

    void CreatTopWord()
    {
        CreatMap();

        for(auto it = unordetMap.begin(); it != unordetMap.end(); ++it)
        {
            m_wordMap.insert(pair<int, string>(it->second, it->first));
        }
    }
    string& GetNameOfBook()
    {
        return m_bookName;
    }

    void ShowTop(const int& top = 10)
    {
        int i = 0;
        for(auto it = m_wordMap.begin(); i < top && it != m_wordMap.end(); ++i, ++it)
        {
            cout << "'" << it->second << "'" <<" - " << it->first << endl;
        }
    }
private:
    string m_bookName;
    multimap<int, string, Cmp> m_wordMap;
    unordered_map<string,int> unordetMap;
    ifstream m_book;
    vector<string> closeWord =
    {
        "if","from","were","they","", "of","the","and","to","is","a", "in", "that","as","by","for","all",
        "when","where","how","why","who","whose","what","which","that","be","been","are","with","will","have"
    };
};





int main()
{
    Map m("LaVey_-_The_Satanic_Bible.txt");
    Map m2("bible.txt");

    cout <<  m.GetNameOfBook() << endl;
    m.CreatTopWord();
    m.ShowTop(20);

    cout <<  m2.GetNameOfBook() << endl;
    m2.CreatTopWord();
    m2.ShowTop(20);
    return 0;
}
