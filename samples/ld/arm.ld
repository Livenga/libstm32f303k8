MEMORY {
  flash(rxai) : ORIGIN = 0x08000000, LENGTH = 64k
  sram(rwx):    ORIGIN = 0x20000000, LENGTH = 12k
  ccmsram(rw):  ORIGIN = 0x10000000, LENGTH = 4k
}

ENTRY(_startup)

estack = ORIGIN(sram) + LENGTH(sram);


SECTIONS {
  . = 0x00000000;

  .text : {
    . = ALIGN(4);
    KEEP(*(.vector))
    . = ALIGN(4);

    __text_start__ = .;

    *(.text)
    *(.text*)
    *(.rodata)
    *(.rodata*)
    *(.glue_7)
    *(.glue_7t)

    __text_end__ = .;
  } > flash

  .rodata : {
    . = ALIGN(4);
    *(.rodata)
    *(.rodata*)
    . = ALIGN(4);
  } > flash

  .ARM.extab : {
    *(.ARM.extab* .gnu.linkonce.armextab.*)
  } > flash

  .ARM : {
    __exidx_start = .;
    *(.ARM.exidx*)
    __exidx_end   = .;
  } > flash

  .preinit_array : {
    PROVIDE_HIDDEN (__preinit_array_start = .);

    KEEP (*(.preinit_array*))

    PROVIDE_HIDDEN (__preinit_array_end = .);
  } > flash

  .init_array : {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } > flash

  .fini_array : {
    PROVIDE_HIDDEN (__fini_array_start = .);

    KEEP (*(SORT(.fini_array.*)))
    KEEP (*(.fini_array*))

    PROVIDE_HIDDEN (__fini_array_end = .);
  } > flash

  __end_code = .;

  .data : AT(__end_code) {
    /*. = ALIGN(4);*/
    __data_start__ = .;

    *(.data)
    *(.data*)

    /*. = ALIGN(4);*/

    __data_end__ = .;
  } > sram
    
  . = ALIGN(4);

  .bss : {
    __bss_start__ = .;

    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);

    __bss_end__ = .;
  } > sram

  end = __bss_end__;

  /DISCARD/ : {
    libc.a (*)
    libm.a (*)
    libgcc.a (*)
  }
}
