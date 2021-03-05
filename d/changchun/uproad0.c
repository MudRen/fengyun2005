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
        set("exits", ([ 
	  	"northeast" : __DIR__"uproad1",
  		"west" : __DIR__"island",
	]));
        set("outdoors", "tieflag");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
