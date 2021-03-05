// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "衣钵寮");
        set("long", @LONG
这是专门制造僧衣所在，少林庙产众多，瓜果蔬菜，衣食起居的大部物品，皆
为自产。其中僧衣多为施主捐赠，但大小难以合意，便在此重新改制，你有兴趣，
不妨也可以买一件来穿穿。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"guagua",
]));
        set("objects", ([
                __DIR__"npc/clothmonk" : 2,
       ]) );
	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
