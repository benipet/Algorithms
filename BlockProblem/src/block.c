#include "block.h"

struct _position{
	unsigned int	index;
	pos*		addr_table;
	pos*		addr_next;
	blck*		addr_block;

};

struct _block{
	unsigned int	index;
	pos*		base;
	blck*		above;
	blck*		bottom;
	pos*		pos;
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
	blck* myChild = init_block(table);
	myChild->bottom=myChild;

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
	blck* myChild = init_block(new);
	myChild->bottom=myChild;
	old=new;
	}

}

blck* init_block(pos* base){
	blck* new_block = (blck*)malloc(sizeof(blck));
	new_block->index = base->index;
	new_block->base=base;
	new_block->above=0;
	/*bottom link ?*/
	new_block->pos=base;
	return new_block;
}
int* link_block(blck* linker, blck* receiver){
	if(receiver->above!=0){
	printf("Sorry I have above a block\n");
	}
	else{
	receiver->above=linker;	
	linker->bottom=receiver;
	linker->pos=receiver->pos;
	}
	
}
   /*Receiver: the bottom blolck*/
blck* ulink_block(blck* b_block,blck* a_block){
	b_block->above=0;
	a_block->bottom=0;

}	/*bottom block and aboce block*/
pos* get_blpos(blck* block);			/*Returns the position addr. block*/
pos* get_base(blck* block);			/*Returns the base position addr.*/
