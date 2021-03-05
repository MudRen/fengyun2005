
inherit ROOM;

void create()
{
    set("short", "牢房");
	set("long", @LONG
这里是关押犯人的地方，不到十尺见方的牢房中没有床榻被褥，只有几堆枯黄
散发着难闻气味的稻草，不时的有大老鼠从你的脚下跑过，不知从那里飘来的腐臭
之气充斥着整个牢房。死寂黑暗的牢房里，不时从远处传来犯人的呼救声。
 [33m（ｌｉｓｔｅｎ　呼救声）[32m
LONG
	);
    	set("indoors", "jinan");
	set("coor/x",40);
	set("coor/y",20);
	set("coor/z",0);
	set("valid_startroom",1);
	set("no_magic", 1);
	setup();
}
void init()
{
	this_player()->set("startroom", base_name(this_object()));
	add_action("do_listen", "listen");
}

int do_listen(string arg)
{ 
	object player;
	player = this_player();
	if (arg == "sound" || arg== "呼救声")
	{
		tell_object(player,"你小心地想倾听远处牢房里的呼救声，可周围突然陷入死一般的寂静中。\n");
		tell_object(player,	"一阵惶恐涌上心头，你不由想大声呼救(yell help) \n") ;
		add_action("do_yell","yell");
	}else
	{
		return notify_fail("你要听什么？\n");
	}
	return 1;
}

int do_yell(string arg)
{
	object player,yuzuzhang;
	player = this_player();
	if (arg != "help")
	{
		return notify_fail("你要大声呼叫什么？\n");
	}else
	{
		message_vision("$N声嘶力竭地大喊：“快来人啊！放我出去！！！”\n",player);
		if (!random(3))
		{
			
			if (yuzuzhang = present("yuzu zhang",this_object()))
			{
				return notify_fail("狱卒长这会儿正忙着哪，没空理你！等会儿再试试吧。\n");
			}else
			{
				yuzuzhang = new(__DIR__"npc/yuzuzhang");
				yuzuzhang->move(this_object());
			}
			
			message_vision("只见$N慢慢踱了过来 \n",yuzuzhang);
			yuzuzhang->release_player(player);
		}
		else
		{
			tell_object(player,"你只听见你凄惨的叫声在空荡荡的牢房中回荡，更加加深了你的恐惧。\n");
		}
	}
	return 1;
}
