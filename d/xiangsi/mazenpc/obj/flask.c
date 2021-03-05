inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大肚瓶", ({ "flask"}) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个大肚子的水晶瓶。\n");
		set("unit", "个");
		set("value", 2);
		set("max_liquid", 450);
	}

	set("liquid", ([
		"type": "water",
		"name": "淡绿色的清水",
		"remaining": 450,
		"drunk_apply": 7,
	]) );
	set("no_transfer",1);
	set("desc_ext","可放在大黑箱子内");
	set("generate_item",1);	// can be stack as boss item.

	::init_item();
}

void auto_fill()
{
	int i;
	if (query("liquid/name") != "淡绿色的清水")
		return;
	i = query("liquid/remaining");
	i += 30;
	if (i> 450)
		i=450;
	set("liquid/remaining",i);
	i /= 2;
	call_out("auto_fill",i);
}

void init()
{
  	if(this_player()==environment())
		auto_fill();
	::init();
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
