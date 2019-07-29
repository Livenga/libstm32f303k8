MEMORY {
  flash(rxai) : ORIGIN = 0x08000000, LENGTH = 64k
  sram(rwx):    ORIGIN = 0x20000000, LENGTH = 12k
  ccmsram(rw):  ORIGIN = 0x10000000, LENGTH = 4k
}

ENTRY(startup)

estack = ORIGIN(sram) + LENGTH(sram);


SECTIONS {
  . = 0x00000000;

  .text : {
    KEEP(*(.vector))
    _text_start = .;

    *(.text)
    *(.text*)
    *(.rodata*)

    _text_end = .;
  } > flash


  .data : AT(_text_end) {
    . = ALIGN(4);
    _data_start = .;

    *(.data)
    *(.data*)

    . = ALIGN(4);
    _data_end = .;
  } > sram
    
  . = ALIGN(4);

    _bss_start = .;
  .bss : {

    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
  } > sram
    _bss_end = .;
}
