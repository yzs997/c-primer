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
