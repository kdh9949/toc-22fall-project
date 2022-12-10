# toc-22fall-project
Theory of Computing ('22 Fall) Project

8조 - 김동현, 선민준

## Reference

Takuya Mieno, Kiichi Watanabe, Yuto Nakashima, Shunsuke Inenaga, Hideo Bannai, Masayuki Takeda, Palindromic trees for a sliding window and its applications,
Information Processing Letters, Volume 173, 2022

Can read at [https://arxiv.org/abs/2006.02134](https://arxiv.org/abs/2006.02134)

## Build

```bash
cd code
g++ -o main main.cc -O2 -std=c++17
```

## Counting Number of distinct palindromes

Efficiently counts number of distinct palindromes in current substring.

Usage : `./main -d`

Example Input:
```
10
push a
push b
push c
push a
push a
pop
pop
push c
push a
push a
```

Example Output:
```
1
2
3
3
4
4
3
4
5
6
```

Explanation:
```
a         a
ab        a,b
abc       a,b,c
abca      a,b,c
abcaa     a,aa,b,c
 bcaa     a,aa,b,c
  caa     a,aa,c
  caac    a,aa,c,caac
  caaca   a,aa,aca,c,caac
  caacaa  a,aa,aca,aacaa,c,caac
```

## Counting Number of MUPS

MUPS(Minimal Unique Palindromic Substrings) : substring `S[i..j]` of string `S` such that:

* `S[i..j]` is palindrome
* `S[i..j]` is unique in `S`
* `i+1>j-1`, or `S[i+1..j-1]` is not unique (repeating) in `S`

For example, `bbabb` is MUPS of `aaababbabb`, since it's palindrome, uniquely appears, and `bab` is repeated.

Usage : `./main -m`

Example Input:
```
10
push a
push a
push b
push a
push b
push b
pop
push a
push b
pop
```

Example Output:
```
1
1
2
2
3
4
3
3
2
1
```

Explanation:
```
a         a
aa        aa
aab       aa,b
aaba      aa,b
aabab     aa,aba,bab
aababb    aa,aba,bab,bb
 ababb    aba,bab,bb
 ababba   aba,bab,bb
 ababbab  aba,bb
  babbab  bb
```
