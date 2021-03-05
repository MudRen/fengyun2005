
#include <room.h>
inherit ROOM;
void create()
{
  set("short","配天门");
  set("long",@LONG
配天就是取孔子之语“德配天地”之意。配天门面阔五间，进深三间，歇山顶，
前后步廊式穿堂而过。殿内有青龙、白虎、朱雀、玄武等四方星宿的泥塑神像。朱
漆大门上的额匾上御笔题写着配天门三个大字。向东可至汉柏院，向西有雨花道院。
LONG
  );
  	set("exits",([
         	"north":__DIR__"renan",
         	"south":__DIR__"zhengyan",
         	"east" :__DIR__"sanling",
         	"west" :__DIR__"taiwei",
               ]));
        set("objects", ([
                 __DIR__"npc/yin":	1,
       	]) );
	set("coor/x",0);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}



int valid_leave(object who, string dir) {
	object wei;

		if (who->query("class") == "demon")
		return 1;

	if (dir == "north" || dir =="east" || dir == "west") {
		if (wei = present("yin wei",this_object()))
		if (!userp(wei) && !who->query_temp("daimiao/passwd") ) {
			return notify_fail(wei->name()+"喝道：“口令！”（answer）\n");
		if (who->query("vendetta/demon"))
			return notify_fail(wei->name()+"喝道：小子，杀了人还敢来？\n");
		}
	}
	return 1;
}

	