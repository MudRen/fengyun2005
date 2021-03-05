// - neon
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIG"绿绮"NOR, ({ "lvqi qin", "qin" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 500);
		set("material", "wood");
		set("timbre" , 30);
        set("long", "琴体暗现绿色，大都为江南灵秀女子喜用的瑶琴，外观极其秀美，\n琴音清澈，是古传名琴之一。\n");
		
	}

}
void init()
{
  add_action("do_play","play");
}
int do_play()
{
	message_vision("$N轻拨琴弦，"HIG"绿绮"NOR"发出梵天清唱般的音色。\n",this_player());
	return 1;
}













