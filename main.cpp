#include "Header.h"

using namespace std;

int main()
{
	int min_kb, max_kb;
	string travel;
	min_kb = 128;
	max_kb = 6144;

	Cache cache(min_kb, max_kb);
	Cache::Experiment *direct = cache.MakeTest("direct");
	Cache::Experiment *reverse = cache.MakeTest("reverse");
	Cache::Experiment *random = cache.MakeTest("random");
}
