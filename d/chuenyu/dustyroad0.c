// Room: /d/chuenyu/dustyroad.c

inherit ROOM;

void create()
{
        set("short", "乡间小路");
        set("long", @LONG
山在风云城的东北三四十里地处，山脚下有一座小镇，一条黄土小路通向风云
城，南面是小镇的郊外，站在这里似乎还可以听到从小镇传来的噪杂人声。往北，
一座黑朦朦的山在云雾里忽隐忽现，那就是黑松山。
LONG
        );
        set("exits", ([ 
  		"southwest" : AREA_EASTCOAST"palace_path1",
  		"north" : __DIR__"dustyroad.c",
]));
        set("objects", ([
                __DIR__"npc/flowerseller" : 1,
        ]) );
        set("outdoors", "chuenyu");

	set("coor/x",-30);
	set("coor/y",-50);
	set("coor/z",-20);
	setup();
}
