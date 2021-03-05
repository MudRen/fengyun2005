inherit ITEM;
#include <ansi.h>

void create()
{
    	set_name("碎纸片左上角", ({ "paper" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 1);
		 set("long", "一张撕碎了的纸片，上面写着“薛斌”。\n");
	}
	
	::init_item();
}


/* “十九年前梅花庵血案，三十八人围攻神刀堂白天羽，那天的雪下得很大，
地上一片银白，但那战斗结束后，整个一片银白色的大地，竟都被鲜血染
红了。染红那一片雪地的鲜血，并不仅是白家人的，别人的血流得更多，
能活着回去的只有七个人，现已查明的有易大经，薛斌，桃花娘子，柳东
来，白天羽的结拜兄弟马空群，还有一个神秘的幕后人物。”*/