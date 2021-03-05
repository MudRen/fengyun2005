// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "内院门");
        set("long", @LONG
这是面并不高大的墙，闻得此门之后便是少林后院，也就是天下武学的发源地
--少林武院。墙前站着几个少林武僧，手持戒刀，纹丝不动地注视着前方。
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"neiyuan",
  		"southup" : __DIR__"qianfe",
	]));
        set("objects", ([
                __DIR__"npc/monk81" : 1,
                __DIR__"npc/monk82" : 1,
       	]) );
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",10);
	setup();
}

int valid_leave(object me, string dir)
{
        object *env, ob;
	int i;
		
	env = all_inventory();
	for (i=0; i<sizeof(env);i++)
	{
		if (env[i]->query("npc_team") == "shaolin_blade")
		{
			ob = env[i];
			break;
		}
	}

	if (F_LEVEL->get_level(me->query("combat_exp"))>=65){
		if (objectp(ob) && me->query("vendetta/shaolin")>=1)
			ob->ccommand("say 师叔祖吩咐了，将这贼子放进去关门打狗。");
		return ::valid_leave(me,dir);
	}
	        
	if( userp(me) &&
		dir=="north" && ob
		&& me->query("vendetta/shaolin")>=1 )
		return notify_fail( ob->name()+ "喝道：大胆贼子，敢闯少林内院！\n");
        
	if( userp(me) &&
		dir=="north" && ob &&
		(me->query("family/generation") > 22  ||
		me->query("family/family_name") != "少林寺"))
		return notify_fail(ob->name()+"说道：只有少林寺入室弟子才可以进入少林内院。\n");
	return 1;
}
