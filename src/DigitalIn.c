#include <DigitalIn.h>

#include <assert.h>
#include <stdlib.h>

#include <applibs/gpio.h>

struct DigitalInInstType
{
	int Fd;
};
typedef struct DigitalInInstType DigitaInInstType;

void* DigitalIn_new(int pin)
{
	DigitaInInstType* inst = malloc(sizeof(DigitaInInstType));
	assert(inst != NULL);

	inst->Fd = GPIO_OpenAsInput(pin);
	assert(inst->Fd >= 0);

	return inst;
}

int DigitalIn_read(void* inst)
{
	DigitaInInstType* this = (DigitaInInstType*)inst;

	GPIO_Value_Type outValue;
	int ret = GPIO_GetValue(this->Fd, &outValue);
	assert(ret == 0);
	assert(outValue == GPIO_Value_High || outValue == GPIO_Value_Low);

	return outValue == GPIO_Value_High ? 1 : 0;
}
