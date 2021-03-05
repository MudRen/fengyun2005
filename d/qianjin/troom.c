inherit ROOM;
void create()
{
        set("short", "私刑房");
        set("long", @LONG
这里是千金楼逼良为娼的地方。每个不肯就范的姑娘都会被关在这里，不给吃
喝。如还不从，则严刑拷打。墙上和地上都有暗红色的血迹。屋角一张肮脏的小床，
床上发灰的床单，似乎还有老鼠咬过的痕迹。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
 	 		"west" : __DIR__"sr2",
	]));
       set("objects", ([
        __DIR__"npc/funu" : 2,
                        ]) );

	set("coor/x",-50);
	set("coor/y",15);
	set("coor/z",-10);
	setup();

}
			
void reset() {
	string item= "broken_cloth";
	int num = 2;
	object obj, *inv;
	
	:: reset();
	
	inv = all_inventory();
	foreach (object ob in inv) 
	{
		if (userp(ob)) continue;
		if (ob->query("id") == "neiyi") destruct(ob);
	}
	while (num--) 
	{
		obj = new(__DIR__"obj/"+item);
		obj->move(this_object());
	}
}

int valid_leave(object me, string dir)
{
 	REWARD_D->riddle_done(me,"千金暗舱",10,1);
	if (QUESTS_D->verify_quest(me,"千金暗舱"))
		QUESTS_D->special_reward(me,"千金暗舱");  
	return 1;
}