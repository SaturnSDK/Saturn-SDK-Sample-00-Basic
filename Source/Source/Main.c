#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define USB_FIFO	( *( volatile uint8_t * )( 0x22100001 ) )
#define USB_FLAGS	( *( volatile uint8_t * )( 0x22200001 ) )
#define USB_TXE		( 1 << 1 )
#define WAIT_FOR_WRITE_FIFO( ) do { while( ( USB_FLAGS & USB_TXE ) ); }while( 0 )

#define SMPC_COMREG	( *( volatile uint8_t * )( 0x2010001F ) )
#define SMPC_SR		( *( volatile uint8_t * )( 0x20100061 ) )
#define SMPC_SF		( *( volatile uint8_t * )( 0x20100063 ) )

#define SMPC_IREG0	( *( volatile uint8_t * )( 0x20100001 ) )
#define SMPC_IREG1	( *( volatile uint8_t * )( 0x20100003 ) )
#define SMPC_IREG2	( *( volatile uint8_t * )( 0x20100005 ) )
#define SMPC_IREG3	( *( volatile uint8_t * )( 0x20100007 ) )
#define SMPC_IREG4	( *( volatile uint8_t * )( 0x20100009 ) )
#define SMPC_IREG5	( *( volatile uint8_t * )( 0x2010000B ) )
#define SMPC_IREG6	( *( volatile uint8_t * )( 0x2000000D ) )

#define SMPC_OREG0	( *( volatile uint8_t * )( 0x20100021 ) )
#define SMPC_OREG1	( *( volatile uint8_t * )( 0x20100023 ) )
#define SMPC_OREG2	( *( volatile uint8_t * )( 0x20100025 ) )
#define SMPC_OREG3	( *( volatile uint8_t * )( 0x20100027 ) )
#define SMPC_OREG4	( *( volatile uint8_t * )( 0x20100029 ) )
#define SMPC_OREG5	( *( volatile uint8_t * )( 0x2010002B ) )
#define SMPC_OREG6	( *( volatile uint8_t * )( 0x2010002D ) )
#define SMPC_OREG7	( *( volatile uint8_t * )( 0x2010002F ) )
#define SMPC_OREG8	( *( volatile uint8_t * )( 0x20100031 ) )
#define SMPC_OREG9	( *( volatile uint8_t * )( 0x20100033 ) )
#define SMPC_OREG10	( *( volatile uint8_t * )( 0x20100035 ) )
#define SMPC_OREG11	( *( volatile uint8_t * )( 0x20100037 ) )
#define SMPC_OREG12	( *( volatile uint8_t * )( 0x20100039 ) )
#define SMPC_OREG13	( *( volatile uint8_t * )( 0x2010003B ) )
#define SMPC_OREG14	( *( volatile uint8_t * )( 0x2010003D ) )
#define SMPC_OREG15	( *( volatile uint8_t * )( 0x2010003F ) )
#define SMPC_OREG16	( *( volatile uint8_t * )( 0x20100041 ) )
#define SMPC_OREG17	( *( volatile uint8_t * )( 0x20100043 ) )
#define SMPC_OREG18	( *( volatile uint8_t * )( 0x20100045 ) )
#define SMPC_OREG19	( *( volatile uint8_t * )( 0x20100047 ) )
#define SMPC_OREG20	( *( volatile uint8_t * )( 0x20100049 ) )
#define SMPC_OREG21	( *( volatile uint8_t * )( 0x2010004B ) )
#define SMPC_OREG22	( *( volatile uint8_t * )( 0x2010004D ) )
#define SMPC_OREG23	( *( volatile uint8_t * )( 0x2010004F ) )
#define SMPC_OREG24	( *( volatile uint8_t * )( 0x20100051 ) )
#define SMPC_OREG25	( *( volatile uint8_t * )( 0x20100053 ) )
#define SMPC_OREG26	( *( volatile uint8_t * )( 0x20100055 ) )
#define SMPC_OREG27	( *( volatile uint8_t * )( 0x20100057 ) )
#define SMPC_OREG28	( *( volatile uint8_t * )( 0x20100059 ) )
#define SMPC_OREG29	( *( volatile uint8_t * )( 0x2010005B ) )
#define SMPC_OREG30	( *( volatile uint8_t * )( 0x2010005D ) )
#define SMPC_OREG31	( *( volatile uint8_t * )( 0x2010005F ) )

#define SMPC_PDR1	( *( volatile uint8_t * )( 0x20100075 ) )
#define SMPC_PDR2	( *( volatile uint8_t * )( 0x20100077 ) )
#define SMPC_DDR1	( *( volatile uint8_t * )( 0x20100079 ) )
#define SMPC_DDR2	( *( volatile uint8_t * )( 0x2010007B ) )
#define SMPC_IOSEL	( *( volatile uint8_t * )( 0x2010007D ) )
#define SMPC_EXLE	( *( volatile uint8_t * )( 0x2010007F ) )

