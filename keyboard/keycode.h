/*
Copyright 2011,2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * Keycodes based on HID Usage Keyboard/Keypad Page(0x07) plus special codes
 * http://www.usb.org/developers/devclass_docs/Hut1_12.pdf
 */
#ifndef KEYCODE_H
#define KEYCODE_H


#define IS_ERROR(code)           (KC_ROLL_OVER <= (code) && (code) <= KC_UNDEFINED)
#define IS_ANY(code)             (KC_A         <= (code) && (code) <= 0xFF)

#ifndef ACTIONMAP_ENABLE
#define IS_KEY(code)             (KC_A         <= (code) && (code) <= KC_EXSEL)
#else
#define IS_KEY(code)             ((KC_A         <= (code) && (code) <= KC_EXSEL) || \
                                  (KC_KP_00     <= (code) && (code) <= KC_KP_HEXADECIMAL))
#endif

#define IS_MOD(code)             (KC_LCTRL     <= (code) && (code) <= KC_RGUI)


#define IS_SPECIAL(code)         ((0xA5 <= (code) && (code) <= 0xDF) || (0xE8 <= (code) && (code) <= 0xFF))
#define IS_SYSTEM(code)          (KC_PWR       <= (code) && (code) <= KC_WAKE)
#define IS_CONSUMER(code)        (KC_MUTE      <= (code) && (code) <= KC_WFAV)
#define IS_FN(code)              (KC_FN0       <= (code) && (code) <= KC_FN31)
#define IS_MOUSEKEY(code)        (KC_MS_UP     <= (code) && (code) <= KC_MS_ACCEL2)
#define IS_MOUSEKEY_MOVE(code)   (KC_MS_UP     <= (code) && (code) <= KC_MS_RIGHT)
#define IS_MOUSEKEY_BUTTON(code) (KC_MS_BTN1   <= (code) && (code) <= KC_MS_BTN5)
#define IS_MOUSEKEY_WHEEL(code)  (KC_MS_WH_UP  <= (code) && (code) <= KC_MS_WH_RIGHT)
#define IS_MOUSEKEY_ACCEL(code)  (KC_MS_ACCEL0 <= (code) && (code) <= KC_MS_ACCEL2)

#define MOD_BIT(code)   (1<<MOD_INDEX(code))
#define MOD_INDEX(code) ((code) & 0x07)
#define FN_BIT(code)    (1<<FN_INDEX(code))
#define FN_INDEX(code)  ((code) - KC_FN0)
#define FN_MIN          KC_FN0
#define FN_MAX          KC_FN31


/*
 * Short names for ease of definition of keymap
 */
#define KC_LCTL KC_LCTRL
#define KC_RCTL KC_RCTRL
#define KC_LSFT KC_LSHIFT
#define KC_RSFT KC_RSHIFT
#define KC_ESC  KC_ESCAPE
#define KC_BSPC KC_BSPACE
#define KC_ENT  KC_ENTER
#define KC_DEL  KC_DELETE
#define KC_INS  KC_INSERT
#define KC_CAPS KC_CAPSLOCK
#define KC_CLCK KC_CAPSLOCK
#define KC_RGHT KC_RIGHT
#define KC_PGDN KC_PGDOWN
#define KC_PSCR KC_PSCREEN
#define KC_SLCK KC_SCROLLLOCK
#define KC_PAUS KC_PAUSE
#define KC_BRK  KC_PAUSE
#define KC_NLCK KC_NUMLOCK
#define KC_SPC  KC_SPACE
#define KC_MINS KC_MINUS
#define KC_EQL  KC_EQUAL
#define KC_GRV  KC_GRAVE
#define KC_RBRC KC_RBRACKET
#define KC_LBRC KC_LBRACKET
#define KC_COMM KC_COMMA
#define KC_BSLS KC_BSLASH
#define KC_SLSH KC_SLASH
#define KC_SCLN KC_SCOLON
#define KC_QUOT KC_QUOTE
#define KC_APP  KC_APPLICATION
#define KC_NUHS KC_NONUS_HASH
#define KC_NUBS KC_NONUS_BSLASH
#define KC_LCAP KC_LOCKING_CAPS
#define KC_LNUM KC_LOCKING_NUM
#define KC_LSCR KC_LOCKING_SCROLL
#define KC_ERAS KC_ALT_ERASE
#define KC_CLR  KC_CLEAR
/* Japanese specific */
#define KC_ZKHK KC_GRAVE
#define KC_RO   KC_INT1
#define KC_KANA KC_INT2
#define KC_JYEN KC_INT3
#define KC_JPY  KC_INT3
#define KC_HENK KC_INT4
#define KC_MHEN KC_INT5
/* Korean specific */
#define KC_HAEN KC_LANG1
#define KC_HANJ KC_LANG2
/* Keypad */
#define KC_P1   KC_KP_1
#define KC_P2   KC_KP_2
#define KC_P3   KC_KP_3
#define KC_P4   KC_KP_4
#define KC_P5   KC_KP_5
#define KC_P6   KC_KP_6
#define KC_P7   KC_KP_7
#define KC_P8   KC_KP_8
#define KC_P9   KC_KP_9
#define KC_P0   KC_KP_0
#define KC_PDOT KC_KP_DOT
#define KC_PCMM KC_KP_COMMA
#define KC_PSLS KC_KP_SLASH
#define KC_PAST KC_KP_ASTERISK
#define KC_PMNS KC_KP_MINUS
#define KC_PPLS KC_KP_PLUS
#define KC_PEQL KC_KP_EQUAL
#define KC_PENT KC_KP_ENTER
/* Unix function key */
#define KC_EXEC KC_EXECUTE
#define KC_SLCT KC_SELECT
#define KC_AGIN KC_AGAIN
#define KC_PSTE KC_PASTE
/* Mousekey */
#define KC_MS_U KC_MS_UP
#define KC_MS_D KC_MS_DOWN
#define KC_MS_L KC_MS_LEFT
#define KC_MS_R KC_MS_RIGHT
#define KC_BTN1 KC_MS_BTN1
#define KC_BTN2 KC_MS_BTN2
#define KC_BTN3 KC_MS_BTN3
#define KC_BTN4 KC_MS_BTN4
#define KC_BTN5 KC_MS_BTN5
#define KC_WH_U KC_MS_WH_UP
#define KC_WH_D KC_MS_WH_DOWN
#define KC_WH_L KC_MS_WH_LEFT
#define KC_WH_R KC_MS_WH_RIGHT
#define KC_ACL0 KC_MS_ACCEL0
#define KC_ACL1 KC_MS_ACCEL1
#define KC_ACL2 KC_MS_ACCEL2
/* Sytem Control */
#define KC_PWR  KC_SYSTEM_POWER
#define KC_SLEP KC_SYSTEM_SLEEP
#define KC_WAKE KC_SYSTEM_WAKE
/* Consumer Page */
#define KC_MUTE KC_AUDIO_MUTE
#define KC_VOLU KC_AUDIO_VOL_UP
#define KC_VOLD KC_AUDIO_VOL_DOWN
#define KC_MNXT KC_MEDIA_NEXT_TRACK
#define KC_MPRV KC_MEDIA_PREV_TRACK
#define KC_MFFD KC_MEDIA_FAST_FORWARD
#define KC_MRWD KC_MEDIA_REWIND
#define KC_MSTP KC_MEDIA_STOP
#define KC_MPLY KC_MEDIA_PLAY_PAUSE
#define KC_EJCT KC_MEDIA_EJECT
#define KC_MSEL KC_MEDIA_SELECT
#define KC_MAIL KC_MAIL
#define KC_CALC KC_CALCULATOR
#define KC_MYCM KC_MY_COMPUTER
#define KC_WSCH KC_WWW_SEARCH
#define KC_WHOM KC_WWW_HOME
#define KC_WBAK KC_WWW_BACK
#define KC_WFWD KC_WWW_FORWARD
#define KC_WSTP KC_WWW_STOP
#define KC_WREF KC_WWW_REFRESH
#define KC_WFAV KC_WWW_FAVORITES
/* Jump to bootloader */
#define KC_BTLD KC_BOOTLOADER
/* Transparent */
#define KC_TRANSPARENT  1
#define KC_TRNS KC_TRANSPARENT


