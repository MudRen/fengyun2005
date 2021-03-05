// halt.c

#include <ansi.h>
#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *inv;
	int i;
	
	inv = all_inventory(environment(me));
	for (i=0;i<sizeof(inv);i++) {
		if( inv[i]->is_corpse() ) continue;
		if( !inv[i]->is_character()) continue;
		if( !inv[i]->is_fighting()) continue;
		inv[i]->remove_all_killer();
	}
			
	message_vision("$N用巫师的神力停止了周围的打斗。\n", me);
	return 1;
}

int help(object me)
{
   write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	haltall[0m
[0;1;37m────────────────────────────────[0m   

停止你周围所有的战斗。

[0;1;37m────────────────────────────────[0m   
HELP
   );
   return 1;
}
