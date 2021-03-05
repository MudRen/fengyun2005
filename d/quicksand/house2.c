
inherit ROOM;

void create()
{
        set("short", "富家客厅");
        set("long", @LONG
走过木叶森森的院子，就是宽敞而华丽的客厅，堂前挂着几重竹帘，秋日的褥
暑，已全部被隔在帘外，微风吹动竹帘，重帘中似有燕子在飞翔。精美的瓷器里，
装着精美而可口的菜，白玉雕成的酒杯里，盛满了琉璃色的酒。
LONG
        );
        set("exits", ([ 
  		"out": __DIR__"house",
	]));
        set("objects", ([
        	__DIR__"npc/ji":	1,
                
        ]) );
	set("coor/x",-1035);
	set("coor/y",-10);
	set("coor/z",0);
	setup();

}

