#ifndef _BLE_SERVER_LIB_H_
#define _BLE_SERVER_LIB_H_

#include "stdint.h"

// Type definition for BLE receive callback function
typedef void (*ble_recv_callback_handle_t)(uint8_t *, uint16_t);

// Register a callback function for BLE events
void ble_callback_register_callback(ble_recv_callback_handle_t cb);

// Initialize the BLE server
void BLE_SERVER_INIT(void);

// Send a message to the phone
void send_message_to_phone(char *payload, uint16_t size);

// Disable BLE functionality
void ble_disable(void);
#endif