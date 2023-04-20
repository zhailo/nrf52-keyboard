/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2019 Jim Jiang <jim@lotlab.org>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <stdint.h>

/* USB和蓝牙的显示参数 */
#define VENDOR_ID 0x1209 /* USB VID */
#define PRODUCT_ID 0x0514 /* USB PID */
#define CONF_VENDOR_ID 0x4366 /* 配置项目内显示的VendorID */
#define CONF_PRODUCT_ID 0x0324 /* 配置项目内显示的ProductID */
#define DEVICE_VER 0x0000 /* 硬件版本 */
#define MANUFACTURER "Glab" /* 硬件制造商，用于蓝牙显示 */
#define PRODUCT "HAL67" /* 硬件名词，用于蓝牙显示 */
#define MACADDR_SEPRATOR ' ' /* 蓝牙名称后地址的分隔符。若不设置则不显示蓝牙名称后面的地址 */

/* USB HID report parameter */
#define KEYBOARD_EPSIZE 8 /* 键盘上传端点大小，请不要修改 */
#define NKRO_EPSIZE 28 /* 键盘NKRO端点大小，请不要修改 */

// 定义Bootmagic按键
#define BOOTMAGIC_KEY_BOOT KC_U /* 开机 */
#define BOOTMAGIC_KEY_ERASE_BOND KC_E /* 删除所有绑定 */

// 键盘省电参数
#define SLEEP_SLOW_TIMEOUT 15 // 键盘闲置多久后转入慢速扫描模式 (s)
#define SLEEP_OFF_TIMEOUT 1100 // 键盘闲置多久后转入自动关机 (s)
#define KEYBOARD_SCAN_INTERVAL 1 // 键盘最小时间单位TICK (ms)
#define KEYBOARD_FAST_SCAN_INTERVAL 10 // 通常模式下，多久扫描一次键盘 (ms)
#define KEYBOARD_SLOW_SCAN_INTERVAL 100 // 慢速模式下，多久扫描一次键盘 (ms)
#define LED_AUTOOFF_TIME 5 /* LED自动熄灭时长(s)，设为0则不自动熄灭 */
#define DCDC_ENABLED //启用DCDC电源模式

// 键盘额外功能
//#define DYNAMIC_TX_POWER /* 启用自动发射功率调整 */
//#define PASSKEY_REQUIRED /* 需要输入配对码 */
#define ENABLE_WATCHDOG /* 启用看门狗 */
#define HIGH_TX_POWER /* 更改发射功率到+4dBm */
#define MULTI_DEVICE_SWITCH  /*启用多设备切换 */
#define KEYMAP_STORAGE /* 启用keymap存储 */
// #define MACRO_BLOCKING_MODE /* 在宏播放时禁用其他按键输入 */
#define MACRO_STORAGE /* 启用宏存储功能 */
#define CONFIG_STORAGE /* 启用配置存储功能 */

// #define DEBUG_SKIP_PWRON_CHECK /*  直接开机而跳过开机条件检测，用于调试 */

/* TMK固件内置功能 */
/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

// LED 配置
// #define LED_CAPS 4  //caps led ：5 ； led1、2、3、4：19、20、27、26

// ws2812 RGB 配置
#define RGB_DI_PIN 4
#define RGBLED_NUM 100
#define DRIVER_LED_TOTAL RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGB_PWR_PIN 3 // P-mos
//#define RGB_PWR_PIN_REVERSE 20 // N-mos

//RGB_MATRIX 配置
#define RGB_MATRIX_KEYPRESSES // reacts to keypresses
//#define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS // enable framebuffer effects
#define RGB_DISABLE_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
#define RGB_DISABLE_AFTER_TIMEOUT 2 // OBSOLETE: number of ticks to wait until disabling effects
//#define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
//#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT // Sets the default mode, if none has been set
#define RGB_MATRIX_STARTUP_HUE 0 // Sets the default hue value, if none has been set
#define RGB_MATRIX_STARTUP_SAT 255 // Sets the default saturation value, if none has been set
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#define RGB_MATRIX_CENTER { 70, 16 }
#define RGB_MATRIX_INDICATORS_CAPS 32
#define RGB_MATRIX_INDICATORS_HOST 1
// 3灯指示配置引脚
// #define LED_STATUS_BLE 19
// #define LED_STATUS_CHARGING 18
// #define LED_STATUS_USB 20
// #define LED_BLE_CHANNEL1 19
// #define LED_BLE_CHANNEL2 20
// #define LED_BLE_CHANNEL3 18
#define LED_POSITIVE // LED上拉驱动

