
; Constants used in NGP.MAC

	T0LO	=	232	; Ultrasonic timer initial count value = 13.8ms
	T0HI	=	53	; - update frequency of about 24 Hz

				; Ultrasonic transmit timer increment
	TXDELTA	=	1

	FxTLO	=	64 	; Flex timer initial value
	FxTHI	=	31	; - try about xx5 ms - 8ms

	FxDLO	=	238	; Flex discharge timer initial value
	FxDHI	=	2	; Try about xx500 us - 750us

	BONE	=	0D9	; Watchdog service value: service window =
				; 2048 to 65536 clock cycles (microseconds)

	RejDelta	=	01400	; Rejection constant for ultrasonic
					; timer values.

	DEFP1		=	04F	; Default pulse 1 rate = ? Hz
	DEFP2		=	04F	;         pulse 2 rate = ? Hz
					; - both On        (see RATETABLE)

; Pulse mode bit definitions for PULxRATE

	PULON	=	6	; Pulse mode on

	PULPHS	=	7	; Pulse phase
				; bit 5 still undefined
; SWMODE bit definitions
	DIGIT2	=	0	; Nybble counter

	CLRCNT	=	1	; CLEAR button count

	ENTCNT	=	2	; Enter button counter

	MODE2	=	3	; Edit mode 2 flag

	INSM	=	4	; Insert mode

	DELM	=	5	; Delete mode

	OFFS	=	6	; Offset mode complete

	OFFM	=	7	; Offset mode

SWMASK	=	06	; Used to turn off all modes except CLRCNT & ENTCNT
	
; Gesture header byte bit definitions

	REL	=	2	; Relative(1) / absolute(0) position

	SHOT	=	6	; One shot gesture

	LSTSTA	=	7	; Last state of gesture

; Bit definitions for ECHOFLAGS

	T1FIN	=	0	; Timer underflow flags

	T2FIN	=	1

	PERR	=	2	; Pulse error flag

	IFLG	=	3	; Flag used in interrupt

	XBIT	=	4	; Flag used in thumb flex routine

; These 3 defs are also used in GLBFLAGS
	HIV	=	5	; Receiver miss flags

	MIV	=	6	; Receiver miss flags

	VIV	=	7	; Receiver miss flags

IVMASK	=	0E0			; Mask for all: HIV, MIV & VIV	

; Bit definitions for GLBFLAGS

	CTRDONCE	=	0	; Center once has been done

	CTR		=	1	; Center always flag

	CTRX		=	2	; Center X flag

	CTRY		=	3	; Center Y flag

	CTRZ		=	4	; Center Z flag

; Bits 5, 6 and 7 are used for global receiver "miss" flags

CAMASK	=	01E		; Center all bit pattern
CXMASK	=	006		; Center X
CYMASK	=	00A		; Center Y
CZMASK	=	012		; Center Z

;
; Bit 7 in ICNTRL is unused - use for data ready flag for uploading data
;
	GPDRDY	=	7

;
; Bits 0 and 1 in CNTRL (uWire clock divide selects) not used...
;
	BYTE1	=	0	; Used to indicate the first byte of download

	LOCF	=	1	; Local flag used for low level subroutines

;
; Multi input wakeup edge select register is not used at all, 
; so it can be used for more flags. (WKEDG)
;
	PE0	=	0	; Period 0 bit

	PE1	=	1	; Period 1 bit:
				; PE1 = 0, PE0 = 0: Flex 1, Ultra tx 1
				; PE1 = 0, PE0 = 1: Flex 2, no Ultra tx
				; PE1 = 1, PE0 = 0: Flex 3, Ultra tx 2
				; PE1 = 1, PE0 = 1: Flex 4, no Ultra tx

	SLOMOP	=	2	; Slo-motion toggle phase

	SLOMO	=	3	; Slo-motion ON switch

	MODE1	=	4	; Edit mode 1 flag

	UPDN	=	5	; Data transfer mode (upload/download)

	INDT	=	6	; Indent flag for logic

	BLIPFL	=	7	; Blip flag for logic interp. process

SMMASK	=	008	; Bit mask for SLOMO Phase
SLOMASK	=	004	; Bit mask for SLOMO on/off

	.end

;