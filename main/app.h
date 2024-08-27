#include "driver/gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_bt.h"
#include "bt_app_core.h"
#include "bt_app_av.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"
#include "esp_a2dp_api.h"
#include "esp_avrc_api.h"

/* device name */
#define LOCAL_DEVICE_NAME "ESP_SPIKER"


enum {
    BT_APP_EVT_STACK_UP = 0,
};
#define VAL_PLUS_BUTTON_GPIO    GPIO_NUM_34
#define VAL_MINUS_BUTTON_GPIO   GPIO_NUM_35

#define LED_ERROR   GPIO_NUM_21
#define LED_OK      GPIO_NUM_19

void my_bt_init();
void bt_av_hdl_stack_evt(uint16_t event, void *p_param);
void button_init(int pin);
void led_init(int pin);