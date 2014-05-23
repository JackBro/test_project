	; Don't even think of reading this code
	; It was automatically generated by x86cpuid
	; Which is a perl program used to generate the x86 assember for
	; any of ELF, a.out, COFF, Win32, ...
	; eric <eay@cryptsoft.com>
	; 
%ifdef __omf__
section	code	use32 class=code
%else
section	.text
%endif
global	_OPENSSL_ia32_cpuid
_OPENSSL_ia32_cpuid:
	push	ebp
	push	ebx
	push	esi
	push	edi
	xor	edx,		edx
	pushfd
	pop	eax
	mov	ecx,		eax
	xor	eax,		2097152
	push	eax
	popfd
	pushfd
	pop	eax
	xor	ecx,		eax
	bt	ecx,		21
	jnc NEAR	@L000done
	xor	eax,		eax
	cpuid
	xor	eax,		eax
	cmp	ebx,		1970169159
DB	15,149,192
	mov	ebp,		eax
	cmp	edx,		1231384169
DB	15,149,192
	or	ebp,		eax
	cmp	ecx,		1818588270
DB	15,149,192
	or	ebp,		eax
	mov	eax,		1
	cpuid
	cmp	ebp,		0
	jne NEAR	@L001notP4
	and	eax,		3840
	cmp	eax,		3840
	jne NEAR	@L001notP4
	or	edx,		1048576
@L001notP4:
	bt	edx,		28
	jnc NEAR	@L000done
	shr	ebx,		16
	and	ebx,		255
	cmp	ebx,		1
	ja NEAR	@L000done
	and	edx,		4026531839
@L000done:
	mov	eax,		edx
	mov	edx,		ecx
	pop	edi
	pop	esi
	pop	ebx
	pop	ebp
	ret
extern	_OPENSSL_ia32cap_P
global	_OPENSSL_rdtsc
_OPENSSL_rdtsc:
	xor	eax,		eax
	xor	edx,		edx
	lea	ecx,		[_OPENSSL_ia32cap_P]
	bt	DWORD [ecx],	4
	jnc NEAR	@L002notsc
	rdtsc
@L002notsc:
	ret
global	_OPENSSL_instrument_halt
_OPENSSL_instrument_halt:
	lea	ecx,		[_OPENSSL_ia32cap_P]
	bt	DWORD [ecx],	4
	jnc NEAR	@L003nohalt
DD	2421723150
	and	eax,		3
	jnz NEAR	@L003nohalt
	pushfd
	pop	eax
	bt	eax,		9
	jnc NEAR	@L003nohalt
	rdtsc
	push	edx
	push	eax
	hlt
	rdtsc
	sub	eax,		DWORD [esp]
	sbb	edx,		DWORD [4+esp]
	add	esp,		8
	ret
@L003nohalt:
	xor	eax,		eax
	xor	edx,		edx
	ret
global	_OPENSSL_far_spin
_OPENSSL_far_spin:
	pushfd
	pop	eax
	bt	eax,		9
	jnc NEAR	@L004nospin
	mov	eax,		DWORD [4+esp]
	mov	ecx,		DWORD [8+esp]
DD	2430111262
	xor	eax,		eax
	mov	edx,		DWORD [ecx]
	jmp	@L005spin
align	16
@L005spin:
	inc	eax
	cmp	edx,		DWORD [ecx]
	je NEAR	@L005spin
DD	529567888
	ret
@L004nospin:
	xor	eax,		eax
	xor	edx,		edx
	ret
global	_OPENSSL_wipe_cpu
_OPENSSL_wipe_cpu:
	xor	eax,		eax
	xor	edx,		edx
	lea	ecx,		[_OPENSSL_ia32cap_P]
	mov	ecx,		DWORD [ecx]
	bt	DWORD [ecx],	1
	jnc NEAR	@L006no_x87
	bt	DWORD [ecx],	26
	jnc NEAR	@L007no_sse2
	pxor	xmm0,		xmm0
	pxor	xmm1,		xmm1
	pxor	xmm2,		xmm2
	pxor	xmm3,		xmm3
	pxor	xmm4,		xmm4
	pxor	xmm5,		xmm5
	pxor	xmm6,		xmm6
	pxor	xmm7,		xmm7
@L007no_sse2:
DD	4007259865,4007259865,4007259865,4007259865,2430851995
@L006no_x87:
	lea	eax,		[4+esp]
	ret
global	_OPENSSL_atomic_add
_OPENSSL_atomic_add:
	mov	edx,		DWORD [4+esp]
	mov	ecx,		DWORD [8+esp]
	push	ebx
	nop
	mov	eax,		DWORD [edx]
@L008spin:
	lea	ebx,		[ecx+eax]
	nop
DD	447811568
	jne NEAR	@L008spin
	mov	eax,		ebx
	pop	ebx
	ret
global	_OPENSSL_indirect_call
_OPENSSL_indirect_call:
	push	ebp
	mov	ebp,		esp
	sub	esp,		28
	mov	ecx,		DWORD [12+ebp]
	mov	DWORD [esp],	ecx
	mov	edx,		DWORD [16+ebp]
	mov	DWORD [4+esp],	edx
	mov	eax,		DWORD [20+ebp]
	mov	DWORD [8+esp],	eax
	mov	eax,		DWORD [24+ebp]
	mov	DWORD [12+esp],	eax
	mov	eax,		DWORD [28+ebp]
	mov	DWORD [16+esp],	eax
	mov	eax,		DWORD [32+ebp]
	mov	DWORD [20+esp],	eax
	mov	eax,		DWORD [36+ebp]
	mov	DWORD [24+esp],	eax
	call	DWORD [8+ebp]
	mov	esp,		ebp
	pop	ebp
	ret
segment	.CRT$XCU data
extern	_OPENSSL_cpuid_setup
DD	_OPENSSL_cpuid_setup
