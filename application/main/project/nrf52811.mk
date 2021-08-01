SRC_FILES += \
	$(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52811.S \
	$(SDK_ROOT)/modules/nrfx/mdk/system_nrf52811.c

CFLAGS += -DFLOAT_ABI_SOFT
CFLAGS += -DNRF52811_XXAA
CFLAGS += -mfloat-abi=soft

ASMFLAGS += -mfloat-abi=soft
ASMFLAGS += -DFLOAT_ABI_SOFT
ASMFLAGS += -DNRF52811_XXAA

SOFTDEVICE := S112
HEAP_SIZE := 2048
STACK_SIZE := 2048

LD_NAME := nrf52811_s112.ld

NRF_FAMILY := NRF52811