enum ConsumerKeycode {
	// Some keys might only work with linux
	CONSUMER_POWER	= 0x30,
	CONSUMER_SLEEP = 0x32,

	MEDIA_RECORD = 0xB2,
	MEDIA_FAST_FORWARD	= 0xB3,
	MEDIA_REWIND	= 0xB4,
	MEDIA_NEXT	= 0xB5,
	MEDIA_PREVIOUS	= 0xB6,
	MEDIA_PREV	= 0xB6, // Alias
	MEDIA_STOP	= 0xB7,
	MEDIA_PLAY_PAUSE	= 0xCD,
	MEDIA_PAUSE	= 0xB0,

	MEDIA_VOLUME_MUTE	= 0xE2,
	MEDIA_VOL_MUTE = 0xE2, // Alias
	MEDIA_VOLUME_UP	= 0xE9,
	MEDIA_VOL_UP	= 0xE9, // Alias
	MEDIA_VOLUME_DOWN	= 0xEA,
	MEDIA_VOL_DOWN	= 0xEA, // Alias

	CONSUMER_BRIGHTNESS_UP = 0x006F,
	CONSUMER_BRIGHTNESS_DOWN = 0x0070,

	CONSUMER_SCREENSAVER = 0x19e,

	CONSUMER_PROGRAMMABLE_BUTTON_CONFIGURATION = 0x182,
	CONSUMER_CONTROL_CONFIGURATION = 0x183,
	CONSUMER_EMAIL_READER	= 0x18A,
	CONSUMER_CALCULATOR	= 0x192,
	CONSUMER_EXPLORER	= 0x194,

	CONSUMER_BROWSER_HOME	= 0x223,
	CONSUMER_BROWSER_BACK	= 0x224,
	CONSUMER_BROWSER_FORWARD	= 0x225,
	CONSUMER_BROWSER_REFRESH	= 0x227,
	CONSUMER_BROWSER_BOOKMARKS	= 0x22A,


