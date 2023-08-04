mingw32-make.exe -f Makefile
PAUSE

openocd.exe -f interface/stlink.cfg -f target/stm32f3x.cfg -c "program main.elf verify reset exit"
PAUSE

start cmd /K ""..\openocd\bin\openocd.exe" -f interface/stlink.cfg -f target/stm32f3x.cfg && exit"
TIMEOUT 3
"arm-none-eabi-gdb.exe" main.elf -q -ex "target remote localhost:3333"
PAUSE