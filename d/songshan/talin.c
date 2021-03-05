
inherit ROOM;
void create()
{
        set("short", "塔林");
        set("long", @LONG
东接少林寺，是嵩山最灵秀之地，占地万余平方米，自唐至清历时千年的少林
方丈，高僧大都埋骨于此，大大小小二百二十多座砖石墓塔，按照死者生前的佛学
地位，修养等等大小不一，高下不一的排列着。墓塔造型各异，是研究古代砖石建
筑，雕刻艺术的宝库，最为出名的便是天竺和尚就公塔和日僧的菊庵塔。
LONG
        );
        set("exits", ([ 
  			"east" : __DIR__"houmen",
  			"northeast" : __DIR__"huishan",
  			"northwest" : __DIR__"damo",
  			"south" : __DIR__"erzu",
		]));
        set("outdoors", "songshan");
        set("objects", ([
                __DIR__"obj/ta1" : 1,
                __DIR__"npc/lama3" : 1,
       ]) );
        
        
		set("coor/x",65);
		set("coor/y",25);
		set("coor/z",0);
		setup();

}

void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
        object obj, room;
        object me;
        if(!arg || arg=="")
        {
                return 0;
        }
        if( arg == "tower" || arg == "塔" || arg == "就公塔" || arg == "up")
        {
	        me = this_player();
        	if (me->is_busy() || me->query_temp("climb/jiugong"))
        		return notify_fail("你现在正忙。\n");
        	
        	if (REWARD_D->riddle_check( me, "力斗三佛") != 2)
        		return notify_fail("塔林乃肃穆之地，没事儿乱跳干吗？\n");
        	
        	if (!room= find_object(__DIR__"talin_top"));
        		room = load_object(__DIR__"talin_top");
        	
        	if (room->usr_in())
        		return notify_fail("塔顶似乎站了许多人，没有你立足之地。\n");

			room->reset();
			        	        			
        	message_vision("$N纵身一跃，稳稳地落在就公塔顶。\n", me);
        	me ->move(room);
            return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
