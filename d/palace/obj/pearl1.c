
inherit ITEM;

void create()
{
	set_name("雷火珠", ({ "pearl" , "雷火珠"}) );
	set_weight(1);
	set("explosive",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "江南霹雳堂独制，一个有强大爆炸力的雷火珠。
不过，在露天时间长了，火药的威力似乎减了许多。
恐怕也炸不开什么东西了。\n");
		set("value", 10);
	}
}
