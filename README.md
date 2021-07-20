# esp-idf-benchmark
Dhrystone/Whetstone benchmark for esp-idf.

Benchmark with O2 compile option enabled.   

# Dhrystone Benchmark
I ported from [here](https://github.com/Keith-S-Thompson/dhrystone/tree/master/v2.2).   

# Whetstone Benchmark 
I ported from [here](https://github.com/fm4dd/sbc-benchmarks/tree/master/sbc-bench/src/whetstone).

# Installation for ESP32
```
git clone https://github.com/nopnop2002/esp-idf-dhrystone
cd esp-idf-dhrystone/
idf.py set-target esp32
idf.py menuconfig
idf.py flash
```

# Installation for ESP32-S2
```
git clone https://github.com/nopnop2002/esp-idf-dhrystone
cd esp-idf-dhrystone/
idf.py set-target esp32s2
idf.py menuconfig
idf.py flash
```


# Installation for ESP32-C3
```
git clone https://github.com/nopnop2002/esp-idf-dhrystone
cd esp-idf-dhrystone/
idf.py set-target esp32c3
idf.py menuconfig
idf.py flash
```
# How to set O2 compile option   
The default compile option for esp-idf is Os.   
Compile options can be changed in the CMakeLists.txt.   
Changing the compile option to [O2] enables [zero-overhead loop].   
zero-overhead loop can execute a loop with a predetermined number of executions without branching overhead.   

# Result   

|SoC|Freq(Mhz)|Dhrystone(MIPS)|Whetstones(MIPS)|
|:-:|:-:|:-:|:-:|
|ESP32|240|259|50.0|
|ESP32|160|167|33.3|
|ESP32S2|160|142|25.0|
|ESP32C3|160|356|20.0|
