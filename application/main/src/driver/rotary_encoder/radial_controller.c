#include "app_scheduler.h"
#include "keyboard_fn.h"
#include "keyboard_host_driver.h"

union radial_controller_data
{
    uint16_t data;
    struct {
        bool press: 1;
        int16_t deg: 15;
    };
};

static union radial_controller_data data_send;

static void send_data_handler(void* pointer, uint16_t len)
{
    keyboard_send_packet(PACKET_RADIAL_CONTROLLER, 2, (uint8_t*)&data_send);
    data_send.deg = 0; // 其他数据自动归零
}

void press_fn_handler(keyrecord_t* record, uint8_t id, uint8_t opt)
{
    int8_t sz = opt <= 7 ? opt : opt - 16;
    if (id == RADIAL_CONTROLL) {
        if (sz) {
            if (record->event.pressed) {
                data_send.deg  = sz * 100;
            }
        } else {
            data_send.press = record->event.pressed;
        }
        app_sched_event_put(0, 0, &send_data_handler);
    }
}

FN_HANDLER(press_fn_handler);
