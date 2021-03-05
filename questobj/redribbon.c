// icy_band.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIR"红丝巾"NOR, ({ "red-ribbon" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
                set("long", HIR
"红丝巾，红得象刚升起的太阳。任何人佩带这条红丝巾，就永远不要放弃你的目标。
因为谁也不能辱没了这柄刀上系著的红丝市，不能辱没这红丝巾所象徵的那个人。
系上这红丝巾，就表示你决心要奋斗到底，死也不能在任何人面前示弱！
这红丝巾的本身仿佛就能带给人一种不屈不挠的勇气！  \n"NOR);
        set("value",0);
		set("material", "cloth");
        set("armor_prop/armor", 5);
	}
	::init_head();
}
