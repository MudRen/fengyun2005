// searoad.c
inherit ROOM;
void create()
{
        set("short", "山中小路");
        set("long", @LONG
这里往东，地势略略向下倾斜。路两旁的灌木渐渐换成乔木，越走地势越开阔，
再走下去显然要走到大道上去了。
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"troad2",
  		"east" : __DIR__"plain",
	]));
        set("outdoors", "tieflag");
	set("coor/x",870);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
