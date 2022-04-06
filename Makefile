
all: lib

lib: seg_driver.c led.h
	$(CC) ...

test: seg_driver.c led.h led_dummy.c
	${CC) -DTEST ...