#define PER_DELAY	16
#define PER_LBUTTON	( 1 << 15 )
#define PER_RBUTTON ( 1 << 3 )
#define PER_X		( 1 << 2 )
#define PER_Y		( 1 << 1 )
#define PER_Z		( 1 << 0 )
#define PER_START	( 1 << 11 )
#define PER_A		( 1 << 10 )
#define PER_B		( 1 << 8 )
#define PER_C		( 1 << 9 )
#define PER_RIGHT	( 1 << 7 )
#define PER_LEFT	( 1 << 6 )
#define PER_DOWN	( 1 << 5 )
#define PER_UP		( 1 << 4 )

/* VDP1 */
/* Base address of VDP1 */
#define VDP1_BASE	0x25C00000
#define VDP1_VRAM	( *( volatile uint16_t * )( VDP1_BASE ) )
/* TV mode selection */
#define VDP1_TVMR	( *( volatile uint16_t * )( VDP1_BASE + 0x100000 ) )
/* Frame buffer switch mode */
#define VDP1_FBCR	( *( volatile uint16_t * )( VDP1_BASE + 0x100002 ) )
/* Plot trigger */
#define VDP1_PTMR	( *( volatile uint16_t * )( VDP1_BASE + 0x100004 ) )
/* Erase/Write data */
#define VDP1_EWDR	( *( volatile uint16_t * )( VDP1_BASE + 0x100006 ) )
/* Erase/Write upper-left coordinate */
#define VDP1_EWUL	( *( volatile uint16_t * )( VDP1_BASE + 0x100008 ) )
/* Erase/Write lower-right coordinate */
#define VDP1_EWLR	( *( volatile uint16_t * )( VDP1_BASE + 0x10000A ) )
/* Plot abnormal end */
#define VDP1_ENDR	( *( volatile uint16_t * )( VDP1_BASE + 0x10000C ) )
/* Transfer end status */
#define VDP1_EDSR	( *( volatile uint16_t * )( VDP1_BASE + 0x100010 ) )
/* Last operation command address */
#define VDP1_LOCR	( *( volatile uint16_t * )( VDP1_BASE + 0x100012 ) )
/* Current operation command address */
#define VDP1_COCR	( *( volatile uint16_t * )( VDP1_BASE + 0x100014 ) )
/* Mode status */
#define VDP1_MODR	( *( volatile uint16_t * )( VDP1_BASE + 0x100016 ) )


/* VDP2 */
#define VDP2_BASE	0x25E00000
#define VDP2_VRAM	VDP2_BASE
#define VDP2_CRAM	VDP2_BASE + 0x100000
#define VDP2_REG	VDP2_BASE + 0x180000
#define VDP2_TVMD	( *( volatile uint16_t * )( 0x25F80000 ) )
#define VDP2_TVSTAT	( *( volatile uint16_t * )( 0x25F80004 ) )

/* Pointer access to VDP2 addresses */
volatile uint16_t *VDP2_VRAM_PTR	= ( volatile uint16_t * )( VDP2_VRAM );
volatile uint16_t *VDP2_CRAM_PTR	= ( volatile uint16_t * )( VDP2_CRAM );
volatile uint16_t *VDP2_REG_PTR		= ( volatile uint16_t * )( VDP2_REG );

/* SCU */
#define SCU_INMR	( *( volatile uint32_t * )( 0x25FE009C ) )
#define SCU_INSR	( *( volatile const uint32_t * )( 0x25FE00A0 ) )
#define SCU_VERR	( *( volatile uint32_t * )( 0x25FE00C8 ) )

#define SCU_SETINT( p_Int, p_Func ) \
	( ( **( volatile void( ** )( uint32_t, void * ) )0x6000300 )( ( p_Int ), ( p_Func ) ) )
#define SCU_GETINT( p_Int ) \
	( ( void * )( **( void( * ( ** )( uint32_t ) )( uint32_t ) ) 0x6000304 )( p_Int ) )


/* Resetable system management commands */
const uint8_t SMPC_COMMAND_MSHON		= 0x00;
const uint8_t SMPC_COMMAND_SSHON		= 0x02;
const uint8_t SMPC_COMMAND_SSHOFF		= 0x03;
const uint8_t SMPC_COMMAND_SNDON		= 0x06;
const uint8_t SMPC_COMMAND_SNDOFF		= 0x07;
const uint8_t SMPC_COMMAND_RESET		= 0x0D;
const uint8_t SMPC_COMMAND_CLKCHG352	= 0x0E;
const uint8_t SMPC_COMMAND_CLKCHG320	= 0x0F;
const uint8_t SMPC_COMMAND_NMIREQ		= 0x18;
const uint8_t SMPC_COMMAND_RESETENAB	= 0x19;
const uint8_t SMPC_COMMAND_RESETDISA	= 0x1A;

