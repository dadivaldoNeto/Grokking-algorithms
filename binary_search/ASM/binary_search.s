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

	sub rsp, ALLOC_INT # allocate a int called result

	lea r9, [rsp]
	add r9, LEFT
	mov DWORD PTR [r9], 0 # left = 10

	lea r10, [rsp]
	add r10, RIGHT
	dec esi
	mov DWORD PTR [r10], esi # right  size - 1

	mov DWORD PTR [rsp + RESULT], -1

	start_loop:
		mov eax, DWORD PTR [r10]
		cmp DWORD PTR [r9], eax # left <= right
		jg end_loop

		sub eax, DWORD PTR [r9] # right - left
		
		sar eax, 1 # right / 2

		add eax, DWORD PTR [r9] # right + left
		
		mov DWORD PTR [r10], eax
		cmp DWORD PTR [rdi + rax*INT_SIZE], r11d # if arr[mid] == target
		je equal_val 
		jg greater_than_target # if arr[mid] > target
		# ; if arr[mid] < target
		less_than_target:
			inc eax
			mov DWORD PTR [r9], eax
			jmp start_loop
	
	greater_than_target:
		dec eax
		mov DWORD PTR [r10], eax
		jmp start_loop

	equal_val:
		mov DWORD PTR [rsp + RESULT], eax

	end_loop:
		xor rax, rax
		mov eax, DWORD PTR [rsp + RESULT]

	epilogue:
		mov rsp, rbp
		pop rbp
		ret
