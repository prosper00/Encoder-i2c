PREFIX?=riscv64-unknown-elf
NEWLIB?=/usr/include/newlib

ADDITIONAL_C_FILES  = $(notdir $(wildcard ./*.c))

TARGET_MCU?=CH32V003
TARGET_EXT?=c

CH32V003FUN?=ch32v003fun
MINICHLINK?=minichlink

WRITE_SECTION?=flash
SYSTEM_C?=$(CH32V003FUN)/ch32v003fun.c

CFLAGS?=-g -Os -flto -ffunction-sections -fdata-sections -fmessage-length=0 -msmall-data-limit=8

CFLAGS_ARCH+=-march=rv32ec -mabi=ilp32e -DCH32V003=1
GENERATED_LD_FILE?=$(CH32V003FUN)/generated_ch32v003.ld
TARGET_MCU_LD:=0
LINKER_SCRIPT?=$(GENERATED_LD_FILE)
LDFLAGS+=-L$(CH32V003FUN)/../misc -lgcc

CFLAGS+= \
	$(CFLAGS_ARCH) -static-libgcc \
	-I$(NEWLIB) \
	-I$(CH32V003FUN) \
	-nostdlib \
	-I. -Wall $(EXTRA_CFLAGS)

LDFLAGS+=-T $(LINKER_SCRIPT) -Wl,--gc-sections -Wl,--print-memory-usage
FILES_TO_COMPILE:=$(SYSTEM_C) $(ADDITIONAL_C_FILES) 

$(TARGET).bin : $(TARGET).elf
	$(PREFIX)-size $^
	$(PREFIX)-objdump -S $^ > $(TARGET).lst
	$(PREFIX)-objdump -t $^ > $(TARGET).map
	$(PREFIX)-objcopy -O binary $< $(TARGET).bin
	$(PREFIX)-objcopy -O ihex $< $(TARGET).hex

ifeq ($(OS),Windows_NT)
closechlink :
	-taskkill /F /IM minichlink.exe /T
else
closechlink :
	-killall minichlink
endif

terminal : monitor

monitor :
	$(MINICHLINK)/minichlink -T

unbrick :
	$(MINICHLINK)/minichlink -u

gdbserver : 
	-$(MINICHLINK)/minichlink -aG

clangd :
	make clean
	bear -- make build
	@echo "CompileFlags:" > .clangd
	@echo "  Remove: [-march=*, -mabi=*]" >> .clangd

clangd_clean :
	rm -f compile_commands.json .clangd
	rm -rf .cache

FLASH_COMMAND?=$(MINICHLINK)/minichlink -w $< $(WRITE_SECTION) -b

$(GENERATED_LD_FILE) :
	$(PREFIX)-gcc -E -P -x c -DTARGET_MCU=$(TARGET_MCU) -DMCU_PACKAGE=$(MCU_PACKAGE) -DTARGET_MCU_LD=$(TARGET_MCU_LD) $(CH32V003FUN)/ch32v003fun.ld > $(GENERATED_LD_FILE)


$(TARGET).elf : $(FILES_TO_COMPILE) $(LINKER_SCRIPT) $(EXTRA_ELF_DEPENDENCIES)
	$(PREFIX)-gcc -o $@ $(FILES_TO_COMPILE) $(CFLAGS) $(LDFLAGS)

cv_flash : $(TARGET).bin
	make -C $(MINICHLINK) all
	$(FLASH_COMMAND)

cv_clean :
	rm -rf $(TARGET).elf $(TARGET).bin $(TARGET).hex $(TARGET).lst $(TARGET).map $(TARGET).hex || true

build : $(TARGET).bin
