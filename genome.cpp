#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include "genome.h"

using namespace std;

long long int calculate_genome_chars_in_file(std::ifstream &ip_file_pointer)
{
    std::string line;
    long long int index;
    long long int line_length;

    long long int char_count = 0;

    while (getline(ip_file_pointer, line))
    {
        if (line[0] != '>')
        {
            line_length = line.length();

            for (index = 0; index < line_length; index++)
            {
                char_count++;
            }
        }
    }

    return char_count;
}

void read_human_genome(std::string ip_file_path, std::string op_file_path)
{
    struct Genome genome;

    string line;
    long long int line_length, index;

    std::ifstream ip_file_pointer;
    std::ofstream op_file_pointer;

    ip_file_pointer.open(ip_file_path);

    long long int size = calculate_genome_chars_in_file(ip_file_pointer);

    ip_file_pointer.clear();
    ip_file_pointer.seekg(0, ios::beg);

    genome.genome_data = new char[size + 1];

    genome.genome_size = size;

    op_file_pointer.open(op_file_path);

    if (ip_file_pointer.is_open())
    {
        long long int scaffold_length = -1,
                      scaffold_count = 0,
                      genome_index = 0,
                      max_scaffold_length = -1,
                      min_scaffold_length = __LONG_LONG_MAX__;

        string min_scaffold_name = "",
               max_scaffold_name = "",
               name;

        while (getline(ip_file_pointer, line))
        {
            if (line[0] == '>')
            {
                scaffold_count++;

                if (max_scaffold_length < scaffold_length)
                {
                    max_scaffold_length = scaffold_length;
                    max_scaffold_name = name;
                }

                if (min_scaffold_length > scaffold_length && scaffold_length != -1)
                {
                    min_scaffold_length = scaffold_length;
                    min_scaffold_name = name;
                }

                scaffold_length = 0;

                name = line;
            }
            else
            {
                line_length = line.length();
                scaffold_length += line_length;

                for (index = 0; index < line_length; index++)
                {
                    genome.genome_data[genome_index++] = line[index];
                }
            }
        }

        if (max_scaffold_length < scaffold_length)
        {
            max_scaffold_length = scaffold_length;
            max_scaffold_name = name;
        }

        if (min_scaffold_length > scaffold_length)
        {
            min_scaffold_length = scaffold_length;
            min_scaffold_name = name;
        }

        if (op_file_pointer.is_open())
        {
            op_file_pointer << "\tReading Genome Data" << endl;
            op_file_pointer << "------------------------------------" << endl
                            << endl;

            op_file_pointer << "Total number of scaffolds: " << scaffold_count << endl
                            << endl;

            op_file_pointer << "\tLargest Scaffold" << endl;
            op_file_pointer << "-------------------------------------" << endl
                            << endl;
            op_file_pointer << "Name: " << max_scaffold_name << endl;
            op_file_pointer << "Length: " << max_scaffold_length << endl
                            << endl;

            op_file_pointer << "\tSmallest Scaffold" << endl;
            op_file_pointer << "-------------------------------------" << endl
                            << endl;
            op_file_pointer << "Name: " << min_scaffold_name << endl;
            op_file_pointer << "Length: " << min_scaffold_length << endl
                            << endl;

            op_file_pointer << "Average scaffold size: " << genome.genome_size / (double)scaffold_count << endl
                            << endl;

            op_file_pointer << "Length of genome: " << genome.genome_size << endl
                            << endl;
        }

        ip_file_pointer.close();
        op_file_pointer.close();
    }
}

void assess_human_genome(std::string ip_file_path, std::string op_file_path)
{
    time_t start_time, end_time;

    time(&start_time);

    std::ifstream ip_file_pointer(ip_file_path);
    std::ofstream op_file_pointer(op_file_path);

    struct Genome genome;
    long long int line_length, index;
    char genome_char;

    std::string line;

    long long int a_count = 0,
                  g_count = 0,
                  c_count = 0,
                  t_count = 0,
                  n_count = 0,
                  other_count = 0,
                  genome_size = 0;

    if (ip_file_pointer.is_open())
    {
        while (getline(ip_file_pointer, line))
        {
            if (line[0] != '>')
            {
                line_length = line.length();

                for (index = 0; index < line_length; index++)
                {
                    genome_char = line[index];
                    switch (genome_char)
                    {
                    case 'A':
                        a_count++;
                        genome_size++;
                        break;

                    case 'C':
                        c_count++;
                        genome_size++;
                        break;

                    case 'G':
                        g_count++;
                        genome_size++;
                        break;

                    case 'T':
                        t_count++;
                        genome_size++;
                        break;

                    case 'N':
                        n_count++;
                        genome_size++;
                        break;

                    default:
                        other_count++;
                        break;
                    }
                }
            }
        }

        time(&end_time);

        genome.genome_size = genome_size;

        op_file_pointer << "\tGenome computation" << endl;
        op_file_pointer << "-------------------------------" << endl
                        << endl;

        op_file_pointer << "Total number of characters (A, C, G, T, N) in genome: " << genome_size << endl
                        << endl;

        op_file_pointer << "Runtime: " << (end_time - start_time) << " seconds" << endl
                        << endl;

        op_file_pointer << "Count of A: " << a_count << endl
                        << endl;
        op_file_pointer << "Count of C: " << c_count << endl
                        << endl;
        op_file_pointer << "Count of G: " << g_count << endl
                        << endl;
        op_file_pointer << "Count of T: " << t_count << endl
                        << endl;
        op_file_pointer << "Count of N: " << n_count << endl
                        << endl;

        op_file_pointer << "GC Content: " << (double)((double)(c_count + g_count) / (double)genome_size) * 100 << " %" << endl
                        << endl;

        op_file_pointer << "Count of characters other than A, C, G, T, N: " << other_count << endl
                        << endl;

        ip_file_pointer.close();
        op_file_pointer.close();
    }
}

