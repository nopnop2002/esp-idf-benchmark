# esp-idf-benchmark
Dhrystone/Whetstone benchmark for esp-idf.   
I wanted to know the computing power of the ESP32-C3.   

# Dhrystone Benchmark
I ported from [here](https://github.com/Keith-S-Thompson/dhrystone/tree/master/v2.2).   

# Whetstone Benchmark 
I ported from [here](https://github.com/fm4dd/sbc-benchmarks/tree/master/sbc-bench/src/whetstone).

# Installation for ESP32
```
git clone https://github.com/nopnop2002/esp-idf-benchmark
cd esp-idf-benchmark/
idf.py set-target esp32
idf.py menuconfig
idf.py flash
```

# Installation for ESP32-S2
```
git clone https://github.com/nopnop2002/esp-idf-benchmark
cd esp-idf-benchmark/
idf.py set-target esp32s2
idf.py menuconfig
idf.py flash
```

__The following options do not exist in ESP32-S2: FPU, zero-overhead loops, MAC, DFP accelerator.__   


# Installation for ESP32-C3
```
git clone https://github.com/nopnop2002/esp-idf-benchmark
cd esp-idf-benchmark/
idf.py set-target esp32c3
idf.py menuconfig
idf.py flash
```

__It is unknown at this time whether it has the zero-overhead loops function.__   

# Compiler used   
```
$ cd .espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin
$ ./xtensa-esp32-elf-cc --version
xtensa-esp32-elf-cc (crosstool-NG esp-2020r3) 8.4.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE

$ cd .espressif/tools/xtensa-esp32s2-elf/esp-2020r3-8.4.0/xtensa-esp32s2-elf/bin
$ ./xtensa-esp32s2-elf-cc --version
xtensa-esp32s2-elf-cc (crosstool-NG esp-2020r3) 8.4.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

$ cd .espressif/tools/riscv32-esp-elf/1.24.0.123_64eb9ff-8.4.0/riscv32-esp-elf/bin
$ ./riscv32-esp-elf-cc --version
riscv32-esp-elf-cc (crosstool-NG 1.24.0.123_64eb9ff) 8.4.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```


# Benchmark with Os compile option(default).   

|SoC|Freq(Mhz)|Dhrystone(MIPS)|Whetstones(MIPS)|
|:-:|:-:|:-:|:-:|
|ESP32|240|142|16.7|
|ESP32|160|95|10.0|
|ESP32S2|160|95|8.3|
|ESP32C3|160|167|8.3|

# How to set O2 compile option   
The default compile option for esp-idf is Os.   
Compile options can be changed in the CMakeLists.txt.   
On the ESP32, Changing the compile option to [O2] enables [zero-overhead loops].   
zero-overhead loops can execute a loop with a predetermined number of executions without branching overhead.   


# Benchmark with O2 compile option enabled.   

|SoC|Freq(Mhz)|Dhrystone(MIPS)|Whetstones(MIPS)|
|:-:|:-:|:-:|:-:|
|ESP32|240|259|50.0|
|ESP32|160|167|33.3|
|ESP32S2|160|142|25.0|
|ESP32C3|160|356|20.0|
