inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"光阴树"NOR);

	set("long", @LONG
一种不知名的古树，树干上缓缓流着乳白的汁液，藏人们称之为光阴树。站在
浓厚的树阴下远眺，远处的白云在天，风在树梢，积雪的山巅在晴朗的蓝天下，平
凡的人在为自己的生活挣扎，不平凡的人在为自己的生命奋斗。
LONG);

	set("type","street");
	set("exits",([
        "northeast":__DIR__"birdroad2",
		"southwest":__DIR__"birdroad3",
	]) );
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/bancha" : 1,
        ]) );   
	set("coor/x",-15);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}

void init ()
{
        add_action ("do_climb", "climb");
}

int do_climb (string arg)
{
	object npc,me,room;
	int dodge;
	me = this_player();
	dodge = me->query_skill("move",1);
	if (!arg || (arg != "tree" && arg != "光阴树" && arg != "up"))
		return notify_fail("你要爬什么？\n");
	else if( npc = present("bancha bana", this_object()) )
	{
		message_vision("$N斜瞥了$n一眼：班察的五花神箭很久没有饮血了，你莫非想试一下？\n",npc,me);
		return notify_fail("看来不杀班察巴那，是上不了树的．\n");
	}
	else if (dodge < 120)
		return notify_fail("树太高，你的轻功太差，爬不上去耶（需１２０级）\n");
	else
	{
		room = find_object(__DIR__"birdhouse");
		if(!room)
			room=load_object(__DIR__"birdhouse");
		message_vision("$N手足并用，慢慢的爬上光阴树．\n",me);
		me->move(room);
		me->start_busy(2);
        	message("vision",me->name()+"从树下爬了上来。\n",room,me);
		return 1;
	}
}

int valid_leave(object me,string dir)
{
        if ( (dir=="southwest") &&  present("bancha bana", this_object()))
        {
        	if( !me->query_temp("marks/won_bancha") )
        	{
        		return notify_fail("班察巴那冷笑一声道：尔等凡夫俗子，怎配踏入我圣母雪峰半步，除非你打赢我！\n");
        		return ::valid_leave(me,dir);
        	}
        	else
        	{
        		return 1;
        	}
        }
        return 1;
}
