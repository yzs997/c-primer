chp13
=
Exercise 13.1
-
>What is a copy contructor?When we use it?<br>

A copy constructor is a constructor which first parameter is a reference to the class type and any additional parameters have default values.<br>
When copy initialization happens and that copy initialization requires either the copy constructor or the move constructor.<br>
* Define variables using an `=`
* Passing an object as argument to a parameter of non-reference type.
* Return an object from a function that has a non-reference return type.
* Brace initialize the elements in an array or the members of an aggregate class.
* Some class type also use copy initialization of the objects they allocate.

Exercise 13.2
-
>Explan why the following declaration is illegal
```cpp
Sales_data::Sales_data(Sales_data rhs);
```
If declaration like that, the call would never succeed to call the copy constructor, Sales_data rhs is an argument to a parameter, thus, we'd need to use the copy constructor to copy the argument, but to copy the argument, we'd need to call the copy constructor, and so on indefinitely.

Exercise 13.3
-

>What happens when we copy a StrBlob? What about StrBlobPtrs?

when we copy a StrBlob, the shared_ptr member's use_count add one.

when we copy a StrBlobPrts, the weak_ptr member's use_count isn't changed.(cause the count belongs to shared_ptr)

Exercise 13.4
-
>Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:

```cpp
Point global;

Point foo_bar(Point arg)							//1
{
	Point local = arg, *heap = new Point(global);				//2, 3

*heap = local;									
	Point pa[4] = { local, *heap };						//4, 5
	return *heap;								//6
}
```

[Exercise 13.5](https://github.com/yzs997/c-primer/blob/master/chp13/ex_13_05.h)
-
Exercise 13.6
-
>What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?

* The copy-assignment operator is function named `operator=` and takes an argument of the same type as the class.
* This operator is used when assignment occurred.
* The synthesized copy-assignment operator assigns each `nonstatic` member of the right-hand object to corresponding member of the left-hand object using the copy-assignment operator for the type of that member.
* It is synthesized when the class does not define its own.

Exercise 13.7
-
>What happens when we assign one StrBlob to another? What about StrBlobPtrs?

In both cases, shallow copy will happen. All pointers point to the same address.
* the shared_ptr member's use_count add one.
* weak_ptr member's use_count isn't changed.(cause the count belongs to shared_ptr)

[Exercise 13.8](https://github.com/yzs997/c-primer/blob/master/chp13/ex_13_08.h)
-
Exercise 13.9
-
>What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?

* The destructor is a member function with the name of the class prefixed by a tilde(~).
* As with the copy constructor and the copy-assignment operator, for some classes, the synthesized destructor is defined to disallow objects of the type from being destoryed. Otherwise, the synthesized destructor has an empty function body.
* The compiler defines a synthesized destructor for any class that does not define its own destructor.

Exercise 13.10
-
>What happens when a StrBlob object is destroyed? What about a StrBlobPtr?

* When a StrBlob object destroyed, the use_count of the dynamic object will decrement. It will be freed if no shared_ptr to that dynamic object.
* When a StrBlobPter object is destroyed the object dynamically allocated will not be freed.

[Exercise 13.11](https://github.com/yzs997/c-primer/blob/master/chp13/ex_13_11.h)
-
Exercise 13.12
-
>
```cpp
bool fcn(const Sales_data *trans, Sales_data accum)
{
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
```
3 times.
* accum
* item1
* item2

[Exercise 13.13](https://github.com/yzs997/c-primer/tree/master/chp13/ex_13_13)
-
Exercise 13.14
-
>Assume that numbered is a class with a default constructor that generates a unique serial number for each object, which is stored in a data member named mysn. Assuming numbered uses the synthesized copy-control members and given the following function:

```cpp
void f (numbered s) { cout << s.mysn << endl; }
```
>what output does the following code produce?

```cpp
numbered a, b = a, c = b;
f(a); f(b); f(c);
```
3 identical numbers.

Exercise 13.15
-
>Assume numbered has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?

Yes, it does. Because, as described, the newly defined copy constructor can handle such situations as expected.Thus, the output will be three different numbers.

Exericse 13.16
-
>What if the parameter in f were const numbered&? Does that change the output? If so, why? What output gets generated?

Yes, the output will change. Because no copy operation happens within function f. Thus, the three Output are the same.

[Exercise 13.17](https://github.com/yzs997/c-primer/tree/master/chp13/ex_13_17)
-
>Write versions of numbered and f corresponding to the previous three exercises and check whether you correctly predicted the output.

[Exercise 13.18](https://github.com/yzs997/c-primer/blob/master/chp13/ex_13_18.h)
-

Exercise 13.19
-
>Does your Employee class need to define its own versions of the copy-control members?If so, why? If not, why not?Implement whatever copy-control members you think Employee needs.

```cpp
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
```

Exercise 13.20
-
>Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes from § 12.3 (p. 484).

The member (smart pointer and container) will be copied.

Exercise 13.21
-
>Do you think the TextQuery and QueryResult classes need to define their own versions of the copy-control members? If so, why? If not, why not? Implement whichever copy-control operations you think these classes require.

As synthesized version meet all requirements for this case, no custom version control memebers need to define. 







