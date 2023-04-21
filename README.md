# FM demodulation with AD9361, python and PYNQ

---

## 1) Introduction

This project provides an example of FM demodulation with AD9361, python and PYNQ. Both software and hardware implementations are explored.

## 2) Targeted Audience

- People interested in controlling SDR devices with python
- People interested in High-Level-Synthesis development on Xilinx Zynq devices
- People interested in [PYNQ](http://www.pynq.io/) for agile hardware development and verification

## 3) Hardware platform
  * [ZedBoard](https://digilent.com/reference/programmable-logic/zedboard/start)
    * xc7z020, with abundant peripherals
  * [AD-FMCOMMS2-EBZ](https://www.analog.com/en/design-center/evaluation-hardware-and-software/evaluation-boards-kits/eval-ad-fmcomms2.html)
    * AD-FMCOMMS2-EBZ is an evaluation board with AD9361 and an FMC connector.
    
  ZedBoard and FMCOMMS2 can be connected together via the FMC interface.

## 4) Software Platform

  * Vivado 2021.2
  * Vitis HLS 2021.2
  * PYNQ v2.4 with ADI 2019_R1 Linux kernel support
    * see [this repository](https://github.com/Godfly666/zedboard-adi-pynq) for manuals for building the kernel

## 5) Performance

- Software implementation
  - takes ~4.6s to demodulate 2.4M samples
- Hardware implementation
  - takes ~321ms to demodulate 2.4M samples
