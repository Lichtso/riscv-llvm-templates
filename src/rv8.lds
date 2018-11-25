ENTRY(_start)

PHDRS {
    execute PT_LOAD;
    readonly PT_LOAD;
    writeable PT_LOAD;
    uninitialized PT_LOAD;
}

SECTIONS {
    .text 0x1000 : {
        *(.text.init)
        *(.text)
        . = ALIGN(0x1000);
    } :execute

    .rodata : ALIGN(0x1000) {
        *(.rodata)
        . = ALIGN(0x1000);
    } :readonly

    .data : ALIGN(0x1000) {
        *(.data)
        . = ALIGN(0x1000);
    } :writeable

    .bss : ALIGN(0x1000) {
        *(.bss COMMON)
        . = ALIGN(0x1000);
    } :uninitialized

    /DISCARD/ : {
        *(.note .comment)
    }
}
