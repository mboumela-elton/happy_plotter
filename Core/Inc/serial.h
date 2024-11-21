/*
 * serial.h
 *
 *  Created on: Jun 15, 2022
 *      Author: laurmonc
 */

#ifndef INC_SERIAL_H_
#define INC_SERIAL_H_

void SERIAL_Init(UART_HandleTypeDef *phuartInit);
void SERIAL_SendCharBuf(char *buf);
void SERIAL_SendInt(int n);
void SERIAL_SendFloat(float v);
void SERIAL_SendNL(void);
void SERIAL_SendTAB(void);
void SERIAL_SendToPlot(int * dataA,int *dataB,int nb);

#endif /* INC_SERIAL_H_ */
