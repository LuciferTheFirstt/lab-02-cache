#include "Header.h"

void Cache::initbuffer(int n)
{
buffer = new unsigned int[n];

for (unsigned int i = 0; i < n; i++)
buffer[i] = rand() % n;
}

int Cache::KBtoSize(int kb)
{
return kb * 1024 / sizeof(int);
}

void Cache::DirectWay(int n)
{
for (int loop = 0; loop < LOOP; ++loop)
{
for (int i = 0; i < n; ++i)
 buffer[i];
}
}

void Cache::ReversWay(int n)
{
for (int loop = 0; loop < LOOP; ++loop)
{
for (int i = n - 1; i >= 0; --i)
 buffer[i];
}
}

void Cache::RandomWay(int n)
{
for (int loop = 0; loop < LOOP; ++loop)
{
for (int i = n - 1; i >= 0; --i)
 buffer[rand() % n];
}

}

Cache::Experiment* Cache::MakeTest(std::string travel)

{

std::cout << "investigation:" << std::endl;
std::cout << "   travel variant: " << travel << std::endl;
std::cout << "   experiments:" << std::endl;
for (int i = 0; i < size; i++)
{

int n = KBtoSize(mas_sizes[i]);
initbuffer(n);

//прогрев
for (int j = 0; j < n; j++)
int a = buffer[rand() % n];

auto start = std::chrono::high_resolution_clock::now();

if (travel == "direct")
{
DirectWay(n);
}

else if (travel == "reverse")
{
ReversWay(n);
}

else {

RandomWay(n);

}

auto finish = std::chrono::high_resolution_clock::now();


//номер эксперемента
std::cout << "   - experiment:" << std::endl;
std::cout << "       number: " << (i + 1) << std::endl;

//размер
std::cout << "       input data:" << std::endl;
std::cout << "         buffer size: " << mas_sizes[i] << "KB" << std::endl;

//время
std::cout << "       results:" << std::endl;
std::cout << "         duration: " << (std::chrono::duration_cast<std::chrono::milliseconds>(finish - start).count() / LOOP) << "ms" << std::endl;

}

std::cout << std::endl;
return(0);

}
