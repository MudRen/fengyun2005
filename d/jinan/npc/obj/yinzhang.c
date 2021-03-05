#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"知府印章"NOR, ({ "yinzhang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "方");
		set("material", "stone");
        set("long", "一方镶着金边的知府大印，可以在文书上盖章（ｓｅａｌ）。\n");
	}
	::init_item();
}

void init()
{
        add_action("do_seal", "seal");
}

int do_seal(string arg)
{
	object obj;

	if (environment(this_object())!=this_player())
		return 0;
	if (!arg)
		return notify_fail("你要在哪里盖印？\n");
	if (!objectp(obj=present(arg,this_player())))
		return notify_fail("你要在什么地方盖印？\n");
	if (obj==this_object()->query("id"))
		return notify_fail("你不能在印章本身上盖印。\n");
	
	message_vision("$N对"+this_object()->query("name")+"呵了口气，在"+obj->query("name")+"上小心翼翼地盖上一个印章。\n",this_player());
	obj->set("sealed",1);
	if(obj->query("id") == "secret order"){
		obj->set("long", "一道提押犯人上堂的密令，上面盖着知府的朱红色大印。\n");
	}
	return 1;
}