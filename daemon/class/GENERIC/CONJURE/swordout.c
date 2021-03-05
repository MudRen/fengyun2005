// silencer@fy4

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	object sword;	
	int skill;
	object *inv, ob;
	int i;
	
	seteuid(getuid());
	        
	if( me->is_fighting() )
		return notify_fail("你还是先把敌人打发了再说吧！\n");
	
	if (me->query("class")!="wudang")
		return notify_fail("『驭剑诀』是武当绝技。\n");
	
	if (me->query_skill("sword",1)<100)
		return notify_fail("『驭剑诀』至少需要100级的基本剑术。\n");
		
	if (me->query_skill("incarnation",1)<100)
		return notify_fail("『驭剑诀』至少需要100级的修仙术。\n");
		
	if (me->query("atman")<110)
		return notify_fail("『驭剑诀』至少需要100点灵力。\n");
	
	if (me->query("gin")<110)
		return notify_fail("『驭剑诀』至少需要100点精力。\n");
			
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++){
		ob = inv[i];
		if(ob->query("name")== HIY"金剑"NOR
			||ob->query("name")== HIG"木剑"NOR
			||ob->query("name")== HIW"纸剑"NOR 
			||ob->query("id") == "forcesword") {
			return notify_fail("你已经有一把类似的剑了。\n");
		}
	}

	skill=(me->query_skill("incarnation",1) + me->query_skill("sword",1))/ 150;
	
	me->add("atman", -100);
	me->receive_damage("gin", 100);

	message_vision(WHT"一道白光如长虹般飞起，盘旋数圈，跳到$N手中。\n"NOR,me);
	switch( skill ){	
		case 0: 
		case 1:
			sword = new("/obj/weapon/sword_gold");
	        	break;
		case 2:	
			sword = new("/obj/weapon/sword_wood");
	               	break;
		default: sword =  new("/obj/weapon/sword_paper");
	               	break;
        }
	
	if (!sword->move(me)) destruct(sword);
	else
		tell_object(me,"你祭出了一把"+sword->name()+"。\n");
	me->start_busy(2);
	return 1;
}

