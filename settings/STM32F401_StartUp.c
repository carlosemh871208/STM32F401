/*********************************************************************************************************************/
/*                                                  CODE GROUP                                                       */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $Source: STM32F401_StartUp.c $
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2023-03-11
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/** STM32F401_StartUp.c
    Start up code file for microcontroller.
 */
/*********************************************************************************************************************/
/* NOTES :                                                                                                           */
/** weak: 
 * A weak symbol denotes a specially annotated symbol during linking of Executable and Linkable Format (ELF) object files. 
 * By default, without any annotation, a symbol in an object file is strong. During linking, a strong symbol can override 
 * a weak symbol of the same name. In contrast, two strong symbols that share a name yield a link error during link-time. 
 * When linking a binary executable, a weakly declared symbol does not need a definition. In comparison, (by default) a 
 * declared strong symbol without a definition triggers an undefined symbol link error. Weak symbols are not mentioned by 
 * C or C++ language standards; as such, inserting them into code is not very portable. Even if two platforms support the 
 * same or similar syntax for marking symbols as weak, the semantics may differ in subtle points, e.g. whether weak symbols 
 * during dynamic linking at runtime lose their semantics or not.
 * The weak attribute causes the declaration to be emitted as a weak symbol rather than a global. This is primarily useful 
 * in defining library functions that can be overridden in user code, though it can also be used with non-function 
 * declarations. Weak symbols are supported for ELF targets, and also for a.out targets when using the GNU assembler and linker.
 * 
 * 
 * In GNU C, you can use function attributes to declare certain things about functions called in your program which help 
 * the compiler optimize calls and check your code more carefully. For example, you can use attributes to declare that a 
 * function never returns (noreturn), returns a value depending only on its arguments (pure), or has printf-style arguments 
 * (format).
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/

/*                                                      Includes                                                     */
/*********************************************************************************************************************/
#include "STM32F401RE.h"
/*                                                Functions prototypes                                               */
/*********************************************************************************************************************/

/*                                                Constants and types                                                */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                              Function Implementation                                              */
/*********************************************************************************************************************/


/***************************************************Log Projects*******************************************************
 *|    ID   |  JIRA Ticket  |     Date    |                                Description                                |
 *| CMARTI  |  STM32F401-1  | 11-Mar-2023 | First version of STM32F401_StartUp.c                                      |
**********************************************************************************************************************/