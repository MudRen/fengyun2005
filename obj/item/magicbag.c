#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"幻念结碗"NOR, ({ "hallucination" }) );
	set_weight(500);
	set_max_encumbrance(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("prep", "inside");
		set("unit", "个");
		set("long", "这是一个法力凝结成的幻像，可以放进一些东西。\n不过它随时可能带着里面的东西消失，因此动作还是快一点吧。\n");
	}
	call_out("dissolve",30);
}

int is_container() { return 1; }

int dissolve()
{
	object holder,room;
	
	if(!objectp(holder=environment())) {
		destruct(this_object());
		return 1;
	}
	
	if(userp(holder))
		room=environment(holder);
	else room=holder;
	message("vision",this_object()->query("name")+"渐渐的消失在空气中了。\n",room);
	destruct(this_object());
	return 1;
}