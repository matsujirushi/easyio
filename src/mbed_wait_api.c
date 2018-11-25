#include <mbed_wait_api.h>
#include <time.h>

void wait(float s)
{
	wait_us((int)(s * 1000000.f));
}

void wait_ms(int ms)
{
	wait_us(ms * 1000);
}

void wait_us(int us)
{
	struct timespec req;
	struct timespec rem;

	req.tv_sec = us / 1000000;
	req.tv_nsec = (us % 1000000) * 1000;

	while (nanosleep(&req, &rem) != 0)
	{
		req.tv_sec = rem.tv_sec;
		req.tv_nsec = rem.tv_nsec;
	}
}
