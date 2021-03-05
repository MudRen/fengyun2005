// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "刀山狱");
        set("long", @LONG
一片开阔的平地，地上倒插了数不尽的尖刀，在牛油巨烛的映照下，刀刃的寒
光显得森冷无比，触目惊心，犯人戴着长链从这头走到那头，一般走不到十分之一
就倒了下去，被扎成刺猬一般，这时候鬼卒会放下挠钩，搭上来逼你从新走过，日
复一日，年复一年。这里往下便是最后一类人关押的地方了，都是万死难赎之徒。
LONG
        );
        set("exits", ([
		"up" : __DIR__"heian",
		"down" : __DIR__"xuechi",
        ]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",-150);
	set("no_fight",1);

	setup();
        replace_program(ROOM);
}
 
