// MESSAGE SLUGS_CAMERA_ORDER PACKING

#define MAVLINK_MSG_ID_SLUGS_CAMERA_ORDER 184

typedef struct __mavlink_slugs_camera_order_t 
{
	uint8_t target; ///< The system reporting the action
	uint8_t pan; ///< Order the mount to pan: -1 left, 0 No pan motion, +1 right
	uint8_t tilt; ///< Order the mount to tilt: -1 down, 0 No tilt motion, +1 up
	uint8_t zoom; ///< Order the camera to zoom: -1 zoom out, 0 No zoom change, +1 zoom in
	uint8_t moveHome; ///< Orders the camera mount to move home. The other fields are ignored when this field is set. 1: move home, 0 ignored

} mavlink_slugs_camera_order_t;



/**
 * @brief Pack a slugs_camera_order message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target The system reporting the action
 * @param pan Order the mount to pan: -1 left, 0 No pan motion, +1 right
 * @param tilt Order the mount to tilt: -1 down, 0 No tilt motion, +1 up
 * @param zoom Order the camera to zoom: -1 zoom out, 0 No zoom change, +1 zoom in
 * @param moveHome Orders the camera mount to move home. The other fields are ignored when this field is set. 1: move home, 0 ignored
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_slugs_camera_order_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint8_t target, uint8_t pan, uint8_t tilt, uint8_t zoom, uint8_t moveHome)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_SLUGS_CAMERA_ORDER;

	i += put_uint8_t_by_index(target, i, msg->payload); // The system reporting the action
	i += put_uint8_t_by_index(pan, i, msg->payload); // Order the mount to pan: -1 left, 0 No pan motion, +1 right
	i += put_uint8_t_by_index(tilt, i, msg->payload); // Order the mount to tilt: -1 down, 0 No tilt motion, +1 up
	i += put_uint8_t_by_index(zoom, i, msg->payload); // Order the camera to zoom: -1 zoom out, 0 No zoom change, +1 zoom in
	i += put_uint8_t_by_index(moveHome, i, msg->payload); // Orders the camera mount to move home. The other fields are ignored when this field is set. 1: move home, 0 ignored

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

/**
 * @brief Pack a slugs_camera_order message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param target The system reporting the action
 * @param pan Order the mount to pan: -1 left, 0 No pan motion, +1 right
 * @param tilt Order the mount to tilt: -1 down, 0 No tilt motion, +1 up
 * @param zoom Order the camera to zoom: -1 zoom out, 0 No zoom change, +1 zoom in
 * @param moveHome Orders the camera mount to move home. The other fields are ignored when this field is set. 1: move home, 0 ignored
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_slugs_camera_order_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, uint8_t target, uint8_t pan, uint8_t tilt, uint8_t zoom, uint8_t moveHome)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_SLUGS_CAMERA_ORDER;

	i += put_uint8_t_by_index(target, i, msg->payload); // The system reporting the action
	i += put_uint8_t_by_index(pan, i, msg->payload); // Order the mount to pan: -1 left, 0 No pan motion, +1 right
	i += put_uint8_t_by_index(tilt, i, msg->payload); // Order the mount to tilt: -1 down, 0 No tilt motion, +1 up
	i += put_uint8_t_by_index(zoom, i, msg->payload); // Order the camera to zoom: -1 zoom out, 0 No zoom change, +1 zoom in
	i += put_uint8_t_by_index(moveHome, i, msg->payload); // Orders the camera mount to move home. The other fields are ignored when this field is set. 1: move home, 0 ignored

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, i);
}

/**
 * @brief Encode a slugs_camera_order struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param slugs_camera_order C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_slugs_camera_order_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_slugs_camera_order_t* slugs_camera_order)
{
	return mavlink_msg_slugs_camera_order_pack(system_id, component_id, msg, slugs_camera_order->target, slugs_camera_order->pan, slugs_camera_order->tilt, slugs_camera_order->zoom, slugs_camera_order->moveHome);
}

/**
 * @brief Send a slugs_camera_order message
 * @param chan MAVLink channel to send the message
 *
 * @param target The system reporting the action
 * @param pan Order the mount to pan: -1 left, 0 No pan motion, +1 right
 * @param tilt Order the mount to tilt: -1 down, 0 No tilt motion, +1 up
 * @param zoom Order the camera to zoom: -1 zoom out, 0 No zoom change, +1 zoom in
 * @param moveHome Orders the camera mount to move home. The other fields are ignored when this field is set. 1: move home, 0 ignored
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_slugs_camera_order_send(mavlink_channel_t chan, uint8_t target, uint8_t pan, uint8_t tilt, uint8_t zoom, uint8_t moveHome)
{
	mavlink_message_t msg;
	mavlink_msg_slugs_camera_order_pack_chan(mavlink_system.sysid, mavlink_system.compid, chan, &msg, target, pan, tilt, zoom, moveHome);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE SLUGS_CAMERA_ORDER UNPACKING

/**
 * @brief Get field target from slugs_camera_order message
 *
 * @return The system reporting the action
 */
static inline uint8_t mavlink_msg_slugs_camera_order_get_target(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload)[0];
}

/**
 * @brief Get field pan from slugs_camera_order message
 *
 * @return Order the mount to pan: -1 left, 0 No pan motion, +1 right
 */
static inline uint8_t mavlink_msg_slugs_camera_order_get_pan(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t))[0];
}

/**
 * @brief Get field tilt from slugs_camera_order message
 *
 * @return Order the mount to tilt: -1 down, 0 No tilt motion, +1 up
 */
static inline uint8_t mavlink_msg_slugs_camera_order_get_tilt(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t)+sizeof(uint8_t))[0];
}

/**
 * @brief Get field zoom from slugs_camera_order message
 *
 * @return Order the camera to zoom: -1 zoom out, 0 No zoom change, +1 zoom in
 */
static inline uint8_t mavlink_msg_slugs_camera_order_get_zoom(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t))[0];
}

/**
 * @brief Get field moveHome from slugs_camera_order message
 *
 * @return Orders the camera mount to move home. The other fields are ignored when this field is set. 1: move home, 0 ignored
 */
static inline uint8_t mavlink_msg_slugs_camera_order_get_moveHome(const mavlink_message_t* msg)
{
	return (uint8_t)(msg->payload+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t)+sizeof(uint8_t))[0];
}

/**
 * @brief Decode a slugs_camera_order message into a struct
 *
 * @param msg The message to decode
 * @param slugs_camera_order C-struct to decode the message contents into
 */
static inline void mavlink_msg_slugs_camera_order_decode(const mavlink_message_t* msg, mavlink_slugs_camera_order_t* slugs_camera_order)
{
	slugs_camera_order->target = mavlink_msg_slugs_camera_order_get_target(msg);
	slugs_camera_order->pan = mavlink_msg_slugs_camera_order_get_pan(msg);
	slugs_camera_order->tilt = mavlink_msg_slugs_camera_order_get_tilt(msg);
	slugs_camera_order->zoom = mavlink_msg_slugs_camera_order_get_zoom(msg);
	slugs_camera_order->moveHome = mavlink_msg_slugs_camera_order_get_moveHome(msg);
}
