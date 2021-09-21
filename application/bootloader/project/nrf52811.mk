SRC_FILES += \
	$(SDK_ROOT)/modules/nrfx/mdk/gcc_startup_nrf52811.S \
	$(SDK_ROOT)/modules/nrfx/mdk/system_nrf52811.c
	
# Libraries common to all targets
LIB_FILES += \
	$(SDK_ROOT)/external/nrf_oberon/lib/cortex-m4/soft-float/liboberon_3.0.8.a \
	$(SDK_ROOT)/external/micro-ecc/nrf52nf_armgcc/armgcc/micro_ecc_lib_nrf52.a \

CFLAGS += -DFLOAT_ABI_SOFT
CFLAGS += -DNRF52811_XXAA
CFLAGS += -mfloat-abi=soft
CFLAGS += -DDEVELOP_IN_NRF52840
CFLAGS += -DBOARD_PCA10056

ASMFLAGS += -mfloat-abi=soft
ASMFLAGS += -DFLOAT_ABI_SOFT
ASMFLAGS += -DNRF52811_XXAA
ASMFLAGS += -DDEVELOP_IN_NRF52840
ASMFLAGS += -DBOARD_PCA10056

SOFTDEVICE := S112
HEAP_SIZE := 2048
STACK_SIZE := 2048

LD_NAME := nrf52811_s112.ld

NRF_FAMILY := NRF52810
