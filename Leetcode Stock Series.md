# Leetcode Stock Series

source: https://mp.weixin.qq.com/s/hvaTYIz73xjR0_Kqel2mgw

## State Transfer Illustration

Take problem 188 as the most general example



### Choice

- there are **3 choices for each day**
  - buy
  - sell
  - rest (no operation done)
- Constraints on these choices:
  - `sell` must happen after `buy`
  - `buy` must happen after `sell` or nothing has been done
  - `rest` has 2 types: after `buy` and after `sell` 
  - `buy` can only be done with `k>0`

### State

- 3 state properties for this problem
  - number of day
  - maximum number of transactions allowed
  - current state of holding stocks
    - 1 - holding
    - 0 - not holding

- Example:
  - `dp[3][2][1]` - on Day 3, hold stock and 2 transactions can be done
  - `dp[2][3][0]` - on Day 2, not holding stock and 3 transactions can be done
- The final answer is `dp[n-1][K][0]`

### State Transfer

![image-20220416173401142](C:\Users\Morphling\AppData\Roaming\Typora\typora-user-images\image-20220416173401142.png)

We have:

```
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
```

Interpretation: the maximum profit achieved today (today I don't hold stock) can result from 2 possibility:

- yesterday didn't hold either and today choose to rest
- yesterday hold and today choose to sell it at price `prices[i]`

And another transfer:

```
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
```

Interpretation: the maximum profit achieved today (today I hold stock) can result from 2 possibility:

- yesterday held too and today choose to rest
- yesterday didn't hold and today choose to buy it at price `prices[i]`
  - note **the reason why use `dp[i-1][k-1][0]`:**
    - `k` here doesn't mean the number of transactions has been made
    - but it means the limit of transactions that can be made from that day
    - so the state tranferring to this should be the optimal state with maximum number of transactions being `k-1` because on this day we need one transaction

### Base Case

```
dp[-1][...][0] = 0
```

because the stock hasn't been released and no profit can be made

```
dp[-1][...][1] = -inf
```

because it is impossible to have profit before start. Assign it with the least value

```
dp[...][0][0] = 0
```

because no transaction can be made. profit is 0

```
dp[...][0][1] = -inf
```

because no transaction can be made and it is impossible to hold stock

## Problems

### 121

k = 1

simplify the tranfer for selling:

```
dp[i][1] = max(dp[i-1][1], 0 - prices[i])
```

### 122

k = infinity

We can then simplify the state transfer because state `dp[...][k][...]` is the same as `dp[...][k-1][...]`

### 123

k = 2

Follow the normal transfer equation and do optimization on space complexity

### 188

k = user specify

Follow the normal transfer equation and do optimization on space complexity

### 309

k = infinity with cooldown

Affects the action of `buy`. When choosing to buy on day i, the transfer should start from day i-2

```
dp[i][1] = max(dp[i-1][1], 
			(i >= 2 ? dp[i-2][0] - prices[i-1] : -prices[i-1]);
```

- question: the `dp[i-1][0]` can also be the one reached by `rest ` and it can also buy after day i-1. Why we use the value `dp[i-2][0]` but not considering the value `dp[i-1][0]`
  - Because if it is the case (`dp[i-1][0]` is reached by rest from `dp[i-2][0]`), `dp[i-1][0] == dp[i-2][0]` is true 
- when `i < 2`, it is impossible to sell and only `buy` can happen (on the first day)

### 714

 k = infinity with fee

simply subtract the fee when doing the action `buy` 

```
dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1] - fee);
```

