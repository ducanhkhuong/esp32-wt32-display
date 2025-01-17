#include "utils.h"
#include "stdbool.h"
#include "esp_log.h"

#define TAG "Parse BLE data: "

bool sound_id_4 = false;
bool sound_id_5 = false;
bool sound_id_6 = false;
bool sound_id_7 = false;
bool sound_id_8 = false;
bool sound_id_9 = false;
bool sound_id_10 = false;
bool sound_id_11 = false;
bool sound_id_12 = false;
bool sound_id_13 = false;
bool sound_id_14 = false;
bool sound_id_15 = false;
bool sound_id_16 = false;
bool sound_id_18 = false;
bool sound_id_32 = false;
bool sound_id_33 = false;
bool sound_id_34 = false;

void check_sign_two_position(uint8_t ps2, uint8_t ps3){
	 if (ps2 != ID_SPEED_LIMIT_40 && ps3 != ID_SPEED_LIMIT_40 && sound_id_4 == true)
            {
                sound_id_4 = false;
            }
            if (ps2 != ID_SPEED_LIMIT_50 && ps3 != ID_SPEED_LIMIT_50 && sound_id_5 == true)
            {
                sound_id_5 = false;
            }
            if (ps2 != ID_SPEED_LIMIT_60 && ps3 != ID_SPEED_LIMIT_60 && sound_id_6 == true)
            {
                sound_id_6 = false;
            }
            if (ps2 != ID_SPEED_LIMIT_70 && ps3 != ID_SPEED_LIMIT_70 && sound_id_7 == true)
            {
                sound_id_7 = false;
            }
            if (ps2 != ID_SPEED_LIMIT_80 && ps3 != ID_SPEED_LIMIT_80 && sound_id_8 == true)
            {
                sound_id_8 = false;
            }
            if (ps2 != ID_SPEED_LIMIT_90 && ps3 != ID_SPEED_LIMIT_90 && sound_id_9 == true)
            {
                sound_id_9 = false;
            }
            if (ps2 != ID_SPEED_LIMIT_100 && ps3 != ID_SPEED_LIMIT_100 && sound_id_10 == true)
            {
                sound_id_10 = false;
            }
            if (ps2 != ID_SPEED_LIMIT_120 && ps3 != ID_SPEED_LIMIT_120 && sound_id_11 == true)
            {
                sound_id_11 = false;
            }
             if (ps2 != ID_TS_ENTER_URBAN_AREA && ps3 != ID_TS_ENTER_URBAN_AREA && sound_id_12 == true)
            {
                sound_id_12 = false;
            }
            if (ps2 != ID_TS_EXIT_URBAN_AREA && ps3 != ID_TS_EXIT_URBAN_AREA && sound_id_13 == true)
            {
                sound_id_13 = false;
            }
            if (ps2 != ID_TS_NO_OVER_TAKING_ZONE && ps3 != ID_TS_NO_OVER_TAKING_ZONE && sound_id_14 == true)
            {
                sound_id_14 = false;
            }
            if (ps2 != ID_TS_END_OF_NO_OVER_TAKING_ZONE && ps3 != ID_TS_END_OF_NO_OVER_TAKING_ZONE && sound_id_15 == true)
            {
                sound_id_15 = false;
            }
            if (ps2 != ID_TS_SLOW_DOWN_ZONE && ps3 != ID_TS_SLOW_DOWN_ZONE && sound_id_16 == true)
            {
                sound_id_16 = false;
            }
            if (ps2 != ID_TS_TOLL_STATION && ps3 != ID_TS_TOLL_STATION && sound_id_18 == true)
            {
                sound_id_18 = false;
            }
            if (ps2 != ID_PENALTY_CAMERA && ps3 != ID_PENALTY_CAMERA && sound_id_33 == true)
            {
                sound_id_33 = false;
            }
            if (ps2 != ID_TRAFFIC_CAMERA && ps3 != ID_TRAFFIC_CAMERA && sound_id_32 == true)
            {
                sound_id_32 = false;
            }
            if (ps2 != ID_RED_LIGHT_SURVEILLANCE_CAMERA && ps3 != ID_RED_LIGHT_SURVEILLANCE_CAMERA && sound_id_34 == true)
            {
                sound_id_34 = false;
            }
}
sign_data_t sign_handle(uint8_t *data, uint16_t len)
{

    // priority
    // 1 - limit speed (current speed -> next speed)
    // 2 - enter or exit urban
    // 3 - camera
    // 4 - other
    sign_data_t sign_data = {0}; // Initialize the structure to zero
    uint8_t offset = 0;
    if (data == NULL)
    {
        ESP_LOGE(TAG, "Received null data");
        return sign_data;
    }

    // Parse the data
    while (offset < len)
    {
        uint8_t header = data[offset];
        switch (header)
        {
        case HEADER_CURRENT_SPEED:
            sign_data.current_speed.current_speed = data[offset + 1];
            ESP_LOGI(TAG, "Current Speed: %d", sign_data.current_speed.current_speed);
            offset += 2; // Move to the next header
            break;

        case HEADER_NEXT_SPEED:
            memcpy(sign_data.next_speed.unique_id, &data[offset + 1], 3);
            sign_data.next_speed.next_speed = data[offset + 4];
            memcpy(sign_data.next_speed.distance, &data[offset + 5], 2);
            // ESP_LOGI(TAG, "Next Speed Unique ID: 0x%02X%02X%02X",
            //          sign_data.next_speed.unique_id[0],
            //          sign_data.next_speed.unique_id[1],
            //          sign_data.next_speed.unique_id[2]);
            // ESP_LOGI(TAG, "Next Speed: %d, Distance: 0x%02X%02X",
            //          sign_data.next_speed.next_speed,
            //          sign_data.next_speed.distance[0],
            //          sign_data.next_speed.distance[1]);
            offset += 7;
            break;

        case HEADER_CAMERA:
            sign_data.camera_sign.number_of_sign = data[offset + 1];
            if (sign_data.camera_sign.number_of_sign == 0)
            {
                // ESP_LOGI(TAG, "Dont have camera");
                offset += 2;
                break;
            }
            offset += 2;
            for (int i = 0; i < sign_data.camera_sign.number_of_sign; i++)
            {
                memcpy(sign_data.camera_sign.unique_id[i], &data[offset], 3);
                sign_data.camera_sign.traffic_id_sign[i] = data[offset + 3];
                memcpy(sign_data.camera_sign.distance[i], &data[offset + 4], 2);
                offset += 6;
                // ESP_LOGI(TAG, "Camera Sign[%d]: Unique ID: 0x%02X%02X%02X, Traffic ID: 0x%02X, Distance: 0x%02X%02X",
                //          i + 1,
                //          sign_data.camera_sign.unique_id[i][0],
                //          sign_data.camera_sign.unique_id[i][1],
                //          sign_data.camera_sign.unique_id[i][2],
                //          sign_data.camera_sign.traffic_id_sign[i],
                //          sign_data.camera_sign.distance[i][0],
                //          sign_data.camera_sign.distance[i][1]);
            }
            break;

        case HEADER_TRAFFIC:
            sign_data.traffic_sign.number_of_sign = data[offset + 1];
            if (sign_data.traffic_sign.number_of_sign == 0)
            {
                // ESP_LOGI(TAG, "Don't have traffic sign");
                offset += 2;
                break;
            }
            else
            {
                offset += 2;
                for (int i = 0; i < sign_data.traffic_sign.number_of_sign; i++)
                {
                    memcpy(sign_data.traffic_sign.unique_id[i], &data[offset], 3);
                    sign_data.traffic_sign.traffic_id_sign[i] = data[offset + 3];
                    memcpy(sign_data.traffic_sign.distance[i], &data[offset + 4], 2);
                    offset += 6;

                    // ESP_LOGI(TAG, "Traffic Sign[%d]: Unique ID: 0x%02X%02X%02X, Traffic ID: 0x%02X, Distance: 0x%02X%02X",
                    //          i + 1,
                    //          sign_data.traffic_sign.unique_id[i][0],
                    //          sign_data.traffic_sign.unique_id[i][1],
                    //          sign_data.traffic_sign.unique_id[i][2],
                    //          sign_data.traffic_sign.traffic_id_sign[i],
                    //          sign_data.traffic_sign.distance[i][0],
                    //          sign_data.traffic_sign.distance[i][1]);
                }
            }
            break;

        case HEADER_OTHER:
            sign_data.other_sign.number_of_sign = data[offset + 1];
            if (sign_data.other_sign.number_of_sign == 0)
            {
                ESP_LOGI(TAG, "Don't have other traffic sign");
                offset += 2;
                break;
            }
            else
            {
                offset += 2;
                for (int i = 0; i < sign_data.other_sign.number_of_sign; i++)
                {
                    memcpy(sign_data.other_sign.unique_id[i], &data[offset], 3);
                    sign_data.other_sign.traffic_id_sign[i] = data[offset + 3];
                    memcpy(sign_data.other_sign.distance[i], &data[offset + 4], 2);
                    offset += 6;

                    ESP_LOGI(TAG, "Other Sign[%d]: Unique ID: 0x%02X%02X%02X, Traffic ID: 0x%02X, Distance: 0x%02X%02X",
                             i + 1,
                             sign_data.other_sign.unique_id[i][0],
                             sign_data.other_sign.unique_id[i][1],
                             sign_data.other_sign.unique_id[i][2],
                             sign_data.other_sign.traffic_id_sign[i],
                             sign_data.other_sign.distance[i][0],
                             sign_data.other_sign.distance[i][1]);
                }
            }
            break;

        default:
            // ESP_LOGW(TAG, "Unknown header: 0x%02X at offset %d", header, offset);
            offset++;
            break;
        }
    }
    return sign_data;
}


