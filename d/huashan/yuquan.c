
inherit ROOM;

void create()
{
        set("short", "玉泉院");
        set("long", @LONG
玉泉院位于华山峪口，乃攀登华山主峰必经之径。院中有清泉一股，清冽甘
美，饮之可口，玉泉院因之得名。院内古木擎天，绿茵婆娑，奇石嶙峋，小桥流
水，曲径回廊，风景如画。这里游人甚多，因此也有一些小摊贩再此摆摊，向游
人兜售各类物品。
LONG
        );
    set("exits", ([ 
  		"eastdown" : __DIR__"changpu",
  		"westup" : __DIR__"wuli",
		"northwest" : __DIR__"path1",
	]));
    set("resource/water", 1);
    set("liquid/container", "清泉");   
    set("liquid/name","玉泉水");
   	set("objects", ([
   		__DIR__"npc/seller1" : 1,
   	]));
    set("outdoors", "huashan");

	set("coor/x",-5);
	set("coor/y",10);
	set("coor/z",-10);
	setup();
}

void init(){
	object me;
	me = this_player();
	if ((int)me->query_condition("music") > 0) {
		tell_object(me, "琴声渐远，慢慢消失了。\n");
		me->clear_condition("music"); 
	}
}
