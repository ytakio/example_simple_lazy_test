#include "led.h"

static int led_val[] = {
	// 7seg LED
	0, 0, 0, 0,
	0, 0, 0, 0,
}

static int led_dummy_error = 0;

int led_dummy_force_error(int error) {
	led_dummy_error = error;
}

int led_set(int idx, int val) {
	if (led_dummy_error) {
		return -1;
	}
	led_val[idx] = val;
	return 0;
}

int led_get(int idx) {
	if (led_dummy_error) {
		return -1;
	}
	return led_val[idx];
}

