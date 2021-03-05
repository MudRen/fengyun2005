inherit ROOM;
void create ()
{
        set ("short", "阴暗小路");
        set ("long", @LONG
沉香城西南一条阴暗潮湿的小路，周围散落着残垣断壁，路边杂草丛生。官府
很少管这里，所以治安并不十分好。到处是沉闷的灰色，不见一丝生机。路边立着
一个破木牌子上潦草的写着官府告示：『近日[33m西山[32m群狼横行，占山为王，打劫过往
客商，官府无力顾及，行旅安全不得保障，姑忠告暂停西行。若不听劝告，私自身
涉险境，后果自负。』
LONG);
        set("exits", ([ //sizeof() == 4
                "east" : AREA_CHENXIANG"mw",
		"west" : __DIR__"yinroad2",
        ]));
        set("outdoors", "wolfmount");
        set("item_desc", ([
	        "paizi": @TEXT
近日西山群狼横行，占山为王，专门打劫过往客商，官府无力顾及，
鉴于大家之安全问题日益严重，官府建议暂时不要西行。如有不听劝
告，私自身涉险境，一切后果自负。
TEXT
	]) );
        set("type", "road");
	set("coor/x",80);
	set("coor/y",180);
	set("coor/z",-60);
        setup();
	replace_program(ROOM);
}