// RGB 配置
//#define LED_RGB_CC // 是否为共阴LED
//#define LED_RGB_R 5
//#define LED_RGB_G 4
//#define LED_RGB_B 3
//#define RGB_LIGHT_ANIMATIONS

// 独立硬件按钮
#define POWER_BUTTON 21

// USB UART 传输配置
#define HAS_USB // 启用与CH554的通信支持
#define UART_RXD 0 // UART_RX口IO 17
#define UART_TXD 1 // UART_TX口IO 18
//#define UART_DET 19 // UART 检测引脚，若此脚被拉低，则说明USB正在工作。若不配置则使用RX口作为检测引脚
#define UART_BAUDRATE NRF_UART_BAUDRATE_115200 // 通信波特率，请不要修改

// 电量检测配置
#define BATTERY_ADC_PIN NRF_SAADC_INPUT_AIN0 // 电量检测引脚 Pin 2

// 充电检测配置
//#define PIN_CHARGING !UCC1
//#define PIN_STANDBY !UCC2

// 多用途 Bootloader 按钮
#define NRF_BL_DFU_MULTI_ROLE_BTN 21
// Bootloader指示灯
//#define LED_DFU_INIT 5
//#define LED_DFU_START 4
//#define LED_DFU_FINISH 3
// 按键阵列配置
#define MATRIX_ROWS 5 /* 硬件阵列行数 */
#define MATRIX_COLS 16 /* 硬件阵列列数 */

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))

static const uint8_t row_pin_array[MATRIX_ROWS] = { 8, 7, 6, 12, 24 };
static const uint8_t column_pin_array[MATRIX_COLS] = { 25, 26, 27, 28, 29, 30, 31, 5, 11, 13, 14, 15, 16, 17, 18, 99 };
#define ROW_IN // 键盘阵列的二极管方向是从COL->ROW

// 编码器数量
#define NUMBER_OF_ENCODERS 2
// 旋钮配置
#define ROTARY_ENCODER_A {9,20} // 编码器A脚IO
#define ROTARY_ENCODER_B {10,19} // 编码器B脚IO
// 旋钮正向按钮映射
#define ROTARY_ENCODER_POS {{1,15},{3,15}} // 正向旋转映射到键盘的按键行列
// 旋钮负向按钮映射
#define ROTARY_ENCODER_NEG {{2,15},{4,15}} // 负向旋转映射到键盘的按键行列
// 独立旋钮按键  用于关机后开机
// #define ROTARY_BUTTON 15

/* define if matrix has ghost */
// #define MATRIX_HAS_GHOST /* 按键阵列是否出现Ghost Key，若没有加二极管则需要启用这个项目 */

#define DEBOUNCE 5 /* 硬件消抖次数，设置为0则不消抖 */
#define MATRIX_SCAN_DELAY_CYCLE 48 /* 按键扫描等待IO稳定的延时时长 */

// 采用内部RC
#define NRFX_CLOCK_CONFIG_LF_SRC 0
#define CLOCK_CONFIG_LF_SRC 0
#define NRF_SDH_CLOCK_LF_SRC 0
#define NRF_SDH_CLOCK_LF_RC_CTIV 16
#define NRF_SDH_CLOCK_LF_RC_TEMP_CTIV 2
#define NRF_SDH_CLOCK_LF_ACCURACY 1

//配置RTC预分频器.
// <0> 32MHz <1> 16MHz <3> 8MHz <7> 4MHz <15> 2MHz <31> 1MHz 
#define APP_TIMER_CONFIG_RTC_FREQUENCY 0
