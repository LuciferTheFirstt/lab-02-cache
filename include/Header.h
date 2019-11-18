#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>

class Cache
{
public:

	Cache(int min_kb, int max_kb)
	{
		size = log2(max_kb / min_kb) + 3;
		mas_sizes = new int[size];
		int n = 0;
		min_kb /= 2;

		while (min_kb <= max_kb * 3 / 2)
		{
			mas_sizes[n++] = min_kb;
			min_kb *= 2;
		}

		mas_sizes[n++] = max_kb * 3 / 2;
		buffer = nullptr;
		std::cout << std::endl << "Massiv sizes: ";
		for (unsigned int i = 0; i < n; i++)
			std::cout << mas_sizes[i] << " ";
		std::cout << std::endl;

	}

	struct Experiment
	{
		int id;
		std::string name;
		double time;
	};

	Experiment* MakeTest(std::string travel);

private:
	int LOOP = 1000;
	unsigned int* buffer;

	int* mas_sizes;//массив размеров(память) 
	int size;// элементов в массиве для iго веса

	void initbuffer(int n);//заполняем буфер
	void DirectWay(int n);//прямой путь
	void ReversWay(int n);//обратный путь
	void RandomWay(int n);//рандомный проход

	int KBtoSize(int kb);

};
