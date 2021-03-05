// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "藏阁东廊");
        set("long", @LONG
红木长廊，上雕飞凤，美伦美焕，道路宽阔无比，路中有大锅一口重一千一百
斤，明代所铸，每顿所产，足够全寺食用，后少林日益蓬勃，此锅尚不能足，便放
置于此，供游人赏玩。
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"changjing",
]));
        set("objects", ([
                __DIR__"obj/daguo" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",-30);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
