#include <cyg/hal/hal_io.h>
#include <cyg/hal/hal_intr.h>

int main(void)
{
	int b=0,i=0;
	while (true)
	{
		CYGHWR_HAL_STM32_GPIO_IN(CYGHWR_HAL_STM32F4DISCOVERY_BTN1,&b);
		CYGHWR_HAL_STM32_GPIO_OUT(CYGHWR_HAL_STM32F4DISCOVERY_LED1, b&1);

		i ^= 1;
		CYGHWR_HAL_STM32_GPIO_OUT(CYGHWR_HAL_STM32F4DISCOVERY_LED2, i&1);

		HAL_DELAY_US(1000 * 100 ); // 100ms
	}
	return 0;
}