inherit ROOM;
void create()
{
    set("short", "会客厅");
    set("long", @LONG
大厅布置简单，几张太师椅围着一张八仙桌。房间的两侧是一些小巧玲珑的陈
设品。每当风吹入门，门口的风铃发出沙哑的低吟。红砖铺地，上面似乎还有条条
暗红色的花纹。大厅左右各有小门。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"jinqian",
	"north" : __DIR__"jhuang",
	"south" : __DIR__"jhuang1",
      ]));
    set("coor/x",-180);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}
