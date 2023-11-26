#pragma

#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

template<class K,class V>
std::ostream& operator<< (std::ostream& ost, std::pair<K,V>& v)
{
    ost << '[' << v.first << "," << v.second << ']';
    return ost;
}

template<class T>
std::ostream& operator<< (std::ostream& ost, const std::vector<T>& v)
{
    ost << '[';
    if(!v.empty())
    {
        auto it = v.begin();
        ost << *it;
        ++it;
        while(it != v.end())
        {
            ost << ',' << *it;
            ++it;
        }
    }
    ost << ']';
    return ost;
}

template<class T>
std::ostream& operator<< (std::ostream& ost, const std::unordered_set<T>& v)
{
    ost << '{';
    if(!v.empty())
    {
        auto it = v.begin();
        ost << *it;
        ++it;
        while(it != v.end())
        {
            ost << ',' << *it;
            ++it;
        }
    }
    ost << '}';
    return ost;
}
