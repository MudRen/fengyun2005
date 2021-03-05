// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "白水殿");
        set("long", @LONG
一座高大的殿堂，在山腹中有如此杰作，实在让人叹为观止，可见构思人的心
机是多么的巧妙，工程是多麽的巨大。殿很大，中间却没有一根柱子，大殿的顶上
镶满了各色珍珠和珊瑚，正中间是一张雕花椅，四周静静的站了几个侍女。
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([ 
  "southdown" : __DIR__"huoyan",
  "east" : __DIR__"shanfang",
  "west" : __DIR__"yaofang",
  "northeast" : __DIR__"woshi",
  "northwest" : __DIR__"qingong",
   ]));
   
   set("objects", ([
      __DIR__"npc/master" : 1,
      __DIR__"npc/girl": 3,
   ]) );
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();

}


int valid_leave(object me, string dir)
{

 	REWARD_D->riddle_done(me,"神水探幽",10,1);
	
/*	if (me->query("marks/enter_ss/风筝") 
		&& me->query("marks/enter_ss/白石") 
		&& me->query("marks/enter_ss/钓鱼")) {
		me->delete("marks/enter_ss");
		REWARD_D->riddle_done(me,"三入神水",20,1);
	}*/
	
	if (QUESTS_D->verify_quest(me,"神水探幽"))
		QUESTS_D->special_reward(me,"神水探幽");
	return 1;		
	
}

