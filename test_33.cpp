template<typename T1, typename T2>
class DATA
{
private:
    T1 id;
    T2 value;
public:
    DATA(T1 _id, T2 _value):id(_id),value(_value)
    {
        std::cout << "constructor" << std::endl;
    }
    ~DATA()
    {
        std::cout << "distructor" << std::endl;
    }

    T2 getValue()
    {
        return value;
    }

    T1 getId()
    {
        return id;
    }

};

template<typename T1, typename T2>
class REGISTRY {
private:
    std::vector<DATA<T1,T2>> reg;
public:
    REGISTRY()
    {

    }
    void add(T1 id, T2 value)
    {
        reg.push_back(new DATA(id,value));
    }
    void find(T2 value)
    {
        bool isFind=false;
        for(int i=0; i<reg.size();++i)
        {
            if(reg[i].getValue()==value)
            {
                std::cout << reg[i].getId() << " | " << reg[i].getValue();
                isFind=true;
                break;
            }
            if(!isFind) std::cout << "no data found" << std::endl;
        }
    }
};