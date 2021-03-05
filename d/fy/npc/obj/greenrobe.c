#include <armor.h>
inherit CLOTH;

void create()
{
    set_name("墨绿绣花长袍", ({ "green robe","robe", }) );

	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "
墨绿绣花长袍上绣着一张脸，眉清目秀，面目娟好，仿佛是个绝色少女。
仔细一看，竟是个人首蛇身，鸟爪蛹翼的怪兽。\n");
		set("material", "cloth");
		set("value", 1000);
		set("armor_prop/armor", 10);
	}
	::init_cloth();
}
