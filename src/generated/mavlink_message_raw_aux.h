// MESSAGE RAW_AUX PACKING

#define MAVLINK_MSG_ID_RAW_AUX 102

typedef struct __raw_aux_t 
{
	uint32_t adc1; ///< ADC1 (J405 ADC3, LPC2148 AD0.6)
	uint32_t adc2; ///< ADC2 (J405 ADC5, LPC2148 AD0.2)
	uint32_t adc3; ///< ADC3 (J405 ADC6, LPC2148 AD0.1)
	uint32_t adc4; ///< ADC4 (J405 ADC7, LPC2148 AD1.3)
	uint32_t vbat; ///< Battery voltage
	int32_t temp; ///< Temperature (degrees celcius)
	int32_t baro; ///< Barometric pressure (hecto Pascal)

} raw_aux_t;

/**
 * @brief Send a raw_aux message
 *
 * @param adc1 ADC1 (J405 ADC3, LPC2148 AD0.6)
 * @param adc2 ADC2 (J405 ADC5, LPC2148 AD0.2)
 * @param adc3 ADC3 (J405 ADC6, LPC2148 AD0.1)
 * @param adc4 ADC4 (J405 ADC7, LPC2148 AD1.3)
 * @param vbat Battery voltage
 * @param temp Temperature (degrees celcius)
 * @param baro Barometric pressure (hecto Pascal)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t message_raw_aux_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint32_t adc1, uint32_t adc2, uint32_t adc3, uint32_t adc4, uint32_t vbat, int32_t temp, int32_t baro)
{
	msg->msgid = MAVLINK_MSG_ID_RAW_AUX;
	uint16_t i = 0;

	i += put_uint32_t_by_index(adc1, i, msg->payload); //ADC1 (J405 ADC3, LPC2148 AD0.6)
	i += put_uint32_t_by_index(adc2, i, msg->payload); //ADC2 (J405 ADC5, LPC2148 AD0.2)
	i += put_uint32_t_by_index(adc3, i, msg->payload); //ADC3 (J405 ADC6, LPC2148 AD0.1)
	i += put_uint32_t_by_index(adc4, i, msg->payload); //ADC4 (J405 ADC7, LPC2148 AD1.3)
	i += put_uint32_t_by_index(vbat, i, msg->payload); //Battery voltage
	i += put_int32_t_by_index(temp, i, msg->payload); //Temperature (degrees celcius)
	i += put_int32_t_by_index(baro, i, msg->payload); //Barometric pressure (hecto Pascal)

	return finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t message_raw_aux_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const raw_aux_t* raw_aux)
{
	return message_raw_aux_pack(system_id, component_id, msg, raw_aux->adc1, raw_aux->adc2, raw_aux->adc3, raw_aux->adc4, raw_aux->vbat, raw_aux->temp, raw_aux->baro);
}

#if !defined(_WIN32) && !defined(__linux) && !defined(__APPLE__)

#include "global_data.h"

static inline void message_raw_aux_send(mavlink_channel_t chan, uint32_t adc1, uint32_t adc2, uint32_t adc3, uint32_t adc4, uint32_t vbat, int32_t temp, int32_t baro)
{
	mavlink_message_t msg;
	message_raw_aux_pack(global_data.param[PARAM_SYSTEM_ID], global_data.param[PARAM_COMPONENT_ID], &msg, adc1, adc2, adc3, adc4, vbat, temp, baro);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE RAW_AUX UNPACKING

/**
 * @brief Get field adc1 from raw_aux message
 *
 * @return ADC1 (J405 ADC3, LPC2148 AD0.6)
 */
static inline uint32_t message_raw_aux_get_adc1(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload)[0];
	r.b[2] = (msg->payload)[1];
	r.b[1] = (msg->payload)[2];
	r.b[0] = (msg->payload)[3];
	return (uint32_t)r.i;
}

/**
 * @brief Get field adc2 from raw_aux message
 *
 * @return ADC2 (J405 ADC5, LPC2148 AD0.2)
 */
static inline uint32_t message_raw_aux_get_adc2(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint32_t))[3];
	return (uint32_t)r.i;
}

/**
 * @brief Get field adc3 from raw_aux message
 *
 * @return ADC3 (J405 ADC6, LPC2148 AD0.1)
 */
static inline uint32_t message_raw_aux_get_adc3(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t))[3];
	return (uint32_t)r.i;
}

/**
 * @brief Get field adc4 from raw_aux message
 *
 * @return ADC4 (J405 ADC7, LPC2148 AD1.3)
 */
static inline uint32_t message_raw_aux_get_adc4(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[3];
	return (uint32_t)r.i;
}

/**
 * @brief Get field vbat from raw_aux message
 *
 * @return Battery voltage
 */
static inline uint32_t message_raw_aux_get_vbat(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[3];
	return (uint32_t)r.i;
}

/**
 * @brief Get field temp from raw_aux message
 *
 * @return Temperature (degrees celcius)
 */
static inline int32_t message_raw_aux_get_temp(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t))[3];
	return (int32_t)r.i;
}

/**
 * @brief Get field baro from raw_aux message
 *
 * @return Barometric pressure (hecto Pascal)
 */
static inline int32_t message_raw_aux_get_baro(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(int32_t))[0];
	r.b[2] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(int32_t))[1];
	r.b[1] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(int32_t))[2];
	r.b[0] = (msg->payload+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(uint32_t)+sizeof(int32_t))[3];
	return (int32_t)r.i;
}

static inline void message_raw_aux_decode(const mavlink_message_t* msg, raw_aux_t* raw_aux)
{
	raw_aux->adc1 = message_raw_aux_get_adc1(msg);
	raw_aux->adc2 = message_raw_aux_get_adc2(msg);
	raw_aux->adc3 = message_raw_aux_get_adc3(msg);
	raw_aux->adc4 = message_raw_aux_get_adc4(msg);
	raw_aux->vbat = message_raw_aux_get_vbat(msg);
	raw_aux->temp = message_raw_aux_get_temp(msg);
	raw_aux->baro = message_raw_aux_get_baro(msg);
}