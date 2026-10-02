.intel_syntax noprefix

.equ DEFAULT_SPACE, 8
.equ LEFT, 8
.equ RIGHT, 4
.equ INT_SIZE, 4
.equ RESULT, 0
.equ ALLOC_INT, 4
.equ ALLOC_LL, 8
.equ EXIT_SUCCESS, 0

.global _binary_search
	
# rdi - array pointer , (esi | rsi) -> array.size(), (edx | rdx) -> target
.text
_binary_search:
	prologue:
		push rbp
		mov rbp, rsp
		sub rsp, DEFAULT_SPACE
	xor r11, r11
	xor r9, r9
	xor r10, r10
	
	mov r11d, edx
	

	sub rsp, ALLOC_INT # allocate an int called left
	sub rsp, ALLOC_INT # allocate an int called right

	mov DWORD PTR [rsp], esi
	dec DWORD PTR [rsp]
	
	sub rsp, ALLOC_INT # allocate a int called result

	lea r9, DWORD PTR [rsp + LEFT]
	lea r10, DWORD PTR [rsp + RIGHT]
	mov DWORD PTR [rsp + RESULT], -1

	start_loop:
		mov eax, DWORD PTR [r10]
		cmp eax, DWORD PTR [r9] # left <= right
		jg end_loop

		sub eax, DWORD PTR [r9] # right - left
		
		mov ecx, 2
		idiv ecx # previous result / 2 

		add eax, DWORD PTR [r9] # previous result + left
		
		mov DWORD PTR [r10], eax
		cmp DWORD PTR [rdi + rax*INT_SIZE], r11d # if arr[mid] == target
		mov DWORD PTR [rsp + RESULT], eax
		je end_loop

		jg update_right
		
		inc eax
		mov DWORD PTR [r9], eax
		jmp start_loop
	
	update_right:
		dec eax
		mov DWORD PTR [r10], eax
		jmp start_loop

	end_loop:
		xor rax, rax
		mov eax, DWORD PTR [rsp + RESULT]

	epilogue:
		mov rsp, rbp
		pop rbp
		ret