	// Consumer_Page_(0x0C)	0x15
	HID_CONSUMER_UNASSIGNED		= 0x00,
	HID_CONSUMER_NUMERIC_KEY_PAD	= 0x02,	// HID type NARY
	HID_CONSUMER_PROGRAMMABLE_BUTTONS	= 0x03,	// HID type NARY
	HID_CONSUMER_MICROPHONE_CA	= 0x04,
	HID_CONSUMER_HEADPHONE_CA	= 0x05,
	HID_CONSUMER_GRAPHIC_EQUALIZER_CA	= 0x06,
	// Reserved	= 0x07-1F
	HID_CONSUMER_PLUS_10	= 0x20,	// HID type OSC
	HID_CONSUMER_PLUS_100	= 0x21,	// HID type OSC
	HID_CONSUMER_AM_SLASH_PM	= 0x22,	// HID type OSC
	// Reserved	= 0x23-3F
	HID_CONSUMER_POWER	= 0x30,	// HID type OOC
	HID_CONSUMER_RESET	= 0x31,	// HID type OSC
	HID_CONSUMER_SLEEP	= 0x32,	// HID type OSC
	HID_CONSUMER_SLEEP_AFTER	= 0x33,	// HID type OSC
	HID_CONSUMER_SLEEP_MODE	= 0x34,	// HID type RTC
	HID_CONSUMER_ILLUMINATION	= 0x35,	// HID type OOC
	HID_CONSUMER_FUNCTION_BUTTONS	= 0x36,	// HID type NARY
	// Reserved	= 0x37-3F
	HID_CONSUMER_MENU	= 0x40,	// HID type OOC
	HID_CONSUMER_MENU_PICK	= 0x41,	// HID type OSC
	HID_CONSUMER_MENU_UP	= 0x42,	// HID type OSC
	HID_CONSUMER_MENU_DOWN	= 0x43,	// HID type OSC
	HID_CONSUMER_MENU_LEFT	= 0x44,	// HID type OSC
	HID_CONSUMER_MENU_RIGHT	= 0x45,	// HID type OSC
	HID_CONSUMER_MENU_ESCAPE	= 0x46,	// HID type OSC
	HID_CONSUMER_MENU_VALUE_INCREASE	= 0x47,	// HID type OSC
	HID_CONSUMER_MENU_VALUE_DECREASE	= 0x48,	// HID type OSC
	// Reserved 0x49-5F
	HID_CONSUMER_DATA_ON_SCREEN	= 0x60,	// HID type OOC
	HID_CONSUMER_CLOSED_CAPTION	= 0x61,	// HID type OOC
	HID_CONSUMER_CLOSED_CAPTION_SELECT	= 0x62,	// HID type OSC
	HID_CONSUMER_VCR_SLASH_TV	= 0x63,	// HID type OOC
	HID_CONSUMER_BROADCAST_MODE	= 0x64,	// HID type OSC
	HID_CONSUMER_SNAPSHOT	= 0x65,	// HID type OSC
	HID_CONSUMER_STILL	= 0x66,	// HID type OSC
	// Reserved 0x67-7F
	HID_CONSUMER_SELECTION	= 0x80,	// HID type NARY
	HID_CONSUMER_ASSIGN_SELECTION	= 0x81,	// HID type OSC
	HID_CONSUMER_MODE_STEP	= 0x82,	// HID type OSC
	HID_CONSUMER_RECALL_LAST	= 0x83,	// HID type OSC
	HID_CONSUMER_ENTER_CHANNEL	= 0x84,	// HID type OSC
	HID_CONSUMER_ORDER_MOVIE	= 0x85,	// HID type OSC
	HID_CONSUMER_CHANNEL	= 0x86,	// HID type LC
	HID_CONSUMER_MEDIA_SELECTION	= 0x87,	// HID type NARY
	HID_CONSUMER_MEDIA_SELECT_COMPUTER	= 0x88,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_TV	= 0x89,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_WWW	= 0x8A,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_DVD	= 0x8B,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_TELEPHONE	= 0x8C,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_PROGRAM_GUIDE	= 0x8D,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_VIDEO_PHONE	= 0x8E,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_GAMES	= 0x8F,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_MESSAGES	= 0x90,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_CD	= 0x91,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_VCR	= 0x92,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_TUNER	= 0x93,	// HID type SEL
	HID_CONSUMER_QUIT	= 0x94,	// HID type OSC
	HID_CONSUMER_HELP	= 0x95,	// HID type OOC
	HID_CONSUMER_MEDIA_SELECT_TAPE	= 0x96,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_CABLE	= 0x97,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_SATELLITE	= 0x98,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_SECURITY	= 0x99,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_HOME	= 0x9A,	// HID type SEL
	HID_CONSUMER_MEDIA_SELECT_CALL	= 0x9B,	// HID type SEL
	HID_CONSUMER_CHANNEL_INCREMENT	= 0x9C,	// HID type OSC
	HID_CONSUMER_CHANNEL_DECREMENT	= 0x9D,	// HID type OSC
	HID_CONSUMER_MEDIA_SELECT_SAP	= 0x9E,	// HID type SEL
	// Reserved 0x9F
	HID_CONSUMER_VCR_PLUS	= 0xA0,	// HID type OSC
	HID_CONSUMER_ONCE	= 0xA1,	// HID type OSC
	HID_CONSUMER_DAILY	= 0xA2,	// HID type OSC
	HID_CONSUMER_WEEKLY	= 0xA3,	// HID type OSC
	HID_CONSUMER_MONTHLY	= 0xA4,	// HID type OSC
	// Reserved 0xA5-AF
	HID_CONSUMER_PLAY	= 0xB0,	// HID type OOC
	HID_CONSUMER_PAUSE	= 0xB1,	// HID type OOC
	HID_CONSUMER_RECORD	= 0xB2,	// HID type OOC
	HID_CONSUMER_FAST_FORWARD	= 0xB3,	// HID type OOC
	HID_CONSUMER_REWIND	= 0xB4,	// HID type OOC
	HID_CONSUMER_SCAN_NEXT_TRACK	= 0xB5,	// HID type OSC
	HID_CONSUMER_SCAN_PREVIOUS_TRACK	= 0xB6,	// HID type OSC
	HID_CONSUMER_STOP	= 0xB7,	// HID type OSC
	HID_CONSUMER_EJECT	= 0xB8,	// HID type OSC
	HID_CONSUMER_RANDOM_PLAY	= 0xB9,	// HID type OOC
	HID_CONSUMER_SELECT_DISC	= 0xBA,	// HID type NARY
	HID_CONSUMER_ENTER_DISC_MC	= 0xBB,
	HID_CONSUMER_REPEAT	= 0xBC,	// HID type OSC
	HID_CONSUMER_TRACKING	= 0xBD,	// HID type LC
	HID_CONSUMER_TRACK_NORMAL	= 0xBE,	// HID type OSC
	HID_CONSUMER_SLOW_TRACKING	= 0xBF,	// HID type LC
	HID_CONSUMER_FRAME_FORWARD	= 0xC0,	// HID type RTC
	HID_CONSUMER_FRAME_BACK	= 0xC1,	// HID type RTC
	HID_CONSUMER_MARK	= 0xC2,	// HID type OSC
	HID_CONSUMER_CLEAR_MARK	= 0xC3,	// HID type OSC
	HID_CONSUMER_REPEAT_FROM_MARK	= 0xC4,	// HID type OOC
	HID_CONSUMER_RETURN_TO_MARK	= 0xC5,	// HID type OSC
	HID_CONSUMER_SEARCH_MARK_FORWARD	= 0xC6,	// HID type OSC
	HID_CONSUMER_SEARCH_MARK_BACKWARDS	= 0xC7,	// HID type OSC
	HID_CONSUMER_COUNTER_RESET	= 0xC8,	// HID type OSC
	HID_CONSUMER_SHOW_COUNTER	= 0xC9,	// HID type OSC
	HID_CONSUMER_TRACKING_INCREMENT	= 0xCA,	// HID type RTC
	HID_CONSUMER_TRACKING_DECREMENT	= 0xCB,	// HID type RTC
	HID_CONSUMER_STOP_SLASH_EJECT	= 0xCC,	// HID type OSC
	HID_CONSUMER_PLAY_SLASH_PAUSE	= 0xCD,	// HID type OSC
	HID_CONSUMER_PLAY_SLASH_SKIP	= 0xCE,	// HID type OSC
	// Reserved 0xCF-DF
	HID_CONSUMER_VOLUME	= 0xE0,	// HID type LC
	HID_CONSUMER_BALANCE	= 0xE1,	// HID type LC
	HID_CONSUMER_MUTE	= 0xE2,	// HID type OOC
	HID_CONSUMER_BASS	= 0xE3,	// HID type LC
	HID_CONSUMER_TREBLE	= 0xE4,	// HID type LC
	HID_CONSUMER_BASS_BOOST	= 0xE5,	// HID type OOC
	HID_CONSUMER_SURROUND_MODE	= 0xE6,	// HID type OSC
	HID_CONSUMER_LOUDNESS	= 0xE7,	// HID type OOC
	HID_CONSUMER_MPX	= 0xE8,	// HID type OOC
	HID_CONSUMER_VOLUME_INCREMENT	= 0xE9,	// HID type RTC
	HID_CONSUMER_VOLUME_DECREMENT	= 0xEA,	// HID type RTC
	// Reserved 0xEB-EF
	HID_CONSUMER_SPEED_SELECT	= 0xF0,	// HID type OSC
	HID_CONSUMER_PLAYBACK_SPEED	= 0xF1,	// HID type NARY
	HID_CONSUMER_STANDARD_PLAY	= 0xF2,	// HID type SEL
	HID_CONSUMER_LONG_PLAY	= 0xF3,	// HID type SEL
	HID_CONSUMER_EXTENDED_PLAY	= 0xF4,	// HID type SEL
	HID_CONSUMER_SLOW	= 0xF5,	// HID type OSC
	// Reserved 0xF6-FF
	HID_CONSUMER_FAN_ENABLE	= 0x100,	// HID type OOC
	HID_CONSUMER_FAN_SPEED	= 0x101,	// HID type LC
	HID_CONSUMER_LIGHT_ENABLE	= 0x102,	// HID type OOC
	HID_CONSUMER_LIGHT_ILLUMINATION_LEVEL	= 0x103,	// HID type LC
	HID_CONSUMER_CLIMATE_CONTROL_ENABLE	= 0x104,	// HID type OOC
	HID_CONSUMER_ROOM_TEMPERATURE	= 0x105,	// HID type LC
	HID_CONSUMER_SECURITY_ENABLE	= 0x106,	// HID type OOC
	HID_CONSUMER_FIRE_ALARM	= 0x107,	// HID type OSC
	HID_CONSUMER_POLICE_ALARM	= 0x108,	// HID type OSC
	HID_CONSUMER_PROXIMITY	= 0x109,	// HID type LC
	HID_CONSUMER_MOTION	= 0x10A,	// HID type OSC
	HID_CONSUMER_DURESS_ALARM	= 0x10B,	// HID type OSC
	HID_CONSUMER_HOLDUP_ALARM	= 0x10C,	// HID type OSC
	HID_CONSUMER_MEDICAL_ALARM	= 0x10D,	// HID type OSC
	// Reserved 0x10E-14F
	HID_CONSUMER_BALANCE_RIGHT	= 0x150,	// HID type RTC
	HID_CONSUMER_BALANCE_LEFT	= 0x151,	// HID type RTC
	HID_CONSUMER_BASS_INCREMENT	= 0x152,	// HID type RTC
	HID_CONSUMER_BASS_DECREMENT	= 0x153,	// HID type RTC
	HID_CONSUMER_TREBLE_INCREMENT	= 0x154,	// HID type RTC
	HID_CONSUMER_TREBLE_DECREMENT	= 0x155,	// HID type RTC
	// Reserved 0x156-15F
	HID_CONSUMER_SPEAKER_SYSTEM	= 0x160,	// HID type CL
	HID_CONSUMER_CHANNEL_LEFT	= 0x161,	// HID type CL
	HID_CONSUMER_CHANNEL_RIGHT	= 0x162,	// HID type CL
	HID_CONSUMER_CHANNEL_CENTER	= 0x163,	// HID type CL
	HID_CONSUMER_CHANNEL_FRONT	= 0x164,	// HID type CL
	HID_CONSUMER_CHANNEL_CENTER_FRONT	= 0x165,	// HID type CL
	HID_CONSUMER_CHANNEL_SIDE	= 0x166,	// HID type CL
	HID_CONSUMER_CHANNEL_SURROUND	= 0x167,	// HID type CL
	HID_CONSUMER_CHANNEL_LOW_FREQUENCY_ENHANCEMENT	= 0x168,	// HID type CL
	HID_CONSUMER_CHANNEL_TOP	= 0x169,	// HID type CL
	HID_CONSUMER_CHANNEL_UNKNOWN	= 0x16A,	// HID type CL
	// Reserved 0x16B-16F
	HID_CONSUMER_SUB_CHANNEL	= 0x170,	// HID type LC
	HID_CONSUMER_SUB_CHANNEL_INCREMENT	= 0x171,	// HID type OSC
	HID_CONSUMER_SUB_CHANNEL_DECREMENT	= 0x172,	// HID type OSC
	HID_CONSUMER_ALTERNATE_AUDIO_INCREMENT	= 0x173,	// HID type OSC
	HID_CONSUMER_ALTERNATE_AUDIO_DECREMENT	= 0x174,	// HID type OSC
	// Reserved 0x175-17F
	HID_CONSUMER_APPLICATION_LAUNCH_BUTTONS	= 0x180,	// HID type NARY
	HID_CONSUMER_AL_LAUNCH_BUTTON_CONFIGURATION_TOOL	= 0x181,	// HID type SEL
	HID_CONSUMER_AL_PROGRAMMABLE_BUTTON_CONFIGURATION	= 0x182,	// HID type SEL
	HID_CONSUMER_AL_CONSUMER_CONTROL_CONFIGURATION	= 0x183,	// HID type SEL
	HID_CONSUMER_AL_WORD_PROCESSOR	= 0x184,	// HID type SEL
	HID_CONSUMER_AL_TEXT_EDITOR	= 0x185,	// HID type SEL
	HID_CONSUMER_AL_SPREADSHEET	= 0x186,	// HID type SEL
	HID_CONSUMER_AL_GRAPHICS_EDITOR	= 0x187,	// HID type SEL
	HID_CONSUMER_AL_PRESENTATION_APP	= 0x188,	// HID type SEL
	HID_CONSUMER_AL_DATABASE_APP	= 0x189,	// HID type SEL
	HID_CONSUMER_AL_EMAIL_READER	= 0x18A,	// HID type SEL
	HID_CONSUMER_AL_NEWSREADER	= 0x18B,	// HID type SEL
	HID_CONSUMER_AL_VOICEMAIL	= 0x18C,	// HID type SEL
	HID_CONSUMER_AL_CONTACTS_SLASH_ADDRESS_BOOK	= 0x18D,	// HID type SEL
	HID_CONSUMER_AL_CALENDAR_SLASH_SCHEDULE	= 0x18E,	// HID type SEL
	HID_CONSUMER_AL_TASK_SLASH_PROJECT_MANAGER	= 0x18F,	// HID type SEL
	HID_CONSUMER_AL_LOG_SLASH_JOURNAL_SLASH_TIMECARD	= 0x190,	// HID type SEL
	HID_CONSUMER_AL_CHECKBOOK_SLASH_FINANCE	= 0x191,	// HID type SEL
	HID_CONSUMER_AL_CALCULATOR	= 0x192,	// HID type SEL
	HID_CONSUMER_AL_A_SLASH_V_CAPTURE_SLASH_PLAYBACK	= 0x193,	// HID type SEL
	HID_CONSUMER_AL_LOCAL_MACHINE_BROWSER	= 0x194,	// HID type SEL
	HID_CONSUMER_AL_LAN_SLASH_WAN_BROWSER	= 0x195,	// HID type SEL
	HID_CONSUMER_AL_INTERNET_BROWSER	= 0x196,	// HID type SEL
	HID_CONSUMER_AL_REMOTE_NETWORKING_SLASH_ISP_CONNECT	= 0x197,	// HID type SEL
	HID_CONSUMER_AL_NETWORK_CONFERENCE	= 0x198,	// HID type SEL
	HID_CONSUMER_AL_NETWORK_CHAT	= 0x199,	// HID type SEL
	HID_CONSUMER_AL_TELEPHONY_SLASH_DIALER	= 0x19A,	// HID type SEL
	HID_CONSUMER_AL_LOGON	= 0x19B,	// HID type SEL
	HID_CONSUMER_AL_LOGOFF	= 0x19C,	// HID type SEL
	HID_CONSUMER_AL_LOGON_SLASH_LOGOFF	= 0x19D,	// HID type SEL
	HID_CONSUMER_AL_TERMINAL_LOCK_SLASH_SCREENSAVER	= 0x19E,	// HID type SEL
	HID_CONSUMER_AL_CONTROL_PANEL	= 0x19F,	// HID type SEL
	HID_CONSUMER_AL_COMMAND_LINE_PROCESSOR_SLASH_RUN	= 0x1A0,	// HID type SEL
	HID_CONSUMER_AL_PROCESS_SLASH_TASK_MANAGER	= 0x1A1,	// HID type SEL
	HID_CONSUMER_AL_SELECT_TASK_SLASH_APPLICATION	= 0x1A2,	// HID type SEL
	HID_CONSUMER_AL_NEXT_TASK_SLASH_APPLICATION	= 0x1A3,	// HID type SEL
	HID_CONSUMER_AL_PREVIOUS_TASK_SLASH_APPLICATION	= 0x1A4,	// HID type SEL
	HID_CONSUMER_AL_PREEMPTIVE_HALT_TASK_SLASH_APPLICATION	= 0x1A5,	// HID type SEL
	HID_CONSUMER_AL_INTEGRATED_HELP_CENTER	= 0x1A6,	// HID type SEL
	HID_CONSUMER_AL_DOCUMENTS	= 0x1A7,	// HID type SEL
	HID_CONSUMER_AL_THESAURUS	= 0x1A8,	// HID type SEL
	HID_CONSUMER_AL_DICTIONARY	= 0x1A9,	// HID type SEL
	HID_CONSUMER_AL_DESKTOP	= 0x1AA,	// HID type SEL
	HID_CONSUMER_AL_SPELL_CHECK	= 0x1AB,	// HID type SEL
	HID_CONSUMER_AL_GRAMMAR_CHECK	= 0x1AC,	// HID type SEL
	HID_CONSUMER_AL_WIRELESS_STATUS	= 0x1AD,	// HID type SEL
	HID_CONSUMER_AL_KEYBOARD_LAYOUT	= 0x1AE,	// HID type SEL
	HID_CONSUMER_AL_VIRUS_PROTECTION	= 0x1AF,	// HID type SEL
	HID_CONSUMER_AL_ENCRYPTION	= 0x1B0,	// HID type SEL
	HID_CONSUMER_AL_SCREEN_SAVER	= 0x1B1,	// HID type SEL
	HID_CONSUMER_AL_ALARMS	= 0x1B2,	// HID type SEL
	HID_CONSUMER_AL_CLOCK	= 0x1B3,	// HID type SEL
	HID_CONSUMER_AL_FILE_BROWSER	= 0x1B4,	// HID type SEL
	HID_CONSUMER_AL_POWER_STATUS	= 0x1B5,	// HID type SEL
	HID_CONSUMER_AL_IMAGE_BROWSER	= 0x1B6,	// HID type SEL
	HID_CONSUMER_AL_AUDIO_BROWSER	= 0x1B7,	// HID type SEL
	HID_CONSUMER_AL_MOVIE_BROWSER	= 0x1B8,	// HID type SEL
	HID_CONSUMER_AL_DIGITAL_RIGHTS_MANAGER	= 0x1B9,	// HID type SEL
	HID_CONSUMER_AL_DIGITAL_WALLET	= 0x1BA,	// HID type SEL
	// _Reserved 0x1BB
	HID_CONSUMER_AL_INSTANT_MESSAGING	= 0x1BC,	// HID type SEL
	HID_CONSUMER_AL_OEM_FEATURES_SLASH__TIPS_SLASH_TUTORIAL_BROWSER	= 0x1BD,	// HID type SEL
	HID_CONSUMER_AL_OEM_HELP	= 0x1BE,	// HID type SEL
	HID_CONSUMER_AL_ONLINE_COMMUNITY	= 0x1BF,	// HID type SEL
	HID_CONSUMER_AL_ENTERTAINMENT_CONTENT_BROWSER	= 0x1C0,	// HID type SEL
	HID_CONSUMER_AL_ONLINE_SHOPPING_BROWSER	= 0x1C1,	// HID type SEL
	HID_CONSUMER_AL_SMARTCARD_INFORMATION_SLASH_HELP	= 0x1C2,	// HID type SEL
	HID_CONSUMER_AL_MARKET_MONITOR_SLASH_FINANCE_BROWSER	= 0x1C3,	// HID type SEL
	HID_CONSUMER_AL_CUSTOMIZED_CORPORATE_NEWS_BROWSER	= 0x1C4,	// HID type SEL
	HID_CONSUMER_AL_ONLINE_ACTIVITY_BROWSER	= 0x1C5,	// HID type SEL
	HID_CONSUMER_AL_RESEARCH_SLASH_SEARCH_BROWSER	= 0x1C6,	// HID type SEL
	HID_CONSUMER_AL_AUDIO_PLAYER	= 0x1C7,	// HID type SEL
	// Reserved 0x1C8-1FF
	HID_CONSUMER_GENERIC_GUI_APPLICATION_CONTROLS	= 0x200, // HID type NARY
	HID_CONSUMER_AC_NEW	= 0x201,	// HID type SEL
	HID_CONSUMER_AC_OPEN	= 0x202,	// HID type SEL
	HID_CONSUMER_AC_CLOSE	= 0x203,	// HID type SEL
	HID_CONSUMER_AC_EXIT	= 0x204,	// HID type SEL
	HID_CONSUMER_AC_MAXIMIZE	= 0x205,	// HID type SEL
	HID_CONSUMER_AC_MINIMIZE	= 0x206,	// HID type SEL
	HID_CONSUMER_AC_SAVE	= 0x207,	// HID type SEL
	HID_CONSUMER_AC_PRINT	= 0x208,	// HID type SEL
	HID_CONSUMER_AC_PROPERTIES	= 0x209,	// HID type SEL
	HID_CONSUMER_AC_UNDO	= 0x21A,	// HID type SEL
	HID_CONSUMER_AC_COPY	= 0x21B,	// HID type SEL
	HID_CONSUMER_AC_CUT	= 0x21C,	// HID type SEL
	HID_CONSUMER_AC_PASTE	= 0x21D,	// HID type SEL
	HID_CONSUMER_AC_SELECT_ALL	= 0x21E,	// HID type SEL
	HID_CONSUMER_AC_FIND	= 0x21F,	// HID type SEL
	HID_CONSUMER_AC_FIND_AND_REPLACE	= 0x220,	// HID type SEL
	HID_CONSUMER_AC_SEARCH	= 0x221,	// HID type SEL
	HID_CONSUMER_AC_GO_TO	= 0x222,	// HID type SEL
	HID_CONSUMER_AC_HOME	= 0x223,	// HID type SEL
	HID_CONSUMER_AC_BACK	= 0x224,	// HID type SEL
	HID_CONSUMER_AC_FORWARD	= 0x225,	// HID type SEL
	HID_CONSUMER_AC_STOP	= 0x226,	// HID type SEL
	HID_CONSUMER_AC_REFRESH	= 0x227,	// HID type SEL
	HID_CONSUMER_AC_PREVIOUS_LINK	= 0x228,	// HID type SEL
	HID_CONSUMER_AC_NEXT_LINK	= 0x229,	// HID type SEL
	HID_CONSUMER_AC_BOOKMARKS	= 0x22A,	// HID type SEL
	HID_CONSUMER_AC_HISTORY	= 0x22B,	// HID type SEL
	HID_CONSUMER_AC_SUBSCRIPTIONS	= 0x22C,	// HID type SEL
	HID_CONSUMER_AC_ZOOM_IN	= 0x22D,	// HID type SEL
	HID_CONSUMER_AC_ZOOM_OUT	= 0x22E,	// HID type SEL
	HID_CONSUMER_AC_ZOOM	= 0x22F,	// HID type LC
	HID_CONSUMER_AC_FULL_SCREEN_VIEW	= 0x230,	// HID type SEL
	HID_CONSUMER_AC_NORMAL_VIEW	= 0x231,	// HID type SEL
	HID_CONSUMER_AC_VIEW_TOGGLE	= 0x232,	// HID type SEL
	HID_CONSUMER_AC_SCROLL_UP	= 0x233,	// HID type SEL
	HID_CONSUMER_AC_SCROLL_DOWN	= 0x234,	// HID type SEL
	HID_CONSUMER_AC_SCROLL	= 0x235,	// HID type LC
	HID_CONSUMER_AC_PAN_LEFT	= 0x236,	// HID type SEL
	HID_CONSUMER_AC_PAN_RIGHT	= 0x237,	// HID type SEL
	HID_CONSUMER_AC_PAN	= 0x238,	// HID type LC
	HID_CONSUMER_AC_NEW_WINDOW	= 0x239,	// HID type SEL
	HID_CONSUMER_AC_TILE_HORIZONTALLY	= 0x23A,	// HID type SEL
	HID_CONSUMER_AC_TILE_VERTICALLY	= 0x23B,	// HID type SEL
	HID_CONSUMER_AC_FORMAT	= 0x23C,	// HID type SEL
	HID_CONSUMER_AC_EDIT	= 0x23D,	// HID type SEL
	HID_CONSUMER_AC_BOLD	= 0x23E,	// HID type SEL
	HID_CONSUMER_AC_ITALICS	= 0x23F,	// HID type SEL
	HID_CONSUMER_AC_UNDERLINE	= 0x240,	// HID type SEL
	HID_CONSUMER_AC_STRIKETHROUGH	= 0x241,	// HID type SEL
	HID_CONSUMER_AC_SUBSCRIPT	= 0x242,	// HID type SEL
	HID_CONSUMER_AC_SUPERSCRIPT	= 0x243,	// HID type SEL
	HID_CONSUMER_AC_ALL_CAPS	= 0x244,	// HID type SEL
	HID_CONSUMER_AC_ROTATE	= 0x245,	// HID type SEL
	HID_CONSUMER_AC_RESIZE	= 0x246,	// HID type SEL
	HID_CONSUMER_AC_FLIP_HORIZONTAL	= 0x247,	// HID type SEL
	HID_CONSUMER_AC_FLIP_VERTICAL	= 0x248,	// HID type SEL
	HID_CONSUMER_AC_MIRROR_HORIZONTAL	= 0x249,	// HID type SEL
	HID_CONSUMER_AC_MIRROR_VERTICAL	= 0x24A,	// HID type SEL
	HID_CONSUMER_AC_FONT_SELECT	= 0x24B,	// HID type SEL
	HID_CONSUMER_AC_FONT_COLOR	= 0x24C,	// HID type SEL
	HID_CONSUMER_AC_FONT_SIZE	= 0x24D,	// HID type SEL
	HID_CONSUMER_AC_JUSTIFY_LEFT	= 0x24E,	// HID type SEL
	HID_CONSUMER_AC_JUSTIFY_CENTER_H	= 0x24F,	// HID type SEL
	HID_CONSUMER_AC_JUSTIFY_RIGHT	= 0x250,	// HID type SEL
	HID_CONSUMER_AC_JUSTIFY_BLOCK_H	= 0x251,	// HID type SEL
	HID_CONSUMER_AC_JUSTIFY_TOP	= 0x252,	// HID type SEL
	HID_CONSUMER_AC_JUSTIFY_CENTER_V	= 0x253,	// HID type SEL
	HID_CONSUMER_AC_JUSTIFY_BOTTOM	= 0x254,	// HID type SEL
	HID_CONSUMER_AC_JUSTIFY_BLOCK_V	= 0x255,	// HID type SEL
	HID_CONSUMER_AC_INDENT_DECREASE	= 0x256,	// HID type SEL
	HID_CONSUMER_AC_INDENT_INCREASE	= 0x257,	// HID type SEL
	HID_CONSUMER_AC_NUMBERED_LIST	= 0x258,	// HID type SEL
	HID_CONSUMER_AC_RESTART_NUMBERING	= 0x259,	// HID type SEL
	HID_CONSUMER_AC_BULLETED_LIST	= 0x25A,	// HID type SEL
	HID_CONSUMER_AC_PROMOTE	= 0x25B,	// HID type SEL
	HID_CONSUMER_AC_DEMOTE	= 0x25C,	// HID type SEL
	HID_CONSUMER_AC_YES	= 0x25D,	// HID type SEL
	HID_CONSUMER_AC_NO	= 0x25E,	// HID type SEL
	HID_CONSUMER_AC_CANCEL	= 0x25F,	// HID type SEL
	HID_CONSUMER_AC_CATALOG	= 0x260,	// HID type SEL
	HID_CONSUMER_AC_BUY_SLASH_CHECKOUT	= 0x261,	// HID type SEL
	HID_CONSUMER_AC_ADD_TO_CART	= 0x262,	// HID type SEL
	HID_CONSUMER_AC_EXPAND	= 0x263,	// HID type SEL
	HID_CONSUMER_AC_EXPAND_ALL	= 0x264,	// HID type SEL
	HID_CONSUMER_AC_COLLAPSE	= 0x265,	// HID type SEL
	HID_CONSUMER_AC_COLLAPSE_ALL	= 0x266,	// HID type SEL
	HID_CONSUMER_AC_PRINT_PREVIEW	= 0x267,	// HID type SEL
	HID_CONSUMER_AC_PASTE_SPECIAL	= 0x268,	// HID type SEL
	HID_CONSUMER_AC_INSERT_MODE	= 0x269,	// HID type SEL
	HID_CONSUMER_AC_DELETE	= 0x26A,	// HID type SEL
	HID_CONSUMER_AC_LOCK	= 0x26B,	// HID type SEL
	HID_CONSUMER_AC_UNLOCK	= 0x26C,	// HID type SEL
	HID_CONSUMER_AC_PROTECT	= 0x26D,	// HID type SEL
	HID_CONSUMER_AC_UNPROTECT	= 0x26E,	// HID type SEL
	HID_CONSUMER_AC_ATTACH_COMMENT	= 0x26F,	// HID type SEL
	HID_CONSUMER_AC_DELETE_COMMENT	= 0x270,	// HID type SEL
	HID_CONSUMER_AC_VIEW_COMMENT	= 0x271,	// HID type SEL
	HID_CONSUMER_AC_SELECT_WORD	= 0x272,	// HID type SEL
	HID_CONSUMER_AC_SELECT_SENTENCE	= 0x273,	// HID type SEL
	HID_CONSUMER_AC_SELECT_PARAGRAPH	= 0x274,	// HID type SEL
	HID_CONSUMER_AC_SELECT_COLUMN	= 0x275,	// HID type SEL
	HID_CONSUMER_AC_SELECT_ROW	= 0x276,	// HID type SEL
	HID_CONSUMER_AC_SELECT_TABLE	= 0x277,	// HID type SEL
	HID_CONSUMER_AC_SELECT_OBJECT	= 0x278,	// HID type SEL
	HID_CONSUMER_AC_REDO_SLASH_REPEAT	= 0x279,	// HID type SEL
	HID_CONSUMER_AC_SORT	= 0x27A,	// HID type SEL
	HID_CONSUMER_AC_SORT_ASCENDING	= 0x27B,	// HID type SEL
	HID_CONSUMER_AC_SORT_DESCENDING	= 0x27C,	// HID type SEL
	HID_CONSUMER_AC_FILTER	= 0x27D,	// HID type SEL
	HID_CONSUMER_AC_SET_CLOCK	= 0x27E,	// HID type SEL
	HID_CONSUMER_AC_VIEW_CLOCK	= 0x27F,	// HID type SEL
	HID_CONSUMER_AC_SELECT_TIME_ZONE	= 0x280,	// HID type SEL
	HID_CONSUMER_AC_EDIT_TIME_ZONES	= 0x281,	// HID type SEL
	HID_CONSUMER_AC_SET_ALARM	= 0x282,	// HID type SEL
	HID_CONSUMER_AC_CLEAR_ALARM	= 0x283,	// HID type SEL
	HID_CONSUMER_AC_SNOOZE_ALARM	= 0x284,	// HID type SEL
	HID_CONSUMER_AC_RESET_ALARM	= 0x285,	// HID type SEL
	HID_CONSUMER_AC_SYNCHRONIZE	= 0x286,	// HID type SEL
	HID_CONSUMER_AC_SEND_SLASH_RECEIVE	= 0x287,	// HID type SEL
	HID_CONSUMER_AC_SEND_TO	= 0x288,	// HID type SEL
	HID_CONSUMER_AC_REPLY	= 0x289,	// HID type SEL
	HID_CONSUMER_AC_REPLY_ALL	= 0x28A,	// HID type SEL
	HID_CONSUMER_AC_FORWARD_MSG	= 0x28B,	// HID type SEL
	HID_CONSUMER_AC_SEND	= 0x28C,	// HID type SEL
	HID_CONSUMER_AC_ATTACH_FILE	= 0x28D,	// HID type SEL
	HID_CONSUMER_AC_UPLOAD	= 0x28E,	// HID type SEL
	HID_CONSUMER_AC_DOWNLOAD_SAVE_TARGET_AS	= 0x28F,	// HID type SEL
	HID_CONSUMER_AC_SET_BORDERS	= 0x290,	// HID type SEL
	HID_CONSUMER_AC_INSERT_ROW	= 0x291,	// HID type SEL
	HID_CONSUMER_AC_INSERT_COLUMN	= 0x292,	// HID type SEL
	HID_CONSUMER_AC_INSERT_FILE	= 0x293,	// HID type SEL
	HID_CONSUMER_AC_INSERT_PICTURE	= 0x294,	// HID type SEL
	HID_CONSUMER_AC_INSERT_OBJECT	= 0x295,	// HID type SEL
	HID_CONSUMER_AC_INSERT_SYMBOL	= 0x296,	// HID type SEL
	HID_CONSUMER_AC_SAVE_AND_CLOSE	= 0x297,	// HID type SEL
	HID_CONSUMER_AC_RENAME	= 0x298,	// HID type SEL
	HID_CONSUMER_AC_MERGE	= 0x299,	// HID type SEL
	HID_CONSUMER_AC_SPLIT	= 0x29A,	// HID type SEL
	HID_CONSUMER_AC_DISRIBUTE_HORIZONTALLY	= 0x29B,	// HID type SEL
	HID_CONSUMER_AC_DISTRIBUTE_VERTICALLY	= 0x29C,	// HID type SEL
};

