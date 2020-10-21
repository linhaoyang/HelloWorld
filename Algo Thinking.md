#算法思想

### BackTracking 回溯:
So in fact, it’s kinda like a depth-first search(DFS) with an added constraint that we stop exploring the subtree 
as soon as we know for sure that it won’t lead to valid solution. 
The problems that can be solved using this tool generally satisfy the following criteria :

1.You are explicitly asked to return a collection of all answers.

2.You are concerned with what the actual solutions are rather than say the most optimum value of some parameter. 
(if it were the latter it’s most likely DP or greedy).

---

##### 最优子结构: 
> 最优子结构想表达的是，如果一个问题的最优解包含其子问题的最优解，那么我们就称这个问题有最优子结构性质。也就是说，一个问题的最优解一定是由其各个子问题的最优解组合而成的。

### Divide and Conquer 分而治之特点:

满足两条性质:

1. 具有最优子结构，该问题可以分解为若干个规模较小的**相同**子问题。即问题一样,规模变小!

2.  该问题所分解出的各个子问题是相互**独立**的，并且它们的解可以**合并**为最终该问题的解；

### DP 动态规划特点
满足三条性质:

1. 具有最优子结构
2. 重叠子问题：
   这个问题相对就容易理解很多。如果我们在递归求解的过程中，反复的求解了相同的子问题，那么就称这个问题有**重叠**子问题。

3. 状态的无后效性: 
   状态的无后效性指的是，**当一个状态被确定之后，一定不会被在其之后确定的状态所影响**。也就是说，每个状态的确定都不会影响到之前已经确定的状态。 或者说，一个子问题的解是在 子子 问题中选择得到的，那么在计算出子问题的解之后，子问题的解不会影响到 子子 问题。

---

### Greedy 贪心：
A greedy algorithm, as the name suggests, always makes the choice that seems to be the best at that moment. This means that it makes a locally-optimal choice in the hope that this choice will lead to a globally-optimal solution.
The Greedy algorithm has only one shot to compute the optimal solution so that it **never goes back and reverses the decision.**

---

# 数据结构分析
## Tree-based Data Structure
### Heap
- Complete Tree,Parent always larger than children(max heap)
- 常用于处理最大最小问题,并且不需要sort时

### BinaryTree
- The left subtree of a node contains only nodes with keys lesser than the node’s key.
- The right subtree of a node contains only nodes with keys greater than the node’s key.
- The left and right subtree each must also be a binary search tree.
