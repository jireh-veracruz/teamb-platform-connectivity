
/* Define memory regions */
MEMORY
{
  FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
  RAM   (xrw) : ORIGIN = 0x10000000, LENGTH = 256K
}

/* Entry point */
ENTRY(Reset_Handler)

/* Sections */
SECTIONS
{
  /* Interrupt vector table */
  .isr_vector :
  {
    KEEP(*(.isr_vector))
  } >FLASH

  /* Code section */
  .text :
  {
    *(.text*)
    *(.rodata*)
    KEEP(*(.init))
    KEEP(*(.fini))
  } >FLASH

  /* Initialized data */
  .data : AT (ADDR(.text) + SIZEOF(.text))
  {
    _sdata = .;
    *(.data*)
    _edata = .;
  } >RAM

  /* Uninitialized data */
  .bss :
  {
    _sbss = .;
    *(.bss*)
    *(COMMON)
    _ebss = .;
  } >RAM

  /* Stack */
  .stack :
  {
    . = ALIGN(8);
    _stack_start = .;
    . = . + 0x400; /* 1KB stack */
    _stack_end = .;
  } >RAM

  /* Heap (optional) */
  .heap :
  {
    . = ALIGN(8);
    _heap_start = .;
    . = . + 0x400; /* 1KB heap */
    _heap_end = .;
  } >RAM
}
