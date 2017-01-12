# Facebook Hacker Cup 2017

## Qualification Round

* 25: Progress Pie 
* 30: Lazy Loading 
* 45: Fighting the Zombie 

## Qualification Round Solutions

The problems for this round were written by Wesley May.

### Progress Pie

For each point, we need to check two things:

**1) Is the point close enough to the center that it could be within the circle at all?**


This is as simple as computing the distance between the point and the center of the circle: `sqrt((X - 50)^2 + (Y - 50)^2)`. This distance must be no greater than 50, the radius of the circle.

**2) Is the point between the two lines that define the bounds of the current circle sector?**

We’d like to know the angle of the given point in the reference frame where 0 degrees is up and 90 degrees is to the right, since that’s the way the boundary of the circle sector moves as the progress increases.

Most languages have an `atan2()` function which can give you the angle from (0, 0) to a given point. However, this function puts 0 degrees to the right and 90 degrees upwards, so it’s necessary to translate the output to the desired reference frame.

And of course, if P = 0%, all points are white.

### Lazy Loading

Consider the heaviest item that hasn’t yet been moved. When this item is moved, it should certainly be on the top of the stack to make the current bag appear as heavy as possible. To move this item we’ll need to add as many other items as necessary to make the bag appear to weigh at least 50 pounds.

This leads us to the following greedy solution: At every step, put the heaviest available item (with weight `W`) in the bag, along with the `K` lightest available items, where `K` is the lowest integer that satisfies `(K + 1) * W >= 50`. If there aren’t enough remaining items to fake a 50-pound bag, then you can’t complete another trip. Pretend that you put those items in the last bag moved.
To efficiently find the heaviest and lightest items, we should first sort the input. This takes `O(N log N)` time, and the rest of the algorithm takes `O(N)` time. (Given the small bound on the weights of the items, a more efficient sorting method is possible, but unnecessary.)

### Fighting the Zombie

For each attack, we need to compute the probability that it rolls at least `H` damage. We can compute this using dynamic programming.

Let `f(D, K)` be the probability of dealing at least `K` damage with `D` dice. For a given input `X Y Z` we want to compute `f(X, H - Z)`. We can use the following recursive definition:

* `f(D, K) = 1` for `K <= 0` (We can always do at least 0 damage)
* `f(0, K) = 0` for `K > 0` (We can't do a positive amount of damage with 0 dice)
* `f(D, K) = (1 / Y) * ( f(D - 1, K - 1) + f(D - 1, K - 2) + ... + f(D - 1, K - Y) )`

This last formula combines the outcomes of all possible die rolls for a single die, and weights them evenly by `1 / Y`.

In this way, we can compute the probability of success for each attack in `O(X * Y * (H - Z))` time.

Since the most damage we can do is X * Y, we can trivially reject any case where `H - Z > X * Y`. That means we can also consider the time complexity to be `O(X * Y * X * Y) = O(X^2 * Y^2)`.
