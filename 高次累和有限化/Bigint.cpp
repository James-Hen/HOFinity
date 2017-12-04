#include "Bigint.h"

James::bigint::bigint()
{
	bottom = new node;
	topper = bottom;
	bottom->frnt = NULL;
	bottom->nxt = NULL;
}
