
#include "platform.h"
#include "platform_specific.h"
#include "stdlib.h"
#include "string.h"
#include <stdlib.h>
#include <VL53L1X_api.h>
#include <VL53L1X_calibration.h>

char Uart_RXBuffer[80];		/* Buffer for continuous RX */
char UartComm_RXBuffer[80];	/* Buffer for decrypted command from RX	*/
size_t Uart_RxIndex;			/* Index of continuous RX buffer */
int UartComm_RXIndex;			/* Index of decrypted RX buffer */
int UART_Active;				/* Flag to see if UART is active */
int UART_Ready;					/* Flag to see if a new command is available */

void I2C_Init(void)
{
	    GPIO_InitTypeDef GPIO_InitStruct;

	    _I2cFailRecover();

	    /* Peripheral clock enable */
	    __GPIOB_CLK_ENABLE();
	    __I2C1_CLK_ENABLE();

	    /**I2C1 GPIO Configuration\n
	     PB8     ------> I2C1_SCL\n
	     PB9     ------> I2C1_SDA
	     */
	    GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
	    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	    I2C_HANDL.Instance = I2C1;
	    I2C_HANDL.Init.ClockSpeed = 400000;
	    I2C_HANDL.Init.DutyCycle = I2C_DUTYCYCLE_2;
	    I2C_HANDL.Init.OwnAddress1 = 0;
	    I2C_HANDL.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	    I2C_HANDL.Init.DualAddressMode = I2C_DUALADDRESS_DISABLED;
	    I2C_HANDL.Init.OwnAddress2 = 0;
	    I2C_HANDL.Init.GeneralCallMode = I2C_GENERALCALL_DISABLED;
	    I2C_HANDL.Init.NoStretchMode = I2C_NOSTRETCH_DISABLED;
	    HAL_I2C_Init(&I2C_HANDL);

}

void _I2cFailRecover(void){
    GPIO_InitTypeDef GPIO_InitStruct;
    int i, nRetry=0;


    // We can't assume bus state based on SDA and SCL state (we may be in a data or NAK bit so SCL=SDA=1)
    // by setting SDA high and toggling SCL at least 10 time we ensure whatever agent and state
    // all agent should end up seeing a "stop" and bus get back to an known idle i2c  bus state

    // Enable I/O
    __GPIOB_CLK_ENABLE();
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9 ;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
    //TODO we could do this faster by not using HAL delay 1ms for clk timing
    do{
        for( i=0; i<10; i++){
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_RESET);
            HAL_Delay(1);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, GPIO_PIN_SET);
            HAL_Delay(1);
        }
    }while(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == 0 && nRetry++<7);

    if( HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == 0 ){
        __GPIOA_CLK_ENABLE();
        //We are still in bad i2c state warm user by blinking led but stay here
        GPIO_InitStruct.Pin = GPIO_PIN_5 ;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
        do{
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_Delay(33);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_Delay(33);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_Delay(33);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_Delay(33*20);
        }while(1);
    }
}


void UART_Init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__DMA1_CLK_ENABLE();

	/*
	HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);
	SERIAL_UART.Instance = USART2;
	SERIAL_UART.Init.BaudRate = 460800;
	SERIAL_UART.Init.WordLength = UART_WORDLENGTH_8B;
	SERIAL_UART.Init.StopBits = UART_STOPBITS_1;
	SERIAL_UART.Init.Parity = UART_PARITY_NONE;
	SERIAL_UART.Init.Mode = UART_MODE_TX_RX;
	SERIAL_UART.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	SERIAL_UART.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&SERIAL_UART);
	HAL_UART_IRQHandler(&SERIAL_UART);
	*/
	HAL_NVIC_SetPriority(USART2_IRQn, 0, 1);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	SERIAL_UART.Instance = USART2;
	SERIAL_UART.Init.BaudRate = 460800;
	SERIAL_UART.Init.WordLength = UART_WORDLENGTH_8B;
	SERIAL_UART.Init.StopBits = UART_STOPBITS_1;
	SERIAL_UART.Init.Parity = UART_PARITY_NONE;
	SERIAL_UART.Init.Mode = UART_MODE_TX_RX;
	SERIAL_UART.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	SERIAL_UART.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&SERIAL_UART);

	SERIAL_UART.Instance->CR1 = 0x202C;
}

