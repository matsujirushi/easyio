I/O peripherals access library for Azure Sphere

# Functions

|Category|Function|
|:--|:--|
|mbed_wait_api|void wait(float s)|
||void wait_ms(int ms)|
||void wait_us(int us)|
|DigitalOut|void* DigitalOut_new(int pin, int value)|
||void DigitalOut_write(void* inst, int value)|
|DigitalIn|void* DigitalIn_new(int pin)|
||int DigitalIn_read(void* inst)|
