inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "南街");
        set("long", @LONG
小街的繁华很快就到了尽头，往远处看，南面是一条湍急的河流。一条黑猫被
脚步声惊起，却已失去了它原有的机敏和灵活，喘息着，蹒跚爬过长街，看来几乎
已不像是一条猫。路旁有一家店铺，招牌上写着“李记杂货铺”几个黑字。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"zahuopu",
		"north": __DIR__"sstreet2",
		"south": __DIR__"sstreet4",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",-30);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
