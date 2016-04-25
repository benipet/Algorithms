void display_position(pos* node);
void display_all(pos* table);

void display_all(pos* table){
	while(table!=0){
	display_position(table);
	table=table->addr_next;
	}
}

void display_position(pos* node){
	printf("----------Position-------------\n");
	printf("Position index	:%d\n", node->index);
	printf("Next Position	:%p\n", node->addr_next);
	printf("Block child	:%p\n", node->addr_block);
	printf("----------Blocks--------------\n");
	blck* blnode = node->addr_block;
	if(blnode->bottom==0){
	while(blnode!=0){
	printf("%d ", blnode->index);
	blnode=blnode->above;
	}}
	printf("\n-----------------------------\n");
	
}