/* Non-resetable system management commands */
const uint8_t SMPC_COMMAND_INTBACK		= 0x10;
const uint8_t SMPC_COMMAND_SETSMEM		= 0x17;

/* RTC */
const uint8_t SMPC_COMMAND_SETTIME		= 0x16;

/* INTBACK */
const uint8_t SMPC_IREG0_PERONLY	= 0x00;
const uint8_t SMPC_IREG1_PEN		= 1 << 3;
const uint8_t SMPC_IREG2_INTBACK	= 0xF0;
const uint8_t SMPC_IREG0_CONT		= 1 << 7;
const uint8_t SMPC_IREG0_BREAK		= 1 << 6;
const uint8_t SMPC_PORT1_15			= 0xCF;
const uint8_t SMPC_PORT1_255		= 0xEF;
const uint8_t SMPC_PORT1_0			= 0xFF;
const uint8_t SMPC_PORT2_15			= 0x3F;
const uint8_t SMPC_PORT2_255		= 0x7F;
const uint8_t SMPC_PORT2_0			= 0xFF;

/* Debug functions */
void StringOut( const char *p_pString );
void CON_Initialize( void );
void CON_PrintChar( int p_X, int p_Y, uint8_t p_Color, char p_Char );
void CON_Print( int p_X, int p_Y, uint8_t p_Color, char *p_pString );

