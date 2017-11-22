chp10
=
[Exercise 10.1](https://github.com/yzs997/c-primer/tree/master/chp10/10.1)
-
> The algorithm header defines a function named count that, like find,
takes a pair of iterators and a value.count returns a count of how
often that value appears.Read a sequence of ints into a vector and print the count of how many elements have a given value.

[Exercise 10.2](https://github.com/yzs997/c-primer/tree/master/chp10/10.2)
-
> Repeat the previous program, but read values into a list of strings.

[Exercise 10.3](https://github.com/yzs997/c-primer/tree/master/chp10/10.3)
-
> Use accumulate to sum the elements in a vector<int>.

Exercise 10.4
-
> Assuming v is a vector<double>, what, if anything, is wrong with calling ```
```
accumulate(v.cbegin(), v.cend(), 0)?
```
The reason is std::accumulate is a template function. The third parameter is _Tp __init. When "0" , an integer, had been specified here, the compiler deduced _Tp as interger.

Exercise 10.5
-
> In the call to equal on rosters, what would happen if both rosters held C-style strings, rather than library strings?

For such case, std::equal is going to compare the address value rather than the string value. So the result is not the same as std::string. Try to avoid coding this way
