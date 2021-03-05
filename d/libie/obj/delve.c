// corpse.c
#include <ansi.h>
inherit ITEM;
int imbue_event(object me);

void create()
{
        set_name("土坑", ({ "delve" }) );
        set("long", "一个土坑，里面似乎可以用来掩埋什么（ｂｕｒｙ）。\n");
        set("unit", "个" );
        set_max_encumbrance(800000000);
        set("no_get",1);
        
}

int is_container() { return 1; }

void init()
{
	add_action("do_bury","bury");
}

int do_bury()
{	object me;

	me=this_player();
	if (me->query_temp("libie/离别钩_尾声") && 
			(present("yang's corpse", this_object()) && present("lu's corpse", this_object())))
	{
		message_vision("$N一点一点的将土铲进了坑中，将杨铮夫妇的尸体掩埋了起来。\n",me);
		tell_object(me,"当你将最后一陂黄土铲进坑中时，悲痛中，你似乎领悟了什么，这一切莫非都是天意么！！\n"NOR);
		if(!REWARD_D->imbue_check(me,"离别"))
		{
			me->delete_temp("libie");
			me->start_busy(3);
			imbue_event(me); 			
		}
	} else {
		message_vision("$N用黄土将坑填平。\n",me);
	}
	destruct(this_object());
	return 1;
}
	
	
int imbue_event(object me){
	object weapon, ob, *inv, obj;
	string prop;
	int i;
	mapping data;
	
	if(!interactive(me) || environment(me) != environment(this_object())) {
		return 0;
	}

	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(YEL"\n一阵旋风吹过，荡起一阵黄色的沙尘。\n"NOR, me);
		} else {
			message_vision(YEL"\n一阵旋风吹过，荡起一阵黄色的沙尘，$N的" + obj->name() +
					HIR"上，转眼间便落上了一层薄薄的黄沙。\n"NOR, me);
		}
	}else{
		if(weapon->query("equipped") == "wielded") {
			tell_object(me, "站在填平的土坑旁，你心中充满感慨，不由得松开手中的"+weapon->name()+"。\n");
			weapon->unequip();
		}
		message_vision(YEL"\n一阵旋风吹过，荡起一阵黄色的沙尘，$N的" + weapon->name() + YEL"上，转眼间便落上了一层薄薄的黄沙。\n"NOR,
				me);
		message_vision(HIY"\n一道耀眼的黄色光芒从" + weapon->name() + 
HIY"上闪过，黄沙已然不见，" + weapon->name()+HIY"光可鉴人。\n"NOR, me);
	}	
	data = ([
		"name":		"离别",
		"target":	me,
		"att_3":	"random",
		"att_3c":	1,
		"mark":		1,
	]);
		
	REWARD_D->imbue_att(data);
	destruct(this_object());
}	
