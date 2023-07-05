# esp-idf-benchmark
Dhrystone/Whetstone benchmark for esp-idf.   
I wanted to know the computing power of the ESP32-C3.   

# Dhrystone Benchmark
I ported from [here](https://github.com/Keith-S-Thompson/dhrystone/tree/master/v2.2).   

# Whetstone Benchmark 
I ported from [here](https://github.com/fm4dd/sbc-benchmarks/tree/master/sbc-bench/src/whetstone).

# Supported versions of frameworks

|Chip|Framework|Versions|
|:-:|:-:|:-:|
|ESP8266|ESP8266 RTOS SDK|v3.x|
|ESP32|ESP-IDF|v5.1|
|ESP32-S2|ESP-IDF|v5.1|
|ESP32-S3|ESP-IDF|v5.1|
|ESP32-C3|ESP-IDF|v5.1|
|ESP32-C2|ESP-IDF|v5.1|
|ESP32-C6|ESP-IDF|v5.1|

# Installation for ESP8266
```
git clone https://github.com/nopnop2002/esp-idf-benchmark
cd esp-idf-benchmark/
make menuconfig(*1)
make flash monitor
```

__(*1)__   
You have to change this config.   
![ESP8266_RTOS_SDK ](https://user-images.githubusercontent.com/6020549/129280851-0a7e375d-ae32-40d6-b439-34c0ab54eb98.jpg)


# Installation for ESP32
```
git clone https://github.com/nopnop2002/esp-idf-benchmark
cd esp-idf-benchmark/
idf.py set-target {esp32/esp32s2/esp32s3/esp32c2/esp32c3/esp32c6}
idf.py menuconfig
idf.py flash monitor
```



# Compiler Version   

## ESP8266
```
$ xtensa-lx106-elf-gcc --version
xtensa-lx106-elf-gcc (crosstool-NG esp-2020r3-49-gd5524c1) 8.4.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## ESP32
```
$ xtensa-esp32-elf-cc --version
xtensa-esp32-elf-cc (crosstool-NG esp-12.2.0_20230208) 12.2.0
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## ESP32-S2
```
$ xtensa-esp32s2-elf-cc --version
xtensa-esp32s2-elf-cc (crosstool-NG esp-12.2.0_20230208) 12.2.0
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

## ESP32-S3
```
$ xtensa-esp32s3-elf-cc --version
xtensa-esp32s3-elf-cc (crosstool-NG esp-12.2.0_20230208) 12.2.0
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```


## ESP32-C2/C3/C6
```
$ riscv32-esp-elf-cc --version
riscv32-esp-elf-cc (crosstool-NG esp-12.2.0_20230208) 12.2.0
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```


# Benchmark with Og compile option(default).   

|SoC|Freq(Mhz)|Dhrystone(MIPS)|Whetstone(MIPS)||
|:-:|:-:|:-:|:-:|:-:|
|ESP8266|160|57|6.2||
|ESP32|160|95|10.0||
|ESP32|240|142|16.7||
|ESP32S2|160|95|8.3||
|ESP32S2|240|142|12.5||
|ESP32S3|160|142|10.0||
|ESP32S3|240|190|14.3||
|ESP32C3|160|167|8.3||
|ESP32C2|120|142|8.3|26MHz XTAL|
|ESP32C6|160|178|12.5||

![graph1](https://github.com/nopnop2002/esp-idf-benchmark/assets/6020549/27f054b8-4239-496a-a777-d5ddc73f9e1d)

# How to set O2 compile option   
The default compile option for esp-idf is Og.   
Compile options can be changed in the CMakeLists.txt or menuconfig.   
On the ESP32, Changing the compile option to [O2] enables [zero-overhead loops].   
zero-overhead loops can execute a loop with a predetermined number of executions without branching overhead.   


# Benchmark with O2 compile option enabled.   

|SoC|Freq(Mhz)|Dhrystone(MIPS)|Whetstone(MIPS)||
|:-:|:-:|:-:|:-:|:-:|
|ESP32|160|203|33.3||
|ESP32|240|316|50.0||
|ESP32S2|160|178|25.0||
|ESP32S2|240|283|33.3||
|ESP32S3|160|237|25.0||
|ESP32S3|240|356|50.0||
|ESP32C3|160|407|20.0||
|ESP32C2|120|356|20.0|26MHz XTAL|
|ESP32C6|160|474|25.0||

![graph2](https://github.com/nopnop2002/esp-idf-benchmark/assets/6020549/156ffcf3-ae32-405a-beee-ef004ffa9a4c)