enum SystemKeycode {
	SYSTEM_POWER_DOWN	= 0x81,
	SYSTEM_SLEEP	= 0x82,
	SYSTEM_WAKE_UP	= 0x83,

	// System control mappings
	HID_SYSTEM_UNASSIGNED		= 0x00,
	HID_SYSTEM_POWER_DOWN	= 0x81,	// HID type OSC
	HID_SYSTEM_SLEEP	= 0x82,	// HID type OSC
	HID_SYSTEM_WAKE_UP	= 0x83,	// HID type OSC
	HID_SYSTEM_CONTEXT_MENU	= 0x84,	// HID type OSC
	HID_SYSTEM_MAIN_MENU	= 0x85,	// HID type OSC
	HID_SYSTEM_APP_MENU	= 0x86,	// HID type OSC
	HID_SYSTEM_MENU_HELP	= 0x87,	// HID type OSC
	HID_SYSTEM_MENU_EXIT	= 0x88,	// HID type OSC
	HID_SYSTEM_MENU_SELECT	= 0x89,	// HID type OSC
	HID_SYSTEM_MENU_RIGHT	= 0x8A,	// HID type RTC
	HID_SYSTEM_MENU_LEFT	= 0x8B,	// HID type RTC
	HID_SYSTEM_MENU_UP	= 0x8C,	// HID type RTC
	HID_SYSTEM_MENU_DOWN	= 0x8D,	// HID type RTC
	HID_SYSTEM_COLD_RESTART	= 0x8E,	// HID type OSC
	HID_SYSTEM_WARM_RESTART	= 0x8F,	// HID type OSC
	HID_D_PAD_UP	= 0x90,	// HID type OOC
	HID_D_PAD_DOWN	= 0x91,	// HID type OOC
	HID_D_PAD_RIGHT	= 0x92,	// HID type OOC
	HID_D_PAD_LEFT	= 0x93,	// HID type OOC
	// 0x94-0x9F are reserved
	HID_SYSTEM_DOCK	= 0xA0,	// HID type OSC
	HID_SYSTEM_UNDOCK	= 0xA1,	// HID type OSC
	HID_SYSTEM_SETUP	= 0xA2,	// HID type OSC
	HID_SYSTEM_BREAK	= 0xA3,	// HID type OSC
	HID_SYSTEM_DEBUGGER_BREAK	= 0xA4,	// HID type OSC
	HID_APPLICATION_BREAK	= 0xA5,	// HID type OSC
	HID_APPLICATION_DEBUGGER_BREAK	= 0xA6,	// HID type OSC
	HID_SYSTEM_SPEAKER_MUTE	= 0xA7,	// HID type OSC
	HID_SYSTEM_HIBERNATE	= 0xA8,	// HID type OSC
	// 0xA9-0xAF are reserved
	HID_SYSTEM_DISPLAY_INVERT	= 0xB0,	// HID type OSC
	HID_SYSTEM_DISPLAY_INTERNAL	= 0xB1,	// HID type OSC
	HID_SYSTEM_DISPLAY_EXTERNAL	= 0xB2,	// HID type OSC
	HID_SYSTEM_DISPLAY_BOTH	= 0xB3,	// HID type OSC
	HID_SYSTEM_DISPLAY_DUAL	= 0xB4,	// HID type OSC
	HID_SYSTEM_DISPLAY_TOGGLE_INT_SLASH_EXT	= 0xB5,	// HID type OSC
	HID_SYSTEM_DISPLAY_SWAP_PRIMARY_SLASH_SECONDARY	= 0xB6,	// HID type OSC
	HID_SYSTEM_DISPLAY_LCD_AUTOSCALE	= 0xB7,	// HID type OSC
};

