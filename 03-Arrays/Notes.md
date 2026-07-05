# Arrays

## Key Concepts
- Contiguous memory → O(1) random access via index.
- Insertion/deletion in the middle costs O(n) (shifting required).
- A **subarray** is contiguous; a **subsequence** is not.

## STL / Syntax Used
- `vector<int> v;` — dynamic array
- `max_element(v.begin(), v.end())`
- `accumulate(v.begin(), v.end(), 0)` (needs `<numeric>`)

## Tricks & Patterns
- **Kadane's Algorithm**: track best-sum-ending-here, reset when it drops below the current element.
- **Prefix Sum**: O(1) range-sum queries after O(n) preprocessing.
- **Two Pointers**: works well on sorted arrays for pair/triplet problems.

## Common Mistakes
- Initializing max/best variable to `0` — breaks on all-negative arrays.
- Off-by-one errors between 0-indexed and 1-indexed prefix sums.

## Summary
> Arrays are the base data structure for almost everything else. Most "optimize this O(n²)" interview questions reduce to a single pass with a running local/global best (Kadane's is the canonical example).
