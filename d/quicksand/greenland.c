
inherit ROOM;

void create()
{
        set("short", "绿洲");
        set("long", @LONG
脚下的流沙突然不见，凉爽的微风拂面而来，一个小小的湖泊呈现在你的眼前。
水虽然只有二指厚，却很清澈，湖边绿树成荫绿草芬芳。虽然在酷热的沙漠中，湖
水仍是那么的清凉。从这儿一直向西，就可以走到关外的[33m大昭寺[32m，向北越过沙岭便
是著名的[33m玉门关[32m，也就是通向[33m藏北之地[32m的必经之路。
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"desert9",
  		"north" : __DIR__"sandlin",
  		"east" : __DIR__"desert7",
	]));
	set("objects", ([
		__DIR__"npc/thinlama" : 1,
	]));
	set("resource/water",1);
        set("liquid", (["container": "湖"]));
        set("outdoors", "quicksand");

	set("coor/x",-1085);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
