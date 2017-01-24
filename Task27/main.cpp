#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;


//struct CmpLen
//{
//    bool operator()(const std::string& a, const std::string& b) const
//    {
//        char number1[10];
//        char number2[10];
//        int i = 0 , j = 0;

//        size_t pos = a.copy(number1, a.find_first_of("-") + 1);
//        number1[pos - 1] = '\0';
//        pos = b.copy(number2, b.find_first_of("-") + 1);
//        number2[pos - 1] = '\0';

//        int numb1 = std::stoi(number1);
//        int numb2 = std::stoi(number2);

//        return numb1 > numb2;
//    }
//};

struct Map
{
    Map(string nameBook)
        : m_bookName(nameBook)
    {
    }

    void CreatMap()
    {
        m_file.open(m_bookName);
        string word;
		map<string, int> mapTest;
        while(m_file >> word)
        {
            if(word == "a" || word == "the" || word == "this" || word == "is")
            {
                continue;
            }
        }
		//for (auto it = m_wordMap.begin(); it != m_wordMap.end(); ++it)
		//{
		//	word = atoi(it->second) + "-" + it->first;
		//	mapTest[word];
		//}
    }

    void ShowTopWord()
    {
        CreatMap();

        bool *flag = new bool[m_wordMap.size()];
        memset(flag, false, sizeof(flag));

        int max = 0;
        int j = 0;
        int index;

        string word;

        for(int i = 0; i < m_wordMap.size(); i++, j = 0)
        {
            for(auto it = m_wordMap.begin(); it != m_wordMap.end(); ++it, ++j)
            {
                if(it->second > max && flag[j] != true)
                {
                    max = it->second;
                    word = it->first;
                    index = j;
                }
            }
            flag[index] = true;
            cout << m_wordMap[word] << "  " << word << endl;

            max = 0;
        }

        delete []flag;
    }
    string& GetNameOfBook()
    {
        return m_bookName;
    }

private:
    string m_bookName;
    map<string,int> m_wordMap;
    ifstream m_file;

};


int main()
{
    Map m("Romeo.txt");

    m.ShowTopWord();

    cout << m.GetNameOfBook() << endl;

    m.GetNameOfBook() = "name.txt";

    cout << m.GetNameOfBook() << endl;
 //-----------------------------------

    return 0;
}
