;-------------------------------------------;
; Templates for Nintendo glove peripheral   ;
;-------------------------------------------;

;-------------------------------------------;
; This constant define the number of        ;
; templates in this file                    ;
;-------------------------------------------;

NUMTEMPLATES	=	14

;--------------TEMPLATE ROM STORAGE------------------
; All data must be packed with no gaps from TMROM to the end of the data
; Two byte bits of code are inserted at the last 2 bytes of each page.
;

	.=	0DF0	; 1st page of templates- if less room is available,
			;   put this at a higher addr 

;-------------------------------------------;
; Data starts here                          ;
;-------------------------------------------;
TMROM:		;TMROM value used to begin search

;-------------------------------------------;
TMP1:
;;;*************************************
;;; TEMPLATE:  ga
;;; LENGTH:   47 bytes
;;;*************************************
 
	.BYTE	049		; Header Byte
 
;; GESTURES
	.BYTE	044,0C		; ONE_SHOTBACK
	.BYTE	01,028		; RIGHT_ABS
	.BYTE	01,02C		; LEFT_ABS
	.BYTE	01D,018		; RIGHT_REL
	.BYTE	00,00		; LEFT_REL
	.BYTE	01,041		; UP_ABS
	.BYTE	01

;///////////////////////////////////////////;
	.=0DFE	;lookup overhead/ first page
TMPAG0:
	LAID
	RET

	.=0E00	; 2nd page of templates 	
;///////////////////////////////////////////;
;TMP1 continued...

	.BYTE	045		; DOWN_ABS	
	.BYTE	020,0C		; THUMB_A
	.BYTE	010,0C		; INDEX_B
 
;; LOGIC
	.BYTE	01B		; Logic Header
 
	.BYTE	016
	.BYTE	084
	.BYTE	017
	.BYTE	083
	.BYTE	011
	.BYTE	087
	.BYTE	02E
	.BYTE	082
	.BYTE	0C1
	.BYTE	0BE
					
	.BYTE	072
	.BYTE	022
	.BYTE	044
	.BYTE	081
	.BYTE	02E
	.BYTE	089
	.BYTE	0FE
	.BYTE	033
	.BYTE	045
	.BYTE	082
	.BYTE	02E
	.BYTE	0BE
	.BYTE	066
	.BYTE	018
	.BYTE	098
	.BYTE	019
	.BYTE	0A7
TMP2:
;;;*************************************
;;; TEMPLATE:  teach
;;; LENGTH:   40 bytes
;;;*************************************
 
	.BYTE	048		; Header Byte
 
;; GESTURES
	.BYTE	01,044		; LEFT
	.BYTE	01,040		; RIGHT
	.BYTE	01,041		; UP
	.BYTE	01,045		; DOWN
	.BYTE	020,0C		; A_BUTTON
	.BYTE	010,0C		; B_BUTTON
	.BYTE	04,0C		; BEEP_TOGGLE
	.BYTE	041,052		; BEEP_PULL
 
;; LOGIC
	.BYTE	016		; Logic Header
 
	.BYTE	017
	.BYTE	048
	.BYTE	0B0
	.BYTE	011
	.BYTE	052
	.BYTE	053
	.BYTE	054
	.BYTE	020
	.BYTE	080
	.BYTE	061
	.BYTE	011
	.BYTE	082
	.BYTE	012
	.BYTE	081
	.BYTE	013
	.BYTE	084
	.BYTE	014
	.BYTE	083
	.BYTE	015
	.BYTE	098
	.BYTE	016
	.BYTE	0A7
TMP3:
;;;*************************************
;;; TEMPLATE:  gb
;;; LENGTH:   38 bytes
;;;*************************************
 
	.BYTE	04A		; Header Byte
 
;; GESTURES
	.BYTE	01,030		; RIGHT_ABS
	.BYTE	01,034		; LEFT_ABS
	.BYTE	01D,018		; RIGHT_REL
	.BYTE	00,00		; LEFT_REL
	.BYTE	020,0C		; JUMP
	.BYTE	010,0C		; SHOOT
	.BYTE	01,026		; FORWARD_ABS
	.BYTE	01,022		; BACK_ABS
	.BYTE	01D,01A		; BACK_REL
	.BYTE	00,00		; FORWARD_REL
 
