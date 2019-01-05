# CodeforcesSimplesFetcher
A simple application that fetch a codeforce problem simple tests, and put them into a folder called TT

## How to use it
1. step generate the .jar file 
2. call the jar with the link of the problem in argument
```
yourfile.jar https://codeforces.com/problemset/problem/4/A
```
  
3.  Use the files of the TT folder


## Structure of TT Floder
The command wil generate the TT folder in the same working folder, which will contains:
1. numberofinput contains the number of test cases equal to n
1. Input-i i in {1..n} contains input data for the i st simple test cases
2. output-i i in {1..n} contains input data for the i st simple test cases
