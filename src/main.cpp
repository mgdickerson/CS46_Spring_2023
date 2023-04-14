#include "unordered_list.h"

int main(int argc, char * argv[])
{
	const char * input_file = argc == 2 ? argv[1] : "random.txt";
    measure_lists(input_file);
    return 0;
}
