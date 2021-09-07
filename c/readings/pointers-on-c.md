# Pointers On C by Kenneth Reek

### 1.1 Tips: Comments code bocks with `#if 0 #endif`

Supposed that we have blocks of codes with traditional c-comments(`/* */`).

```c
/* This is a multi-line comments.
 * line 
 * line
 */
#include <stdio.h>
...
```

If we comments the code in traditional way, then - 

```c
/*
/* This is a multi-line comments.
 * line 
 * line
 */
*/
#include <stdio.h>
...
```
It may cause a compiler-time error.
