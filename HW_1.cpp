#include <iostream>
#include <string.h>
#include "genome.h"

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc == 4)
    {
        if (strcmp("assess", argv[1]) == 0)
        {
            assess_human_genome(argv[2], argv[3]);
        }
        else if (strcmp("read", argv[1]) == 0)
        {
            read_human_genome(argv[2], argv[3]);
        }
        else
        {
            cout << "ERROR: Invalid command" << endl;
        }
    }
    else
    {
        cout << "ERROR: Invalid arguments" << endl;
    }
    return 0;
}
