// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>


inherit SWORD;

void create()
{
	set_name(HIG "凝碧剑" NOR, ({ "ningsword" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	        set("long", @LONG
这是一把青光四射，寒气逼人的宝剑，剑长三尺二，剑柄上刻有“枯梅”
二字，字迹清秀，俨然出自女子之手，不言而喻，这就是华山派现任掌门
－－枯梅大师的配剑。枯梅大师自从一只手被沸油烧焦后，尽管功力没受
大影响，但行动总不想以前灵便，而且被沸油热毒所侵，脾气也变得比以
前焦躁。后来爱徒丁枫一次奇缘求得千年寒玉一块，交由名匠煅成长三尺
二，宽二寸三的神兵，以减少枯梅大师运功时所受热毒煎熬之苦。自此以
后，枯梅大师腰间“凝碧剑”从不离身，“枯梅凝碧”也成为华山派的标
志。  
LONG);
		set("material", "steel");
	}
	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的剑鞘。\n");
	::init_sword(45);
}
