//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIG"迷仙引"NOR);
    set("long", @LONG
才过笄年，初绾云鬟，便学歌舞。席上尊前，王孙随分相许。算等闲、酬一笑，
便千金慵觑。常只恐、容易瞬华偷换，光阴虚度。
    已受君恩顾。好与花为主。万里丹霄，何妨携手同归去。永弃却、烟花伴侣。
教人见妾，朝云暮雨。 
LONG
    );
    set("exits",
      ([
	"down" : __DIR__"yaoxian",
	"up" : __DIR__"yinxian",
      ]));
    set("objects",
      ([
	__DIR__"npc/mixian" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",30);
    set("coor/y",-160);
    set("coor/z",50);
    setup();
    replace_program(ROOM);
}
