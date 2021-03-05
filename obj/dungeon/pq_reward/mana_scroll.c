#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
	set_name("『"MAG"紫陌残篇·经天断恨"NOR"』"NOR, ({ "scroll" }));
	set_weight(1000);
	if( clonep() )
			set_default_object(__FILE__);
	else {
            set("long",YEL"一卷薄薄的丝绢，可以阅读(Read)以学习上面所记载的能力。\n"NOR);
			set("value", 1000);
			set("unit", "本");
			set("material", "paper");
			set("teaching", "mana");
	}
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
