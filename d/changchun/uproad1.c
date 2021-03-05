// searoad.c
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
小路曲曲折折返向山峰，一路上但见青翠的山林中，种满了五彩缤纷的花朵。
林木间，花光间，不时可瞧见亭台楼阁，翩翩人影，当真犹如一群仙女倘徉在这世
外仙山中。
LONG
        );
        set("objects",([
        	AREA_TIEFLAG"npc/qinggirl" : 1,
        	AREA_TIEFLAG"npc/qinggirl1" : 1,
        ]) );
        set("exits", ([ 
	  	"southeast" : __DIR__"uproad2",
  		"southwest" : __DIR__"uproad0",
	]));
        set("outdoors", "tieflag");
	set("coor/x",20);
	set("coor/y",10);
	set("coor/z",10);
	setup();
}
