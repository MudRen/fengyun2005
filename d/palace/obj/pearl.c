
inherit ITEM;

void create()
{
	set_name("雷火珠", ({ "pearl" , "雷火珠"}) );
	set_weight(1);
	set("explosive",2);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "江南霹雳堂独制，一个有强大爆炸力的雷火珠。
在洞里干燥的条件下，火药还是那么威力无穷。\n");
		set("value", 10);
	}
}
