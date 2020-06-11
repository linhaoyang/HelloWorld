BackTracking:
So in fact, it’s kinda like a depth-first search(DFS) with an added constraint that we stop exploring the subtree 
as soon as we know for sure that it won’t lead to valid solution. 
The problems that can be solved using this tool generally satisfy the following criteria :

1.You are explicitly asked to return a collection of all answers.

2.You are concerned with what the actual solutions are rather than say the most optimum value of some parameter. 
(if it were the latter it’s most likely DP or greedy).


======================================================

Divide and Conquer:
1.该问题的规模缩小到一定的程度就可以容易地解决

2.该问题可以分解为若干个规模较小的相同问题。  问题一样,规模变小!

3.利用该问题分解出的子问题的解可以合并为该问题的解；

4.该问题所分解出的各个子问题是相互独立的，即子问题之间不包含公共的子子问题。(非必需）

5.2.1对使用条件的分析
第1条随着问题规模的减少，问题自然会容易解决。条件2，3是分治的前提。即Divide-and-Conquer的必要条件。 
第4条，对于存在公共子问题的问题，使用分治算法会存在重复计算的问题，使用动态规划较为合适。

5.2.1.1浅谈分治与动态规划
分治和动态规划有共通也有不同，我们来看如下两个定义。

最优子结构：如果问题的一个最优解中包含了子问题的最优解，则该问题具有最优子机构。

重叠子问题：用来求解原问题的递归算法反复地解同样的子问题，而不是总是在产生新的子问题。对两个子问题来说，
如果它们确实是相同的子问题，只是作为不同问题的子问题出现的话，则它们是重叠的。
当子问题相互独立时，能且只能使用分治。存在重叠子问题时，动态规划是更好的算法。 
In a word, 分治法 —— 各子问题独立；动态规划 —— 各子问题重叠。

====================================================

Greedy：
A greedy algorithm, as the name suggests, always makes the choice that seems to be the best at that moment. This means that it makes a locally-optimal choice in the hope that this choice will lead to a globally-optimal solution.
The Greedy algorithm has only one shot to compute the optimal solution so that it **never goes back and reverses the decision.**
