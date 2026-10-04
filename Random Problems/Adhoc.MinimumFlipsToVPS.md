Given a string s consisting only of '(' and ')'.

In **one operation**, you can flip any parenthesis:

`   '(' → ')'  ')' → '('   `

Return the **minimum number of flips** required to make s a valid parentheses string.

If it is impossible, return -1.

### Examples

`   s = "))(("  Answer = 2   `

One solution:

`   ))((  ↓ flip first )  ()((  ↓ flip third (  ()()   `

`   s = "())("  Answer = 1   `

Flip the last (:

`   ())(  ↓  ()))   `

Actually, that's not valid—so let's use a cleaner example:

`   s = "())"   `

This has odd length, so answer is -1.

A valid example:

`   s = "())("   `

Flip the third character:

`   ())(   ↓  ()()   `

Answer = 1.

Derivation
==========

First observation:

### 1\. Odd length → impossible

A valid parentheses string must contain equal numbers of ( and ).

Therefore:

`   if (s.size() % 2)      return -1;   `

2\. Track balance
-----------------

`   '(' → +1  ')' → -1   `

While scanning:

`   balance += (s[i] == '(' ? 1 : -1);   `

If:

`   balance < 0   `

the current prefix is invalid.

We **must** fix it.

What can fix it?

`   ')' → '('   `

This changes:

`   -1 → +1   `

so the balance increases by **2**.

Therefore:

`   ans++;  balance += 2;   `

This flip is **forced**.

3\. What if balance is positive at the end?
===========================================

Suppose:

`   balance = 4   `

That means we have excess (.

Flip:

`   '(' → ')'   `

which changes balance:

`   +1 → -1   `

So balance decreases by **2**.

Therefore:

`   4 → 2 → 0   `

requires:

`   4 / 2 = 2   `

flips.

So:

`   ans += balance / 2;   `

Final solution
==============

`   class Solution {  public:      int minFlips(string s) {          int n = s.size();          if (n % 2)              return -1;          int balance = 0;          int ans = 0;          for (char c : s) {              if (c == '(')                  balance++;              else                  balance--;              // Prefix became invalid.              // Must flip a ')' to '('.              if (balance < 0) {                  ans++;                  balance += 2;              }          }          // Remaining excess '('.          // Each flip changes balance by -2.          ans += balance / 2;          return ans;      }  };   `

### Complexity

`   Time:  O(n)  Space: O(1)   `

The Q&A you should keep
=======================

### Q1. Why check odd length?

A valid string has equal numbers of opening and closing brackets, so its length must be even.

### Q2. Why do we immediately flip when balance < 0?

Because the current prefix is already invalid.

At least **one flip is unavoidable**.

So:

`   ans++;   `

is forced, not an arbitrary greedy choice.

### Q3. Why balance += 2?

We're conceptually changing:

`   ')' → '('   `

whose contribution changes:

`   -1 → +1   `

Difference = +2.

### Q4. Why don't we carry the negative balance?

Because a valid parentheses string can **never** have negative balance at any prefix.

So as soon as it happens, we repair it.

### Q5. Why is flipping immediately optimal?

When the balance first becomes negative, **some** ')' must eventually be changed to '(' to repair that prefix.

Doing it immediately restores the balance by 2 and keeps the prefix valid.

Waiting cannot reduce the number of flips required for that already-invalid prefix.

### Q6. Why balance / 2 at the end?

Suppose:

`   balance = 6   `

There are excess opening brackets.

Each:

`   '(' → ')'   `

reduces balance by 2.

Therefore:

`   6 → 4 → 2 → 0   `

\= 3 flips.

Hence:

`   balance / 2   `

### Q7. Why don't we need to know which ) we flipped?

Because for counting the minimum, **the exact position doesn't matter** once a prefix has become negative.

We only need to account for the required +2 correction.

### Q8. What if balance is -2?

You won't normally see -2 after the repair because you immediately fix when it first reaches negative.

For example:

`   "))   `

First ):

`   balance = -1   `

fix:

`   balance = 1   `

Second ):

`   balance = 0   `

So we keep the balance non-negative throughout the scan.

### Q9. What's the big greedy idea?

There are **two independent types of imbalance**:

`   During scan:  balance < 0  → too many ')'  → flip ')' → '('  → +2  At the end:  balance > 0  → too many '('  → flip '(' → ')'  → -2   `

That's the entire algorithm.

### Q10. What's the proof in one line?

> **Every time a prefix becomes negative, at least one flip is unavoidable; after all prefixes are valid, every remaining 2 units of positive balance require exactly one flip.**

That's the reasoning I'd actually remember rather than memorizing the code.