#ifndef _BLE_SERVER_LIB_H_
#define _BLE_SERVER_LIB_H_

#include "stdint.h"


#define CONNECT_EVENT 14

#define DISCONNECT_EVENT 15
// Type definition for BLE receive callback function
typedef void (*ble_recv_callback_handle_t)(uint8_t *, uint16_t);

typedef void (*ble_connect_callback_handle_t)(int);

// Register a callback function for BLE events
void ble_callback_register_callback(ble_recv_callback_handle_t cb);


void ble_connect_event_register_callback(ble_connect_callback_handle_t cb);

// Initialize the BLE server
void BLE_SERVER_INIT(void);

// Send a message to the phone
void send_message_to_phone(char *payload, uint16_t size);

// Disable BLE functionality
void ble_disable(void);
#endif