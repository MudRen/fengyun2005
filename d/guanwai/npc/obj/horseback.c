#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("马背", ({ "horseback" }) );
	set("short",WHT"白骏马的背上"NOR);
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
            set("long", "你骑在白骏马背上，重重雾气从你身边掠过。马蹄迅疾，你紧紧地抱住马颈。\n");
			set("value",0);
			set("closed", 1);
			set("is_horse",1);
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
	write("现在不能乱动，当心掉下马摔死！\n");
	return 1;
}