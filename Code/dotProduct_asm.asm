section .data
sdot dq 0.0

section .text
bits 64
default rel

global asmDotProduct

asmDotProduct:
	push rsi
	push rcx		; n
	push rdx		; A
	push r8			; B
	mov r15, 0		; iterator
	push r15
	xorps xmm0, xmm0 ; initialize to 0
	movsd [sdot], xmm0 ; restart var
	call loop
	pop rsi
	movsd xmm0, [sdot]
	ret
	; first parameter is n

loop:
	dec rcx						; dec counter

	movsd xmm1, [rdx+r15*8]		; a * b
	movsd xmm2, [r8+r15*8]

	mulsd xmm1, xmm2			; sum of a * b
	movsd xmm0, [sdot]
	addsd xmm0, xmm1
	movsd [sdot], xmm0

	inc r15
	
	cmp rcx, 0
	jne loop
	ret 32