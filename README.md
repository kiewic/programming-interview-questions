# Programming Interview Questions

Questions organized in topics:

* [Facebook Hacker Cup 2017](./HackerCup2017)
* [Cracking the Coding Interview](./CrackingTheCodingInterview)
* [STL examples](./stl)

Questions not organized in topics:

* Get Duplicates
* Longest Chain
* Playlists
* Zombie Clusters

## Problems on 8/28/2020:

* How many unique numbers there are in an array: `[3, 2, 1, 1, 9] = > 4`
* Given a two dimensional array of nes and zeros, where one means land and zero means water, find the larges perimeter island. For example 7 in the following map.

```
1 0 1 1 1
1 0 1 1 1
0 0 0 1 1
```

## Problems on 9/10/2020:

Given a binary tree, calculate the greater number sum. For example:

```
        10
      /    \
    5       15
   /       /  \
  2      12    20
```

The output should be:

```
        47
      /    \
    52      20
   /       /  \
  54     35    0
```

Given a coordinate system, a list of nodes and a number K, return the K nodes with the shortest Euclidean distance from the origin (0, 0). For example:

```
[[1, 2], [-10, 4], [5, 6]]
K = 2
```

The K closest nodes are:

```
[[1, 2], [5, 6]]
```

Given an alphabet and a list of words, determine if the list of words is in alphabetical order.

```
words = ["cat", "bat", "tab"]
alphabet = "catb"
Solution is true
```

Given a list of wood pieces L and a desired number of pieces K, what is the largest size we can cut the pieces? For example:

```
L = [5, 9, 7]
K = 4
Solution is 4
First pieces cut into 4 + 1
Second piece cut into 4 + 4 + 1
Third piece cut into 4 + 3
```