void UART_Reboot(size_t *Uart_RxIndex, int *UartActive, int *UART_Ready,
		 char *Uart_RXBuffer)
{				/* Reboot all default values for UART communication */
	*Uart_RxIndex = 0;
	*UartActive = 1;
	*UART_Ready = 0;
	HAL_UART_Receive_IT(&SERIAL_UART, (uint8_t *) Uart_RXBuffer, 1);
}

void UART_Print(const char *msg)
{
	HAL_UART_Transmit(&SERIAL_UART, (uint8_t *) msg, strlen(msg), 100);
}

void UART_CheckError(uint16_t status)
{				/* Check is value sent is correct */
	if (status == 0)
		UART_Print(MSG_OK);
	else
		UART_Print(MSG_WRONG_VALUE);
}


__weak void USART2_IRQHandler(void)
{
	HAL_UART_IRQHandler(&SERIAL_UART);	/* Handles USART global interrupt */
}

/* DMA to get RX data */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	__USART2_CLK_ENABLE();
	GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3;/* PIN2 --> USART2_TX */
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;	/* PIN3 --> USART2_RX */
	GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	DMA_HANDLE.Instance = DMA1_Stream6;
	DMA_HANDLE.Init.Channel = DMA_CHANNEL_4;
	DMA_HANDLE.Init.Direction = DMA_MEMORY_TO_PERIPH;
	DMA_HANDLE.Init.PeriphInc = DMA_PINC_DISABLE;
	DMA_HANDLE.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	DMA_HANDLE.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	HAL_DMA_Init(&DMA_HANDLE);
	__HAL_LINKDMA(huart, hdmatx, DMA_HANDLE);
	HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{				/* RX Callback to get command from UART */
	int ContinueRX = 1;

	if (!UART_Active)
		return; /* If UART is not active, exit the function */
	if (Uart_RXBuffer[Uart_RxIndex] == '\r' ||
			Uart_RXBuffer[Uart_RxIndex] == '\n') {
		Uart_RXBuffer[Uart_RxIndex] = 0;
		ContinueRX = 0;
		memcpy(UartComm_RXBuffer, (char *)Uart_RXBuffer, Uart_RxIndex + 1);
		UartComm_RXIndex = Uart_RxIndex;
		UART_Ready = 1;	/* Flag to new command available */
	} else if (Uart_RXBuffer[Uart_RxIndex] == '\3') {
		Uart_RXBuffer[Uart_RxIndex] = 0;
		ContinueRX = 0;
		UartComm_RXBuffer[0] = '\3';
		UartComm_RXBuffer[1] = '0';
		UartComm_RXIndex = 1;
		UART_Ready = 1;	/* Flag to new command available */

	} else {
		if (Uart_RxIndex >= sizeof(Uart_RXBuffer) - 1)
			Uart_RxIndex = 0;
		else
			Uart_RxIndex++;
	}
	if (ContinueRX)		/* Getting data in continuous         */
		HAL_UART_Receive_IT(huart,
				    (uint8_t *) &Uart_RXBuffer[Uart_RxIndex],
				    1);
}

void Peek(uint16_t dev, uint16_t Register)
{
	char buffer[40];

	uint8_t peek8 = ReadRegister8(dev, Register);
	snprintf(buffer, sizeof (buffer), "register 0x%x =0x%x\n", Register,
		 peek8);
	UART_Print(buffer);
}

void Peek16(uint16_t dev, uint16_t Register)
{
	char buffer[40];

	uint16_t peek16 = ReadRegister16(dev, Register);
	snprintf(buffer, sizeof (buffer), "register 0x%x =0x%x\n", Register,
		 peek16);
	UART_Print(buffer);

}

static union CurIOVal_u {
	uint8_t bytes[4];	/*!<  4 bytes array i/o view */
	uint32_t u32;		/*!<  single dword i/o view */
} CurIOVal;

