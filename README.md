## Generic-C-API

A simple generic Poco API for CRUD operations with Random Access Files (console application)

It allows to save/load plain old C++ object data into/from random access data files, regardless of data types.

The file data structure is defined by a fixed lenght data block that results from the size of a Poco object.

This example of implementation consists in 3 modules: Dynamic Menus, Generic CRUD API and an example of implementation (bank account management)

The generic API has a main template class: File. File has the core methods that allows file management and CRUD operations. It is possible to:
- create files 
- create records 
- read records 
- update records
- delete records 
- obtain ordered data lists
- import objects from files
- export data to .txt
 
Data flows through string streams. A multimap data structure is also provided, allowing in-memory data manipulation so more personalized implementation is possible. 

The Menu module allows to create "unending" menus and sub-menus. It follows a logic similar to linked lists. The main class BaseMenu contains the core methods. A sub-menu is created by extending the BaseMenu class and implementing load() and printOptions() methods.

The requisits to implement this API are:
- a sequencial integer id attribute 
- a fixed lenght Poco 
- It is limited to one Poco per file.  

Implementation can be done by instantiating a File object to create a file and implement read/write operations. For comparisons between attributes, is is necessary to create a struct (cmpByString) to overload the multimap compare operator.

The main objective and motivation was to consolidate knowledge in C++ programming.
The API is very simple and it needs further improvement.

The bank account implementation is merly exemplary and it needs a lot of improvement. It uses the generic API to provide a simple bank account management and transactions.
