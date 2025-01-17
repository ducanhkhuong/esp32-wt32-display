#ifndef __ID_SIGN_H_
#define __ID_SIGN_H_

#include "stdint.h"
#include <string.h>
#include "stdbool.h"

#define PRIORITY_1 1
#define PRIORITY_2 2
#define PRIORITY_3 3
#define PRIORITY_4 4

#define HEADER_CURRENT_SPEED 0x21
#define HEADER_NEXT_SPEED 0x22
#define HEADER_CAMERA 0x23
#define HEADER_TRAFFIC 0x24
#define HEADER_OTHER 0x25
#define HEADER_SPEED 0x26

#define ID_NOTHING 0x00
#define ID_SPEED_LIMIT_40 0x04
#define ID_SPEED_LIMIT_50 0x05
#define ID_SPEED_LIMIT_60 0x06
#define ID_SPEED_LIMIT_70 0x07
#define ID_SPEED_LIMIT_80 0x08
#define ID_SPEED_LIMIT_90 0x09
#define ID_SPEED_LIMIT_100 0x0A
#define ID_SPEED_LIMIT_120 0x0B

#define ID_TS_ENTER_URBAN_AREA 0x0C
#define ID_TS_EXIT_URBAN_AREA 0X0D
#define ID_TS_NO_OVER_TAKING_ZONE 0x0E
#define ID_TS_END_OF_NO_OVER_TAKING_ZONE 0x0F
#define ID_TS_SLOW_DOWN_ZONE 0x10
#define ID_TS_REST_STATIOMN 0x11
#define ID_TS_TOLL_STATION 0x12
#define ID_TS_CROSSING_RAILING_WITHOUT_BARRIER_SIGN 0x13
#define ID_TS_UNDERPASS 0x14
#define ID_OTS_NO_LEFT_TURN_SIGN 0x15
#define ID_OTS_NO_RIGHT_TURN_SIGN 0x16
#define ID_OTS_NO_LEFT_TURN_AND_UTURN_SIGN 0x17
#define ID_OTS_NO_RIGHT_TURN_AND_UTURN_SIGN 0x18
#define ID_OTS_NO_LEFT_UTURN_SIGN 0x19
#define ID_OTS_NO_RIGHT_UTURN_SIGN 0x1A
#define ID_OTS_NO_STRAIGHT_SIGN 0x1B
#define ID_OTS_NO_PARKING_SIGN 0x1C
#define ID_OTS_NO_STOP_AND_PARKING_SIGN 0x1D
#define ID_OTS_NO_PARKING_ON_ODD_DAYS_SIGN 0x1E
#define ID_OTS_NO_PARKING_ON_EVENT_DAYS_SIGN 0x1F
#define ID_TRAFFIC_CAMERA 0x20
#define ID_PENALTY_CAMERA 0x21
#define ID_RED_LIGHT_SURVEILLANCE_CAMERA 0x22
#define CENSOR_BEEP 0x100
#define OVER_LMIT_SPEED 0x101

extern bool sound_id_4;
extern bool sound_id_5;
extern bool sound_id_6;
extern bool sound_id_7;
extern bool sound_id_8;
extern bool sound_id_9;
extern bool sound_id_10;
extern bool sound_id_11;
extern bool sound_id_12;
extern bool sound_id_13;
extern bool sound_id_14;
extern bool sound_id_15;
extern bool sound_id_16;
extern bool sound_id_18;
extern bool sound_id_32;
extern bool sound_id_33;
extern bool sound_id_34;

/* STRUCTURES & TYPEDEFS -----------------------------------------------------*/

typedef struct
{
	uint8_t position_1;
	uint8_t position_2;
	uint8_t position_3;
	uint16_t distance_to_ps_2;
	uint16_t distance_to_ps_3;
} sign_display_on_watch_t;

typedef struct
{
	uint8_t current_speed;
} current_speed_t;

typedef struct
{
	uint8_t unique_id[3];
	uint8_t next_speed;
	uint8_t distance[2];
} next_speed_t;

typedef struct
{
	uint8_t number_of_sign;
	uint8_t unique_id[3][3];
	uint8_t traffic_id_sign[3];
	uint8_t distance[3][2];
} camera_sign_t;

typedef struct
{
	uint8_t number_of_sign;
	uint8_t unique_id[9][3];
	uint8_t traffic_id_sign[9];
	uint8_t distance[9][2];
} traffic_sign_t;

typedef struct
{
	uint8_t number_of_sign;
	uint8_t unique_id[10][3];
	uint8_t traffic_id_sign[10];
	uint8_t distance[10][2];
} other_sign_t;
typedef struct
{
	current_speed_t current_speed;
	next_speed_t next_speed;
	camera_sign_t camera_sign;
	traffic_sign_t traffic_sign;
	other_sign_t other_sign;

} sign_data_t;

typedef struct
{
	uint8_t last_position_1;
	uint8_t last_position_2;
	uint8_t last_position_3;
} last_sign_display_t;

sign_data_t sign_handle(uint8_t *data, uint16_t len);
sign_display_on_watch_t get_sign_display_on_watch(sign_data_t sign_data);
void check_sign_two_position(uint8_t ps2, uint8_t ps3);

#endif
