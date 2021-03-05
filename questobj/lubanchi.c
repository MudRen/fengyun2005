// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(WHT"鲁班尺"NOR, ({ "lubanchi" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("jungle",1);
		set("material", "iron");
		set("long", @LONG
木匠名师鲁班有两个徒弟，一个笨，一个骄傲自满和不自量力，他们就是
阿毛和阿发。他们每天跟在鲁班身边，扎实地学不少手艺。但阿发因为骄
傲自满，所以他一个人离开了师傅，只剩下阿毛跟在师傅身边。阿毛是阿
发的弟弟，他虽然笨，但勤力向上用心学习，每天手持鲁班尺在大小佛塔
上量尺寸。因此阿毛量尺寸非常准确。每当阿毛手持鲁班尺时，他便想起
他的师傅如何用心地教他。阿毛手上的鲁班尺就像他身体的一部份，寸步
不离。
LONG);
		set("wield_msg", "$N抽出一把黑油油的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间。\n");
	}
	::init_blade(5);
}
