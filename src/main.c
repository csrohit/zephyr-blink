#include <zephyr/zephyr.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>
#include <zephyr/devicetree/gpio.h>

#define LED DT_ALIAS(csled)
static struct gpio_dt_spec spec = GPIO_DT_SPEC_GET(LED, gpios);
void main(void)
{
    

    if (!device_is_ready(spec.port))
    {
        return;
    }

    int ret = gpio_pin_configure_dt(&spec, GPIO_OUTPUT_ACTIVE);
    if (ret < 0)
    {
        return;
    }

    while (1)
    {
        ret = gpio_pin_toggle_dt(&spec);
        k_msleep(1000);
    }
}