;; LOGIC
	.BYTE	010		; Logic Header
 
	.BYTE	016
	.BYTE	0A7
	.BYTE	011
	.BYTE	043
	.BYTE	081
	.BYTE	012
	.BYTE	044
	.BYTE	082
	.BYTE	017
	.BYTE	04A
	.BYTE	084
	.BYTE	019
	.BYTE	048
	.BYTE	083
	.BYTE	015
	.BYTE	098
TMP4:
;;;*************************************
;;; TEMPLATE:  tank
;;; LENGTH:   38 bytes
;;;*************************************
 
	.BYTE	049		; Header Byte
 
;; GESTURES
	.BYTE	018,03C		; RIGHT
	.BYTE	018,0C3		; LEFT
	.BYTE	018,033		; UP
	.BYTE	018,0CC		; DOWN
	.BYTE	020,0C		; A_BUTTON
	.BYTE	01,019		; B_BUTTON
	.BYTE	01,01A		; STOP
	.BYTE	02,062		; ADD_RIGHT
	.BYTE	02,0B6		; ADD_LEFT
 
;; LOGIC
	.BYTE	012		; Logic Header
 
	.BYTE	015
	.BYTE	098
	.BYTE	016
	.BYTE	0A7
	.BYTE	018
	.BYTE	081
	.BYTE	019
	.BYTE	082
	.BYTE	017
	.BYTE	078
	.BYTE	023
	.BYTE	084
	.BYTE	014
	.BYTE	083
	.BYTE	011
	.BYTE	081
	.BYTE	012
	.BYTE	082
TMP5:
;;;*************************************
;;; TEMPLATE:  gd
;;; LENGTH:   36 bytes
;;;*************************************
 
	.BYTE	048		; Header Byte
 
;; GESTURES
	.BYTE	01,01E		; FORWARD
	.BYTE	01,01A		; BACK
	.BYTE	01,044		; LEFT
	.BYTE	02,071		; BANKRIGHT
	.BYTE	01,040		; RIGHT
	.BYTE	02,06		; BANKLEFT
	.BYTE	020,08		; BOMB
	.BYTE	010,0C		; ONESHOTFIRE
 
;; LOGIC
	.BYTE	012		; Logic Header
 
	.BYTE	018
	.BYTE	0A7
	.BYTE	017
	.BYTE	098
	.BYTE	011
	.BYTE	084
	.BYTE	012
	.BYTE	083
	.BYTE	014
	.BYTE	056
	.BYTE	026
	.BYTE	082
	.BYTE	0C1
	.BYTE	073
	.BYTE	023
	.BYTE	082
	.BYTE	015
	.BYTE	081
TMP6:
;;;*************************************
;;; TEMPLATE:  double_d
;;; LENGTH:   46 bytes
;;;*************************************
 
	.BYTE	049		; Header Byte
 
;; GESTURES
	.BYTE	01,02E		; UP
	.BYTE	01,02A		; DOWN
	.BYTE	01,020		; RIGHT
	.BYTE	01,024		; LEFT
	.BYTE	08,08		; KICK
	.BYTE	010,08		; PUNCH
	.BYTE	020,08		; JUMP
	.BYTE	02,074		; HEADBUTT
	.BYTE	04,0C		; FIST
 
;; LOGIC
	.BYTE	098		; Logic Header
 
	.BYTE	018
	.BYTE	023
	.BYTE	091
	.BYTE	0D2
	.BYTE	070
	.BYTE	029
	.BYTE	041
	.BYTE	084
	.BYTE	072
	.BYTE	021
	.BYTE	084
	.BYTE	012
	.BYTE	083
	.BYTE	013
	.BYTE	081
	.BYTE	034
	.BYTE	082
	.BYTE	016
	.BYTE	098
	.BYTE	035
	.BYTE	0A7
	.BYTE	017
	.BYTE	088
	.BYTE	087
	.BYTE	057
	.BYTE	057
TMP7:
;;;*************************************
;;; TEMPLATE:  punch0
;;; LENGTH:   44 bytes
;;;*************************************
 
	.BYTE	049		; Header Byte
 
