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
File        : GUIDRV_DCache.h
Purpose     : Interface definition for GUIDRV_DCache driver
---------------------------END-OF-HEADER------------------------------
*/

#ifndef GUIDRV_DCACHE_H
#define GUIDRV_DCACHE_H

/*********************************************************************
*
*       Display driver
*/
//
// Address
//
extern const GUI_DEVICE_API GUIDRV_DCache_API;

//
// Macros to be used in configuration files
//
#if defined(WIN32) && !defined(LCD_SIMCONTROLLER)

  #define GUIDRV_DCACHE &GUIDRV_Win_API

#else

  #define GUIDRV_DCACHE &GUIDRV_DCache_API

#endif

/*********************************************************************
*
*       Public routines
*/
#if defined(WIN32) && !defined(LCD_SIMCONTROLLER)

  #define GUIDRV_DCache_AddDriver(pDevice, pDriver)
  #define GUIDRV_DCache_SetMode1bpp(pDevice)

#else

  void GUIDRV_DCache_AddDriver  (GUI_DEVICE * pDevice, GUI_DEVICE * pDriver);
  void GUIDRV_DCache_SetMode1bpp(GUI_DEVICE * pDevice);

#endif

#endif /* GUIDRV_DCACHE_H */

/*************************** End of file ****************************/
