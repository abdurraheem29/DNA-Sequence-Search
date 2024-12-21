# DNA-Sequence-Search
This GitHub repository offers a detailed exploration of managing large-scale data structures with a step-by-step approach to improving efficiency. The main focus is on searching DNA sequences from a dataset containing 3 billion sequences. The journey begins with a straightforward brute-force method, which emphasizes simplicity in handling and searching large datasets. As the data size increases, the brute-force technique proves inefficient due to long processing times.

The repository provides a thorough demonstration of moving from brute-force methods to more advanced and efficient data structures. The initial implementation sheds light on the difficulties faced when working with large-scale data, highlighting the need for optimization. The subsequent versions introduce more sophisticated data structures, such as hash tables, which improve search performance.

The optimization process culminates in the use of a prefix trie, a highly effective data structure for improving both processing speed and memory usage, making it a highly suitable solution for handling extensive data sets.

Key Features:
Brute Force Approach: Learn about the challenges of processing large datasets through a basic brute-force technique.
Hash Tables: Discover how hash tables enhance search efficiency by speeding up data retrieval.
Prefix Trie: See how the introduction of a prefix trie significantly improves performance in handling large-scale data.
Helpers:
The repository includes user-defined helper functions, such as strCmp, which compares two strings, as well as functions for reading and extracting data from files.

File Reading:
This section demonstrates how to read and examine the contents of a file, helping users understand the structure of the stored data.

Linear and Binary Search:
Here, linear search (brute-force) and binary search methods are implemented to search queries, and the time taken for each approach is analyzed for comparison.

Hash Table:
This section showcases the use of hash tables to store queries, speeding up the search process. It also addresses how collisions are handled using linked lists.

Sequence Alignment Algorithms:
Needleman-Wunsch Algorithm (Global Alignment):
Initialization: A matrix is created to store alignment scores, with the first row and column initialized with gap penalties.
Score Calculation: Alignment scores are computed for each matrix cell, considering match/mismatch and gap penalties.
Traceback: The optimal alignment is determined by tracing back through the matrix.
BLAST Algorithm (Basic Local Alignment Search Tool):
Seed Finding: Identifies short exact matches (seeds) between the query and database sequences.
Extension: Extends these seed matches in both directions to form local alignments.
Scoring: Assigns scores to local alignments based on matches, mismatches, and gaps.
Filtering: Applies statistical filters to remove low-scoring matches.
Reporting: Presents significant local alignments as results.
Prefix Trie:
This section demonstrates the use of a prefix trie to store queries. Searching in a prefix trie is considerably faster than in previous methods, providing a significant performance boost.
