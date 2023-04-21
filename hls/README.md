# Note

Note that the following codes are added at the header files:

```c
#include <gmp.h>
#define __gmp_const const
```

This is to resolve the cosimulation bug when using arbitrary precision data types. 

Reference: https://support.xilinx.com/s/question/0D52E00006xoQLMSA2/using-apinth-in-my-design-causes-many-crtl-cosimulation-errors-mainly-in-mpfrh?language=en_US
