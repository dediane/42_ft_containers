#include <iostream>
#include <vector>

void print_line(int res, std::string container_name, std::string test_name)
{
    if (res == 0)
    {
        std::cout << "[\033[1;32m ["<< container_name  << "] \033[0;37m" << " test_name " << "[\033[1;32m[V]\033[0;37m";
    }
    else 
    {
        std::cout << "[\033[1;31m ["<< container_name  << "] \033[0;37m" << " test_name " << "[\033[1;31m[X]\033[0;37m";
    }
}