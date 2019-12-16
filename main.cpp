
#include "Cache.h"



using namespace std;

int main()
{
	int min_kb, max_kb;
	string travel;
	min_kb = 256;
	max_kb = 8192;

	Cache cache(min_kb, max_kb);
	Cache::Experiment *direct = cache.MakeTest("Direct");
	Cache::Experiment *reverse = cache.MakeTest("reverse");
	Cache::Experiment *random = cache.MakeTest("random");
}


