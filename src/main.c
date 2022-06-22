#include <zephyr.h>
#include <drivers/gpio.h>
#include <device.h>
#include <devicetree/gpio.h>

#define LED DT_ALIAS(csled)

void main(void)
{


    // struct gpio_dt_spec spec = {
    //     .port = DEVICE_DT_GET(DT_NODELABEL(gpio2)),
    //     .pin = 3,
    //     .dt_flags = GPIO_ACTIVE_HIGH
    // };

        struct gpio_dt_spec spec = GPIO_DT_SPEC_GET(LED, gpios);

    if(!device_is_ready(spec.port)){
        return ;
    }

    int ret = gpio_pin_configure_dt(&spec, GPIO_OUTPUT_ACTIVE);
    if(ret < 0){
        return;
    }


    while (1)
    {
        ret = gpio_pin_toggle_dt(&spec);
        ret = gpio_pin_get_dt(&spec);
        if(ret < 0){
            return;
        }
        k_msleep(5000);
    }
    


}