;; GESTURES
	.BYTE	018,0CC		; FIST
	.BYTE	05,0A		; DUMBPUNCH
	.BYTE	00,00		; PUNCH
	.BYTE	01,00		; RIGHT_PUNCH
	.BYTE	01,029		; PUNCH_UP
	.BYTE	02,073		; BLOCK
	.BYTE	01,03D		; DUCK
	.BYTE	01,02A		; STAR_PUNCH
	.BYTE	02,0A6		; GET_UP
 
;; LOGIC
	.BYTE	096		; Logic Header
 
	.BYTE	019
	.BYTE	0A7
	.BYTE	016

;///////////////////////////////////////////;
	.=0EFE	;lookup overhead/ second page
TMPAG1:
	LAID
	RET

	.=0F00	; 3rd page of templates
;///////////////////////////////////////////;
;TMP7 continued...

	.BYTE	083
	.BYTE	011
	.BYTE	028
	.BYTE	085
	.BYTE	033
	.BYTE	024
	.BYTE	088
	.BYTE	0C7
	.BYTE	025
	.BYTE	084
	.BYTE	061
	.BYTE	061
	.BYTE	071
	.BYTE	027
	.BYTE	093
	.BYTE	076
	.BYTE	024
	.BYTE	081
	.BYTE	0C2
	.BYTE	057
	.BYTE	059
TMP8:
;;;*************************************
;;; TEMPLATE:  rbi
;;; LENGTH:   45 bytes
;;;*************************************
 
	.BYTE	04B		; Header Byte
 
;; GESTURES
	.BYTE	01,01E		; UP
	.BYTE	01,01A		; DOWN
	.BYTE	01,020		; RIGHT
	.BYTE	01,024		; LEFT
	.BYTE	020,08		; SWNG_PTC_THR_RTRN
	.BYTE	02,016		; PICK_RUN_RUNWBALL
	.BYTE	01D,018		; RIGHT_REL
	.BYTE	00,00		; LEFT_REL
	.BYTE	010,0C		; THROW_MODE
	.BYTE	01,090		; THROW_RIGHT
	.BYTE	01,094		; THROW_LEFT
 
;; LOGIC
	.BYTE	015		; Logic Header
 
	.BYTE	012
	.BYTE	083
	.BYTE	011
	.BYTE	084
	.BYTE	015
	.BYTE	088
	.BYTE	016
	.BYTE	087
	.BYTE	019
	.BYTE	02A
	.BYTE	081
	.BYTE	03B
	.BYTE	082
	.BYTE	062
	.BYTE	072
	.BYTE	023
	.BYTE	047
	.BYTE	081
	.BYTE	014
	.BYTE	048
	.BYTE	082
TMP9:
;;;*************************************
;;; TEMPLATE:  rad_race
;;; LENGTH:   34 bytes
;;;*************************************
 
	.BYTE	048		; Header Byte
 
;; GESTURES
	.BYTE	02,061		; RIGHT
	.BYTE	02,0B6		; LEFT
	.BYTE	01,035		; BRAKE
	.BYTE	01,016		; TURBO
	.BYTE	010,0C		; THROTLEL
	.BYTE	01,0A1		; RADIO
	.BYTE	01,042		; IE
	.BYTE	020,0C		; THUMB
 
;; LOGIC
	.BYTE	010		; Logic Header
 
	.BYTE	017
	.BYTE	073
	.BYTE	025
	.BYTE	088
	.BYTE	014
	.BYTE	084
	.BYTE	013
	.BYTE	087
	.BYTE	018
	.BYTE	089
	.BYTE	016
	.BYTE	083
	.BYTE	011
	.BYTE	081
	.BYTE	012
	.BYTE	082
TMP10:
;;;*************************************
;;; TEMPLATE:  rcproam
;;; LENGTH:   21 bytes
;;;*************************************
 
	.BYTE	044		; Header Byte
 
;; GESTURES
	.BYTE	08,08		; RIGHT
	.BYTE	010,08		; LEFT
	.BYTE	020,08		; FIRE
	.BYTE	01,0A5		; STOP
 
