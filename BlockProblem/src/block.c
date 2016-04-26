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

/*Function definitions*/
pos* init_table(void){
	pos* table = (pos*)malloc(sizeof(pos));
	table->index=0;
	table->addr_table=table;
	table->addr_next=0;
	table->addr_block=init_block(table);
	
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

/*
	STACK FUNCTION DEFINITIONS
*/

stck* init_stack(void){
	stck* new_stack = (stck*)malloc(sizeof(stck));
	return new_stack;
}
void kill_stack(stck* stack){
	free(stack);
}


stck* define_stack(pos* table, int bl_index){
	blck* wanted;
	int counter=0;

	while(table->index<=bl_index & table->addr_next!=0){
	if(table->addr_next==0){
	wanted=0;	
	}
	else {
	wanted=table->addr_block;		
	}	
	table=table->addr_next;
	}
	if(wanted!=0){
	
	while(wanted->above!=0){
	++counter;
	wanted=wanted->above;
	}
	stck* stack = init_stack();
	stack->b_index=wanted->index;
	stack->p_index=wanted->pos->index;
	stack->size=counter;
	stack->addr_block=wanted;
	stack->addr_pos=wanted->pos;
	return stack;
	}
	return 0;

}

int cmp_stack(pos* table, int a_index, int b_index){
	if(a_index==b_index){
	stck* a = define_stack(table, a_index);
	stck* b = define_stack(table, b_index);
	int a_pos;
	int b_pos;
	if(a_pos==b_pos){
	return 1;	
	}
	else{
	return 0;
	}}
	else{
	return -1;
	}


}
int demolish_stack(pos* table, int bl_index){
	stck* trash=define_stack(table, bl_index);
	blck* block;	
	while(trash->size!=0){
	block=trash->addr_block;
	printf("Trash size: %d\n", trash->size);
	ulink_block(block);
	kill_stack(trash);
	trash=define_stack(table, block->index);
	printf("Trash size: %d\n", trash->size);
	}
	kill_stack(trash);
}
