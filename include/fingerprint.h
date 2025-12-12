#include "../../../Inc/main.h"
#include "defs.h"

extern uint32_t joystick_center_flag;
extern uint32_t joystick_down_flag;
extern bool IsNowRegistrationMode;
extern bool StandbyMode;
extern uint32_t scanner_irq_flag;
extern uint8_t current_template_count;
extern char mesg[32];


int FingerPrint_RecieveMessage(uint16_t rxData[(32 * (FINGERPRINT_FRAME_SIZE + 1))]);
int FingerPrint_RecieveDebugMessages(uint16_t* rxDebugData);
uint8_t FingerPrint_GenImg(void);
uint8_t FingerPrint_PwdVfy(void);
uint8_t FingerPrint_Empty(void);
uint8_t FingerPrint_GenImg(void);
uint8_t FingerPrint_Img2Tz(uint8_t buf);
uint8_t FingerPrint_RegModel(void);
//uint8_t FingerPrint_Store(uint16_t BufferId, uint16_t PageID);
int FingerPrint_Search(uint8_t buf, uint16_t StartPage, uint16_t PageNum);

/**
 * @brief  Getting a metadata about P557 fingerprint scanner.
 * 
 * This function generates a data transmission packet, which is 
 * received and processed on the R557 fingerprint scanner side 
 * (sending is done using the HAL function HAL_UART_Transmit; 
 * the response packet is also received using the HAL function 
 * HAL_UART_Receive)
 * 
 * @param  UART_HandleTypeDef* huart
 * @retval int
 */
uint8_t FingerPrint_ShowSystemData(UART_HandleTypeDef* huart);

uint16_t System_GetControlSum(uint8_t* Data, int StartIndex, int StopIndex);
int System_EchoViaUART(UART_HandleTypeDef* huart, char* Message);

uint8_t GetBusyState(void);
uint8_t FingerPrint_Store(int current_page);
void FingerPrint_InitDelay(void);
void GlobalHandler(void);
