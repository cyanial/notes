# Notes on Fluent Python

- [Notes on Fluent Python](#notes-on-fluent-python)
  - [Python 内置序列类型](#python-内置序列类型)
    - [可变序列 & 不可变序列](#可变序列--不可变序列)
    - [list comprehension & generator expression](#list-comprehension--generator-expression)
    - [namedtuple](#namedtuple)
    - [list.sort & sorted](#listsort--sorted)
    - [bisect](#bisect)
    - [array.array](#arrayarray)

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

array.array('I', (x for x in my_list))

### namedtuple

创建包含数据的类：

```python
>>> import collections
>>> City = collections.namedtuple('City', 'name country population coordinates')
>>> tokyo = City('Tokyo', 'JP', 36.933, (35.689722, 139.691667))
>>> tokyo
City(name='Tokyo', country='JP', population=36.933, coordinates=(35.689722, 139.691667))
>>> tokyo.population
36.933
>>> tokyo.coordinates
(35.689722, 139.691667)
>>> tokyo[1]
'JP'
>>> tokyo[0]
'Tokyo'
>>> 
```

### list.sort & sorted

list.sort(): in place sort

sorted(list): return a new list


### bisect 

Founctions:

`bisect`, `bisect_left`, `insort`, `insort_left`

e.g. quick find:

```python
def grade(score, breakpoints=[60, 70, 80, 90], grades='FDCBA'):
    i = bisect.bisect(breakpoints, score)
    return grades[i]
```

### array.array

```python
>>> from array import array
>>> from random import random
>>> floats = array('d', (random() for i in range(10**7)))
>>> floats[-1]
0.9430053573451561
>>> fp = open('floats.bin', 'wb')
>>> floats.tofile(fp)
>>> fp.close()
>>> floats2 = array('d')
>>> fp = open('floats.bin', 'rb')
>>> floats2.fromfile(fp, 10**7)
>>> floats2[-1]
0.9430053573451561
>>> floats2 == floats
True
>>> 
```