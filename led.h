#ifndef LED__H
#define LED__H

const int LED_IDX_NUM = 8;	/// number of indices

/**
 * @brief set led status
 *
 * @param idx index
 * @param val status
 *
 * @return result
 * @retval 0 success
 * @retval -1 fail
 */
int led_set(int idx, int val);

/**
 * @brief get led status
 *
 * @param idx index
 *
 * @return result
 * @retval 0/1 status
 * @retval -1 fail
 */
int led_get(int idx);

#endif
