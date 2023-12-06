#include <iostream>
#include <map>
#include <exception>

class GOODS
{
private:
    std::map<std::string, int> goods;

    bool checkGoodIn(const auto& name)
    {
        for(auto it = goods.begin(); it!=goods.end(); ++it)
        {
            if(it->first==name) return true;
        }
        return false;
    }

    void getListOfStore()
    {
        std::cout << "====================STORE===================" <<std::endl;
        if (goods.empty()) std::cout << "no data found" << std::endl;
        else {
            //std::cout << "List of storage:" << std::endl;
            for(auto it = goods.begin(); it!=goods.end();++it)
            {
                std::cout << it->first << ", cnt: " << it->second << std::endl;

            }
        }
        std::cout << "===========================================" <<std::endl;
    }


public:
    //constructor
    GOODS(){
        getListOfStore();
    };

    //methods

    //

    void addGood(std::string& name, int& cnt)
    {
        try {
            if(cnt < 1) throw "You should input cnt > 0";
            if (!checkGoodIn(name)) goods.insert(std::make_pair(name, cnt));
            else goods.at(name) += cnt;
            getListOfStore();
        }
        catch (const char* x)
        {
            std::cout << x << std::endl;
        }
    }

    void removeGood(std::string& name, int& cnt)
    {
        try {
            if(!checkGoodIn(name)) throw "try again! Invalid good";
            if(cnt < 1) throw "You should input cnt > 0";
            if (cnt>goods.at(name)) throw "You cant remove such";
            else goods.at(name)-=cnt;

        } catch (const char* x)
        {
            std::cout << x << std::endl;
        }
        getListOfStore();
    }

    bool checkEmpty()
    {
        return goods.size()==0 ? true : false;
    }
};



int main() {
    std::cout << "Cmd: add, removed, exit are available" << std::endl;
    GOODS goods;
    std::string cmd;
    while (true)
    {
        std::cout << "Input cmd ";
        std::cin >> cmd;
        std::string name;
        int cnt;
        if(cmd=="exit") break;
        if(cmd=="add")
        {
            try {
                std::cout << "Input name and cnt ";

                std::cin >> name >> cnt;
                if(!std::cin)
                {
                    std::cin.clear();
                    throw "Invalid data!";
                }
                goods.addGood(name, cnt);
            } catch(const char* x)
            {
                std::cout << x << std::endl;
            }

        }
        if(cmd=="remove")
        {
            try {
                if(goods.checkEmpty()) throw "Store is empty";
                std::cout << "Input name and cnt ";
                std::cin >> name >> cnt;
                if (!std::cin)
                {
                    std::cin.clear();
                    throw "Invalid data!";
                }

                goods.removeGood(name, cnt);
            }
            catch(const char* x)
            {
                std::cout << x << std::endl;
            }
        }
    }
    return 0;
}
