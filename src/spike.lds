ENTRY(_start)

PHDRS {
    execute PT_LOAD;
    readonly PT_LOAD;
    writeable PT_LOAD;
    uninitialized PT_LOAD;
}

SECTIONS {
    .text 0x80000000 : {
        *(.text.init)
        *(.text)
    } :execute

    .rodata : ALIGN(0x1000) {
        *(.rodata)
    } :readonly

    .data : ALIGN(0x1000) {
        *(.data)
    } :writeable

    .bss : ALIGN(0x1000) {
        *(.bss COMMON)
    } :uninitialized

    .stack : ALIGN(0x1000) {
        *(.stack)
    } :uninitialized

    /DISCARD/ : {
        *(.note .comment)
    }
}