/* USB HID Keyboard/Keypad Usage(0x07) */
enum hid_keyboard_keypad_usage {
    KC_NO               = 0x00,
    KC_ROLL_OVER,
    KC_POST_FAIL,
    KC_UNDEFINED,
    KC_A,               /* 0x04 */
    KC_B,
    KC_C,
    KC_D,
    KC_E,
    KC_F,
    KC_G,
    KC_H,
    KC_I,
    KC_J,
    KC_K,
    KC_L,
    KC_M,               /* 0x10 */
    KC_N,
    KC_O,
    KC_P,
    KC_Q,
    KC_R,
    KC_S,
    KC_T,
    KC_U,
    KC_V,
    KC_W,
    KC_X,
    KC_Y,
    KC_Z,
    KC_1,
    KC_2,
    KC_3,               /* 0x20 */
    KC_4,
    KC_5,
    KC_6,
    KC_7,
    KC_8,
    KC_9,
    KC_0,
    KC_ENTER,
    KC_ESCAPE,
    KC_BSPACE,
    KC_TAB,
    KC_SPACE,
    KC_MINUS,
    KC_EQUAL,
    KC_LBRACKET,
    KC_RBRACKET,        /* 0x30 */
    KC_BSLASH,          /* \ (and |) */
    KC_NONUS_HASH,      /* Non-US # and ~ (Typically near the Enter key) */
    KC_SCOLON,          /* ; (and :) */
    KC_QUOTE,           /* ' and " */
    KC_GRAVE,           /* Grave accent and tilde */
    KC_COMMA,           /* , and < */
    KC_DOT,             /* . and > */
    KC_SLASH,           /* / and ? */
    KC_CAPSLOCK,
    KC_F1,
    KC_F2,
    KC_F3,
    KC_F4,
    KC_F5,
    KC_F6,
    KC_F7,              /* 0x40 */
    KC_F8,
    KC_F9,
    KC_F10,
    KC_F11,
    KC_F12,
    KC_PSCREEN,
    KC_SCROLLLOCK,
    KC_PAUSE,
    KC_INSERT,
    KC_HOME,
    KC_PGUP,
    KC_DELETE,
    KC_END,
    KC_PGDOWN,
    KC_RIGHT,
    KC_LEFT,            /* 0x50 */
    KC_DOWN,
    KC_UP,
    KC_NUMLOCK,
    KC_KP_SLASH,
    KC_KP_ASTERISK,
    KC_KP_MINUS,
    KC_KP_PLUS,
    KC_KP_ENTER,
    KC_KP_1,
    KC_KP_2,
    KC_KP_3,
    KC_KP_4,
    KC_KP_5,
    KC_KP_6,
    KC_KP_7,
    KC_KP_8,            /* 0x60 */
    KC_KP_9,
    KC_KP_0,
    KC_KP_DOT,
    KC_NONUS_BSLASH,    /* Non-US \ and | (Typically near the Left-Shift key) */
    KC_APPLICATION,

