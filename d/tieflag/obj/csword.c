#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG"长生剑"NOR, ({ "longlife sword","sword" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是一把明如秋水的长剑。\n");
                set("material", "steel");
                set("baiyujing", 1);
                set("rigidity", 1000);
                set("wield_msg", "$N从陈旧的剑鞘中拔出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon_prop/agility", 0);
                set("weapon_prop/personality", 0);
        }

        ::init_sword(20);

}
 
void init()
{
	add_action("do_look","look");
	add_action("do_turn","turn");
}

int do_look(string arg)
{
	object me;
	object obj;
	me=this_player();
	if (!arg) return 0;
	if (arg[0..4] != "sword") return 0;
	if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
	{
		if (obj != this_object()) return 0;
		if ((random(me->query_int())<15) || (random(me->query_kar())<12))
		{
			obj->set("long","这是一把明如秋水的长剑。\n");
			obj->set_temp("can_turn",0);
			return 0;
		}
		else
		{
			obj->set("long","这把剑的剑柄似乎可以旋开！(turn)\n");
			obj->set_temp("can_turn",1);
			return 0;
		}
	}
	return 0;
}
    
int do_turn(string arg)
{
	object paper;
	if(!arg || arg != "sword") return 0;
	if(!query_temp("can_turn")) return 0;
	message_vision("$N试着转动长生剑的剑柄...\n",this_player());
	if(query_temp("been_get"))
		return notify_fail("你转开剑柄，但里面空空如也，什么也没有。\n");
	set_temp("been_get",1);
	tell_object(this_player(),"你发现里面藏着一个纸卷，你把纸卷拿了出来。\n");
	paper=new(__DIR__"fakedesign");
	paper->move(this_player());
	return 1;
}