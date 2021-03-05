
inherit ROOM;

void create()
{
        set("short", "翠竹屋");
        set("long", @LONG
青青的软竹搭成小小的翠竹屋，屋中几乎所有的家具都是用青竹编成的，透着
股儿怡人的清香，竹子怎么会有香味呢？亦或是竹几上紫砂茶具里逸出的袅袅茶香？
墙上悬着一幅墨竹，笔势纵横，墨迹淋漓，颇有森森之意。桌上放着一具瑶琴，一
管洞箫。一对少年男女正在品茶下棋。
LONG
        );
        set("exits", ([ 
		  "south" : __DIR__"front_yard",
		  "north" : __DIR__"back_yard",
		  "west" : __DIR__"teagarden",
		  "east" : __DIR__"restroom",
	]));
        set("objects", ([
                __DIR__"npc/master" : 1,
                __DIR__"npc/master2" : 1,
                __DIR__"npc/girl" : 1,
        ]) );
        set("valid_startroom", 1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
    
    REWARD_D->riddle_done(me,"铁雪侠隐",10,1);
    
    if (QUESTS_D->verify_quest(me,"铁雪侠隐"))
		QUESTS_D->special_reward(me,"铁雪侠隐");
		
    if( me->query("class") != "legend" && (dir == "east"|| dir== "west")) {
    	if(ob=present("master tieshao", this_object())){
        	return notify_fail("铁少微微皱了皱眉。\n\n这个方向的路被"+ob->name()+"挡住了 。\n");
		} else if(ob=present("master xuerui", this_object())){
			return notify_fail(ob->name()+"柳眉微蹙。\n\n这个方向的路被"+ob->name()+"挡住了 。\n");
		}
	}
	return 1;
}
