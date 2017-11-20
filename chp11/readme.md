
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
