/*
	The Block problem HEADER file
	File name: block.h
	Peter Benis
*/

#include <stdlib.h>
#include <stdio.h>

/*Data type definitions*/

typedef struct _position 	pos;
typedef struct _block		blck;
typedef struct _stack		stck;

/*Function prototypes*/
pos* init_table(void);
pos* build_positions(pos* table, int size);

blck* init_block(pos* base);
int* link_block(blck* linker, blck* receiver);   /*Receiver: the bottom blolck*/
blck* ulink_block(blck* leaver);		/*bottom block and aboce block*/
pos* get_blpos(blck* block);			/*Returns the position addr. block*/
pos* get_base(blck* block);			/*Returns the base position addr.*/


