inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", HIR"探花阁顶楼"NOR);
    set("long", "明月几时有，把酒问青天。不知天上宫阙，今夕是何年。我欲乘风归去，
惟恐琼楼玉宇，高处不胜寒。起舞弄清影，何似在人间。
转朱阁，低绮户，照无眠。不应有恨，何事长向别时圆。人有悲欢离合，
月有阴晴圆缺，此事古难全。但愿人长久，千里共婵娟。。\n"NOR                                   
        );
        set("exits", ([ 
  	"down" : __DIR__"poemp4",
]));
        set("objects", ([
 //	__DIR__"npc/mother4" : 1,
                        ]) );
	set("no_death_penalty",1);
	set("NONPC", 1);
	set("PK_FREE", 1);
	set("no_fly", 1);
  	set("coor/x",-40);
 	set("coor/y",20);
 	set("coor/z",40);
	setup();
}
