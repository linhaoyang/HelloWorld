
使用一个vector 处理矩阵问题

class Solution {
    int uniquePaths(int m, int n) {
    
    	
        if (m > n) return uniquePaths(n, m);		//处理内存占用 始终用小的一端开始计算
	
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
}; 

==========================================================================================================

$$组合公式

class Solution {
    public:
        int uniquePaths(int m, int n) {
            int N = n-1 + m-1;// how much steps we need to do
            int k = m - 1; // number of steps that need to go down
            double res = 1;
            // here we calculate the total possible path number 
            // Combination(N, k) = n! / (k!(n - k)!)
            // reduce the numerator and denominator and get
            // C = ( (n - k + 1) * (n - k + 2) * ... * n ) / k!
            for (int i = 1; i <= k; i++)
                res = res * (N - k + i) / i;
            return (int)res;
        }
    };

===========================================================================================================

class Solution {
public:

	int lookup[100][100];
	int count;

	int nn;

	int uniquePaths(int m, int n) {

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				lookup[i][j] = -1;
			}
		}

		nn = n-1;
		count = tryFindEnd(m - 1, 0);

		return count;
	}

	int tryFindEnd(int x, int y) {

		if (lookup[x][y] > -1) {
			return lookup[x][y];
		}

		cout << " tryFindEnd" << x << y << endl;
		if (y == nn || x == 0) {
			return 1;
		}

		int result = tryFindEnd(x - 1, y) + tryFindEnd(x, y + 1);
		lookup[x][y] = result;
		return result;
		
	}
};

====================================================================================================================
