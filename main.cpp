#include <iostream>
#include <vector>


using namespace std;
template<typename T1, typename T2>
class DATA
{
public:
    T1 id;
    T2 value;
    DATA(T1 _id, T2 _value):id(_id),value(_value){};
    DATA(T1 _id):id(_id) {};
    friend bool operator==(const DATA &lhs, const DATA &rhs)
    {
        if(lhs.id==rhs.id) return true;
        else return false;
    }
};

template<typename T1, typename T2>
class REGISTRY {
private:
    std::vector<DATA<T1,T2>> reg;
public:
    REGISTRY() = default;
    ~REGISTRY() = default;

    auto add (const T1 _id, const T2 _value)
    {
        reg.push_back(DATA<T1,T2>(_id,_value));
    };

    void find (const T1 _id)
    {
        for (auto it : reg)
        {
            if(it.id==_id)
            {
                cout << it.id << " | " << it.value << endl;
            }
        }
    }

    auto remove (DATA<T1, T2> _id)
    {
        std::cout << "\tREMOVE" << std::endl;
        auto it = std::remove(reg.begin(), reg.end(), _id);
        reg.erase(it, reg.end());
    };
    auto print ()
    {
        for (auto i : reg)
        {
            std::cout << i.id << " | " << i.value << std::endl;
        }
    };


};

void print(string text="-----------")
{
    cout << text << endl;
}

int main() {
    REGISTRY<int, std::string> registr;
    print("ADD");
    registr.add(1,"Ivan");
    registr.add(4,"Petr");
    registr.add(3,"Sidr");
    registr.add(4,"Serg");
    registr.print();

    print("REMOVE");
    registr.remove(DATA<int, std::string>(4));

    print("PRINT");
    registr.print();

}