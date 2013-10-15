
#ifndef BURSTTRIE_H_
#define BURSTTRIE_H_

/**
 * Reference Paper:
 * Burst tries: A fast, efficient data structure for string keys
 * Heinz, S., Zobel, J. & Williams, H. E. (2002)
 */


/**
 * Why Burst Trie?
 * - Normal R-way tries are fast, but memory-intensive.
 * - Hash tables are fast, takes less memory but doesn't support ordering.
 * - Compact and Ternary search tries are slower, takes lesser memory than R-way tries but aren't good enough.
 */

/**
 * Hash Tables are faster, because of cache-conscious. Burst Tries are not cache-conscious.
 */

/**
 * Choices:
 * - Uses Limit heuristic for bursting.
 * - Uses BST for containers.
 * - Consolidation not implemented.
 */

#endif /* BURSTTRIE_H_ */
