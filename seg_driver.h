#ifndef SEG_DRIVER__H
#define SEG_DRIVER__H

/**
 * @brief set 7seg led
 *
 * @param val number
 *
 * @return result
 * @retval 0 success
 * @retval -1 fail
 */
int seg_set_number(int val);

/**
 * @brief get 7seg led value
 *
 * @return result
 * @retval <= 0 value
 * @retval -1 fail
 */
int seg_get_number();

#endif
