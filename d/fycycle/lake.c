inherit ROOM;
void create()
{
        set("short", "梅林");
        set("long", @LONG
长堤转了几个弯，遍地都是梅树，老干横斜，枝叶茂密，想像初春梅花盛开之
日，香雪如海，定然观赏不尽。行不几步，转入了一条山脚下的小道，走到一座
小桥前，梅树丛中，有三五石屋，红花白屋，风物宛如图画。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"northeast" : __DIR__"sroad3",
  		"west":      __DIR__"village",
	]));
        set("outdoors", "fengyun");
		set("coor/x",-120);
		set("coor/y",-320);
		set("coor/z",0);
        setup();
}

int valid_leave(object who, string dir) {
	object ob;
	
	if (dir == "west") {
		if (QUESTS_D->verify_quest(who,"竹林医隐"))
		QUESTS_D->special_reward(who,"竹林医隐");
	}			
	return ::valid_leave(who, dir);	
}