    // Most of the following keys will only work with Linux or not at all.
    // F13+ keys are mostly used for laptop functions like ECO key.
    KC_POWER,
    KC_KP_EQUAL,
    KC_F13,
    KC_F14,
    KC_F15,
    KC_F16,
    KC_F17,
    KC_F18,
    KC_F19,
    KC_F20,
    KC_F21,             /* 0x70 */
    KC_F22,
    KC_F23,
    KC_F24,
    KC_EXECUTE,
    KC_HELP,
    KC_MENU,
    KC_SELECT,
    KC_STOP,
    KC_AGAIN,
    KC_UNDO,
    KC_CUT,
    KC_COPY,
    KC_PASTE,
    KC_FIND,
    KC__MUTE,
    KC__VOLUP,          /* 0x80 */
    KC__VOLDOWN,
    KC_LOCKING_CAPS,    /* locking Caps Lock */
    KC_LOCKING_NUM,     /* locking Num Lock */
    KC_LOCKING_SCROLL,  /* locking Scroll Lock */
    KC_KP_COMMA,
    KC_KP_EQUAL_AS400,  /* equal sign on AS/400 */
    KC_INT1,
    KC_INT2,
    KC_INT3,
    KC_INT4,
    KC_INT5,
    KC_INT6,
    KC_INT7,
    KC_INT8,
    KC_INT9,
    KC_LANG1,           /* 0x90 */
    KC_LANG2,
    KC_LANG3,
    KC_LANG4,
    KC_LANG5,
    KC_LANG6,
    KC_LANG7,
    KC_LANG8,
    KC_LANG9,
    KC_ALT_ERASE,
    KC_SYSREQ,
    KC_CANCEL,
    KC_CLEAR,
    KC_PRIOR,
    KC_RETURN,
    KC_SEPARATOR,
    KC_OUT,             /* 0xA0 */
    KC_OPER,
    KC_CLEAR_AGAIN,
    KC_CRSEL,
    KC_EXSEL,           /* 0xA4 */

