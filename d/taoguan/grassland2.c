
inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
西面是陡峭的山崖，东面水声隆隆，白雾阵阵，远远看去是一个大湖。地上碧
草如茵，长着各式各样的奇异花卉，那些药农们辛劳一世也未必得以一见的珍贵药
草，在这儿却只是普通的点缀之物。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"east" : __DIR__"lake2",
  		"north" : __DIR__"taoguan",
  		"south" : __DIR__"grassland1",
	]));
	set("item_desc", ([
		"奇异花卉": "名贵的药草，你忍不住想要摘(pick)几把。\n",
		"珍贵药草":"名贵的药草，你忍不住想要摘(pick)几把。\n",
		"药草":"名贵的药草，你忍不住想要摘(pick)几把。\n",
		"flower":"名贵的药草，你忍不住想要摘(pick)几把。\n",
		"herb":"名贵的药草，你忍不住想要摘(pick)几把。\n"
	]));
	set("outdoors", "taoguan");
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
}

int init(){
	add_action("do_pick","pick");
}


int do_pick(string arg) {
	int num;
	object herb, me = this_player();
	if (arg == "flower" || arg == "herb" || arg == "奇异花卉" || arg =="珍贵药草" || arg == "药草") {
		message_vision("趁没人注意，$N低下身去拉了拉地上的花草。\n",this_player());
	    tell_object(this_player(),"
你感到脖子发凉，黑暗处好像有双眼睛盯着你！
你仔细地看了一下四周，却什么也没有！\n");
		if (!this_player()->query("宿命A/三清_摘花")) {
			num = 1 + random(10);
	   		this_player()->set("宿命A/三清_摘花",num);
	   		log_file("riddle/FATE_LOG",
				sprintf("%s(%s) 得到宿命A/三清_摘花 "+num+"。 %s \n",
						me->name(1), geteuid(me), ctime(time()) ));
		}
		return 1;
    }  
    return notify_fail("你想摘什么？\n");
}

