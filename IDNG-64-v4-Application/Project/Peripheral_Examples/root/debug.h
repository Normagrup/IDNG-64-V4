	#define DEBUG_DALI_SEND
	#define DEBUG_NORMALINK_SEND	
	#define DEBUG_TEMP_SEND
	#define DEBUG_WEBSERVER_SEND
	#define DEBUG_UTILS_SEND	
	#define DEBUG_SENSORS_INTERFACE_RECEIVED
	#define	DEBUG_ACTIONS_SEND
	
	#define DEBUG_DALI_SEND_PORT 																			5555
	#define DEBUG_NORMALINK_SEND_PORT																	5555
	#define DEBUG_TEMP_SEND_PORT																			5555
	#define DEBUG_WEBSERVER_SEND_PORT																	5555
	#define DEBUG_UTILS_SEND_PORT																			5555
	#define	DEBUG_ACTIONS_SEND_PORT																		5555
	#define DEBUG_SENSORS_INTERFACE_RECEIVED_PORT											5555
	
	#define	DEBUG_FRAME_TYPE																					0x86	
	
	#define DEBUG_DALI_SEND_OP																				0x00
	#define DEBUG_NORMALINK_SEND_OP																		0x01
	#define DEBUG_SENSORS_INTERFACE_RECEIVED_OP												0x02
	#define DEBUG_ACTIONS_SEND_OP																			0x03	
	#define DEBUG_TEMP_SEND_OP																				0x04
	#define DEBUG_WEBSERVER_SEND_OP																		0x05
	#define DEBUG_UTILS_SEND_OP																				0x06
	
	#define DEBUG_NORMALINK_SEND_FRAME_LENGHT													14
	#define DEBUG_SENSORS_INTERFACE_RECEIVED_FRAME_LENGHT							19
	#define DEBUG_ACTIONS_SEND_FRAME_LENGHT														7	
	#define DEBUG_TEMP_SEND_FRAME_LENGHT															6
	#define DEBUG_WEBSERVER_SEND_FRAME_LENGHT													5
	#define DEBUG_UTILS_SEND_FRAME_LENGHT															5
	#define DEBUG_DALI_SEND_FRAME_LENGHT															11
			
	#define DEBUG_DALI_SEND_HIDE_POLLINGS
	#define DEBUG_DALI_SEND_HIDE_SENSOR_QUERIES				
	
	#define DEBUG_ACTIONS_SEND_SUB_OP_DETECTORES_PRESENCIA						0x00	
	#define DEBUG_ACTIONS_SEND_SUB_OP_PULSADORES_ACCION_BASCULANTE		0x01
	#define DEBUG_ACTIONS_SEND_SUB_OP_PULSADORES_ACCION_FIJA					0x02
	#define DEBUG_ACTIONS_SEND_SUB_OP_PULSADORES_ACCION_REGULACION		0x03
	#define DEBUG_ACTIONS_SEND_SUB_OP_PULSADORES_ACCION_TEMPORIZADA		0x04
	#define DEBUG_ACTIONS_SEND_SUB_OP_REGULADORES_LUZ									0x05
		
	#define DEBUG_TEMP_SEND_SUB_OP_START															0x01
	#define DEBUG_TEMP_SEND_SUB_OP_STOP																0x00
	#define DEBUG_WEBSERVER_SEND_SUB_OP_MAX														0x01
	#define DEBUG_WEBSERVER_SEND_SUB_OP_OFF														0x00
	#define DEBUG_UTILS_SEND_SUB_OP_MAX																0x01
	#define DEBUG_UTILS_SEND_SUB_OP_OFF																0x00		