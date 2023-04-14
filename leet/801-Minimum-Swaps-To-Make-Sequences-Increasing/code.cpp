/*
in:
4
1 2 3 8
5 6 7 4
out:
2

in:
4
1 3 5 4
1 2 3 7
out:
1

in:
5
0 3 5 8 9
2 1 4 6 9
out:
1

swap[n] means the minimum swaps to make the A[i] and B[i] sequences increasing for 0 <= i <= n,
in condition that we swap A[n] and B[n]
not_swap[n] is the same with A[n] and B[n] not swapped.

@Acker help explain:

1. A[i - 1] < A[i] && B[i - 1] < B[i].
   In this case, if we want to keep A and B increasing before the index i, can only have two choices.
   -> 1.1 don't swap at (i-1) and don't swap at i, we can get not_swap[i] = not_swap[i-1]
   -> 1.2 swap at (i-1) and swap at i, we can get swap[i] = swap[i-1]+1
   if swap at (i-1) and do not swap at i, we can not guarantee A and B increasing.

2. A[i-1] < B[i] && B[i-1] < A[i]
   In this case, if we want to keep A and B increasing before the index i, can only have two choices.
   -> 2.1 swap at (i-1) and do not swap at i, we can get notswap[i] = Math.min(swap[i-1], notswap[i] )
   -> 2.2 do not swap at (i-1) and swap at i, we can get swap[i]=Math.min(notswap[i-1]+1, swap[i])
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int minSwap(std::vector<int>& seq1, std::vector<int>& seq2) {
    int n = seq1.size();
    std::vector<int> to_swap(n, n); to_swap[0] = 1;
    std::vector<int> dont_swap(n, n); dont_swap[0] = 0;
    for(int i = 1 ; i < n ; ++i) {
        if(seq1[i-1] < seq1[i] && seq2[i-1] < seq2[i] ) {
            to_swap[i] = to_swap[i-1] + 1;
            dont_swap[i] = dont_swap[i-1];
        }
        if(seq1[i-1] < seq2[i] && seq2[i-1] < seq1[i] ) {
            to_swap[i] = std::min(to_swap[i], dont_swap[i-1] + 1);
            dont_swap[i] = std::min(dont_swap[i], to_swap[i-1]);
        }
    }
    return std::min(to_swap[n-1], dont_swap[n-1]);
}

std::vector<int> read_vector(int n) {
    std::vector<int> vals(n,0);
    for(int& v: vals) {
        std::cin >> v;
    }
    return vals;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> seq1 = read_vector(n);
    std::vector<int> seq2 = read_vector(n);
    std::cout << minSwap(seq1, seq2) << std::endl;
}