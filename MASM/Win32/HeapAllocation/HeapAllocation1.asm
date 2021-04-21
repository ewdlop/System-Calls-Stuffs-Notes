INCLUDE Irvine32.inc
INCLUDELIB Irvine32.Lib

.data
ARRAY_SIZE = 1000
FILL_VAL EQU 0001h

hHeap   DWORD ?
pArray  DWORD ?
newHeap DWORD ?
str1 BYTE "Heap SIZESTR is: ",0

.code
main PROC

    INVOKE GetProcessHeap
      .IF eax == NULL
      call WriteWindowsMsg
      jmp quit
      .ELSE
      mov hHeap, eax
      .ENDIF

      call allocate_array
      jnc arrayOk
      call WriteWindowsMsg
      call Crlf     ; carriage return/line feed
      jmp quit
arrayOk:            ; ok to fill the array
    call fill_array
    call display_array
    call Crlf
    ;free the array
    INVOKE HeapFree, hHeap, 0, pArray
quit:
    exit
main ENDP

allocate_array PROC USES eax
    INVOKE HeapAlloc, hHeap, HEAP_ZERO_MEMORY, ARRAY_SIZE
    .IF eax == NULL
      stc
    .ELSE
      mov pArray, eax
      clc
    .ENDIF
    
    ret
allocate_array ENDP

fill_array PROC USES ecx edx esi
    mov ecx, ARRAY_SIZE
    mov esi, pArray
L1: mov BYTE PTR [esi], FILL_VAL
    inc esi
    loop L1

    ret
fill_array ENDP

display_array PROC USES eax ebx ecx esi
    mov ecx, ARRAY_SIZE
    mov esi, pArray
L1: mov al, [esi] ;al = lower 8 bit of eax
    mov ebx, TYPE BYTE
    call WriteHexB
    inc esi
    loop L1

    ret
display_array ENDP

END main