    /* NOTE: Following code range(0xB0-DD) are shared with special codes of 8-bit keymap */
    KC_KP_00            = 0xB0,
    KC_KP_000,
    KC_THOUSANDS_SEPARATOR,
    KC_DECIMAL_SEPARATOR,
    KC_CURRENCY_UNIT,
    KC_CURRENCY_SUB_UNIT,
    KC_KP_LPAREN,
    KC_KP_RPAREN,
    KC_KP_LCBRACKET,    /* { */
    KC_KP_RCBRACKET,    /* } */
    KC_KP_TAB,
    KC_KP_BSPACE,
    KC_KP_A,
    KC_KP_B,
    KC_KP_C,
    KC_KP_D,
    KC_KP_E,            /* 0xC0 */
    KC_KP_F,
    KC_KP_XOR,
    KC_KP_HAT,
    KC_KP_PERC,
    KC_KP_LT,
    KC_KP_GT,
    KC_KP_AND,
    KC_KP_LAZYAND,
    KC_KP_OR,
    KC_KP_LAZYOR,
    KC_KP_COLON,
    KC_KP_HASH,
    KC_KP_SPACE,
    KC_KP_ATMARK,
    KC_KP_EXCLAMATION,
    KC_KP_MEM_STORE,    /* 0xD0 */
    KC_KP_MEM_RECALL,
    KC_KP_MEM_CLEAR,
    KC_KP_MEM_ADD,
    KC_KP_MEM_SUB,
    KC_KP_MEM_MUL,
    KC_KP_MEM_DIV,
    KC_KP_PLUS_MINUS,
    KC_KP_CLEAR,
    KC_KP_CLEAR_ENTRY,
    KC_KP_BINARY,
    KC_KP_OCTAL,
    KC_KP_DECIMAL,
    KC_KP_HEXADECIMAL,  /* 0xDD */

