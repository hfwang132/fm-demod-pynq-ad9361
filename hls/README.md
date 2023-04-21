# Introduction

This folder contains the source codes for Vitis HLS. 

There are three IPs: `fir_complex`, `fm_discrim`, and `fir_real`.

* These three IPs have some characteristics in common:
  * AXI-Stream Interface
  * Optimation directives:
    * Arbitrary precision data type
    * Pipelining
    * Coeffcients and data stored in BRAMs

* `fir_complex` is the first-stage two-channel (I/Q) decimation filter.
  * 64-tap FIR; Decimation factor = 10; Programmable coefficients
  * Resource utilization (Before implemention): 4298 FFs, 9519 LUTs, 2 DSPs, 9 BRAMs
  * Latency = 162 cycles

* `fm_discrim` is the phase discrimination IP.
  * Resource utilization (Before implemention): 10363 FFs, 14111 LUTs, 0 DSPs, 0 BRAM
  * Latency = 90 cycles, Initiation Interval (II) = 1 (Very high throughput)

* `fir_real` is the second stage decimation filter.
  * 64-tap FIR; Decimation factor = 5; Programmable coefficients
  * Resource utilization (Before implementation): 2881 FFs, 5908 LUTs, 1 DSPs, 7 BRAMs
  * Latency = 163 cycles

* Design Space Exploration
  * These designs only use pipelining as optimization directives. Data are stored in BRAMs.
  * array partitioning and loop unrolling can be used to exchange more areas for fewer latencies.

# Caveats

Note that the following codes are added at the header files:

```c
#include <gmp.h>
#define __gmp_const const
```

This is to resolve the cosimulation bug when using arbitrary precision data types. 

Reference: https://support.xilinx.com/s/question/0D52E00006xoQLMSA2/using-apinth-in-my-design-causes-many-crtl-cosimulation-errors-mainly-in-mpfrh?language=en_US
