#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"雪球"NOR, ({ "snow ball" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "雪球唉，扔扔试试看吧！（ＴＨＲＯＷ）");
		//set("no_split",1);
		set("no_transfer",1);
		set("value", 0);
		set("unit", "团");
	}
	::init_item();
}

void init()
{
	if(this_player()==environment())
		add_action("do_throw", "throw");
}

int do_throw(string target)
{
	if (!target) {
  	CHANNEL_D->do_sys_channel("info",this_player()->name()+"用力将"HIW"雪球"HIY"扔出，只听见 啪 一声打在"HIR"Hippe"HIY"的脸上("HIG"活动+1"HIY")。\n"NOR);
  } else
  {
		CHANNEL_D->do_sys_channel("info",this_player()->name()+"用力将"HIW"雪球"HIY"扔出，只听见 啪 一声打在"+HIR+target+HIY+"的脸上("HIG"活动+1"HIY")。\n"NOR);
  }
	log_file("HIPPO_DEBUG", sprintf("%s,%s,1,%s\n",this_player()->name(),this_player()->query("id"),ctime(time())));
	destruct(this_object());
	return 1;
}