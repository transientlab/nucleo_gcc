make

openocd -f interface/stlink.cfg -f target/stm32f3x.cfg -c "program main.elf verify reset exit"

openocd -f interface/stlink.cfg -f target/stm32f3x.cfg

TIMEOUT 3

arm-none-eabi-gdb main.elf -q -ex "target remote localhost:3333"
PAUSE