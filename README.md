# esp-idf-benchmark
Dhrystone/Whetstone benchmark for esp-idf.   
I wanted to know the computing power of the ESP32-C3.   

# Dhrystone Benchmark
I ported from [here](https://github.com/Keith-S-Thompson/dhrystone/tree/master/v2.2).   

# Whetstone Benchmark 
I ported from [here](https://github.com/fm4dd/sbc-benchmarks/tree/master/sbc-bench/src/whetstone).

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
idf.py set-target {esp32/esp32s2/esp32s3/esp32c2/esp32c3/esp32c5/esp32c6/esp32h2}
idf.py menuconfig
idf.py flash monitor
```

# Benchmark with Og compile option(default).   

|SoC|Freq(Mhz)|Dhrystone(MIPS)|Whetstone(MIPS)|ESP-IDF||
|:-:|:-:|:-:|:-:|:-:|:-:|
|ESP8266|160|57|6.2|||
|ESP32|160|142|9.1||V6.0|
|ESP32|240|142|16.7|V6.0||
|ESP32S2|160|95|8.3|V6.0||
|ESP32S2|240|142|12.5|V6.0||
|ESP32S3|160|142|10.0|V6.0||
|ESP32S3|240|190|14.3|V6.0||
|ESP32C2|120|142|8.3|V6.0|26MHz XTAL|
|ESP32C3|160|142|9.1|V6.0||
|ESP32C5|240|316|20.0|V6.0||
|ESP32C6|160|142|12.5|V6.0||
|ESP32H2|96|95|5.3|V6.0||
|ESP32P4|360|474|25.0|V6.0||

<img width="481" height="289" alt="Image" src="https://github.com/user-attachments/assets/c6de7943-38d4-48e7-9e54-c726a777d77e" />
<img width="481" height="289" alt="Image" src="https://github.com/user-attachments/assets/fe0df676-76b6-4927-962d-b6006f047047" />

# How to set O2 compile option   
The default compile option for esp-idf is Og.   
Compile options can be changed in the CMakeLists.txt or menuconfig.   
On the ESP32, Changing the compile option to [O2] enables [zero-overhead loops].   
zero-overhead loops can execute a loop with a predetermined number of executions without branching overhead.   


# Benchmark with O2 compile option enabled.   

|SoC|Freq(Mhz)|Dhrystone(MIPS)|Whetstone(MIPS)|ESP-IDF||
|:-:|:-:|:-:|:-:|:-:|:-:|
|ESP32|160|219|25.0|V6.0||
|ESP32|240|356|33.3|V6.0||
|ESP32S2|160|178|25.0|V6.0||
|ESP32S2|240|285|33.3|V6.0||
|ESP32S3|160|237|33.3|V6.0||
|ESP32S3|240|356|50.0|V6.0||
|ESP32C2|120|316|25.0|V6.0|26MHz XTAL|
|ESP32C3|160|407|20.0|V6.0||
|ESP32C5|240|711|50.0|V6.0||
|ESP32C6|160|407|33.3|V6.0||
|ESP32H2|96|259|12.5|V6.0||
|ESP32P4|360|949|100.0|V6.0||

<img width="481" height="289" alt="Image" src="https://github.com/user-attachments/assets/320d1b54-cf16-4aec-b2df-2745cf5ea783" />
<img width="481" height="289" alt="Image" src="https://github.com/user-attachments/assets/8c1e8c71-62cb-4a71-9718-1a1c7728b6f5" />
