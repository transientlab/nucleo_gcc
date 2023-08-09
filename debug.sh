openocd -f interface/stlink.cfg -f target/stm32f3x.cfg -c "program main.elf verify reset exit"
openocd -f interface/stlink.cfg -f target/stm32f3x.cfg &
sleep 5
gdb main.elf -ex "target remote localhost:3333"
quit

gdb-multiarch main.elf -ex "target extended-remote 192.168.0.3:3333"
gdb-multiarch main.elf -x tools/gdb-remote --batch-silent
