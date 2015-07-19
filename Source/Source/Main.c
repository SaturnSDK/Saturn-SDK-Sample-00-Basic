#include <stdint.h>
#define SYSTEM_WORK	0x060FFC00
#define SYSTEM_SIZE	( 0x06100000 - 0x060FFC00 )

extern unsigned int _BSSBegin, _BSSEnd;
#define USB_FIFO	( *( volatile uint8_t * )( 0x22100001 ) )
#define USB_FLAGS	( *( volatile uint8_t * )( 0x22200001 ) )
#define USB_TXE		( 1 << 1 )
#define WAIT_FOR_WRITE_FIFO( ) do { while( ( USB_FLAGS & USB_TXE ) ); }while( 0 )

void StringOut( const char *p_pString );

void main( void )
{
	unsigned char *pDestination;
	unsigned int Index;

	/* Zero the .bss */
	for( pDestination = ( unsigned char * )&_BSSBegin;
		pDestination < ( unsigned char * )&_BSSEnd; ++pDestination )
	{
		*pDestination = 0;
	}

	/* This is for clearing the SGL system variables */
	for( pDestination = ( unsigned char * )SYSTEM_WORK, Index = 0;
		Index < SYSTEM_SIZE; ++Index )
	{
		*pDestination = 0;
	}

	StringOut( "SEGA Saturn SDK test string\n" );

	while( 1 )
	{
		/* Just keep going */
	}
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