void GPIO_Expander_Init(void)
{
	uint8_t ExpanderData[2];

	_ExpanderRd(I2cExpAddr0, 0, ExpanderData, 2);
	_ExpanderRd(I2cExpAddr1, 0, ExpanderData, 2);

	CurIOVal.u32 = 0x0;
	/* setup expender   i/o direction  all output but exp1 bit 14 */
	ExpanderData[0] = 0xFF;
	ExpanderData[1] = 0xFF;
	_ExpanderWR(I2cExpAddr0, GPDR, ExpanderData, 2);
	ExpanderData[0] = 0xFF;
	ExpanderData[1] = 0xBF;	// all but bit 14-15 that is pb1 and xhurt
	 _ExpanderWR(I2cExpAddr1, GPDR, ExpanderData, 2);
	/* shut down all segment and all device */
	CurIOVal.u32 = 0x7F + (0x7F << 7) + (0x7F << 16) + (0x7F << (16 + 7));
	_ExpandersSetAllIO();
}

/*
 * Set all i2c expended gpio in one go
 * @return i/o operation status
 */
int _ExpandersSetAllIO(void)
{
	int status;

	status = _ExpanderWR(I2cExpAddr0, GPSR, &CurIOVal.bytes[0], 2);
	if (status)
		goto done_err;
	status = _ExpanderWR(I2cExpAddr1, GPSR, &CurIOVal.bytes[2], 2);
done_err:
	return status;
}

/**
* STMPE1600  i2c Expender register read
* @param I2cExpAddr Expender address
* @param index      register index
* @param data       read data buffer
* @param n_data     number of byte to read
* @return           of if ok else i2c I/O operation status
*/
int _ExpanderRd(int I2cExpAddr, int index, uint8_t * data, int n_data)
{
	int status;
	uint8_t RegAddr;
	RegAddr = index;
	do {
		status =
		    HAL_I2C_Master_Transmit(&I2C_HANDL, I2cExpAddr, &RegAddr,
					    1, 100);
		if (status)
			break;
		status =
		    HAL_I2C_Master_Receive(&I2C_HANDL, I2cExpAddr, data,
					   n_data, n_data * 100);
	} while (0);
	return status;
}

/*
 * STMPE1600 i2c Expender register write
 * @param I2cExpAddr Expender address
 * @param index      register index
 * @param data       data buffer
 * @param n_data     number of byte to write
 * @return           of if ok else i2c I/O operation status
 */
int _ExpanderWR(int I2cExpAddr, int index, uint8_t *data, int n_data)
{
	int status;
	uint8_t RegAddr[0x10];

	RegAddr[0] = index;
	memcpy(RegAddr + 1, data, n_data);
	status =
	    HAL_I2C_Master_Transmit(&I2C_HANDL, I2cExpAddr, RegAddr,
				    n_data + 1, 100);
	return status;
}

uint8_t Sensor_Reset(uint8_t DevNo, uint8_t state)
{
	uint8_t status;

	switch (DevNo) {
	case XNUCLEO53L1_DEV_CENTER:
	case 'c':
		CurIOVal.bytes[3] &= ~0x80;	/* bit 15 expender 1  => byte #3 */
		if (state)
			CurIOVal.bytes[3] |= 0x80;	/* bit 15 expender 1  => byte #3 */
		status =
		    _ExpanderWR(I2cExpAddr1, GPSR + 1, &CurIOVal.bytes[3], 1);
		break;
	case XNUCLEO53L1_DEV_LEFT:
	case 'l':
		CurIOVal.bytes[1] &= ~0x40;	/* bit 14 expender 0 => byte #1 */
		if (state)
			CurIOVal.bytes[1] |= 0x40;	/* bit 14 expender 0 => byte #1 */
		status =
		    _ExpanderWR(I2cExpAddr0, GPSR + 1, &CurIOVal.bytes[1], 1);
		break;
	case 'r':
	case XNUCLEO53L1_DEV_RIGHT:
		CurIOVal.bytes[1] &= ~0x80;	/* bit 15 expender 0  => byte #1 */
		if (state)
			CurIOVal.bytes[1] |= 0x80;	/* bit 15 expender 0 => byte #1 */
		status =
		    _ExpanderWR(I2cExpAddr0, GPSR + 1, &CurIOVal.bytes[1], 1);
		break;
	default:
		//XNUCLEO53L1_ErrLog("Invalid DevNo %d",DevNo);
		status = -1;
		break;
	}

	return status;
}