sign_display_on_watch_t get_sign_display_on_watch(sign_data_t sign_data)
{
	sign_display_on_watch_t sign_display = {0};
	sign_display.position_1 = sign_data.current_speed.current_speed;

	if (sign_data.next_speed.next_speed == 0)
	{
		bool ps_2 = false;
		bool ps_3 = false;
		if (sign_data.traffic_sign.number_of_sign > 0)
		{
			for (int i = 0; i < sign_data.traffic_sign.number_of_sign; i++)
			{
				ESP_LOGW(TAG, "test");
				if (sign_data.traffic_sign.traffic_id_sign[i] == ID_TS_ENTER_URBAN_AREA ||
					sign_data.traffic_sign.traffic_id_sign[i] == ID_TS_EXIT_URBAN_AREA)
				{
					sign_display.position_2 = sign_data.traffic_sign.traffic_id_sign[i];
					sign_display.distance_to_ps_2 = sign_data.traffic_sign.distance[i][0] << 8 | sign_data.traffic_sign.distance[i][1];
					ps_2 = true;
				}
			}
		}
		if (sign_data.camera_sign.number_of_sign > 0)
		{
			for (int i = 0; i < sign_data.camera_sign.number_of_sign; i++)
			{
				uint16_t current_distance = sign_data.camera_sign.distance[i][0] << 8 | sign_data.camera_sign.distance[i][1];

				if (!ps_2)
				{
					sign_display.position_2 = sign_data.camera_sign.traffic_id_sign[i];
					sign_display.distance_to_ps_2 = current_distance;
					ps_2 = true;
					goto next_camera_sign;
				}
				else if (current_distance < sign_display.distance_to_ps_2)
				{
					if (sign_data.camera_sign.number_of_sign > 2)
					{
						sign_display.position_3 = sign_display.position_2;
						sign_display.distance_to_ps_3 = sign_display.distance_to_ps_2;

						sign_display.position_2 = sign_data.camera_sign.traffic_id_sign[i];
						sign_display.distance_to_ps_2 = current_distance;
						ps_3 = true;
						goto next_camera_sign;
					}
				}

				if (!ps_3)
				{
					sign_display.position_3 = sign_data.camera_sign.traffic_id_sign[i];
					sign_display.distance_to_ps_3 = current_distance;
					ps_3 = true;
				}
				else if (current_distance < sign_display.distance_to_ps_3)
				{
					if (sign_data.camera_sign.number_of_sign > 2)
						sign_display.position_3 = sign_data.camera_sign.traffic_id_sign[i];
					sign_display.distance_to_ps_3 = current_distance;
				}

			next_camera_sign:
				ESP_LOGI(TAG, "next camera sign");
			}
		}

		if (sign_data.traffic_sign.number_of_sign > 0 && ps_3 == false)
		{
			for (int i = 0; i < sign_data.traffic_sign.number_of_sign; i++)
			{
				if (sign_data.traffic_sign.traffic_id_sign[i] != ID_TS_ENTER_URBAN_AREA &&
					sign_data.traffic_sign.traffic_id_sign[i] != ID_TS_EXIT_URBAN_AREA)
				{
					uint16_t current_distance = sign_data.traffic_sign.distance[i][0] << 8 | sign_data.traffic_sign.distance[i][1];

					if (!ps_2)
					{
						sign_display.position_2 = sign_data.traffic_sign.traffic_id_sign[i];
						sign_display.distance_to_ps_2 = current_distance;
						ps_2 = true;
						goto next_traffic_sign;
					}
					else if (current_distance < sign_display.distance_to_ps_2)
					{
						if (sign_data.traffic_sign.number_of_sign > 2)
						{
							sign_display.position_3 = sign_display.position_2;
							sign_display.distance_to_ps_3 = sign_display.distance_to_ps_2;

							sign_display.position_2 = sign_data.traffic_sign.traffic_id_sign[i];
							sign_display.distance_to_ps_2 = current_distance;
							ps_3 = true;
							goto next_traffic_sign;
						}
					}

					if (!ps_3)
					{
						sign_display.position_3 = sign_data.traffic_sign.traffic_id_sign[i];
						sign_display.distance_to_ps_3 = current_distance;
						ps_3 = true;
					}
					else if (current_distance < sign_display.distance_to_ps_3)
					{
						if (sign_data.traffic_sign.number_of_sign > 2)
						{
							sign_display.position_3 = sign_data.traffic_sign.traffic_id_sign[i];
							sign_display.distance_to_ps_3 = current_distance;
						}
					}

				next_traffic_sign:
					ESP_LOGI(TAG, "Go to next traffic sign");
				}
			}
		}

		if (sign_data.other_sign.number_of_sign > 0)
		{
			for (int i = 0; i < sign_data.other_sign.number_of_sign; i++)
			{
				uint16_t current_distance = sign_data.other_sign.distance[i][0] << 8 | sign_data.other_sign.distance[i][1];

				if (!ps_2)
				{
					sign_display.position_2 = sign_data.other_sign.traffic_id_sign[i];
					sign_display.distance_to_ps_2 = current_distance;
					ps_2 = true;
					goto next_other_sign;
				}
				else if (current_distance < sign_display.distance_to_ps_2)
				{
					if (sign_data.other_sign.number_of_sign > 2)
					{
						sign_display.position_3 = sign_display.position_2;
						sign_display.distance_to_ps_3 = sign_display.distance_to_ps_2;

						sign_display.position_2 = sign_data.other_sign.traffic_id_sign[i];
						sign_display.distance_to_ps_2 = current_distance;
						ps_3 = true;
						goto next_other_sign;
					}
				}

				if (!ps_3)
				{
					sign_display.position_3 = sign_data.other_sign.traffic_id_sign[i];
					sign_display.distance_to_ps_3 = current_distance;
					ps_3 = true;
				}
				else if (current_distance < sign_display.distance_to_ps_3)
				{
					if (sign_data.other_sign.number_of_sign > 2)
					{
						sign_display.position_3 = sign_data.other_sign.traffic_id_sign[i];
						sign_display.distance_to_ps_3 = current_distance;
					}
				}

			next_other_sign:
				ESP_LOGI(TAG, "Go to next other sign");
			}
		}
	}
	else
	{
		sign_display.position_2 = sign_data.next_speed.next_speed;
		sign_display.distance_to_ps_2 = sign_data.next_speed.distance[0] << 8 | sign_data.next_speed.distance[1];
		bool sign_3 = false;
		// ESP_LOGI(TAG, "%d", )
		if (sign_data.traffic_sign.number_of_sign > 0)
		{
			for (int i = 0; i < sign_data.traffic_sign.number_of_sign; i++)
			{
				ESP_LOGW(TAG, "test");
				if (sign_data.traffic_sign.traffic_id_sign[i] == ID_TS_ENTER_URBAN_AREA ||
					sign_data.traffic_sign.traffic_id_sign[i] == ID_TS_EXIT_URBAN_AREA)
				{
					sign_display.position_3 = sign_data.traffic_sign.traffic_id_sign[i];
					sign_display.distance_to_ps_3 = sign_data.traffic_sign.distance[i][0] << 8 | sign_data.traffic_sign.distance[i][1];
					sign_3 = true;
				}
			}
		}
		ESP_LOGW(TAG, "Number of cam : %d", sign_data.camera_sign.number_of_sign);
		if (sign_data.camera_sign.number_of_sign > 0)
		{
			for (int i = 0; i < sign_data.camera_sign.number_of_sign; i++)
			{
				ESP_LOGI(TAG, "Check here, %d", sign_3);
				if (sign_3 == false)
				{
					ESP_LOGI(TAG, "Check here now");
					ESP_LOGI(TAG, "%d", sign_data.camera_sign.traffic_id_sign[i]);
					sign_display.position_3 = sign_data.camera_sign.traffic_id_sign[i];
					sign_display.distance_to_ps_3 = sign_data.camera_sign.distance[i][0] << 8 | sign_data.camera_sign.distance[i][1];
					sign_3 = true;
				}
			}
		}

		if (sign_data.traffic_sign.number_of_sign > 0 && sign_3 == false)
		{
			for (int i = 0; i < sign_data.traffic_sign.number_of_sign; i++)
			{
				if (sign_data.traffic_sign.traffic_id_sign[i] != ID_TS_ENTER_URBAN_AREA &&
					sign_data.traffic_sign.traffic_id_sign[i] != ID_TS_EXIT_URBAN_AREA)
				{
					if (sign_3 == false)
					{
						sign_display.position_3 = sign_data.traffic_sign.traffic_id_sign[i];
						sign_display.distance_to_ps_3 = sign_data.traffic_sign.distance[i][0] << 8 | sign_data.traffic_sign.distance[i][1];
						sign_3 = true;
					}
				}
			}
		}

		if (sign_data.other_sign.number_of_sign > 0 && sign_3 == false)
		{
			for (int i = 0; i < sign_data.other_sign.number_of_sign; i++)
			{

				if (sign_3 == false)
				{
					sign_display.position_3 = sign_data.other_sign.traffic_id_sign[i];
					sign_display.distance_to_ps_3 = sign_data.other_sign.distance[i][0] << 8 | sign_data.other_sign.distance[i][1];
					sign_3 = true;
				}
			}
		}
	}
	return sign_display;
}