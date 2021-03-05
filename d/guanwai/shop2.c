#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"伊目布喇"NOR);
    set("long", @LONG
小小的店铺不过三坪，店内氲漫着藏香的白烟和酥油茶的香气，远处钟声不时
的鸣响，一声声梵唱随风飘来，小店里盈满了浓郁的密宗气息。店里出售各种藏宗
佛法祝福过的物件，有唐卡、佛像、摆饰和衣物，主人是一个摇动着手中转经筒的
喇嘛，正满脸微笑地看着你。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"octo3",
      ]));
    set("objects", ([
	__DIR__"npc/cloth" : 1,
      ]) );

	set("coor/x",20);
	set("coor/y",-10);
	set("coor/z",0);
    setup();
    replace_program(ROOM);

}

// 凝輕·dancing_faery@hotmail.com
