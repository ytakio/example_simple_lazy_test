#include "led.h"
#include "seg_driver.h"

static const int SEG_VAL_NUM = 10;	/// number of value

static const int seg_lookup_table[SEG_VAL_NUM] = {
	// bit wise led status
	0x00,	// 0
	0x00,	// 1
	0x00,	// 2
	0x00,	// 3
	0x00,	// 4
	0x00,	// 5
	0x00,	// 6
	0x00,	// 7
	0x00,	// 8
	0x00,	// 9
};

int seg_set_number(int val) {
	array = seg_lookup_table[val];
	for (int i = 0; i < LED_IDX_NUM; i++) {
		if (led_set(i, array & 1) < 0) {
			return -1;
		}
		array >>= 1;
	}
	return 0;
}

int seg_get_number() {
	int array = 0;
	for (int i = LED_IDX_NUM-1; 0 <= i; i--) {
		int val = led_get(i);
		if (val < 0) {
			return -1;
		}
		array <<= led_get(i);
	}
	// check which number
	for (int i = 0; i < SEG_VAL_NUM; i++) {
		if (array == seg_lookup_table[i]) {
			return i;
		}
	}
	return -1;
}

#ifdef TEST

int led_dummy_force_error(int error);	// force include

int main(int argc, char* argv[])
{
	int val;
	val = 0;
	if (seg_set_number(val) != 0) {
		return -1;	// test fail
	}
	if (seg_get_number() != val) {
		return -1;	// test fail
	}

	// check error branch
	led_dummy_force_error(1);
	if (seg_set_number(0) != -1) {
		return -1;	// test fail
	}
	if (seg_get_number() != -1) {
		return -1;	// test fail
	}
	
	return 0;
}

#endif	// TEST
