#include "node.h"
#include "node.c"

/*
	The Compilation with node.c
*/

//Init Table
pos* init_table(void){
	pos* tbNode = (pos*)malloc(sizeof(pos));
	tbNode->index=0;
	tbNode->table=tbNode;
	tbNode->block=init_block(tbNode);
	return tbNode;
}
//Init Position
pos* init_position(pos* table){
	//find the last Node
	while(table->next_pos!=0){
	table=table->next_pos;
	}
	pos* lnode=table;
	pos* newNode=(pos*)malloc(sizeof(pos));
	lnode->next_pos=newNode;
	newNode->index=lnode->index+1;
	newNode->table=lnode->table;
	//call the block init function
	newNode->block=init_block(newNode);
}
//Init BlockNode on PositionNode
blck* init_block(pos* home){
	blck* new_block = (blck*)malloc(sizeof(blck));
	new_block->index=home->index;
	new_block->home=home;
	new_block->home_addr=new_block;
	}


