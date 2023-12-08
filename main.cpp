#include <iostream>
#include <map>
#include <exception>

class EmptyListException :public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "List is empty";
    }
};
class CntMoreZeroException :public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Cnt should be more then zero";
    }
};

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
        try {
            if (goods.size() == 0) {
                throw EmptyListException();
            }
            std::cout << "====================STORE===================" << std::endl;
                //std::cout << "List of storage:" << std::endl;
                for (auto it = goods.begin(); it != goods.end(); ++it) {
                    std::cout << it->first << ", cnt: " << it->second << std::endl;
            }
            std::cout << "===========================================" << std::endl;
        } catch (const EmptyListException& x)
        {
            std::cerr << x.what() << std::endl;
        }

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
        if(cnt < 1)
        {
            throw CntMoreZeroException();
        }
        if (!checkGoodIn(name))
        {
            goods.insert(std::make_pair(name, cnt));
        }
        else
        {
            goods.at(name) += cnt;
        }
        getListOfStore();
    }

    void removeGood(std::string& name, int& cnt)
    {
        if(cnt < 1)
        {
            throw CntMoreZeroException();
        }
        if(!checkGoodIn(name))
        {
            std::cerr <<  "try again! Invalid good" << std::endl;
        }
        if (cnt>goods.at(name))
        {
            std::cerr << "You cant remove such" << std::endl <<
                        goods.at(name) << " are available." << std::endl;;
        }
        else
        {
            goods.at(name)-=cnt;
        }
        getListOfStore();
    }

    bool checkEmpty()
    {
        return goods.size()==0 ? true : false;
    }
};

void getInput(std::string& name, int& cnt) {
    std::cout << "Input name and cnt ";
    std::cin >> name >> cnt;
    if(!std::cin)
    {
        std::cin.clear();
        throw std::invalid_argument("!CIN - cnt");
    }
}

int main() {
    std::cout << "Cmd: add, removed, exit are available" << std::endl;

    GOODS goods;


    while (true)
    {
        try {
            std::cout <<std::endl<< "Input cmd ";
            std::string cmd,name;

            int cnt;
            std::cin >> cmd ;
            if (cmd == "exit") {
                std::cout << "Exit from program" << std::endl;
                break;
            } else if (cmd == "add") {
                getInput(name,cnt);
                goods.addGood(name, cnt);
            } else if (cmd == "remove") {
                getInput(name,cnt);
                goods.removeGood(name, cnt);
            }
        } catch (const std::invalid_argument& x)
        {
            std::cerr << "Caught invalid_argument: " << x.what() << std::endl;

        } catch (const CntMoreZeroException& x)
        {
            std::cerr << "Runtime error: " << x.what() << std::endl;
        }
    }
    return 0;
}
