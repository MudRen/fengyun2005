// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "大雄宝殿");
        set("long", @LONG
此殿有称正殿，神台，月台，望柱一应俱全。殿内供佛像三尊，正是那释迦牟
尼佛，阿弥陀佛和药师佛。是为三世佛，象征着前世，今生和未来。四周壁画围绕，
飞天，法王簇拥佛祖，整个大殿香烛缭绕，让人不由得心生敬畏。明间檐下有匾额，
上书：
		
			大雄宝殿

LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"dianjiao",
  "eastdown" : __DIR__"jinna",
  "westdown" : __DIR__"liuzu",
  "northdown" : __DIR__"yonglu2",
]));
        set("objects", ([
                __DIR__"npc/master_22" : 1,
       ]) );
        set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}
int valid_leave(object me, string dir)
{
        object ob;
        if( userp(me))
        if( dir == "northdown" && ob=present("master yuan", this_object()))
	if((int)me->query("combat_exp") < 10000)	
	{
	ob->ccommand("shake");
	return notify_fail("");
	}
return 1;
}
