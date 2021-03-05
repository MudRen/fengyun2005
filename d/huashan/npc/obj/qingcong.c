// annie. 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
	set_name(CYN"青葱甲"NOR, ({ "qingcong" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "一对雕着精细花纹的青玉指甲，泛着一层幽幽的寒光。\n");
		set("material", "crystal");
		set("no_get",1);
		set("annie/for_kaleidostrike",1);
	}
	::init_fist(40);	// 最好的指甲.
}

int init()
{
//	::init();
	set("weapon_wielded","指尖套");
}

//int query_autoload() { return 1; }
