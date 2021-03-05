#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("飞毯"NOR, ({ "carpet" }) );
	set("short",CYN"蓝天白云之间"NOR);
    set_weight(800);
    set_max_encumbrance(9999999);
			if( clonep() )
            set_default_object(__FILE__);
    else {
			set("no_fight",1);
			set("no_magic",1);
			set("no_spells",1);
            set("unit", "张");
            set("material", "cloth");
            set("long", "你正坐在一张在白云间穿梭的飞毯上，重重雾气从你身边掠过。\n飞毯时高时低，有时掠到云层上方，抬头就能看见温暖的阳光；有时\n沉到云层之下，地面上的景色历历可见。\n");
			set("value",0);
			set("closed", 1);
			set("is_carpet",1);
		  }
    ::init_item();
}

int is_container() {return 1;}

void init()
{
	if (!wizardp(this_player()))
	{
	"/cmds/std/look"->look_room(this_player(),this_object());
	add_action("do_nothing", "");
	}
}	

int do_nothing()
{
	write("现在不能乱动，当心跌下飞毯！\n");
	return 1;
}