#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIY "喜气红包" NOR, ({ "hongbao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("lore",1);
            //set("material", "cloth");
            set("long", "一个鼓鼓的红包，上面印着：HIPPO钱庄。（ｏｐｅｎ）\n");
          }
    ::init_item();
}

void init()
{

	if(environment()==this_player())
		add_action("do_open","open");
}

int do_open(string arg)
{
	object gold;
	int goldnum=0;
	if(arg != "hongbao" && arg != "喜气红包") return 0;
	if(this_player()->query("partymarks/newyear/hongbao")) {
		tell_object(this_player(),HIR"HIPPO"NOR"的声音在耳边回荡："YEL"贪心不足，红包没收!\n"NOR);
		destruct(this_object());
		return 1;
		//return notify_fail("你打开小红包，但里面是空的！\n");
	}
	if (F_LEVEL->get_level(this_player()->query("combat_exp")) >= 20) {
		goldnum=F_LEVEL->get_level(this_player()->query("combat_exp"))*2/3+random(F_LEVEL->get_level(this_player()->query("combat_exp"))*2);
	} else {
		goldnum=F_LEVEL->get_level(this_player()->query("combat_exp"))/2+random(F_LEVEL->get_level(this_player()->query("combat_exp"))/2);
	}
	if (goldnum >= 1 && F_LEVEL->get_level(this_player()->query("combat_exp")) >= 10) {
		gold = new("/obj/money/gold");
		gold->set_amount(goldnum);
		gold->set("name","纯金叶子");
		gold->set("base_unit","张");
		gold->move(this_player());
		this_player()->set("partymarks/newyear/hongbao",1);
	} else {
	 goldnum=0;
	}
	//set("opened",1);
	//return notify_fail("你打开小红包，从里面拿出几张纯金叶子！\n");
	if (goldnum == 0 || F_LEVEL->get_level(this_player()->query("combat_exp")) < 10) {
		CHANNEL_D->do_sys_channel("info",this_player()->name()+"随手将"+this_object()->name()+HIY"折成纸飞机扔了出去。\n"NOR);
	} else {
		CHANNEL_D->do_sys_channel("info",this_player()->name()+"默默祈祷后打开"+this_object()->name()+HIY"，从里面拿出"+goldnum+"张纯金叶子。\n"NOR);
	}
	if (goldnum == 88 || goldnum == 188 || goldnum == 288 || goldnum == 388) {
		this_object()->set("name",HIM"好运彩礼包"NOR);
		this_object()->set("long", "好运连连彩礼包，上面印着：HIPPO钱庄。（ｏｐｅｎ）\n");
		this_player()->set("partymarks/newyear/hongbao",0);
		CHANNEL_D->do_sys_channel("info",this_player()->name()+"受到了财神的光顾，额外获得"+this_object()->name()+HIY"作为奖励。\n"NOR);
	} else {
		destruct(this_object());
	}
	return 1;
}
