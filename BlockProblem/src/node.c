#include "node.h"

struct _posNode {
	unsigned int 	index;
	pos*		table;
	pos*		next_pos;
	blck*		block;
};

struct _blckNode {
	unsigned int	index;
	pos*		home;
	blck*		home_addr;
	blck*		next_block;	
};


