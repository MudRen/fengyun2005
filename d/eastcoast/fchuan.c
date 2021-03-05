inherit ROOM;
void create()
{
 set("short", "靠在海边的船");
 set("long", @LONG
大海，一望无际的大海。海边舶着一艘船。精巧的叁桅船，洁白的帆，狭长的
船身，坚实而光润的木质，给人一种安定、迅速、而且华丽的感觉。阳光灿烂，海
水湛蓝，海鸥轻巧地自船桅间滑过，充满了青春的欢乐。
LONG);
	set("exits", ([ 
	  "west" : __DIR__"lin2",
	  ]));
	set("objects", ([
		  AREA_BAT"npc/chu": 1,
		  AREA_BAT"npc/lihong": 1,
	 ]) );
	set("coor/x",1020);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
 	replace_program(ROOM);
}
