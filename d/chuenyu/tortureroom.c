
inherit ROOM;

void create()
{
        set("short", "刑房");
        set("long", @LONG
整间刑房已被乾曷的血迹然成暗红色。散发着扑鼻的腥臭。墙上挂满了各式各
样的邢具。刑房的地上散落着生锈的铁链和破碎的骷髅。偶尔之间，你还可以听到
老鼠“吱吱”的尖叫声。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  			"west" : __DIR__"tunnel5",
  			"north" : __DIR__"tortureroom2",
		]));
        set("objects", ([
                __DIR__"npc/highrat": 2, 
		__DIR__"npc/guard2" : 2,

		]) );

	set("coor/x",20);
	set("coor/y",30);
	set("coor/z",5);
	setup();
}

