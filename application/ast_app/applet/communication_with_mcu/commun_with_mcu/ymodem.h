#ifndef _FYMODEM_H_
#define _FYMODEM_H_

/**
 * Free YModem implementation.
 *
 * Fredrik Hederstierna 2014
 *
 * This file is in the public domain.
 * You can do whatever you want with it.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

/* max length of filename */
#define FYMODEM_FILE_NAME_MAX_LENGTH  (64)

/* receive file over ymodem */
/*int32_t fymodem_receive(uint8_t *rxdata,
                        size_t rxsize,
                        char filename[FYMODEM_FILE_NAME_MAX_LENGTH]);*/

/* send file over ymodem */
int32_t fymodem_send(uint8_t *txdata,
                     size_t txsize,
                     const char *filename);

void ymodem_transmitter_set_callback_write(int (*callback)(const char *s, int n));
void ymodem_transmitter_set_callback_read(int (*callback)(unsigned int timout));
#endif

