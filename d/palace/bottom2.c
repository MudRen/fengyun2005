
inherit ROOM;

void create()
{
        set("short", "湖底");
        set("long", @LONG
这里实在很美，很静。泉水清澈冰凉，各式各样的鱼虾在你的面前悠闲的游来
游去，看著水草在砂石间娥娜起舞，这种感觉不是未曾经历此境的人所能领略到的。
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"bottom",
  		"north" : __DIR__"bottom3",
  		"up" : __DIR__"smalllake",
  		"south" : __DIR__"bao",
	]));

	set("coor/x",-50);
	set("coor/y",70);
	set("coor/z",0);
	set("underwater",30);
	set("water_damage",20);
    	setup();
}


void init(){
    	object me;
	if (userp(me=this_player()))
		me->apply_condition("underwater",10);
}
