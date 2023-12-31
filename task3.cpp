#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
template<typename T1, typename T2>
struct DATA
{
    T1 id;
    T2 value;
    DATA(){};
    DATA(T1 _id, T2 _value):id(_id),value(_value){};
};

template<typename T1, typename T2>
class REGISTRY {
private:
    std::vector<DATA<T1,T2>> reg;
public:
    REGISTRY(){};
    ~REGISTRY(){};

    auto add (T1 _id, T2 _value)
    {
        std::cout << "\tADD" << std::endl;
        DATA<T1,T2> obj(_id,_value);
        reg.emplace_back(obj);
    };
    auto findV(T1 _id)
    {
        std::cout << "\tFIND" << std::endl;
        bool isFind=false;
        for(auto i=0; i<reg.size(); ++i)
        {
            if(reg[i].id ==_id)
            {
                isFind= true;
                std::cout << reg[i].id << " | " << reg[i].value << std::endl;
            }
        }
        if(!isFind)
        {
            std::cout << "No data found" << std::endl;
        }
    }

    auto remove (T1 _id)
    {
        std::cout << "\tREMOVE" << std::endl;
        while (true) {
            //Не понимаю почему это не работает. Как это пофиксить?
            auto it = std::find(reg.begin(), reg.end(), _id);
            if (it != reg.end()) {
                reg.erase(it);
            } else {
                break;
            }
        }
    };
    auto print ()
    {
        std::cout << "\tPRINT" << std::endl;
        for (int i=0; i<reg.size(); ++i)
        {
            std::cout << reg[i].id << " | " << reg[i].value << std::endl;
        }
    };


};

int main() {
    REGISTRY<int, std::string> registr;
    registr.add(1,"str");
    registr.add(1,"str2");
    registr.add(3,"str3");
    registr.add(2,"str3");
    registr.add(3,"str3");
    registr.print();
    registr.findV(1);
    registr.remove(3);
    registr.print();
}