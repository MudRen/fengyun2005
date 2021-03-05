// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object con,item;
        set("short", "黄山剑庐");
        set("long", @LONG
好不容易过铁索，眼前不觉一亮，峰顶居然有间茅屋，屋上居然也有牌匾上书
“黄山剑庐”，屋内陈设简单，一张红木桌上放着几册经卷，笔筒中稀疏地插着几只
狼毫，西墙一柄长剑，上书“苍穹”二字。
LONG
        );
	set("exits", ([ 
	  "south" : __DIR__"tiesuo",
	]));
    	set("objects", ([
        	__DIR__"npc/mas1" : 1,
        	__DIR__"npc/mas2" : 1,
		__DIR__"obj/xi" : 1,
    	]) );
    
    	set("valid_startroom", 1);
    	set("no_lu_letter", 1);
	set("coor/x",-140);
	set("coor/y",10);
	set("coor/z",40);
	setup();      
}

void init()
{
        add_action("climbing", "climb");
}

void reset()
{
	object me,me2;
	:: reset();
	me2=present("master li",this_object());
	me=present("master liu",this_object());
	if(me) me->dismiss_team();
	if(me2) me2->dismiss_team();
	if(me && me2) me->add_team_member(me2);
}


int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "valley" || arg == "down" || arg == "谷壁")
        {
	       me = this_player();
	       if (me->is_busy())
	       		return notify_fail("你现在正忙。\n");
	       if (me->query_temp("huangshan/hs_climb_down"))
	       		return notify_fail("你已经在往下爬了。\n");
	       message_vision("$N抓着突出的石角，慢慢的顺着谷壁爬了下去。\n", me);
	       call_out("fliping",4,me);
	       me->set_temp("huangshan/hs_climb_down",1);
	       me->start_busy(2);
	       return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}

int fliping(object me)
{
        if(!me->is_ghost() && objectp(me) && environment(me)==this_object()) {
        	me->move(__DIR__"kuzhu");
        	me->delete_temp("huangshan/hs_climb_down");
        	message_vision("$N顺着谷壁爬了下来。\n", me);
        }
        return 1;
}

