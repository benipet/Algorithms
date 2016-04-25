#include "node.h"
#include "node.c"

//Display BlockNode
void display_blockNode(blck* instance){
	printf("--------Block Node------------");
	printf("index		:%d\n", instance->index);
	printf("home(position)	:%p\n", instance->home);
	if(instance->home_addr!=0){	
	printf("home_addr(node)	:%p\n", instance->home_addr);}
	else{
	printf("home_addr(node)	:Node not home\n", instance->home_addr);
	}
}
//Display PositionNode
void display_positionNode(pos* instance){
	printf("---------Position Node---------\n");
	printf("index		:%d\n", instance->index);
	printf("Current_addr	:%p\n", instance->table);
	if(instance->next_pos!=0){
	printf("Next Position	:%p\n",instance->next_pos);
}	
	else{
	printf("Next Position	:(last)\n");	
	}
	if(instance->block!=0){
	blck* instBlock=instance->block;
	
	printf("Related Block	:%p(%d)\n", instBlock, instBlock->index);
	}

}
