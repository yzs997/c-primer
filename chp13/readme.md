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
