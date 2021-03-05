#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
    set_name(CYN"桃花木牌"NOR, ({ "taohua mupai","mupai" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
        set("long", "一块桃花木雕的令牌，令牌上刻着绽放的烟花。\n");
		set("value", 1000);
		set("material", "wood");
	}
    ::init_dagger(1);
}
