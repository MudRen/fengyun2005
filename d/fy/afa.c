inherit ROOM;
void create()
{
    set("short", "阿发木器店");
    set("long", @LONG
这里的老板是从南方过来的。官话很差，所以生意并不很好。但阿发好像并不
在乎，似乎另有发财之路。他好像很怕光，所以这里一盏灯也没有，从傍晚开始，
店里黑漆漆的一片，阿发就睁着一双发亮的眼睛坐在屋里望着门外的大街。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"ecloud31",
      ]));
    set("objects", ([
	__DIR__"npc/afa" : 1,
      ]) );

    set("coor/x",200);
    set("coor/y",20);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
