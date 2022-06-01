CLRMEM: 
  lda #10
  tax 
  lda #$00        ;Set up zero value
  tay             ;Initialize index pointer
CLRM1:   
  sta $0f,Y       ;Clear memory location
  iny             ;Advance index pointer
  dex             ;Decrement counter
  bne CLRM1       ;Not zero, continue checking