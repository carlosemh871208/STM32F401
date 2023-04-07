/*
 * STM32F401RE
 *
 * Linker script to configure memory regions.  
 * Memory regions:
 *     Text Segment (.text)
 *         A text segment, also known as a code segment, is the memory section where executable instructions 
 *         (i.e. your code) live.
 *         If you have a const variable, that will be added under .text and will be saved in FLASH. 
 *     
 *     Initialized Data segment (.data)
 *         A data segment (.data) contains the global variables and static variables that are initialized and 
 *         starts right after .text.
 *         Flash = .text + .data.
 *
 *     Uninitialized Data Segment (.bss)
 *         Uninitialized data segment or bss segment, named after an ancient assembler operator that stood for 
 *         “block started by symbol.” This segment starts at the end of the data segment and contains all global 
 *         and static variables that do not have explicit initialization. bss also end up in RAM.
 *    
 *     dec
 *         dec is the summition of all three segments, dec = .text + .data + .bss.
 *     
 *     In a nutshell:
 *         ‘text’ is your code, and constants (and also the vector table).
 *         ‘data’ is for initialized variables. This is count towards both RAM and FLASH. The initialized value 
 *                allocates space in FLASH which then is copied from ROM to RAM in the startup code.
 *         ‘bss’  is for the uninitialized data in RAM which is initialized with zero in the startup code.
 */

MEMORY 
{
    FLASH     (rx) : ORIGIN = 0x08000000, LENGHT = 512K
    RAM      (rwx) : ORIGIN = 0x20000000, LENGTH = 96K
}

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions FLASH and RAM.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
*/

ENTRY(Reset_Handler)

SECTIONS
{
    .text:
    {

    } > FLASH

    __etext = .;

    .data : AT (__etext)
    {

    } > RAM

    .data : AT (__etext)
    {

    } > RAM

    .bss :
    {

    } > RAM

    .heap (COPY):
    {

    } > RAM

    .stack_dummy (COPY):
    {

    } > RAM

    __StackTop = ORIGIN(RAM) + LENGTH(RAM);
    __StackLimit = __StackTop - SIZEOF(.stack_dummy);

    PROVIDE(__stack = __StackTop);
    
    ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")
}