/* Font */
uint16_t FON_Palette [ 256 ] =
{
	0x0000, 0x5400, 0x02A0, 0x56A0, 0x0015, 0x5415, 0x0155, 0x56B5,
	0x294A, 0x7D4A, 0x2BEA, 0x7FEA, 0x295F, 0x7D5F, 0x2BFF, 0x7FFF,
	0x0000, 0x0842, 0x1084, 0x14A5, 0x1CE7, 0x2108, 0x294A, 0x318C,
	0x39CE, 0x4210, 0x4A52, 0x5294, 0x5AD6, 0x6739, 0x739C, 0x7FFF, 
	0x7C00, 0x7C08, 0x7C0F, 0x7C17, 0x7C1F, 0x5C1F, 0x3C1F, 0x201F,
	0x001F, 0x011F, 0x01FF, 0x02FF, 0x03FF, 0x03F7, 0x03EF, 0x03E8, 
	0x03E0, 0x23E0, 0x3FE0, 0x5FE0, 0x7FE0, 0x7EE0, 0x7DE0, 0x7D00,
	0x7DEF, 0x7DF3, 0x7DF7, 0x7DFB, 0x7DFF, 0x6DFF, 0x5DFF, 0x4DFF, 
	0x3DFF, 0x3E7F, 0x3EFF, 0x3F7F, 0x3FFF, 0x3FFB, 0x3FF7, 0x3FF3,
	0x3FEF, 0x4FEF, 0x5FEF, 0x6FEF, 0x7FEF, 0x7F6F, 0x7EEF, 0x7E6F, 
	0x7ED6, 0x7ED8, 0x7EDB, 0x7EDD, 0x7EDF, 0x76DF, 0x6EDF, 0x62DF,
	0x5ADF, 0x5B1F, 0x5B7F, 0x5BBF, 0x5BFF, 0x5BFD, 0x5BFB, 0x5BF8, 
	0x5BF6, 0x63F6, 0x6FF6, 0x77F6, 0x7FF6, 0x7FB6, 0x7F76, 0x7F16,
	0x3800, 0x3803, 0x3807, 0x380A, 0x380E, 0x280E, 0x1C0E, 0x0C0E, 
	0x000E, 0x006E, 0x00EE, 0x014E, 0x01CE, 0x01CA, 0x01C7, 0x01C3,
	0x01C0, 0x0DC0, 0x1DC0, 0x29C0, 0x39C0, 0x3940, 0x38E0, 0x3860, 
	0x38E7, 0x38E8, 0x38EA, 0x38EC, 0x38EE, 0x30EE, 0x28EE, 0x20EE,
	0x1CEE, 0x1D0E, 0x1D4E, 0x1D8E, 0x1DCE, 0x1DCC, 0x1DCA, 0x1DC8, 
	0x1DC7, 0x21C7, 0x29C7, 0x31C7, 0x39C7, 0x3987, 0x3947, 0x3907,
	0x394A, 0x394B, 0x394C, 0x394D, 0x394E, 0x354E, 0x314E, 0x2D4E, 
	0x294E, 0x296E, 0x298E, 0x29AE, 0x29CE, 0x29CD, 0x29CC, 0x29CB,
	0x29CA, 0x2DCA, 0x31CA, 0x35CA, 0x39CA, 0x39AA, 0x398A, 0x396A, 
	0x2000, 0x2002, 0x2004, 0x2006, 0x2008, 0x1808, 0x1008, 0x0808,
	0x0008, 0x0048, 0x0088, 0x00C8, 0x0108, 0x0106, 0x0104, 0x0102,
	0x0100, 0x0900, 0x1100, 0x1900, 0x2100, 0x20C0, 0x2080, 0x2040,
	0x2084, 0x2085, 0x2086, 0x2087, 0x2088, 0x1C88, 0x1888, 0x1488, 
	0x1088, 0x10A8, 0x10C8, 0x10E8, 0x1108, 0x1107, 0x1106, 0x1105,
	0x1104, 0x1504, 0x1904, 0x1D04, 0x2104, 0x20E4, 0x20C4, 0x20A4, 
	0x20A5, 0x20A6, 0x20A6, 0x20A7, 0x20A8, 0x1CA8, 0x18A8, 0x18A8,
	0x14A8, 0x14C8, 0x14C8, 0x14E8, 0x1508, 0x1507, 0x1506, 0x1506, 
    0x1505, 0x1905, 0x1905, 0x1D05, 0x2105, 0x20E5, 0x20C5, 0x20C5,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

uint8_t FON_Font [ ] =
{
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x7E, 0x81, 0xA5, 0x81, 0xBD, 0x99, 0x81, 0x7E,
	 0x7E, 0xFF, 0xDB, 0xFF, 0xC3, 0xE7, 0xFF, 0x7E,
	 0x6C, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x10, 0x00,
	 0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x10, 0x00,
	 0x38, 0x7C, 0x38, 0xFE, 0xFE, 0x7C, 0x38, 0x7C,
	 0x10, 0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x7C,
	 0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00,
	 0xFF, 0xFF, 0xE7, 0xC3, 0xC3, 0xE7, 0xFF, 0xFF,
	 0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00,
	 0xFF, 0xC3, 0x99, 0xBD, 0xBD, 0x99, 0xC3, 0xFF,
	 0x0F, 0x07, 0x0F, 0x7D, 0xCC, 0xCC, 0xCC, 0x78,
	 0x3C, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x7E, 0x18,
	 0x3F, 0x33, 0x3F, 0x30, 0x30, 0x70, 0xF0, 0xE0,
	 0x7F, 0x63, 0x7F, 0x63, 0x63, 0x67, 0xE6, 0xC0,
	 0x99, 0x5A, 0x3C, 0xE7, 0xE7, 0x3C, 0x5A, 0x99,
	 0x80, 0xE0, 0xF8, 0xFE, 0xF8, 0xE0, 0x80, 0x00,
	 0x02, 0x0E, 0x3E, 0xFE, 0x3E, 0x0E, 0x02, 0x00,
	 0x18, 0x3C, 0x7E, 0x18, 0x18, 0x7E, 0x3C, 0x18,
	 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x00,
	 0x7F, 0xDB, 0xDB, 0x7B, 0x1B, 0x1B, 0x1B, 0x00,
	 0x3E, 0x63, 0x38, 0x6C, 0x6C, 0x38, 0xCC, 0x78,
	 0x00, 0x00, 0x00, 0x00, 0x7E, 0x7E, 0x7E, 0x00,
	 0x18, 0x3C, 0x7E, 0x18, 0x7E, 0x3C, 0x18, 0xFF,
	 0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00,
	 0x18, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00,
	 0x00, 0x18, 0x0C, 0xFE, 0x0C, 0x18, 0x00, 0x00,
	 0x00, 0x30, 0x60, 0xFE, 0x60, 0x30, 0x00, 0x00,
	 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xFE, 0x00, 0x00,
	 0x00, 0x24, 0x66, 0xFF, 0x66, 0x24, 0x00, 0x00,
	 0x00, 0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x00, 0x00,
	 0x00, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x30, 0x78, 0x78, 0x78, 0x30, 0x00, 0x30, 0x00,
	 0x6C, 0x6C, 0x6C, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x6C, 0x6C, 0xFE, 0x6C, 0xFE, 0x6C, 0x6C, 0x00,
	 0x30, 0x7C, 0xC0, 0x78, 0x0C, 0xF8, 0x30, 0x00,
	 0x00, 0xC6, 0xCC, 0x18, 0x30, 0x66, 0xC6, 0x00,
	 0x38, 0x6C, 0x38, 0x76, 0xDC, 0xCC, 0x76, 0x00,
	 0x60, 0x60, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x18, 0x30, 0x60, 0x60, 0x60, 0x30, 0x18, 0x00,
	 0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00,
	 0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00,
	 0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60,
	 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00,
	 0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x80, 0x00,
	 0x7C, 0xC6, 0xCE, 0xDE, 0xF6, 0xE6, 0x7C, 0x00,
	 0x30, 0x70, 0x30, 0x30, 0x30, 0x30, 0xFC, 0x00,
	 0x78, 0xCC, 0x0C, 0x38, 0x60, 0xCC, 0xFC, 0x00,
	 0x78, 0xCC, 0x0C, 0x38, 0x0C, 0xCC, 0x78, 0x00,
	 0x1C, 0x3C, 0x6C, 0xCC, 0xFE, 0x0C, 0x1E, 0x00,
	 0xFC, 0xC0, 0xF8, 0x0C, 0x0C, 0xCC, 0x78, 0x00,
	 0x38, 0x60, 0xC0, 0xF8, 0xCC, 0xCC, 0x78, 0x00,
	 0xFC, 0xCC, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00,
	 0x78, 0xCC, 0xCC, 0x78, 0xCC, 0xCC, 0x78, 0x00,
	 0x78, 0xCC, 0xCC, 0x7C, 0x0C, 0x18, 0x70, 0x00,
	 0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00,
	 0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x60,
	 0x18, 0x30, 0x60, 0xC0, 0x60, 0x30, 0x18, 0x00,
	 0x00, 0x00, 0xFC, 0x00, 0x00, 0xFC, 0x00, 0x00,
	 0x60, 0x30, 0x18, 0x0C, 0x18, 0x30, 0x60, 0x00,
	 0x78, 0xCC, 0x0C, 0x18, 0x30, 0x00, 0x30, 0x00,
	 0x7C, 0xC6, 0xDE, 0xDE, 0xDE, 0xC0, 0x78, 0x00,
	 0x30, 0x78, 0xCC, 0xCC, 0xFC, 0xCC, 0xCC, 0x00,
	 0xFC, 0x66, 0x66, 0x7C, 0x66, 0x66, 0xFC, 0x00,
	 0x3C, 0x66, 0xC0, 0xC0, 0xC0, 0x66, 0x3C, 0x00,
	 0xF8, 0x6C, 0x66, 0x66, 0x66, 0x6C, 0xF8, 0x00,
	 0x7E, 0x60, 0x60, 0x78, 0x60, 0x60, 0x7E, 0x00,
	 0x7E, 0x60, 0x60, 0x78, 0x60, 0x60, 0x60, 0x00,
	 0x3C, 0x66, 0xC0, 0xC0, 0xCE, 0x66, 0x3E, 0x00,
	 0xCC, 0xCC, 0xCC, 0xFC, 0xCC, 0xCC, 0xCC, 0x00,
	 0x78, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00,
	 0x1E, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78, 0x00,
	 0xE6, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0xE6, 0x00,
	 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x00,
	 0xC6, 0xEE, 0xFE, 0xFE, 0xD6, 0xC6, 0xC6, 0x00,
	 0xC6, 0xE6, 0xF6, 0xDE, 0xCE, 0xC6, 0xC6, 0x00,
	 0x38, 0x6C, 0xC6, 0xC6, 0xC6, 0x6C, 0x38, 0x00,
	 0xFC, 0x66, 0x66, 0x7C, 0x60, 0x60, 0xF0, 0x00,
	 0x78, 0xCC, 0xCC, 0xCC, 0xDC, 0x78, 0x1C, 0x00,
	 0xFC, 0x66, 0x66, 0x7C, 0x6C, 0x66, 0xE6, 0x00,
	 0x78, 0xCC, 0xE0, 0x70, 0x1C, 0xCC, 0x78, 0x00,
	 0xFC, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00,
	 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFC, 0x00,
	 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x00,
	 0xC6, 0xC6, 0xC6, 0xD6, 0xFE, 0xEE, 0xC6, 0x00,
	 0xC6, 0xC6, 0x6C, 0x38, 0x38, 0x6C, 0xC6, 0x00,
	 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x30, 0x78, 0x00,
	 0xFE, 0x06, 0x0C, 0x18, 0x30, 0x60, 0xFE, 0x00,
	 0x78, 0x60, 0x60, 0x60, 0x60, 0x60, 0x78, 0x00,
	 0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x02, 0x00,
	 0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00,
	 0x10, 0x38, 0x6C, 0xC6, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
	 0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x78, 0x0C, 0x7C, 0xCC, 0x76, 0x00,
	 0xE0, 0x60, 0x60, 0x7C, 0x66, 0x66, 0xDC, 0x00,
	 0x00, 0x00, 0x78, 0xCC, 0xC0, 0xCC, 0x78, 0x00,
	 0x1C, 0x0C, 0x0C, 0x7C, 0xCC, 0xCC, 0x76, 0x00,
	 0x00, 0x00, 0x78, 0xCC, 0xFC, 0xC0, 0x78, 0x00,
	 0x38, 0x6C, 0x60, 0xF0, 0x60, 0x60, 0xF0, 0x00,
	 0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0xF8,
	 0xE0, 0x60, 0x6C, 0x76, 0x66, 0x66, 0xE6, 0x00,
	 0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00,
	 0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78,
	 0xE0, 0x60, 0x66, 0x6C, 0x78, 0x6C, 0xE6, 0x00,
	 0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00,
	 0x00, 0x00, 0xCC, 0xFE, 0xFE, 0xD6, 0xC6, 0x00,
	 0x00, 0x00, 0xF8, 0xCC, 0xCC, 0xCC, 0xCC, 0x00,
	 0x00, 0x00, 0x78, 0xCC, 0xCC, 0xCC, 0x78, 0x00,
	 0x00, 0x00, 0xDC, 0x66, 0x66, 0x7C, 0x60, 0xF0,
	 0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0x1E,
	 0x00, 0x00, 0xDC, 0x76, 0x66, 0x60, 0xF0, 0x00,
	 0x00, 0x00, 0x7C, 0xC0, 0x78, 0x0C, 0xF8, 0x00,
	 0x10, 0x30, 0x7C, 0x30, 0x30, 0x34, 0x18, 0x00,
	 0x00, 0x00, 0xCC, 0xCC, 0xCC, 0xCC, 0x76, 0x00,
	 0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x00,
	 0x00, 0x00, 0xC6, 0xD6, 0xFE, 0xFE, 0x6C, 0x00,
	 0x00, 0x00, 0xC6, 0x6C, 0x38, 0x6C, 0xC6, 0x00,
	 0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x7C, 0x0C, 0xF8,
	 0x00, 0x00, 0xFC, 0x98, 0x30, 0x64, 0xFC, 0x00,
	 0x1C, 0x30, 0x30, 0xE0, 0x30, 0x30, 0x1C, 0x00,
	 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00,
	 0xE0, 0x30, 0x30, 0x1C, 0x30, 0x30, 0xE0, 0x00,
     0x76, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x10, 0x38, 0x6C, 0xC6, 0xC6, 0xFE, 0x00
};

/* Peripheral functions */
void PER_Initialize( void );
void PER_Shutdown( void );
uint16_t PER_Read( int p_Index );

/* VDP functions */
void VDP_Initialize( void );
void VDP_Shutdown( void );
void VDP2_SetBackgroundColor( uint8_t p_Red, uint8_t p_Green, uint8_t p_Blue );

/* Polling V-Blank and H-Blank */
void WaitHBlankOut( void );
void WaitHBlankIn( void );
void WaitVBlankOut( void );
void WaitVBlankIn( void );
void WaitHBlank( void );
void WaitVBlank( void );

uint16_t Color16( uint8_t p_Red, uint8_t p_Green, uint8_t p_Blue );

void main( void )
{
	unsigned char *pDestination;
	unsigned int Index;
	uint32_t VInt;
	uint16_t PadNew, PadOld, PadDelta;
	uint16_t Red = 3, Green = 11, Blue = 19;
	uint32_t FrameCount = 0U;

	VDP_Initialize( );
	PER_Initialize( );
	CON_Initialize( );

	StringOut( "SEGA Saturn SDK Sample 00 - Basic\n" );

	VDP1_TVMR = 0x0000;
	VDP1_FBCR = 0x0000;
	VDP1_PTMR = 0x0002;
	VDP1_EWUL = 0x0000;
	VDP1_EWLR = 0x28EF;
	VDP1_EWDR = Color16( 31, 31, 31 );

	VDP2_TVMD = 0x8000;

	PadNew = 0x0000;
	PadOld = 0x0000;

	/* First color in VRAM set to a SEGA blue */
	VDP2_SetBackgroundColor( 3, 11, 19 );

	CON_Print( 2, 1, 0xF0, "Buttons" );
	CON_Print( 2, 2, 0xF0, "Start - Reset SEGA Saturn" );
	CON_Print( 2, 3, 0xF0, "A     - Increase red color" );
	CON_Print( 2, 4, 0xF0, "B     - Increase green color" );
	CON_Print( 2, 5, 0xF0, "C     - Increase blue color" );
	CON_Print( 2, 6, 0xF0, "X     - Decrease red color" );
	CON_Print( 2, 7, 0xF0, "Y     - Decrease green color" );
	CON_Print( 2, 8, 0xF0, "Z     - Decrease blue color" );

	CON_Print( 2, 20, 0xF0, "R:" );
	CON_Print( 2, 21, 0xF0, "G:" );
	CON_Print( 2, 22, 0xF0, "B:" );

	CON_Print( 5, 26, 0xF0, "SEGA Saturn Sample 00 - Basic" );
	CON_Print( 8, 27, 0xF0, "[saturnsdk.github.io]" );

	for( ;; )
	{
		char PrintBuffer[ 80 ];
		size_t StringSize;

		WaitVBlankOut( );
		WaitVBlankIn( );

		VDP1_FBCR = 0x0001;
			
		/* Poll peripherals */
		PadOld = PadNew;
		PadNew = PER_Read( 0 );
		PadDelta = ( PadNew ^ PadOld ) & PadNew;

		if( PadNew & PER_START )
		{
			break;
		}

		utoa( FrameCount, PrintBuffer, 10 );
		StringSize = strlen( PrintBuffer );

		/* Clear the nine characters before the last one if the frame counter
		 * loops around */
		if( FrameCount == 0 )
		{
			CON_Print( 30, 0, 0x00, "         " );
		}

		CON_Print( 40 - StringSize, 0, 0xF0, PrintBuffer );

		++FrameCount;

		/* Increase/Decrease the clear color via the gamepad */

		if( PadNew & PER_A )
		{
			++Red;
		}

		if( PadNew & PER_B )
		{
			++Green;
		}

		if( PadNew & PER_C )
		{
			++Blue;
		}

		if( PadNew & PER_X )
		{
			if( Red != 0 )
			{
				--Red;
			}
		}

		if( PadNew & PER_Y )
		{
			if( Green != 0 )
			{
				--Green;
			}
		}

		if( PadNew & PER_Z )
		{
			if( Blue != 0 )
			{
				--Blue;
			}
		}

		if( Red >= 31 )
		{
			Red = 31;
		}
		if( Red <= 0 )
		{
			Red = 0;
		}

		if( Green >= 31 )
		{
			Green = 31;
		}

		if( Green <= 0 )
		{
			Green = 0;
		}

		if( Blue >= 31 )
		{
			Blue = 31;
		}
		if( Blue <= 0 )
		{
			Blue = 0;
		}

		/* Print out the current RGB values */

		utoa( Red, PrintBuffer, 10 );
		StringSize = strlen( PrintBuffer );
		if( StringSize == 2 )
		{
			CON_Print( 5, 20, 0xF0, PrintBuffer );
		}
		else
		{
			CON_Print( 6, 20, 0xF0, PrintBuffer );
			CON_PrintChar( 5, 20, 0xF0, '0' );
		}

		utoa( Green, PrintBuffer, 10 );
		StringSize = strlen( PrintBuffer );
		if( StringSize == 2 )
		{
			CON_Print( 5, 21, 0xF0, PrintBuffer );
		}
		else
		{
			CON_Print( 6, 21, 0xF0, PrintBuffer );
			CON_PrintChar( 5, 21, 0xF0, '0' );
		}

		utoa( Blue, PrintBuffer, 10 );
		StringSize = strlen( PrintBuffer );
		if( StringSize == 2 )
		{
			CON_Print( 5, 22, 0xF0, PrintBuffer );
		}
		else
		{
			CON_Print( 6, 22, 0xF0, PrintBuffer );
			CON_PrintChar( 5, 22, 0xF0, '0' );
		}

		/* Change the background color */

		VDP2_SetBackgroundColor( Red, Green, Blue );
	}

	PER_Shutdown( );
	VDP_Shutdown( );
}

void StringOut( const char *p_pString )
{
#if defined BUILD_USBDEVCART
	char Print = ( *p_pString );

	while( Print != '\0' )
	{
		WAIT_FOR_WRITE_FIFO( );
		USB_FIFO = Print;

		Print = ( *++p_pString );
	}
#endif
}

void CON_Initialize( void )
{
	int Index;

	for( Index = 0; Index < 256; ++Index )
	{
		VDP2_CRAM_PTR[ Index ] = FON_Palette[ Index ];
	}

	VDP2_CRAM_PTR[ 0 ] = VDP2_CRAM_PTR[ 1 ];
	VDP2_CRAM_PTR[ 1 ] = 0x10 << 10;
}

void CON_PrintChar( int p_X, int p_Y, uint8_t p_Color, char p_Char )
{
	int Row, Column;

	volatile uint8_t *pBitmap = ( volatile uint8_t * )VDP2_VRAM;
	uint8_t Foreground = ( p_Color >> 4 ) & 0x0F;
	uint8_t Background = ( p_Color ) & 0x0F;

	for( Row = 0; Row < 8; ++Row )
	{
		uint8_t B = FON_Font[ p_Char << 3 | Row ];
		for( Column = 0; Column < 8; ++Column )
		{
			uint8_t D = ( B & ( 0x80 >> Column ) ) ? Foreground : Background;
			pBitmap[ ( ( p_Y << 3 | Row ) << 10 ) +
				( p_X << 3 | Column ) ] = D;
		}
	}
}

void CON_Print( int p_X, int p_Y, uint8_t p_Color, char *p_pString )
{
	int Index;
	for( Index = 0; p_pString[ Index ] != 0; ++Index )
	{
		CON_PrintChar( p_X + Index, p_Y, p_Color, p_pString[ Index ] );
	}
}

void PER_Initialize( void )
{
	SMPC_DDR1	= 0x60;
	SMPC_DDR2	= 0x60;
	SMPC_IOSEL	= 0x03;
	SMPC_EXLE	= 0x00;
}

void PER_Shutdown( void )
{
	SMPC_IOSEL	= 0x00;
}

uint16_t PER_Read( int p_Port )
{
	uint16_t Temp;
	int Count;

	SMPC_PDR1 = 0x60;
	for( Count = 0; Count < PER_DELAY; ++Count )
	{
		asm( "nop" );
	}
	Temp = ( SMPC_PDR1 & 0x08 ) << 12;

	SMPC_PDR1 = 0x40;
	for( Count = 0; Count < PER_DELAY; ++Count )
	{
		asm( "nop" );
	}
	Temp |= ( SMPC_PDR1 & 0x0F ) << 8;

	SMPC_PDR1 = 0x20;
	for( Count = 0; Count < PER_DELAY; ++Count )
	{
		asm( "nop" );
	}
	Temp |= ( SMPC_PDR1 & 0x0F ) << 4;

	SMPC_PDR1 = 0x00;
	for( Count = 0; Count < PER_DELAY; ++Count )
	{
		asm( "nop" );
	}
	Temp |= ( SMPC_PDR1 & 0x0F );

	return ( Temp ^ 0x8FFF );
}

void VDP_Initialize( void )
{
	int Index;

	VDP2_TVMD = 0x0000;

	/* Set NBG0's color RAM mode to mode 0 */
	*( ( volatile uint16_t * )0x25F8000E ) =
		*( ( volatile uint16_t * ) 0x25F8000E ) & ( ~0x3000 );

	/* Set NBG0's map offset to zero */
	*( ( volatile uint16_t * )0x25F8003C ) = 0;

	/* Set up bitmap 256 color mode for NBG0 (1024x256) */
	*( ( volatile uint16_t * )0x25F80028 ) = 0x0012 | 8;

	/* Set the scroll screen direction */
	*( ( volatile uint16_t * )0x25F80070 ) = 0;
	*( ( volatile uint16_t * )0x25F80072 ) = 0;
	*( ( volatile uint16_t * )0x25F80074 ) = 0;
	
	/* Invalidate transparency for NBG0 */
	*( ( volatile uint16_t * )0x25F80020 ) = 0x0001;

	/* Clear VDP2 VRAM */
	for( Index = 0; Index < 0x40000; ++Index )
	{
		VDP2_VRAM_PTR[ Index ] = 0x0000;
	}

	/* Clear VDP2 CRAM */
	for( Index = 0; Index < 0x0800; ++Index )
	{
		VDP2_CRAM_PTR[ Index ] = 0x0000;
	}
}

void VDP_Shutdown( void )
{
	int Index;

	VDP2_TVMD = 0x0000;

	/* Reset VDP2 registers */
	for( Index = 0; Index < 0x100; ++Index )
	{
		VDP2_REG_PTR[ Index ] = 0x0000;
	}

	/* Clear VDP2 VRAM */
	for( Index = 0; Index < 0x40000; ++Index )
	{
		VDP2_VRAM_PTR[ Index ] = 0x0000;
	}

	/* Clear VDP2 CRAM */
	for( Index = 0; Index < 0x0800; ++Index )
	{
		VDP2_CRAM_PTR[ Index ] = 0x0000;
	}
}

void VDP2_SetBackgroundColor( uint8_t p_Red, uint8_t p_Green, uint8_t p_Blue )
{
	( *( volatile uint16_t * )( VDP2_BASE ) ) =
		( ( ( p_Red ) & 0x1F ) |
		( ( p_Green ) & 0x1F ) << 5 |
		( ( p_Blue ) & 0x1F ) << 10 |
		0x8000 );
}

void WaitHBlankOut( void )
{
	while( ( VDP2_TVSTAT & 4 ) == 4 );
}

void WaitHBlankIn( void )
{
	while( ( VDP2_TVSTAT & 4 ) == 0 );
}

void WaitVBlankOut( void )
{
	while( ( VDP2_TVSTAT & 8 ) == 8 );
}

void WaitVBlankIn( void )
{
	while( ( VDP2_TVSTAT & 8 ) == 0 );
}

void WaitHBlank( void )
{
	while( ( VDP2_TVSTAT & 4 ) == 0 );
	while( ( VDP2_TVSTAT & 4 ) == 4 );
}

void WaitVBlank( void )
{
	while( ( VDP2_TVSTAT & 8 ) == 0 );
	while( ( VDP2_TVSTAT & 8 ) == 8 );
}

uint16_t Color16( uint8_t p_Red, uint8_t p_Green, uint8_t p_Blue )
{
	return	( ( ( p_Red ) & 0x1F ) |
			( ( p_Green ) & 0x1F ) << 5 |
			( ( p_Blue ) & 0x1F ) << 10 |
			0x8000 );
}

