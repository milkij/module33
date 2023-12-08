#include <iostream>
#include <map>
#include <exception>


int main() {
    int cmd;
    try{
        std::cin >> cmd;
        if(!std::cin)
        {
            throw std::invalid_argument("!std::cin");
        }
        if(cmd<1)
        {
            throw std::exception();
        }
        std::cout << cmd << std::endl;
    }
    catch(const std::invalid_argument& x)
    {
        std::cerr << "Caught invalid argument: " << x.what() << std::endl;
    }
    catch(const std::exception& x)
    {
        std::cerr << "Caught exception: " << x.what() << std::endl;
    }


    return 0;
}
