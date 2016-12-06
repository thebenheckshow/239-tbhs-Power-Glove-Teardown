
; Include file for NGP operating system rev. 2 (transmitters on hand)

; Memory definitions

; Available RAM: 	00 - 6F
; Stack uses:		?  - 6F (Must be initialized)
; Misc Registers	F0 - FB
; X Register		FC
; SP Register		FD
; B register		FE
;
; Let's use:		00 - 60
; 
; Miscellaneous accumulators and registers (locate below 16 for fast B 
; loading...)
	ACC1L		=	000
	ACC1H		=	001
ACCMAX	=	02			; ACC1+2
	ACC2L		=	002
	ACC2H		=	003

; New receiver variables are shared between the 3 transmitters
	NewRHL		=	004	; (Horiz)
	NewRHH		=	005	; Unvalidated data
	NewRML		=	006	; (Horiz)
	NewRMH		=	007	; Unvalidated data
	NewRVL		=	008	; (Horiz)
	NewRVH		=	009	; Unvalidated data

;=======================================;

; Shared variables: Used during calculations...
; DON'T change the order of these !
	X1ABS		=	004	; Not needed after rotation has been
	X2ABS		=	005	; calculated
	Y1ABS		=	006	; Not needed after rotation has been
	Y2ABS		=	007	; calculated

	ZNORM		=	009	; Temp variable
; Used during gesture recognition...
	DOMVEC		=	006	; Dominant vector
	GNUM		=	007	; Gesture number
	GADDR		=	008	; Gesture address
		
; Used during logic interpretation...
	STATE		=	004	; array used for logic interpretation
					; 1-3 Bytes
; Used in edit mode only...
	OFFSET		=	00C	; Edit data pointer

	SWMODE		=	00E	; Switch flags

	CHAR		=	010	; Latest character entered

;=======================================;

	GLBFLAGS	=	00A	; Global miscellaneous flags
	ECHOFLAGS	=	00B	; Used to flag first reception of signal

	XABS		=	00C	; Current horizontal position
	XABSOLD		=	00D	; Old horizontal position

	YABS		=	00E	; Current vertical position
	YABSOLD		=	00F	; Old vertical position

	ZABS		=	010	; Distance from screen
	ZABSOLD		=	011	; Old distance from screen

	ROTATION	=	012	; 0 - 12 (new in LSN, old in MSN)

;	Distance from Tx 1 to Horizontal receiver
	OldH1L		=	013	; 
	OldH1H		=	014	; validated data

;	Distance from Tx 2 to Horizontal
	OldH2L		=	015	; 
	OldH2H		=	016	; validated data

;	Distance from Tx 1 to Middle receiver
	OldM1L		=	017	; 
	OldM1H		=	018	; validated data

;	Distance from Tx 2 to Middle
	OldM2L		=	019	; 
	OldM2H		=	01A	; validated data

;	Distance from Tx 1 to Vertical receiver
	OldV1L		=	01B	; 
	OldV1H		=	01C	; validated data
	
;	Distance from Tx 2 to Vertical
	OldV2L		=	01D	; 
	OldV2H		=	01E	; validated data

	ENDZV	=	0F		; (low 4 bits of address only)

; Flex timer variables
	
	THMMAX		=	01F	; Thumb maximum value
	THMMIN		=	020	; Thumb minimum value
	IDXMAX		=	021	; Index finger maximum value
	IDXMIN		=	022	; Index finger minimum value
	MIDMAX		=	023	; Middle finger maximum value
	MIDMIN		=	024	; Middle finger minimum value
	RINMAX		=	025	; Ring finger maximum value
	RINMIN		=	026	; Ring finger minimum value

 ENDFX		=	07	; (Low 4 bits only)

; Position offsets
	XOFS		=	027
	YOFS		=	028
	ZOFS		=	029

	SWACC		=	02A	; Switch accumulator
	NPORT		=	02B	; Gesture/Logic Nintendo port buffer

	FLEXMAP		=	02C	; 2 Bit flex current positions

	TURNX		=	02D	; Relative motion - 
	TURNY		=	02E	; Turning points
	TURNZ		=	02F
MAXTURN		=	00

; Gesture definition and logic uses 40 bytes 

	TEMPLATE	=	030	; 48 bytes_________

TEMPSIZE	=	030	; Template size

	ENDRAM	=	05F

	RVALID		=	05F	; Used only in glove mode
					;         _________

	PUL1RATE	=	060	; pulse rate and mode
	PUL2RATE	=	061
; 
; Register definitions

	GSTAT1		=	0F0	; Gesture status map 16 bits
	GSTAT2		=	0F1
	CREG		=	0F2	; General purpose
	DREG		=	0F3	; General purpose
	IREG		=	0F4	; For use during interrupt only
	GBASE		=	0F5	; Glove output data pointer
	SWR0H		=	0F6	; History - last switch code

	NYREG		=	0F7	; Used in computations OR
	COUNT		=	0F7	; as edit counter

	PUL1MASK	=	0F8	; Pulse variables
	PUL1CT		=	0F9	; pulse counters -
	PUL2MASK	=	0FA	; Keep these together
	PUL2CT		=	0FB	; in this order

	.end
;