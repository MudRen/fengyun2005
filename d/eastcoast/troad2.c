inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
这里的灌木更高了些，几乎使你分不清前方的道路。一不小心就被树枝挂到了
手脚，往前走又不知通往哪里，你不禁产生了退缩之心。
LONG                                         
        );
        set("exits", ([
		  "south" : __DIR__"troad1",
		  "west" :  __DIR__"troad3",  
		  "east" :  __DIR__"troad4",
	])); 
	set("outdoors","tieflag"); 	
	
	set("coor/x",610);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}