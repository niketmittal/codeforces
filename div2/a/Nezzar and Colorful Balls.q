Nezzar has n balls, numbered with integers 1,2,…,n. Numbers a1,a2,…,an are written on them, respectively. Numbers on those balls form a non-decreasing sequence, which means that ai≤ai+1 for all 1≤i<n.

Nezzar wants to color the balls using the minimum number of colors, such that the following holds.

For any color, numbers on balls will form a strictly increasing sequence if he keeps balls with this chosen color and discards all other balls.
Note that a sequence with the length at most 1 is considered as a strictly increasing sequence.

Please help Nezzar determine the minimum number of colors.

Input
The first line contains a single integer t (1≤t≤100) — the number of testcases.

The first line of each test case contains a single integer n (1≤n≤100).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n). It is guaranteed that a1≤a2≤…≤an.

Output
For each test case, output the minimum number of colors Nezzar can use.
