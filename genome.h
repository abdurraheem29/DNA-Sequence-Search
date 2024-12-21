#ifndef GENOME_H
#define GENOME_H

struct Genome
{
    char *genome_data;
    long long int genome_size;
};

long long int calculate_genome_chars_in_file(std::ifstream &ip_file_pointer);
void read_human_genome(std::string ip_file_path, std::string op_file_path);
void assess_human_genome(std::string ip_file_path, std::string op_file_path);

#endif
