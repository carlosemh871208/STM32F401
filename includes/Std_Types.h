/*********************************************************************************************************************/
/*                                                INCLUDES GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: Std_Types.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2023-03-11 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** \Std_Types.h
    This file contains Standard types for entire project according AUTOSAR.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/*                                                       Includes                                                    */
/*********************************************************************************************************************/

/*                                                Constants and types                                                */
/*********************************************************************************************************************/
/* Generic unsigned types */
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;

/* Generic signed types */
typedef signed char  sint8;
typedef signed short sint16;
typedef signed long  sint32;

/* Microcontroller I/O types */
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */



/* AUTOSAR Standard Types */
/* The Std_ReturnType shall normally be used with value E_OK or E_NOT_OK. If those return values are not sufficient 
   user specific values can be defined by using the 6 least specific bits.
   The Std_ReturnType shall normally be used with value E_OK or E_NOT_OK. If those return values are not sufficient 
   user specific values can be defined by using the 6 least specific bits.
   b7, b6 -> RTE Reserved 
   b5, b4, b3, b2, b1, b0 -> availables for error codes.
*/
/* This type can be used as standard API return type which is shared between the RTE and the BSW modules. It shall 
   be defined as follows: typedef uint8 Std_ReturnType; */
typedef uint8 Std_ReturnType;

#define E_OK     (Std_ReturnType)0u
#define E_NOT_OK (Std_ReturnType)1u
/* 0x02-0x3F - 2 -  Available to user specific errors*/

/* This type shall be used to request the version of a BSW module using the <Module name>_Get VersionInfo() function */
typedef struct
{
    uint16 moduleID;
    uint16 sw_major_version;
    uint8  sw_minor_version;
    uint8  sw_patch_version;
}Std_VersionInfoType;

/* The data type Std_TransformerError is a struct which contains the error code and the transformer class to which 
   the error belongs. 
*/
/* The specific meaning of the values of Std_TransformerErrorCode is to be seen for the specific transformer chain 
   for which the data type represents the transformer error. */
typedef uint8 Std_TransformerErrorCode;
typedef uint8 Std_TransformerClass;

#define STD_TRANSFORMER_UNSPECIFIED (Std_TransformerClass)0x00u
#define STD_TRANSFORMER_SERIALIZER  (Std_TransformerClass)0x01u
#define STD_TRANSFORMER_SAFETY      (Std_TransformerClass)0x02u
#define STD_TRANSFORMER_SECURITY    (Std_TransformerClass)0x03u
#define STD_TRANSFORMER_CUSTOM      (Std_TransformerClass)0xFFu

typedef struct
{
    Std_TransformerErrorCode errorCode;
    Std_TransformerClass     transformerClass;
}Std_TransformerError; /* Std_TransformerError represents a transformer error in the context of a certain transformer chain. */

/* The data type Std_TransformerForward is a struct which contains the forwarded status and the transformer class to which 
   the forwarded status applies. */
/* The Std_TransformerForward represents a forwarded trans- former status in the context of a certain transformer chain. 
   The specific meaning of the values of Std_TransformerForward are always to be seen for the specific transformer chain for 
   which the data type represents the transformer status. */
typedef uint8 Std_TransformerForwardCode;

#define E_SAFETY_INVALID_OK  (Std_TransformerForwardCode)0x00u;
#define E_SAFETY_INVALID_REP (Std_TransformerForwardCode)0x01u;
#define E_SAFETY_INVALID_REP (Std_TransformerForwardCode)0x02u;
#define E_SAFETY_INVALID_REP (Std_TransformerForwardCode)0x03u;

typedef struct
{
    Std_TransformerForwardCode errorCode;
    Std_TransformerClass       transformerClass;
}Std_TransformerForward;

/* This type is used to encode the different type of messages. - Currently this encoding is limited to the distinction between 
   requests and responses in C/S communication. */
typedef uint8 Std_MessageTypeType;

#define STD_MESSAGETYPE_OK    (Std_MessageTypeType)0x00;
#define STD_MESSAGETYPE_ERROR (Std_MessageTypeType)0x01;
/* 0x02 - 0x3F - 2 - reserverd for future message results */

/*  */
typedef uint8 Std_MessageResultType;

#define STD_MESSAGERESULT_OK    (Std_MessageResultType)0x00;
#define STD_MESSAGERESULT_ERROR (Std_MessageResultType)0x01;
/* 0x02 - 0x3F - 2 - reserverd for future message results */

/* Type for the function pointer to extract the relevant protocol header fields of the message and the type of the message 
   result of a transformer. - At the time being, this is limited to the types used for C/S communication (i.e., REQUEST and 
   RESPONSE and OK and ERROR).
*/
Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType) (const uint8* buffer,
                                                       uint32 bufferLength,
                                                       Std_MessageTypeType* messageType, 
                                                       Std_MessageResultType* messageResult);

#ifndef STATUSTYPEDEFINED 
#define STATUSTYPEDEFINED
typedef unsigned char StatusType; /* OSEK compliance */
#endif

#define STD_HIGH 0x01u /* Physical state 5V or 3.3V */ 
#define STD_LOW  0x00u /* Physical state 0V */

#define STD_ACTIVE 0x01u /* Logical state active */ 
#define STD_IDLE   0x00u /* Logical state idle */

#define STD_ON  0x01u 
#define STD_OFF 0x00u

#define NULL_PTR ((void*)0)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/

#endif
/***************************************************Log Projects*******************************************************
 *|    ID   |  JIRA Ticket  |     Date    |                               Description                                 |
 *| CMARTI  |  STM32F401-1  | 11-Mar-2023 | Added Std_Types.h according AUTOSAR specification                         |
**********************************************************************************************************************/ 