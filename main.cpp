#include <iostream>
#include <fstream>
#include <ctime>
#include <pthread.h>
#include <thread>
#include <string.h>
#include <omp.h>
#include "genome_processing.h"
#include "suffix_tree.h"

char **create_fragments(char *genome, long fragment_count, int fragment_length);
char *get_random_fragment(char *genome, int fragment_length);

int main(int argc, char **argv)
{
    char *genome_file_path = NULL;
    int genome_size = 50000;
    long fragment_count = 0;
    int query_length = 36;
    string search_type;
    // char *genome = NULL;
    char **fragments = NULL;
    int matches = 0;

    if (argc < 3)
    {
        cout << "Invalid number of arguments" << endl;
        cout << "Usage: ./main --genome <genome_file_path> --fragments <fragment_count>" << endl;
        cout << "Example: ./main --genome genome.txt --fragments 5000" << endl;
        return 0;
    }

    for (int i = 0; i < argc; i++)
    {
        string arg = argv[i];
        if (arg == "--genome")
        {
            genome_file_path = argv[i + 1];
        }
        if (arg == "--fragments")
        {
            fragment_count = atol(argv[i + 1]);
        }
    }

    if (genome_file_path == NULL || fragment_count == 0)
    {
        cout << "Invalid arguments" << endl;
        cout << "Invalid number of arguments" << endl;
        cout << "Usage: ./main --genome <genome_file_path> --fragments <fragment_count>" << endl;
        cout << "Example: ./main --genome genome.txt --fragments 5000" << endl;
        return 0;
    }
    cout << "------------------------------------------------------------------" << endl;

    // Loading the genome into the memory
    // genomeFunctions *genomeFunctionsObject = new genomeFunctions();
    // genomeFunctionsObject->readGenomeData(genome_file_path);
    // genome = genomeFunctionsObject->getrandomfragment(genome_size);

    // Read genome file
    ifstream genome_file_ptr(genome_file_path);
    if (!genome_file_ptr.is_open())
    {
        cout << "Error: Unable to open genome file" << endl;
        return 0;
    }

    // instance of genome_processing class
    GENOMEPROCESSING genome_processor;
    // GENOMEPROCESSING *genomeFunctionsObject = new GENOMEPROCESSING();

    cout << "Reading genome file..." << endl;
    genome_processor.readHumanGenome(genome_file_ptr);

    long long genome_length = genome_processor.getGenomeSize();

    char* subject = genome_processor.getGenomeData();

    char* genome = new char[genome_size];

    // Generate random subject
    // long long start_index = rand() % (genome_length - random_subject_length);
    long long start_index = 2338635;

    for (long long i = 0; i < genome_size; i++)
    {
        genome[i] = subject[start_index + i];
        // random_subject[i] = genome[i];
    }

    // Building the suffix tree
    // the constructor of the suffix tree class takes the genome as an argument
    // and builds the suffix tree from it.
    Suffix_Tree *suffix_tree = new Suffix_Tree(genome);
    cout << "Number of nodes: " << suffix_tree->get_node_count() << endl;
    // create n fragments of length 36 by picking random indexes from the genome, n is given as an argument.
    fragments = create_fragments(genome, fragment_count, query_length);
    cout << "Searching for " << fragment_count << " fragments of length " << query_length << endl;
    for (int i = 0; i < fragment_count; i++)
    {
        matches += suffix_tree->search(fragments[i]);
    }
    cout << "Matches: " << matches << endl;
    cout << "------------------------------------------------------------------" << endl;

    delete suffix_tree;
    // delete genomeFunctionsObject;
    for (long i = 0; i < fragment_count; i++)
    {
        delete[] fragments[i];
    }
    delete[] fragments;

    return 0;
}

char *get_random_fragment(char *genome, int fragment_length)
{
    srand(time(NULL));
    long index = rand() % (strlen(genome) - fragment_length + 1);
    char *fragment = new char[fragment_length + 2];
    memcpy(fragment, genome + index, fragment_length);
    fragment[fragment_length] = '\0';
    return fragment;
}

char **create_fragments(char *genome, long fragment_count, int fragment_length)
{
    char **fragments = new char *[fragment_count];
    srand(time(NULL));
    for (long i = 0; i < fragment_count; i++)
    {
        fragments[i] = new char[fragment_length + 2];
        long index = rand() % (strlen(genome) - fragment_length + 1);
        memcpy(fragments[i], genome + index, fragment_length);
        fragments[i][fragment_length] = '\0';
    }
    return fragments;
}
