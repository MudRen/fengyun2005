//Sinny@fengyun 2003 
//All Rights Reserved ^_^
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIB"海角"NOR);
    set("long", @LONG
海是什么颜色？
    蓝色。
    那你的心是什么颜色？
    也是蓝色。
    为什么？
    因为那里只有悲伤。
LONG
    );
    set("exits", 
      ([ 
	"west" : __DIR__"huangsha1",
      ]));
    set("objects", 
      ([ 
	__DIR__"npc/meiyinxue" : 1,
      ]));
    set("indoors", "baiyun");
    set("coor/x",10);
    set("coor/y",-10);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
