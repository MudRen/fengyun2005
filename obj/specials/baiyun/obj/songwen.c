// - neon
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(YEL"松纹"NOR, ({ "songwen", "qin" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 500);
		set("material", "wood");
		set("timbre" , 20);
		set("long", "琴体显出松木纹理，是古传名琴之一。\n");
		
	}

}
void init()
{
  add_action("do_play","play");
}
int do_play()
{
	message_vision("$N曼挑琴弦，"YEL"松纹"NOR"发出松风吹动般的音色。\n",this_player());
	return 1;
}













