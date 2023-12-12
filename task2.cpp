#include <iostream>
#include <exception>
#include <string>

class catchFishException :public std::exception
{
public:
    const const char * what() const noexcept override
    {
        return "caught fish";
    }
};
class catchBootException :public std::exception
{
public:
    const const char * what() const noexcept override
    {
        return "caught boot";
    }
};

class GAME_FIELD
{
private:
    char* field;
    int size;
    int getRandom()
    {
        return std::rand() % size;
    }
    void setValue(char val, int pos)
    {
        if(pos < 0 || pos > size-1) throw std::invalid_argument("pos > size || pos < size");
        field[pos]=val;
    }
    void createItems(char item)
    {
        while (true)
        {
            int random = getRandom();
            if(field[random]!='F' || field[random]!='P')
            {
                setValue(item,random);
                break;
            } else continue;
        }

    }
public:

    GAME_FIELD(int _size)
    {
        size=_size;
        field = new char(_size);
        for (int i=0; i<_size;++i)
        {
            field[i]='-';
        }
        createItems('F');
        createItems('B');
        createItems('B');
    }
    ~GAME_FIELD()
    {
        delete field;
    }
    void printField()
    {
        for (int i=0; i<size; ++i)
        {
            std::cout << field[i] << ' ';
        }
        std::cout << std::endl;
    }
    void catchingFish(int pos)
    {
        if(pos < 0 || pos > size-1) throw std::invalid_argument("pos > size || pos < size");
        if(field[pos]=='F')
        {
            throw catchFishException();
        }
        if(field[pos]=='B')
        {
            throw catchBootException();
        }
        if(field[pos]=='-')
        {
            std::cout << "try again" << std::endl;
        }

    }
    int getSize()
    {
        return size;
    }
};

int main()
{
    std::srand(std::time(nullptr));
    GAME_FIELD lake(9);
    lake.printField();
    while (true) {
        try {
            std::cout << "try to catch fish! Input from 1 to " << lake.getSize() << ": ";
            int n;
            std::cin >> n;
            if (!std::cin) {
                throw std::invalid_argument("!std::cin");
            }
            lake.catchingFish(n - 1);


        } catch (const std::invalid_argument &x) {
            std::cerr << "caught: " << x.what() << std::endl;
        } catch (const catchFishException &x) {
            std::cerr << "You have " << x.what() << " You are win!" << std::endl;
            return 0;
        } catch (const catchBootException &x) {
            std::cerr << "You have " << x.what() << " You are loser! Game over" << std::endl;
            return 0;
        }
    }

}