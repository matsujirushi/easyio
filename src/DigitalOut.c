#include <DigitalOut.h>

#include <assert.h>
#include <stdlib.h>

#include <applibs/gpio.h>

struct DigitalOutInstType
{
	int Fd;
};
typedef struct DigitalOutInstType DigitalOutInstType;

void* DigitalOut_new(int pin, int value)
{
	DigitalOutInstType* inst = malloc(sizeof(DigitalOutInstType));
	assert(inst != NULL);

	inst->Fd = GPIO_OpenAsOutput(pin, GPIO_OutputMode_PushPull, value == 0 ? GPIO_Value_Low : GPIO_Value_High);
	assert(inst->Fd >= 0);

	return inst;
}

void DigitalOut_write(void* inst, int value)
{
	DigitalOutInstType* this = (DigitalOutInstType*)inst;

	int ret = GPIO_SetValue(this->Fd, value == 0 ? GPIO_Value_Low : GPIO_Value_High);
	assert(ret == 0);
}
