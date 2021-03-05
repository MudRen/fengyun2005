// 2009 FengYun
// Edit by hippo 2009.11
// 孝道 关联

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"奏折"NOR, ({ "zouzhe" }) );
	set_weight(70);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "我叫缇萦，是太仓令淳于意的小女儿。我父亲做官的时候，\n齐地的人都说他是个清官。这回儿他犯了罪，被判处肉刑。\n我不但为父亲难过，也为所有受肉刑的人伤心。一个人砍\n去脚就成了残废；割去了鼻子，不能再按上去，以后就是\n想改过自新，也没有办法了。我情愿给官府没收为奴婢，\n替父亲赎罪，好让他有个改过自新的机会。\n");
		set("value", 200);
		set("no_split",1);
		set("unit", "卷");
		set("no_drop",1);
		set("no_get",1);
		set("no_sell",1);
		set("lore",1);
	}
	::init_item();
}