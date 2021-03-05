#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "风云堂");

	set("long", @LONG
风云客栈的大堂，几张大红木的八仙桌上还镶着云石，墙上挂着各方名家的书
画，架上摆着四季长开的鲜花，让人一走进来，就会觉得自己能在这种地方吃饭是
种荣幸。平时客栈里川流不息地进出的俱是些挺胸凸腹的武林豪杰。
LONG);

	set("type","house");
	set("exits",([
		"south":__DIR__"fyhotel",
		"north":__DIR__"fyyard",
	]) );
        set("indoors", "chenxiang");
	set("coor/x",20);
	set("coor/y",50);
	set("coor/z",0);
	set("item_desc", ([
                "picture": "一幅名家的书画，似乎位置不是很正。\n",
                "书画": "一幅名家的书画，似乎位置不是很正。\n",
                "wall": "雪白的墙上挂着几幅名家的书画，但是书画似乎挂歪了。\n",
                "墙": "雪白的墙上挂着几幅名家的书画，但是书画似乎挂歪了。\n",
        ]) );
	set("objects",([
     		__DIR__"npc/fang":1,
    	]) );
	setup();
}

void init()
{
	add_action("do_pull", ({"pull","open"}));
}

int do_pull(string arg)
{
        object me;
        object fang;
        me=this_player();
        
        if(!arg || arg=="")
        {
			return 0;
        }
        if( arg == "picture" || arg == "书画")
        {
        	if(fang =present("fang longxiang",this_object()))
        	{
        		message_vision(HIR"$N对$n大喝一声：兔崽子，敢打老子的主意，拿命来！\n"NOR, fang,me);
        		fang->kill_ob(me);
        		me->kill_ob(fang);
        		return 1;
        	}
        	else
        	{
        		message_vision("$N拉起墙上的书画，发现了一个暗门。\n", me);
        		if( !query("exits/east") ) 
        		{
        			set("exits/east", __DIR__"stoneroom");
        			call_out("close_path", 2);
        		}
        		return 1;
        	}
        }
        else
        {
                write("你不可以打开"+arg+"\n");
                return 1;
        }
}

void close_path()
{
        if( !query("exits/east") ) return;
        message("vision","书画荡了回来，又遮住了暗门。\n",this_object() );
        delete("exits/east");
}

int valid_leave(object me, string dir)
{
//	object fang;
        if( 	userp(me) && dir=="north"
        	&&	present("fang longxiang", this_object())
        	&& !REWARD_D->check_m_success(me,"天上白玉京"))
        {        	
		return notify_fail("方龙香伸手挡住去路：后边是客房，还是不要打搅客人的好！\n");
	}
	return 1;
}