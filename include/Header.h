#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>

class Cache
{
public:

header.hpp Cache(int min_kb, int max_kb)
header.hpp {
header.hpp header.hpp size = log2(max_kb / min_kb) + 3;
header.hpp header.hpp mas_sizes = new int[size];
header.hpp header.hpp int n = 0;
header.hpp header.hpp min_kb /= 2;

header.hpp header.hpp while (min_kb <= max_kb * 3 / 2)
header.hpp header.hpp {
header.hpp header.hpp header.hpp mas_sizes[n++] = min_kb;
header.hpp header.hpp header.hpp min_kb *= 2;
header.hpp header.hpp }

header.hpp header.hpp mas_sizes[n++] = max_kb * 3 / 2;
header.hpp header.hpp buffer = nullptr;
header.hpp header.hpp std::cout << std::endl << "Massiv sizes: ";
header.hpp header.hpp for (unsigned int i = 0; i < n; i++)
header.hpp header.hpp header.hpp std::cout << mas_sizes[i] << " ";
header.hpp header.hpp std::cout << std::endl;

header.hpp }

header.hpp struct Experiment
header.hpp {
header.hpp header.hpp int id;
header.hpp header.hpp std::string name;
header.hpp header.hpp double time;
header.hpp };

header.hpp Experiment* MakeTest(std::string travel);

private:
header.hpp int LOOP = 1000;
header.hpp unsigned int* buffer;

header.hpp int* mas_sizes;//массив размеров(память) 
header.hpp int size;// элементов в массиве для iго веса

header.hpp void initbuffer(int n);//заполняем буфер
header.hpp void DirectWay(int n);//прямой путь
header.hpp void ReversWay(int n);//обратный путь
header.hpp void RandomWay(int n);//рандомный проход

header.hpp int KBtoSize(int kb);

};