    /* Modifiers */
    KC_LCTRL            = 0xE0,
    KC_LSHIFT,
    KC_LALT,
    KC_LGUI,
    KC_RCTRL,
    KC_RSHIFT,
    KC_RALT,
    KC_RGUI,            /* 0xE7 */
};

/* Special keycodes for 8-bit keymap
   NOTE: 0xA5-DF and 0xE8-FF are used for internal special purpose */
enum internal_special_keycodes {
    /* System Control */
    KC_SYSTEM_POWER     = 0xA5,
    KC_SYSTEM_SLEEP,
    KC_SYSTEM_WAKE,

    /* Media Control */
    KC_AUDIO_MUTE,
    KC_AUDIO_VOL_UP,
    KC_AUDIO_VOL_DOWN,
    KC_MEDIA_NEXT_TRACK,
    KC_MEDIA_PREV_TRACK,
    KC_MEDIA_FAST_FORWARD,
    KC_MEDIA_REWIND,
    KC_MEDIA_STOP,
    KC_MEDIA_PLAY_PAUSE,
    KC_MEDIA_EJECT,
    KC_MEDIA_SELECT,
    KC_MAIL,
    KC_CALCULATOR,
    KC_MY_COMPUTER,
    KC_WWW_SEARCH,
    KC_WWW_HOME,
    KC_WWW_BACK,
    KC_WWW_FORWARD,
    KC_WWW_STOP,
    KC_WWW_REFRESH,
    KC_WWW_FAVORITES,    /* 0xBC */

    KC_BRIGHTNESS_UP,
    KC_BRIGHTNESS_DOWN,

    /* Jump to bootloader */
    KC_BOOTLOADER       = 0xBF,

    /* Fn key */
    KC_FN0              = 0xC0,
    KC_FN1,
    KC_FN2,
    KC_FN3,
    KC_FN4,
    KC_FN5,
    KC_FN6,
    KC_FN7,
    KC_FN8,
    KC_FN9,
    KC_FN10,
    KC_FN11,
    KC_FN12,
    KC_FN13,
    KC_FN14,
    KC_FN15,

    KC_FN16             = 0xD0,
    KC_FN17,
    KC_FN18,
    KC_FN19,
    KC_FN20,
    KC_FN21,
    KC_FN22,
    KC_FN23,
    KC_FN24,
    KC_FN25,
    KC_FN26,
    KC_FN27,
    KC_FN28,
    KC_FN29,
    KC_FN30,
    KC_FN31,            /* 0xDF */

    /**************************************/
    /* 0xE0-E7 for Modifiers. DO NOT USE. */
    /**************************************/

    /* Mousekey */
    KC_MS_UP            = 0xF0,
    KC_MS_DOWN,
    KC_MS_LEFT,
    KC_MS_RIGHT,
    KC_MS_BTN1,
    KC_MS_BTN2,
    KC_MS_BTN3,
    KC_MS_BTN4,
    KC_MS_BTN5,         /* 0xF8 */
    /* Mousekey wheel */
    KC_MS_WH_UP,
    KC_MS_WH_DOWN,
    KC_MS_WH_LEFT,
    KC_MS_WH_RIGHT,     /* 0xFC */
    /* Mousekey accel */
    KC_MS_ACCEL0,
    KC_MS_ACCEL1,
    KC_MS_ACCEL2        /* 0xFF */
};

/* application launch */
#define APPLAUNCH_CC_CONFIG     0x0183
#define APPLAUNCH_EMAIL         0x018A
#define APPLAUNCH_CALCULATOR    0x0192
#define APPLAUNCH_LOCAL_BROWSER 0x0194
/* application control */
#define APPCONTROL_SEARCH       0x0221
#define APPCONTROL_HOME         0x0223
#define APPCONTROL_BACK         0x0224
#define APPCONTROL_FORWARD      0x0225
#define APPCONTROL_STOP         0x0226
#define APPCONTROL_REFRESH      0x0227
#define APPCONTROL_BOOKMARKS    0x022A

/* keycode to system usage */
#define KEYCODE2SYSTEM(key) \
    (key == KC_SYSTEM_POWER ? SYSTEM_POWER_DOWN : \
    (key == KC_SYSTEM_SLEEP ? SYSTEM_SLEEP : \
    (key == KC_SYSTEM_WAKE  ? SYSTEM_WAKE_UP : 0)))

/* keycode to consumer usage */
#define KEYCODE2CONSUMER(key) \
    (key == KC_AUDIO_MUTE           ?  MEDIA_VOL_MUTE : \
    (key == KC_AUDIO_VOL_UP         ?  MEDIA_VOL_UP : \
    (key == KC_AUDIO_VOL_DOWN       ?  MEDIA_VOL_DOWN : \
    (key == KC_MEDIA_NEXT_TRACK     ?  MEDIA_NEXT : \
    (key == KC_MEDIA_PREV_TRACK     ?  MEDIA_PREV : \
    (key == KC_MEDIA_FAST_FORWARD   ?  MEDIA_FAST_FORWARD : \
    (key == KC_MEDIA_REWIND         ?  MEDIA_REWIND : \
    (key == KC_MEDIA_STOP           ?  MEDIA_STOP : \
    (key == KC_MEDIA_EJECT          ?  MEDIA_STOP : \
    (key == KC_MEDIA_PLAY_PAUSE     ?  MEDIA_PLAY_PAUSE : \
    (key == KC_MEDIA_SELECT         ?  APPLAUNCH_CC_CONFIG : \
    (key == KC_MAIL                 ?  APPLAUNCH_EMAIL : \
    (key == KC_CALCULATOR           ?  APPLAUNCH_CALCULATOR : \
    (key == KC_MY_COMPUTER          ?  APPLAUNCH_LOCAL_BROWSER : \
    (key == KC_WWW_SEARCH           ?  APPCONTROL_SEARCH : \
    (key == KC_WWW_HOME             ?  APPCONTROL_HOME : \
    (key == KC_WWW_BACK             ?  APPCONTROL_BACK : \
    (key == KC_WWW_FORWARD          ?  APPCONTROL_FORWARD : \
    (key == KC_WWW_STOP             ?  APPCONTROL_STOP : \
    (key == KC_WWW_REFRESH          ?  APPCONTROL_REFRESH : \
    (key == KC_WWW_FAVORITES        ?  APPCONTROL_BOOKMARKS : \
    (key == KC_BRIGHTNESS_UP        ?  CONSUMER_BRIGHTNESS_UP : \
    (key == KC_BRIGHTNESS_DOWN      ?  CONSUMER_BRIGHTNESS_DOWN : 0)))))))))))))))))))))))

#endif /* KEYCODE_H */