;; LOGIC
	.BYTE	089		; Logic Header
 
	.BYTE	014
	.BYTE	0A7
	.BYTE	0C7
	.BYTE	011
	.BYTE	091
	.BYTE	012
	.BYTE	092
	.BYTE	013
	.BYTE	088
	.BYTE	017
	.BYTE	057
TMP11:
;;;*************************************
;;; TEMPLATE:  thrash2
;;; LENGTH:   46 bytes
;;;*************************************
 
	.BYTE	049		; Header Byte
 
;; GESTURES
	.BYTE	04,0C		; THRASH
	.BYTE	01,028		; RIGHT_ABS
	.BYTE	01,02C		; LEFT_ABS
	.BYTE	01D,018		; RIGHT_REL
	.BYTE	00,00		; LEFT_REL
	.BYTE	01,041		; UP_ABS
	.BYTE	01,045		; DOWN_ABS
	.BYTE	020,0C		; THUMB_A
	.BYTE	010,0C		; INDEX_B
 
;; LOGIC
	.BYTE	098		; Logic Header
 
	.BYTE	0B0
	.BYTE	016
	.BYTE	084
	.BYTE	017
	.BYTE	083
	.BYTE	011
	.BYTE	020
	.BYTE	087
	.BYTE	02F
	.BYTE	082
	.BYTE	0C1
	.BYTE	0BF
	.BYTE	062
	.BYTE	070
	.BYTE	022
	.BYTE	044
	.BYTE	081
	.BYTE	033
	.BYTE	045
	.BYTE	082
	.BYTE	018
	.BYTE	098
	.BYTE	019
	.BYTE	0A7
	.BYTE	057
	.BYTE	057
TMP12:
;;;*************************************
;;; TEMPLATE:  mario1
;;; LENGTH:   48 bytes
;;;*************************************
 
	.BYTE	04C		; Header Byte
 
;; GESTURES
	.BYTE	01,040		; RIGHT_ABS
	.BYTE	01,044		; LEFT_ABS
	.BYTE	01D,018		; RIGHT_REL
	.BYTE	00,00		; LEFT_REL
	.BYTE	020,0C		; JUMP
	.BYTE	010,08		; SHOOT
	.BYTE	055,010		; ONESHOT_RIGHT
	.BYTE	040,00		; ONESHOT_LEFT
	.BYTE	01,031		; UP
	.BYTE	01,035		; DOWN
	.BYTE	0C,03C		; SLOW
	.BYTE	08,08		; FAST
 
;; LOGIC
	.BYTE	094		; Logic Header
 
	.BYTE	01C
	.BYTE	087
	.BYTE	016
	.BYTE	0A7
	.BYTE	015
	.BYTE	088
	.BYTE	011
	.BYTE	043
	.BYTE	02B
	.BYTE	091
	.BYTE	0C1
	.BYTE	012
	.BYTE	044
	.BYTE	02B
	.BYTE	092
	.BYTE	0C2
	.BYTE	019
	.BYTE	084
	.BYTE	01A
	.BYTE	083
	.BYTE	050
	.BYTE	04A
TMP13:
;;;*************************************
;;; TEMPLATE:  norm
;;; LENGTH:   13 bytes
;;;*************************************
 
	.BYTE	043		; Header Byte
 
;; GESTURES
	.BYTE	020,0C		; A
	.BYTE	010,0C		; B
	.BYTE	08,0C		; C
 
;; LOGIC
	.BYTE	05		; Logic Header
 
	.BYTE	011
	.BYTE	053
	.BYTE	098
	.BYTE	012
	.BYTE	0A7
TMP14:
;;;*************************************
;;; TEMPLATE:  ie
;;; LENGTH:   5 bytes
;;;*************************************
 
	.BYTE	041		; Header Byte
 
;; GESTURES
	.BYTE	020,0F		; A
 
;; LOGIC
	.BYTE	01		; Logic Header
 
	.BYTE	089

	.= 	0FEA
	.LIST	0	;abcdef0123456789abcd;
	.BYTE		' After Science 1989 '
	.LIST	021

;///////////////////////////////////////////;
	.=0FFE	;lookup overhead/ third page
TMPAG2:
	LAID
	RET

;--------end of rom----------

	.end

;