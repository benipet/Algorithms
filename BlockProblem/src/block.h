/*
	The Block.h
	//Implemented Abstractions
*/


/*The Block Data Structure*/
typedef struct _block* Block;

/*Block Management Functions*/
Block* init_block(int id);
void link_block(Block* bl);
void reset_block(Block* bl);
Block* get_blockById(int id);

//Stack functions
Block* define_stackById(int id);
void remove_stackById(int id);
void move_stackById(int id);


/*Block System Functions*/

