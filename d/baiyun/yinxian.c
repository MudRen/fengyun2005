#include <ansi.h>
inherit ROOM;
inherit F_LEVEL;

void create()
{
    set("short", BMAG HIW"英仙乱"NOR);
    set("long", @LONG

笑怆然望，正秋凉，老蝉离菀，昏鸦孤栈。芳草萋萋斜阳黯，极目云山遮断。
往来路，孓行已惯。
却忆越石穷窘处，唱扶风，千古悲余叹。国士恨，终难忘。

驽车逆旅流年换。度浮生，尘网织梦，市街挥汗。
吟放经诗无一用，磨尽书生肝胆。
功名累，烟氲云乱。老大而今真何趣，引离杯，醉眼青峰看，岁月晚，空余怅。

LONG
    );
    set("exits",
      ([
	"down" : __DIR__"mixian",
      ]));

    set("indoors", "baiyun");
    set("coor/x",30);
    set("coor/y",-160);
    set("coor/z",60);
    setup();
    set("no_fly", 1);
    set("max_lv",75);	
}

int init()
{
    object me = this_player();
    object exitroom = find_object(__DIR__"mixian");
    if (!exitroom)
	exitroom = load_object(__DIR__"mixian");
    if (exp_to_level(me->query("combat_exp"))["level"] >= query("max_lv") && userp(me))
    {
	me->add_temp("block_msg/all",1);
	me->move(exitroom);
	me->add_temp("block_msg/all",-1);
	tell_object(me,MAG"楼上风色不比三仙，只有粗鄙男子一个，还是不看为妙。\n"NOR);
    }
}



/*

	       (\~~~/)            
	       ( ．．)        

	       (_____)~．      

　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

