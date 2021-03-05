#include <room.h>
inherit ROOM;

void create()
{
  	set("short","垂花门");
  	set("long",@LONG
东御座清代拓建后供皇帝朝山时驻跸，改名驻跸亭；又因在东华门内，故今称
东御座。御座由垂花门、仪门、大门、正殿和厢房组成。向西穿过垂花门，便是岱
庙东侧的东华门。
LONG
  );
  	set("exits",([
        	 "west":__DIR__"dongyu",
         	 "east":__DIR__"donghua",
         	 "north": __DIR__"e_bei",
         	 "south": __DIR__"hanbaiting",
        ]));
        set("objects", ([
                  __DIR__"npc/tie":	1,
       	]) );
        set("item_desc", ([
                
        ]) );
	set("coor/x",20);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
  	
}

int valid_leave(object who, string dir) {
	object wei;

		if (who->query("class") == "demon")
		return 1;

	if (dir == "north" || dir =="south" || dir == "west") {
		if (wei = present("tie wei",this_object()))
		if (!userp(wei) && !who->query_temp("daimiao/passwd") ) {
			return notify_fail(wei->name()+"喝道：“口令！”（answer）\n");
		if (who->query("vendetta/demon"))
			return notify_fail(wei->name()+"喝道：小子，杀了人还敢来？\n");
		}
	}
	return 1;
}