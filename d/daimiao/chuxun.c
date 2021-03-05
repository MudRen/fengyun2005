//mac's chuxun.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","出巡阁");
  set("long",@LONG
此阁按东岳大帝出巡的场面列置：前有卫士，十八学士，东岳大帝乘坐四轮六
马大辇，两边各为八人大轿，穿红衣者为炳灵公，穿蓝衣者为延嬉工，除前簇后拥
的文武百官外，中间还有乐队，仪仗。最前面是夜叉鸣锣，骐鳞开道。
LONG
  );
  	set("exits",([
         	"east":__DIR__"renan",
         	"north": __DIR__"w_bei",
         	"west": __DIR__"xihua",
               ]));
        set("objects", ([
                __DIR__"npc/tong":	1,
                
       	]) );
	set("coor/x",-20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

int valid_leave(object who, string dir) {
	object wei;

		if (who->query("class") == "demon")
		return 1;

	if (dir =="east" || dir =="north") {
		if (wei = present("tong wei",this_object()))
		if (!userp(wei) && !who->query_temp("daimiao/passwd") ) {
			return notify_fail(wei->name()+"喝道：“口令！”（answer）\n");
		if (who->query("vendetta/demon"))
			return notify_fail(wei->name()+"喝道：小子，杀了人还敢来？\n");
		}
	}
	return 1;
}