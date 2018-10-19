#include <iostream>
#include <unordered_map>
#include <list>

class BrowserHistory
{
public:
    BrowserHistory(std::size_t capacity)
    : n(capacity)
    {
        map.reserve(n);
    }

    void visit(std::string& url)
    {
        add(url);
        if (list.size() > n)
        {
            erase(list.begin());
        }
    }

    void print()
    {
        std::cout << "------------\n";
        for (auto it = list.rbegin(); it != list.rend(); ++it) 
        {
            std::cout << *it<< std::endl;
        }
        std::cout << "------------\n";
    }

private:
    using UrlList=std::list<std::string>;
    using UrlMap=std::unordered_map<std::string,UrlList::iterator>;
private:
    void add(std::string& url)
    {
        list.push_back(url);
        auto p = map.emplace(url, --list.end());
        if (!p.second)
        {
            list.erase(p.first->second);
            p.first->second = --list.end();
        }        
    }

    void erase(UrlList::iterator it)
    {
        map.erase(*it);
        list.erase(it);
    }

private:
    std::size_t n;
    UrlList list;
    UrlMap map;
};


int main()
{   
    
    BrowserHistory bh(3);
    std::string url;
    while (std::getline(std::cin, url))
    {
        if (url.length() == 0) continue;
        bh.visit(url);
        bh.print();
    }
    return 0;
}
