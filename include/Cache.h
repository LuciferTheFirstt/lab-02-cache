#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <chrono>
#include <algorithm>

class Cache
{
public:

	Cache( int min_kb, int max_kb )
	{
		size = log2( max_kb / min_kb ) + 3;
		mas_sizes = new int[size];
		int n = 0;
		min_kb /= 2;

		while( min_kb <= max_kb * 3 / 2 )
		{
			mas_sizes[n++] = min_kb;
			min_kb *= 2;
		}

		mas_sizes[n++] = max_kb * 3 / 2;
		buffer = nullptr;
		std::cout << std::endl << "Massiv sizes: ";
		for( unsigned int i = 0; i < n; i++ )
			std::cout << mas_sizes[i] << " ";
		std::cout << std::endl;

	}

	struct Experiment
	{
		int id;
		std::string name;
		double time;
	};

	Experiment* MakeTest( std::string travel );

private:
	int LOOP = 1000;
	unsigned int* buffer;

	int* mas_sizes;//массив размеров(память) 
	int size;// элементов в массиве для iго веса

	void initbuffer( int n );//заполняем буфер
	void releaseBuffer();
	void DirectWay( int n );//прямой путь
	void ReversWay( int n );//обратный путь
	void RandomWay( int n );//рандомный проход

	int KBtoSize( int kb );

};


void Cache::initbuffer( int n )
{
	buffer = new unsigned int[n];

	for( unsigned int i = 0; i < n; i++ )
		buffer[i] = rand() % n;
}

void Cache::releaseBuffer( )
{
	delete[] buffer;
}

int Cache::KBtoSize( int kb )
{
	return kb * 1024 / sizeof( int );
}

void Cache::DirectWay( int n )
{
	for( int loop = 0; loop < LOOP; ++loop )
	{
		for( int i = 0; i < n; ++i )
		{
			int v=0;
			v += buffer[i];
		}
	}
}

void Cache::ReversWay( int n )
{
	for( int loop = 0; loop < LOOP; ++loop )
	{
		for( int i = n - 1; i >= 0; --i )
		{
			int v=0;
			v += buffer[i];
		}	
	}
}

void Cache::RandomWay( int n )
{
	std::vector<int> v(buffer, buffer +n);

	std::random_device rd;
	std::mt19937 g( rd() );

	for( int loop = 0; loop < LOOP; ++loop )
		std::shuffle( v.begin(), v.end(), g );

}

Cache::Experiment* Cache::MakeTest( std::string travel )

{

	std::cout << "investigation:" << std::endl;
	std::cout << "   travel variant: " << travel << std::endl;
	std::cout << "   experiments:" << std::endl;
	for( int i = 0; i < size; i++ )
	{
		std::cout<<"i="<<i<<std::endl;
		int n = KBtoSize( mas_sizes[i] );
		initbuffer( n );

		//прогрев
		for( int j = 0; j < n; j++ )
			int a = buffer[rand() % n];

		auto start = std::chrono::high_resolution_clock::now();

		if( travel == "direct" )
		{
			DirectWay( n );
		}

		else if( travel == "reverse" )
		{
			ReversWay( n );
		}

		else {

			RandomWay( n );

		}

		auto finish = std::chrono::high_resolution_clock::now();

		releaseBuffer();

		//номер эксперемента
		std::cout << "   - experiment:" << std::endl;
		std::cout << "       number: " << ( i + 1 ) << std::endl;

		//размер
		std::cout << "       input data:" << std::endl;
		std::cout << "         buffer size: " << mas_sizes[i] << "KB" << std::endl;

		//время
		std::cout << "       results:" << std::endl;
		std::cout << "         duration: " << ( std::chrono::duration_cast<std::chrono::milliseconds>( finish - start ).count() / LOOP ) << "ms" << std::endl;

	}

	std::cout << std::endl;
	return( 0 );

}


