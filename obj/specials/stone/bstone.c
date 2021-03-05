#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIC"碧海蓝心"NOR, ({"diamond", "blue stone", "stone"}));
    	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "块");
			set("long", "
这是一块罕见的蓝色钻石，明净而无丝毫杂质，然而那幽远的蓝色似乎能 
把你的神思引向一个深深的遥远的世界。\n");
                set("value", 200);
		set("imbue", 1);
		set("lore",1);
        }
	::init_item();
}

/*
void init(){
	add_action("do_lian", "lian");
}

int do_lian(){
	object me;
	int i, j;
	me = this_player();
	if(present("yellow stone", me) && present("green stone", me) && present("red stone", me)
			&& present("purple stone", me)) {
		i = me->query_skill("spells");
		j = me->query("mana");
		if(i >= 200 && j >= 2000) {
			message_vision("$N聚起所有法力，凝成一道白光注入五色灵石。\n", me);
			me->start_busy(3);
			call_out("make_stone", 3, me); 
		} else {
			return notify_fail("你没有足够的法力或咒文。\n");
		}
	} else {
		tell_object(me, "你还缺少石头。\n");
	}
	return 1;	
}

int make_stone(object me){
	object obj, ruby, topaz, amethist, jade;
	me->set("mana",0); 
	ruby = present("red stone", me);
	topaz = present("yellow stone", me);
	jade = present("green stone", me);
	amethist = present("purple stone", me);
	message_vision(HIR"蛰龙赤丹发出炎炎的红光。\n"NOR, me); 
	message_vision(HIY"凝露黄石发出明亮的黄色光芒。\n"NOR, me); 
	message_vision(HIG"天灵翡翠发出的澄碧的绿光。\n"NOR, me);
	message_vision(HIC"碧海蓝心发出莹莹的蓝色光芒。\n"NOR, me); 
	message_vision(HIM"幽冥紫晶发出幽幽的紫色光芒。\n"NOR, me); 
	destruct(ruby);
	destruct(topaz);
	destruct(amethist);
	destruct(jade);
	message_vision("\n五色灵石终于结成一体！\n", me); 
	if(!me->query("m_success/五彩石")){
	    me->set("m_success/五彩石",1);
	    me->add("score",10000);
	}	
	obj = new("/obj/specials/stone/rbstone");
	obj->move(me);
	destruct(this_object());
	return 1;
}*/