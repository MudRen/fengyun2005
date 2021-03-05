inherit ITEM;

void create()
{
        set_name("青苔", ({ "lichen" }) );
        set_weight(100);

        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "丛");
                set("long", "但见峭壁上每隔数尺便生着一丛青苔，数十丛笔直而上。\n");
                set("value", 1);
        }
}

void init()
{
	add_action("do_dig","dig");
	add_action("do_climb","climb");
}

int do_dig(string arg)
{
	object me;
	
	me=this_player();
	if(!arg) return 0;
	if(arg!="lichen"&&arg!="青苔")
		return 0;
	if(query("digged"))
		return 0;
	message_vision("$N往青苔中摸去，抓出一把黑泥，果然是个小小洞穴。\n",me);
	set("digged",1);
	return 1;
}

int do_climb(string arg)
{
	object me;
	
	me=this_player();
	if(!arg) return 0;
	if(arg!="up")
		return 0;
	message_vision("$N小心翼翼的踩着青苔挖去后的洞穴向悬崖上爬去。\n",me);
	me->move("/d/shanliu/sheshenya");
	return 1;
}
	
	

