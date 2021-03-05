inherit ITEM;

void create()
{
        set_name("莲姑的尸体", ({ "corpse" }) );
        set("long", "
这是一具女子的尸骨，虽不是很漂亮，但看上去温柔朴实，令人暗自心惊
的是女子虽死，但双目圆睁不闭，双拳紧握。\n");
        set("unit", "具" );
        set("no_get", 1);
        set("cloth",1);
}


int 	init()
{
	add_action("do_look","look");
}


int do_look(string arg)
{
	object me;
	object cloth;
	me = this_player();
	if(!arg)	return 0;
	
	if (arg != "双拳" && arg != "手" && arg != "hand" && arg!="fist") return 0;
	
	if (!query("cloth"))
	{
		tell_object(me,"你慢慢掰开莲姑紧握的双手，里面什么也没有。\n");
		return 1;
	}
	
	tell_object(me,"你慢慢掰开莲姑紧握的双手，手中是一片碎布，色泽鲜红。\n");
	cloth = new("/d/libie/obj/cloth");
	if (!cloth->move(me))
		cloth->move(environment(me));
	set("cloth",0);
	return 1;
}