#include "block.h"

struct _position{
	int		index;		//Position index
	pos*		addr_table;	//Address of table
	pos*		addr_next;	//Address of next position
	blck*		addr_block;	//Address of the block

};

struct _block{
	int		index;		//index of block
	pos*		base;		//addr of base
	blck*		above;		//addr of above block
	blck*		bottom;		//addr of bottom block
	pos*		pos;		//addr of position
};


struct _stack{
	unsigned int	b_index;
	unsigned int	p_index;
	unsigned int	size;
	blck*		addr_block;
	pos*		addr_pos;
	
};

/*Function prototypes*/
pos* init_table(void){
	pos* table = (pos*)malloc(sizeof(pos));
	table->index=0;
	table->addr_table=table;
	table->addr_next=0;
	table->addr_block=init_block(table);c
	
	return table;
	}

pos* build_positions(pos* table, int size){
	int counter = 1;
	pos* old=table;
	for(counter; counter<=size;counter++){
	pos* new=(pos*)malloc(sizeof(pos));
	old->addr_next=new;
	new->index=counter;
	new->addr_table=old->addr_table;
	//call the init_block function
	new->addr_block=init_block(new);
	old=new;
	}

}

blck* init_block(pos* base){
	blck* new_block = (blck*)malloc(sizeof(blck));
	new_block->index=base->index;
	new_block->base=base;
	new_block->above=0;
	new_block->bottom=0;
	new_block->pos=base;
	return new_block;
}

int* link_block(blck* linker, blck* receiver){
	if(receiver->above!=0){
	printf("Sorry I have above a block\n");
	}
	else{
	linker->bottom=receiver;
	linker->pos=receiver->pos;
	receiver->above=linker;
	}
	
}
   /*Receiver: the bottom blolck*/
blck* ulink_block(blck* leaver){
	if(leaver->bottom!=0){
	leaver->bottom->above=0;
	}
	leaver->bottom=0;
	leaver->pos=leaver->base;
}	/*bottom block and aboce block*/
pos* get_blpos(blck* block);			/*Returns the position addr. block*/
pos* get_base(blck* block);			/*Returns the base position addr.*/
