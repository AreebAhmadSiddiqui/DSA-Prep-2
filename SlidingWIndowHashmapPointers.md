# Subarray / Substring Cheat Sheet

## 1. First: Can I Transform the Elements?

This should become an automatic question.

| Problem wording | Transform |
| --- | --- |
| Number of odd elements | Odd -> `1`, even -> `0` |
| Number of even elements | Even -> `1`, odd -> `0` |
| Number of elements satisfying a condition | `true` -> `1`, `false` -> `0` |
| Binary array | Already `0/1` |
| Sum or count condition | Think prefix sum |

### Example

**Exactly `k` odd numbers** becomes:

- Odd -> `1`
- Even -> `0`

Then the problem becomes:

> Subarray sum = `k`

## 2. Sliding Window

Think sliding window when the condition can be maintained by:

1. Expand `R`.
2. The window becomes invalid.
3. Move `L` until the window is valid again.

### Strong Triggers

- At most `K` distinct values
- At most `K` odd numbers
- At most `K` zeros
- Sum `<= K` with usually non-negative numbers
- Product `< K` with positive numbers
- Longest substring satisfying a condition
- Shortest substring satisfying a condition
- Contains all required characters

### Typical Structure

```cpp
for (int r = 0; r < n; r++) {
    add(a[r]);

    while (invalid) {
        remove(a[l]);
        l++;
    }

    // [l...r] is valid
}
```

### Counting

Once you know the valid boundary, ask:

> How many subarrays can I count at once?

Common answers:

- `r - l + 1`
- `l`
- `n - r`

Do not memorize which one to use blindly. Draw the possible boundaries.

## 3. Exactly `K`

This is where you should pause. Usually, there are two choices.

### A. Prefix Sum + Hashmap

If you can convert the property into `0/1`, such as:

- Odd/even
- Special/not special

Then:

```text
exactly K
    -> subarray sum = K
    -> prefix[R] - prefix[L] = K
    -> prefix[L] = prefix[R] - K
```

So:

```cpp
ans += mp[prefix - K];
mp[prefix]++;
```

### B. `atMost(K) - atMost(K - 1)`

If it is naturally a window property, such as:

- Exactly `K` distinct values
- Exactly `K` odd numbers
- Exactly `K` zeros

You can often use:

```text
exactly K = atMost(K) - atMost(K - 1)
```

## 4. At Most `K`

This should immediately make you think:

> Sliding window.

Examples:

- At most `K` distinct characters
- At most `K` odd numbers
- At most `K` zeros

The pattern is:

```text
valid -> expand -> invalid
                     |
                   shrink
                     |
                   valid
```

## 5. At Least `K`

Do not automatically use the same template. Ask:

> Is the condition monotonic when I shrink or expand?

For example, consider a substring that contains `a`, `b`, and `c`:

- At least one `a`
- At least one `b`
- At least one `c`

This works beautifully with a sliding window. Once a window contains all three:

```text
valid -> shrink -> valid -> shrink -> invalid
```

Once it becomes invalid, further shrinking cannot make it valid again. That is the structure used in problem 1358.

## 6. Sum = `K`

Think:

> Prefix sum + hashmap

### Equation

$$
prefix[R] - prefix[L] = K
$$

Therefore:

$$
prefix[L] = prefix[R] - K
$$

### Code

```cpp
mp[0] = 1;

for (...) {
    prefix += a[i];
    ans += mp[prefix - K];
    mp[prefix]++;
}
```

**Classic:** 560 - Subarray Sum Equals `K`

## 7. Sum Divisible by `K`

Think:

> Prefix remainder + hashmap

### Equation

$$
(prefix[R] - prefix[L]) \bmod K = 0
$$

Therefore:

$$
prefix[R] \bmod K = prefix[L] \bmod K
$$

So:

```cpp
rem = prefix % K;
ans += mp[rem];
mp[rem]++;
```

**Classic:** 974 - Subarray Sums Divisible by `K`

## 8. Sum `% K = X`

This is slightly more general.

If:

$$
(prefix[R] - prefix[L]) \bmod K = X
$$

Then:

$$
prefix[L] \bmod K = (prefix[R] - X + K) \bmod K
$$

So:

```cpp
required = (prefix % K - X + K) % K;
ans += mp[required];
mp[prefix % K]++;
```

This is the pattern from **Interesting Subarrays**.

## 9. Product `< K`

If numbers are positive, think:

> Sliding window

Because:

- Expand -> product increases
- Shrink -> product decreases

That is monotonic.

**Classic:** 713 - Subarray Product Less Than `K`

## 10. Product `% K`

This is a different problem. Do not think sliding window.

Ask:

> How many possible values can `product % K` have?

Only:

```text
0, 1, 2, ..., K - 1
```

If `K` is small, use dynamic programming grouped by remainder. This is the idea behind problem 3524.

The state is essentially:

```text
dp[remainder]
```

for subarrays ending at the current position.

## 11. Subarray or Substring with Character Requirements

| Requirement | Typical approach |
| --- | --- |
| At most `K` distinct | Frequency map + sliding window |
| Exactly `K` distinct | `atMost(K) - atMost(K - 1)` |
| Contains all required characters | Frequency map + sliding window |

**Example:** 1358 - Number of Substrings Containing All Three Characters

## Mental Flow

When you see a new subarray or substring problem:

```text
SUBARRAY / SUBSTRING
          |
          v
What exactly is being counted?
          |
   +------+------+------+
   |      |      |      |
  SUM   COUNT  PRODUCT  |
   |      |      |      |
   |      |      +------+
   |      |       Can I make < K?
   |      |              |
   |      |        Sliding window
   |      |
   |      +---- Can I make it 0/1?
   |                    |
   |              Prefix sum + hashmap
   |
   +---- = K -> Prefix sum + hashmap
   |
   +---- % K -> Prefix remainder + hashmap
```

And separately:

```text
CHARACTER / FREQUENCY
          |
          v
Sliding window
          |
          +--> at most K  -> directly
          +--> exactly K  -> atMost(K) - atMost(K - 1)
          +--> all required -> sliding window
```

## The Five Triggers to Memorize First

1. **Odd/even** -> Convert to `1/0`.
2. **Sum = `K`** -> Prefix sum + hashmap.
3. **Sum `% K = 0`** -> Prefix remainder + hashmap.
4. **At most `K`** -> Sliding window.
5. **Exactly `K`** -> Prefix/hashmap or `atMost(K) - atMost(K - 1)`.

Also remember:

- **Product `< K`** -> Sliding window.
- **Product `% K`** -> Small-state dynamic programming.

That is enough for a large portion of subarray and substring questions without memorizing dozens of individual problems.