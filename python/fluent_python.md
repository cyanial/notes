# Notes on Fluent Python

- [Notes on Fluent Python](#notes-on-fluent-python)
  - [Python 内置序列类型](#python-内置序列类型)
    - [可变序列 & 不可变序列](#可变序列--不可变序列)
    - [list comprehension & generator expression](#list-comprehension--generator-expression)

## Python 内置序列类型


### 可变序列 & 不可变序列

可变序列:

- list
- bytearray
- array.array
- collections.deque
- momoryview

不可变序列:

- tuple
- str
- bytes

### list comprehension & generator expression

list comprehension:

[x for x in my_list]

generator expression:

tuple(x for x in my_list)