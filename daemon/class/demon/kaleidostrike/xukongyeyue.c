
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int havenothingon(object ob)
{  
        object *inv;
        inv = all_inventory(ob);
        if (sizeof(inv)==0) 
                return 1;
        else
                return 0;
}
int perform(object me, object target)
{
    object *tar;
    object obj,ob;
    int i,size;
		
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「虚空夜月」只能对战斗中的对手使用。\n");

	ob = target;

        tar = all_inventory(ob);
        size=sizeof(tar);
        
        if(!havenothingon(ob))
        {
			i=random(size);
			obj=tar[i];
			if(!(int)obj->query("no_get") && !(int)obj->query("no_drop"))
			{
				if (!obj->move(me))
					obj->move(environment(me));   
				message("vision",HIB"一阵微风拂面而过，你似乎看见"+me->name()+"的影子在风中轻轻一晃。\n", environment(me),me);
				message("vision",HIB"你揉揉眼，却发现"+me->name()+"依然还在原地，似乎什么都没有发生。\n"NOR, environment(me),me);
				tell_object(me, "你得手了！\n");
				tell_object(ob, "你感觉身上一轻，似乎丢了什么东西．．．\n");
				return 1;
			}
        }
        else
        {
			return notify_fail("「虚空夜月」没有使用的必要。\n");
        }

	return 1;
}


