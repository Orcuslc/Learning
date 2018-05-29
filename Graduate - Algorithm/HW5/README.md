# Explanation of the algorithm:

Let `dp[i]` represents the number of minimum operations to transform source[0:i] to target[0:i], and `flip[i][j]` represents the number of minimum operations to transform source[i:j] to target[i:j] after a filp of source[i:j+1].

Suppose we have all `dp[n]` and `source[n][j]` for some `j < n`. Then for source[0:n+1] and target[0:n+1], there are such cases and `dp[n+1]` is the minimum among the results of these cases:

1. source[n+1] is not flipped, then `dp[n+1] = dp[n] + 1_{source[n+1] = target[n+1]}`, here `1_{f} = 1` if f is true and `1_f = 0` if f is false.

2. source[n+1] is flipped. Now we suppose it is flipped in some subarray like source[j:n+1], then `dp[n+1] = dp[j-1] + flip[j][n+1] + 1`. The last `1` here refer to the operation of flipping. (I didn't notice the assumption that the portions where any two flips are applied don't overlap, which took me hours writing a much more complex algorithm.) Then we can seperate this into some subcases:
	1. `j = n+1`. In fact, there is no need for flipping here since we can use substitution to replace flipping and save an operation, and `flip[n+1][n+1] = 1_{source[n+1] = target[n+1]}`.
	2. `j = n`. In this case, `flip[n][n+1] = 1_{source[n+1] = target[n]} + 1_{source[n] = target[n+1]}` since there will be an extra substitution for each unsatisfied equation.
	3. `j < n`. We may seperate the sequence into three parts: `source[j], source[j+1:n], source[n+1]`. After a flip, it will become `source[n+1], source[n:j+1], source[j]`. For the ends, it is the same with case 2; for the middle, we have solved it with `flip[j+1][n]`. Hence, `flip[j][n+1] = 1_{source[j] == target[n+1]} + 1_{source[n+1] = target[j]} + flip[j+1:n]`.

Finally, we return `dp[length(source)]` as the final result.


# Compile and run:
There are two versions of this algorithm, the Python version `string_transform.py` and the C++ version `string_transform.cpp`. Since then C++ version uses a lot STL library, it is recommended to compile it with `-O3` or `-Ofast` flag. Suppose the output is `a.out`.

## Data format: 
Each data consists of two rows, the first row is the source, and the second row is the target.
There will be no labels like `1.` and no blank row between two datas.
Suppose the data file be `data.txt`.

## Running: 
1. For Python:
`python3 string_transform.py < data.txt`
2. For C++:
`./a.out < data.txt`


## Output:
Output will be printed to STDOUT, each a line.