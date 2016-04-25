#include <stdlib.h>
#include <stdio.h>

typedef struct 	_posNode 	pos;		//Position node
typedef struct 	_blckNode 	blck;		//Block node
typedef struct 	_local 		loc		//Local structure

/*Position Node Prototype functions*/

//Init Table
pos* init_table(void);
//Init Position
pos* init_position(pos* table);
//Init BlockNode on PositionNode
blck* init_block(pos* home);

//Localisation Functions


//Stack Movement
void move_onto(blck* a, blck* b);
void move_over(blck* a, blck* b);
void pile_onto(blck* a, blck* b);
void pile_over(blck* a, blck* b);
