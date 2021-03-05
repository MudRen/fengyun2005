inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "杜氏暗器铺");
        set("long", @LONG
小小的铁铺，墙壁已被火熏黑。一个小孩子正在拉着风糟。炉火熊熊地飞扬，
站在那前面的一个老头儿似乎已被烤干。他赤裸着上身，肋骨根根可数，那张脸
亦是干尸一样，灰白的须发卷卷曲曲，也不知是天生如此，还是因为经年累月伴
着火炉，被火烘成这样。他一只手拿着铁锤，另一只手拿着火钳，正在打着一件
奇形怪状的东西。
LONG
        );
        set("exits", ([ 
	"north" : __DIR__"vroad4",
	]));
        set("objects", ([
		__DIR__"npc/du":1,
	]) );
	set("coor/x",80);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
