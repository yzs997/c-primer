
Chp11
==
Exercise 11.1
-
>Describe the differences between a map and a vector.

* map is an associative container.
* vector is a sequence container.

Exercise 11.2
-
>Give an example of when each of list, vector, deque, map, and set might be most useful.

* list : 双线链表。只支持顺序访问。在list中任何位置进行插入/删除操作速度都很快。
* vector : 可变大小数组。支持快速随机访问。在尾部之外的位置插入或删除元素可能很慢。
* deque : 双向队列。支持快速随机访问。在头尾插入/删除速度很快。
* mzp : 关联数组 : 保存 key-value 对。
* set : 关键字即值，即只保存关键字的容器。

[Exercise 11.3](https://github.com/yzs997/c-primer/tree/master/chp11/11.3)
-
>编写你自己的单词计数程序


[Exercise 11.4](https://github.com/yzs997/c-primer/tree/master/chp11/11.4)
-
>扩展你的程序，忽略大小写和标点。例如，"example."、"example,"和”Example"应该递增相同的计数器。

Exercise 11.5
-
>解释 map 和 set 的区别。你如何选择呢使用哪个？

Both std::set and std::map are associative containers. The difference is that std::sets contain only the key, while in std::map there is an associated value. Choosing one over the other depends mainly on what the task at hand is. If you want to build a dictionary of all the words that appear in a text, you could use a std::set<std::string>, but if you also want to count how many times each word appeared (i.e. associate a value to the key) then you would need an std::map<std::string,int>. If you don't need to associate that count, it does not make sense to have the int that is unnecessary.

Exercise 11.6
-
>解释 set 和 list 的区别。你如何选择使用哪个？

* List
  *Searching (linear time).
  * Inserting, deleting, moving (takes constant time).
  * Elements may be ordered.
  * Elements may be sorted.
  * Elements may be duplicate.
* Set
  * Searching (logarithmic in size).
  * Insert and delete (logarithimic in general).
  * Elements are un-ordered.
  * Elements are always sorted from lower to higher.
  * Elements are unique.
  
 [Exercise 11.7](https://github.com/yzs997/c-primer/tree/master/chp11/11.7)
 -
 >定义一个map, 关键字是家庭的姓, 值是一个vector, 保存家中的孩子(们)的名. 编写代码, 实现添加新的孩子以及向以后家庭中添加新的孩子。
 
 [Exercise 11.8](https://github.com/yzs997/c-primer/tree/master/chp11/11.8)
 -
>编写一个程序，在一个vector而不是一个set中保存不重复的单词。使用set的优点是什么？

* A set is ordered. It is guaranteed to remain in a specific ordering, according to a functor that you provide. No matter what elements you add or remove (unless you add a duplicate, which is not allowed in a set), it will always be ordered.
* A vector has exactly and only the ordering you explicitly give it. Items in a vector are where you put them. If you put them in out of order, then they're out of order; you now need to sort the container to put them back in order.
* The time it takes to insert an item into a vector is proportional to the number of items already in the vector. The time it takes to insert an item into a set is proportional to the log₂ of the number of items. If the number of items is large, that's a huge difference. log₂(100,000) is ~16; that's a major speed improvement. The same goes for removal.
* However, if you do all of your insertions at once, at initialization time, then there's no problem. You can insert everything into the vector, sort it (paying that price once), and then use standard algorithms for sorted vectors to find elements and iterate over the sorted list. And while iteration over the elements of a set isn't exactly slow, iterating over a vector is faster.
* So there are cases where a sorted vector beats a set. That being said, you really shouldn't bother with the expense of this kind of optimization unless you know that it is necessary. So use a set unless you have experience with the kind of system you're writing (and thus know that you need that performance) or have profiling data in hand that tells you that you need a vector and not a set.


Exercise 11.9
-
> 定义一个 map, 将单词与一个行号的 list 关联, list 中保存的是单词所出现的行号.

```
map<string, list<size_t>> m
```

Exercise 11.10
-
> 可以定义一个 vector<int>::iteartor 到 int 的 map 吗? list<int>::ierator 到 int 的  map 呢? 对于两种情况, 如果不能, 解释为什么?
 
 * vector<int>::iterator to int is ok, because < is defined;
 * list<int>::iterator to int is not ok, as no < is defines;
                                                   
 Exercise 11.11
 -
 > 不适用 decltype 重新定义 bookstore
 
 ```
 multiset<Sales_data, bool (*)(const Sales_data&, const Sales_data&)> bookstore(compareIsbn);
 ```
 
 [Exercise 11.12](https://github.com/yzs997/c-primer/tree/master/chp11/11.12) 
 -
 > 编写程序, 读入 string 和 int 的序列, 将每个 string 和 int 存入一个 pair 中, pair 保存在一个 vector 中.
 
 Exercise 11.13
 -
 > 上一题的程序中, 至少有三种创建 pair 的方法.编写此程序的三个版本, 分别采用不同的方法创建 pair .解释你认为哪种形式最易于编写和理解,为什么?
 
 ```
 vec.push_back(make_pair(s, i));
 vec.push_back({s, i});
 vec.push_back(pair<string, int>(s, i));
 vec.emplace_back(s, i);  //easiest.
 ```

[Exercise 11.14](https://github.com/yzs997/c-primer/tree/master/chp11/11.14)
-
> 扩展你在 11.2.1 节练习(第 378 页)中编写的孩子姓到名的 map,添加一个 pair 的 vector,保存孩子的名和生日.

Exrcsise 11.15 
-
> 对于一个 int 到vector<int> 的 map,其 mapped_type, key_type 和 value_type 分别是什么?

* mapped_type : vector<int>
* key_type : int
* value_type : pair<const int, vector<int>>

Exercise 11.16:
-
> Using a map iterator write an expression that assigns a value to an element.

```
std::map<int, std::string> map;
map[25] = "Alan";
std::map<int, std::string>::iterator it = map.begin();
it->second = "Wang";
```

Exercise 11.17
-
> Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. Indicate whether each call is legal:

```
copy(v.begin(), v.end(), inserter(c, c.end())); // legal
copy(v.begin(), v.end(), back_inserter(c)); // illegal, no `push_back` in `set`.
copy(c.begin(), c.end(), inserter(v, v.end())); // legal.
copy(c.begin(), c.end(), back_inserter(v)); // legal.
```

Exercise 11.18:
-
> Write the type of map_it from the loop on page 430 without using auto or decltype.

```
map<string, size_t>::const_iterator;
```

Exercise 11.19:
-
> Define a variable that you initialize by calling begin() on the multiset named bookstore from 11.2.2 (p. 425). Write the variable’s type without using auto or decltype.

```
multiset<Sales_data, bool (*)(const Sales_data&, Sales_data&)> bookstore(compareIsbn)
multiset<Sales_data, bool (*)(const Sales_data&, Sales_data&)>::iterator it = bookstore.begin()
```

[Exercise 11.20](https://github.com/yzs997/c-primer/tree/master/chp11/11.20)
-
> Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead of subscripting. Which program do you think is easier to write and read?Explain 
your reasoning.

Exercise 11.21
-
> Assuming word_count is a map from string to size_t and word is a string, explain the following loop:

This code can be explained like this pseudocode:

```
while reading into word
    if word_count has key word:
        word_count[word] += 1
    else:
        word_count[word] = 0
        word_count[word] += 1
```

Exercise 11.22
-
> Given a map<string, vector<int>>, write the types used as an argument and as the return value for the version of insert that inserts one element.

```
pair<string, vector<int>>                           // argument
pair<map<string, vector<int>>::iterator, bool>      // return type
```

[Exercise 11.23](https://github.com/yzs997/c-primer/tree/master/chp11/11.20)
-
> Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises

Exercise 11.24
-
> What does the following program do?

```
map<int, int> m;
m[0] = 1;
```

add a key-value pair { 0, 1 } into the map.

Exercise 11.25
-
> Contrast the following program with the one in the previous exercise

```
vector<int> v;
vec[0] = 1;
```

UB, since it's trying to dereference an item out of range.

[Exercise 11.26](https://github.com/yzs997/c-primer/tree/master/chp11/11.26)
-
> What type can be used to subscript a map? What type does the subscript
operator return? Give a concrete example—that is, define a map and then
write the types that can be used to subscript the map and the type that
would be returned from the subscript operator.

Exercise 11.27:
-
>What kinds of problems would you use count to solve?
When might you use find instead?

I would use count to deal with multimap or multi multiset.
As for the associative container that have unique key, I would use find instead of count.

Exercise 11.28:
-
> Define and initialize a variable to hold the result of calling find on a map from string to vector of int.

```
map<string, vector<in>>::iterator
```

Exercise 11.29:
-
> What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not in the container?

* lower_bound and upper_bound will return equal iterators; both will refer to the point at which the key can be inserted without disrupting the order.

* If no matching element is found, then both the first and second iterators refer to the position where this key can be inserted.



Exercise 11.30:
-
> Explain the meaning of the operand pos.first->second used in the output expression of the final program in this section.

```
cout << pos.first->second << endl;
pos                     a pair
pos.first               iterator referring to a pair
pos.first->second       the value
```

[Exercise 11.31](https://github.com/yzs997/c-primer/tree/master/chp11/11.31)
-
> Write a program that defines a multimap of authors and their works.Use find to find an element in the multimap and erase that element.Be sure your program works correctly if the element you look for is not in the map.

[Exercise 11.32](https://github.com/yzs997/c-primer/tree/master/chp11/11.32)
-
> Using the multimap from the previous exercise, write a program to print the list of **authors and their works** alphabetically.

[Exercise 11.33](https://github.com/yzs997/c-primer/tree/master/chp11/11.33)
-
> Implement your own version of the word-transformation program.




