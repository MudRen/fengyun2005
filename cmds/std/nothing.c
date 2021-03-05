/* This is a dummy command to fix a mudos problem.
	It is only used in /obj/user move() function
	It does absolutely nothing , 
		but shouldn't be removed unless we upgrade to a better MUDOS.
		-- Silencer Sept.2005
*/

#include <ansi.h>

int main(object me, string arg)
{
	return 1;
}
