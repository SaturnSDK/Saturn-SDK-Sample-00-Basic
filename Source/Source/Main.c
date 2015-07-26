#include <stdint.h>
#include <stdio.h>

extern unsigned int _BSSBegin, _BSSEnd;

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
#define VDP2_TVSTAT	( *( volatile uint16_t * )( 0x25F80000 ) )

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

/* Peripheral functions */
void PER_Initialise( void );
void PER_Shutdown( void );
uint16_t PER_Read( int p_Index );

/* VDP functions */
void VDP_Initialise( void );
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

	/* Zero the .bss */
	for( pDestination = ( unsigned char * )&_BSSBegin;
		pDestination < ( unsigned char * )&_BSSEnd; ++pDestination )
	{
		*pDestination = 0;
	}

	VDP_Initialise( );
	PER_Initialise( );

	StringOut( "SEGA Saturn SDK Sample 001 - Basic\n" );

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

	for( ;; )
	{
		char PrintBuffer[ 80 ];

		WaitVBlank( );

		VDP1_FBCR = 0x0001;
			
		/* Poll peripherals */
		PadOld = PadNew;
		PadNew = PER_Read( 0 );
		PadDelta = ( PadNew ^ PadOld ) & PadNew;

		if( PadNew & PER_START )
		{
			break;
		}
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

void PER_Initialise( void )
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

void VDP_Initialise( void )
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
	while( ( VDP2_TVSTAT & 4 ) == 0 );
}

void WaitHBlankIn( void )
{
	while( ( VDP2_TVSTAT & 4 ) == 4 );
}

void WaitVBlankOut( void )
{
	while( ( VDP2_TVSTAT & 8 ) == 0 );
}

void WaitVBlankIn( void )
{
	while( ( VDP2_TVSTAT & 8 ) == 8 );
}


void WaitHBlank( void )
{
	while( ( VDP2_TVSTAT & 4 ) == 4 );
	while( ( VDP2_TVSTAT & 4 ) == 4 );
}

void WaitVBlank( void )
{
	while( ( VDP2_TVSTAT & 8 ) == 8 );
	while( ( VDP2_TVSTAT & 8 ) == 8 );
}

uint16_t Color16( uint8_t p_Red, uint8_t p_Green, uint8_t p_Blue )
{
	return	( ( ( p_Red ) & 0x1F ) |
			( ( p_Green ) & 0x1F ) << 5 |
			( ( p_Blue ) & 0x1F ) << 10 |
			0x8000 );
}

