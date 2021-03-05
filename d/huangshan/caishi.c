// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "采石峰");
        set("long", @LONG
这里相传是女娲采石补天所取天下山石中精英所在，山色与别山迥异，竟似有
五色，山上树木也分外茂密，山藤蔓绕，由于游人到松谷庵后多半力竭，加之这里
山藤环绕，甚是难走，所以已无游人到此。远远看见轩辕峰，却已无力过去。
LONG
        );
	set("exits", ([ 
		"southdown" : __DIR__"sroad",
  		"north" : __DIR__"xuanyuan",
	]));
        set("objects", ([
        	__DIR__"npc/dizi2" : 1,
    	]) );
    
    	set("item_desc", ([
    		"vine": "山藤蔓绕，也许可以用什么东西砍开。（chop）\n",
    		"山藤": "山藤蔓绕，也许可以用什么东西砍开。（chop）\n",
    		"山石": "女娲采石补天所取天下山石中精英所在，如果有趁手的工具，
说不定你还能挖出些什么。（dig）\n",
    		"rock": "女娲采石补天所取天下山石中精英所在，如果有趁手的工具，
说不定你还能挖出些什么。（dig）\n",
    	]));
    	
        set("stone_amount", 2);
        set("outdoors", "huangshan");
		set("coor/x",-140);
		set("coor/y",-20);
		set("coor/z",40);
		setup();
}

void init()
{
	add_action("do_chop","chop");
}


int do_chop(string arg)
{
    object obj, me;
    if(!arg || arg=="") return notify_fail("你要砍开什么？\n");
    if( arg == "vine" || arg == "山藤")
	{
        me = this_player();
        obj = me->query_temp("weapon");
        if( !obj )
        {
        	write("你空着手，怎么砍？\n");
        	return 1;
        }
        if( obj->query("jungle"))
        {
        	if( !query("exits/north") ) {
        	set("exits/north", __DIR__"xuanyuan");
        	message_vision(sprintf("$N用手中的%s砍出一条向北的路．\n",obj->name()),
                me);
        	me->perform_busy(1);
        	}
        	else
        		message_vision(sprintf("$N用手中的%s砍向环绕的山藤．\n",obj->name()), me);
        }
        else
        	message_vision(sprintf("$N用手中的%s向蔓绕的山藤一顿乱砍，太不顺手了！\n",obj->name()),me);
        }
    else
         write("你要砍开什么？\n");
    return 1;
}

int dig_notify() {
	object me, item;
	int i;
	
		me = this_player();
		i = NATURE_D->get_season();
		if(me->is_busy()) { 
			write("你现在正在忙！\n");
			return 1;
		}
		if(me->is_fighting()) return 0;
			
		if( me->query_str() < 30) {
			write("你用力往地上一刨，坚硬的土地震得你虎口发痛(需30力量)。\n");
			message("vision", me->name() + "用力一刨，只听“锵。。。”的一声，土地却丝毫未损。\n",
				environment(me), me);
		} else {
			if (random(10) > 7 && query("stone_amount") >= 0) {
				message_vision("$N用力往地上一刨。\n", me);
				write(HIW"你发现一块纹理灿烂的石头。\n"NOR);
				if (random(10) > 7) {
					item = new(__DIR__"obj/xishi2");
					item->move(this_object());
				} else {
					item = new(__DIR__"obj/xishi");
					item->move(this_object());
				}
			   	if (!REWARD_D->check_m_success(me,"凝露黄石")	// 做过了或者已经开始了就不应该再做mark
			   		 && !REWARD_D->riddle_check(me,"凝露黄石")) 
					REWARD_D->riddle_set(me,"凝露黄石",1);
				add("stone_amount", -1);
		} else {
				write("你在地上刨了个大坑，但这里什么也没有找到,换个地方或过阵子再挖？\n");
		}	
	}
	me->start_busy(1);
}


void reset() {
	::reset();
	if (!random(4))	set("stone_amount", 2);
	delete("exits/north");
}
