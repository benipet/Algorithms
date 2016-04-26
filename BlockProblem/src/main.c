
#include "display.c"

int move_onto(pos* table, int a, int b);
int move_over(pos* table, int a, int b);
int pile_onto(pos* table, int a, int b);
int pile_over(pos* table, int a, int b);

int main(void){
	pos* table = init_table();
	build_positions(table, 10);
	move_onto(table, 9,1);
	move_over(table, 8,1);
	move_over(table, 7,1);
	move_over(table, 6,1);
	pile_over(table, 8,6);
	pile_over(table, 8,5);
	move_over(table, 2,1);
	move_over(table, 4,9);
	display_all(table);
	return 0;
}

int move_onto(pos* table, int a, int b){
	//Check the two block is on same block
	int cmp = cmp_stack(table, a, b);
	if(cmp==1){
	printf("The two block is member as same stack\n");
	return -1;
	}
	stck* a_stack = define_stack(table, a);
	stck* b_stack = define_stack(table, b);
	demolish_stack(table, a);
	demolish_stack(table, b);
	ulink_block(a_stack->addr_block);
	ulink_block(b_stack->addr_block);
	link_block(a_stack->addr_block, b_stack->addr_block);

}
int move_over(pos* table, int a, int b){
	int cmp = cmp_stack(table, a, b);
	if(cmp==1){
	printf("The two block is member as same stack\n");
	return -1;
	}
	stck* a_stack = define_stack(table, a);
	stck* b_stack = define_stack(table, b);
	demolish_stack(table, a);
	ulink_block(a_stack->addr_block);
	link_block(a_stack->addr_block, b_stack->addr_btop);
	
}

int pile_onto(pos* table, int a, int b){
	int cmp = cmp_stack(table, a, b);
	if(cmp==1){
	printf("The two block is member as same stack\n");
	return -1;
	}
	stck* a_stack = define_stack(table, a);
	stck* b_stack = define_stack(table, b);
	demolish_stack(table, b);
	ulink_block(a_stack->addr_block);
	link_block(a_stack->addr_btop, b_stack->addr_block);
		
	
}

int pile_over(pos* table, int a, int b){
	int cmp = cmp_stack(table, a, b);
	if(cmp==1){
	printf("The two block is member as same stack\n");
	return -1;
	}
	stck* a_stack = define_stack(table, a);
	stck* b_stack = define_stack(table, b);
	//find the top of block node
	blck* top_b=b_stack->addr_block;
	ulink_block(a_stack->addr_block);
	link_block(a_stack->addr_block, b_stack->addr_btop);	
	
}

