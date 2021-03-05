
inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
	set_name("发黄的小册子", ({"book"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一本发黄的小册子，字迹历久经年，几不可见，隐隐约约只能分辨出＂三．．．五．．．＂几个字眼。\n");
		set("unit", "本");
		set("no_sell",1);
		set("no_pawn",1);
		set("no_stack",1);
		set("no_drop",1); 
		set("base_value", 0);
		set("base_unit", "本");
		set("base_weight", 50);
		set("illegal",1);
		set("volumn",1);
	}
	set_amount(1);
}

void init()
{
  if(this_player()==environment())
  	add_action("do_write","write");
}

int do_write(string arg)
{
	int i;
	i=atoi(arg);
	if (i>1000000)
		i=1;
	set("base_value",i);
	write("你翻开小册子，顺手写下："+arg+"\n");
	return 1;
}


