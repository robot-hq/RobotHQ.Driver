/*********************************************************************
*                SEGGER MICROCONTROLLER GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
**********************************************************************
*                                                                    *
*        (c) 2003-2012     SEGGER Microcontroller GmbH & Co KG       *
*                                                                    *
*        Internet: www.segger.com    Support:  support@segger.com    *
*                                                                    *
**********************************************************************

----------------------------------------------------------------------
File        : GUIDRV_IST3088.h
Purpose     : Interface definition for GUIDRV_IST3088 driver
---------------------------END-OF-HEADER------------------------------
*/

#ifndef GUIDRV_IST3088_H
#define GUIDRV_IST3088_H

/*********************************************************************
*
*       Display drivers
*/
//
// Addresses
//
extern const GUI_DEVICE_API GUIDRV_IST3088_4_API;
extern const GUI_DEVICE_API GUIDRV_IST3088_OY_4_API;
extern const GUI_DEVICE_API GUIDRV_IST3088_OX_4_API;
extern const GUI_DEVICE_API GUIDRV_IST3088_OXY_4_API;
extern const GUI_DEVICE_API GUIDRV_IST3088_OS_4_API;
extern const GUI_DEVICE_API GUIDRV_IST3088_OSY_4_API;
extern const GUI_DEVICE_API GUIDRV_IST3088_OSX_4_API;
extern const GUI_DEVICE_API GUIDRV_IST3088_OSXY_4_API;

//
// Macros to be used in configuration files
//
#if defined(WIN32) && !defined(LCD_SIMCONTROLLER)

  #define GUIDRV_IST3088_4       &GUIDRV_Win_API
  #define GUIDRV_IST3088_OY_4    &GUIDRV_Win_API
  #define GUIDRV_IST3088_OX_4    &GUIDRV_Win_API
  #define GUIDRV_IST3088_OXY_4   &GUIDRV_Win_API
  #define GUIDRV_IST3088_OS_4    &GUIDRV_Win_API
  #define GUIDRV_IST3088_OSY_4   &GUIDRV_Win_API
  #define GUIDRV_IST3088_OSX_4   &GUIDRV_Win_API
  #define GUIDRV_IST3088_OSXY_4  &GUIDRV_Win_API

#else

  #define GUIDRV_IST3088_4       &GUIDRV_IST3088_4_API
  #define GUIDRV_IST3088_OY_4    &GUIDRV_IST3088_OY_4_API
  #define GUIDRV_IST3088_OX_4    &GUIDRV_IST3088_OX_4_API
  #define GUIDRV_IST3088_OXY_4   &GUIDRV_IST3088_OXY_4_API
  #define GUIDRV_IST3088_OS_4    &GUIDRV_IST3088_OS_4_API
  #define GUIDRV_IST3088_OSY_4   &GUIDRV_IST3088_OSY_4_API
  #define GUIDRV_IST3088_OSX_4   &GUIDRV_IST3088_OSX_4_API
  #define GUIDRV_IST3088_OSXY_4  &GUIDRV_IST3088_OSXY_4_API

#endif

/*********************************************************************
*
*       Public routines
*/
void GUIDRV_IST3088_SetBus16(GUI_DEVICE * pDevice, GUI_PORT_API * pHW_API);

#endif

/*************************** End of file ****************************/
