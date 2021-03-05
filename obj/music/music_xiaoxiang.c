#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("潇湘水云技", ({ "xiaoxiang music" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "页");
                set("long","
赛伯牙酷爱古乐但不善琴技，于是请人将各个古谱手法绘
成细图，此技只求音律，不论意境，只要肯用心，粗通琴
道的人也能奏出相关曲目。只是由于其手法需死记硬背，
无法融会贯通，学得了一个曲目，便把以前的忘个精光。
（至少需150琴道）");
                set("value", 1000000);
				set("material", "paper");
				set("desc_ext","揣摩（activate）");
        }
        ::init_item();
}


void init()
{
	   	add_action("do_activate","activate");
}
    
// 	　1"HIY"十面埋伏曲 "HIW"2"HIY"潇湘水云曲 "HIW"3"HIY"碧海潮生曲 "HIW"4"HIY"清心普善曲 "
    
int do_activate(string arg)
{
    	object me = this_player();

		if (!arg || arg != "xiaoxiang music"){
			tell_object(me,"格式：activate xiaoxiang music\n");
			return 1;
		}
		
		if (me->query_skill("music",1)<150) {
			tell_object(me,"你的手法实在太差，作弊都不行啊（需150琴道）\n");
			return 1;
		}
					
		tell_object(me, "你苦苦揣摩，终于背出了潇湘水云曲，可惜用脑过度，原来学的都忘了。\n")	;	
		
        me->set("annie/music_choose",2);
        destruct(this_object());
    	return 1;
}

