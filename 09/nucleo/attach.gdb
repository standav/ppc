target remote | openocd -f /usr/share/openocd/scripts/interface/stlink-v2-1.cfg -f /usr/share/openocd/scripts/target/stm32f4x.cfg -f gdb-pipe.cfg
monitor halt
monitor gdb_sync
stepi
