OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_Reset)

MEMORY
{
    ROM (rx) : ORIGIN = 0xC2000040, LENGTH = 0x0DFFFFC0
    RAM (rw) : ORIGIN = 0xC0200000, LENGTH = 0x01D00000 
    HEAP (rw) : ORIGIN = 0xD0000000, LENGTH = 0x10000000
    SRAM1 (rwx) : ORIGIN = 0x10000000, LENGTH = 128K
    SRAM2 (rwx) : ORIGIN = 0x10020000, LENGTH = 128K
    SRAM3 (rwx) : ORIGIN = 0x10040000, LENGTH = 64K
    SRAM4 (rwx) : ORIGIN = 0x10050000, LENGTH = 64K
    SYSRAM (rw) : ORIGIN = 0x2FFC0000, LENGTH = 256K
}

__HEAP_SIZE = 0x40000;

SECTIONS
{
    .text : {
        *(.vector_table)
        *(.resethandler)
        *(.irqhandler)
        *(.text)
        *(.text*)
        *(.glue_7)
        *(.glue_7t)
        *(.eh_frame)
        KEEP(*(.init))
        KEEP(*(.fini))
        . = ALIGN(8);
    } > ROM

    .rodata : {
        . = ALIGN(8);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(8);
    } > ROM

    .ARM.extab : { *(.ARM.extab* .gnu.linkonce.armextab.*) } > ROM

    .ARM : {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } > ROM

    .preinit_array : {
        . = ALIGN(8);
        PROVIDE_HIDDEN(__preinit_array_start = .);
        KEEP(*(.preinit_array*))
        PROVIDE_HIDDEN(__preinit_array_end = .);
        . = ALIGN(8);
    } > ROM

    .init_array : {
        . = ALIGN(8);
        PROVIDE_HIDDEN(__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array*))
        PROVIDE_HIDDEN(__init_array_end = .);
        . = ALIGN(8);
    } > ROM

    .fini_array : {
        . = ALIGN(8);
        PROVIDE_HIDDEN(__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array*))
        PROVIDE_HIDDEN(__fini_array_end = .);
        . = ALIGN(8);
    } > ROM

    _text_end = .;

    .data : AT(_text_end) {
        . = ALIGN(8);
        _data_start = .;
        *(.data)
        *(.data*)
        . = ALIGN(8);
        _data_end = .;
    } > RAM

    .bss : {
        . = ALIGN(8);
        _bss_start = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(8);
        _bss_end = .;
        . = ALIGN(256);
        _ram_aligned_end = .;
    } > RAM

    .heap (NOLOAD) : {
        . = ALIGN(8);
        _sheap = .;
        . += __HEAP_SIZE;
        _eheap = .;
    } > HEAP

    _user_stack_start = _ram_aligned_end;
    _user_stack_end = _user_stack_start + 0x10000;

    _svc_stack_start = _user_stack_end;
    _svc_stack_end = _svc_stack_start + 0x1000;

    _irq_stack_start = _svc_stack_end;
    _irq_stack_end = _irq_stack_start + 0x100;

    _fiq_stack_start = _irq_stack_end;
    _fiq_stack_end = _fiq_stack_start + 0x100;

    _auxcore_user_stack_start = _fiq_stack_end;
    _auxcore_user_stack_end = _auxcore_user_stack_start + 0x1000;

    /DISCARD/ : {
        libc.a ( * )
        libm.a ( * )
        libgcc.a ( * )
    }

    .ARM.attributes 0 : { *(.ARM.attributes) }

    /* Compatibility aliases for startup/syscalls */
    __bss_start__ = _bss_start;
    __bss_end__ = _bss_end;
    _end = _eheap;
}
