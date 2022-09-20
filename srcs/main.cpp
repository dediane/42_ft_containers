#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"

  
int main()
{
    //Create an empty vector
    // ft::vector<int> vect;
    ft::vector<std::string> vect2;

    //vect2.push_back("Hello");
 //   vect2.push_back("Hola");
 //   vect2.push_back("Ciao");
 //   std::cout << vect2.capacity() << std::endl;
  //  std::cout << vect2.max_size() << std::endl;
  //  vect2.pop_back();
    vect2.insert (vect2.begin(), "Hello");
}
  
//     vect.push_back(10);
//     vect.push_back(20);
//     vect.push_back(30);
  
//     std::cout << "Vector contenant des int" << std::endl;
//     std::cout << vect[0] << " | ";
//     std::cout << vect[1] << " | ";
//     std::cout << vect[2] << " | " << std::endl;

//     std::cout << "Taille de mon vecteur:" << std::endl;
//     std::cout << vect.size() << std::endl;
//     vect.pop_back();
//     std::cout << "Taille de mon vecteur après pop_back:" << std::endl;
//     std::cout << vect.size() << std::endl;

//     std::cout << vect[0] << " | ";
//     std::cout << vect[1] << " | ";
//     std::cout << vect[2] << " | ";

//     vect.push_back(100);
//     std::cout << vect.size() << std::endl;

//     std::cout << vect[0] << " | ";
//     std::cout << vect[1] << " | ";
//     std::cout << vect[2] << " | ";
  
//     std::cout << "Vector contenant des strings" << std::endl;
//     std::cout << vect2[0] << " | ";
//     std::cout << vect2[1] << " | ";
//     std::cout << vect2[2] << " | " << std::endl;

//     std::cout << "Taille de mon vecteur:" << std::endl;
//     std::cout << vect2.size() << std::endl;
//     vect2.pop_back();
//     std::cout << "Taille de mon vecteur après pop_back:" << std::endl;
//     std::cout << vect2.size() << std::endl;

//     ft::vector<int> second(4, 100); 
// 	std::cout << second.size() << std::endl;
//     std::cout << second.front() << std::endl;
//     std::cout << second.back() << std::endl;
// }
//     #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::Stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::Stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::Stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::Stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }