/*
 * serial.c
 *
 *  Created on: Jun 15, 2022
 *      Author: laurmonc
 */
// version 2 : 24/05/2024 for STM32L476 LAB
// it can work with any project built with STM32CubeIDE
// if you initialize one UART!
#include <string.h>
#include <stdio.h>
#include "main.h"


UART_HandleTypeDef *phuart= (UART_HandleTypeDef *) 0;

char gbuf[100];

// use it once for initialization
// send the handler of the UART you want to use
void SERIAL_Init(UART_HandleTypeDef *phuartInit){
	phuart=phuartInit;
}

void SERIAL_SendCharBuf(char *buf){
	int taille=0;
	taille=strlen(buf);
	if(taille>0)
		HAL_UART_Transmit(phuart, (unsigned char *)buf, taille, 1);
}

void SERIAL_SendInt(int n){
	int taille=0;
	taille=sprintf (gbuf,"%d",n);
	if(taille>0)
		HAL_UART_Transmit(phuart, (unsigned char *)gbuf, taille, 1);
}

void SERIAL_SendFloat(float v){
	int taille=0;
	// to use this function, go in the following menu:
	//"Project Properties > C/C++ Build > Settings > Tool Settings > MCU Settings > Use Float"
	taille=sprintf (gbuf, "%5.3f",v);
	if(taille>0)
		HAL_UART_Transmit(phuart, (unsigned char *)gbuf, taille, 1);
}

void SERIAL_SendNL(){
	gbuf[0]=13;
	gbuf[1]=10;
	HAL_UART_Transmit(phuart, (unsigned char *)gbuf, 2, 1);

}

void SERIAL_SendTAB(){
	gbuf[0]=9;

	HAL_UART_Transmit(phuart, (unsigned char *)gbuf, 1, 1);
}

void SERIAL_SendToPlot(int * dataA,int *dataB,int nb){
	int n=0;
	for(n=0;n<nb;n++){
		SERIAL_SendCharBuf("a:");
		SERIAL_SendInt(dataA[n]);
		SERIAL_SendCharBuf(",");
		SERIAL_SendCharBuf("b:");
		SERIAL_SendInt(dataB[n]);
		SERIAL_SendNL();
	}
}

