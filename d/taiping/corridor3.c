#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "回廊");
        set("long", @LONG
一路朱红栏杆，院子遍植花树，却已凋零，花寒依稀梦，蝉语诉秋心。这儿只
有花香，只有虫声，莫说歌声无影，连酒气都没有，和鹦鹉阁里歌舞升平的气氛大
相径庭。抬头望去，空中一排人字形的大雁飞过，雁声嘹亮，凄凉。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"corridor2",
		"west": __DIR__"garden",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-90);
	set("coor/y",-40);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


int valid_leave(object me, string dir) {
	object man;
	if( userp(me) && REWARD_D->riddle_check(me,"喋血鹦鹉")== 9
		&& ( me->query_temp("marks/parrot/reject_sanye") || me->query_temp("marks/parrot/answer_sanye")
		&& !me->query_temp("marks/parrot/sanye_ass"))) {
		if (man=present("middle age man",this_object())) 
				return ::valid_leave(me,dir);
		man = new(__DIR__"npc/assassin");
		if (man) {
			
			message_vision(HIG"忽然，芭蕉叶翻，一个衣衫惨绿的中年人手按蕉叶从树后走出。\n"NOR, me);
			man->move(this_object());
			message_vision("$N叹了一口气，道：“你一定要找死，我们也没有办法。”\n",man);
			man->kill_ob(me);
			me->kill_ob(man);
			me->perform_busy(1);
			me->set_temp("marks/parrot/sanye_ass",1);
		}	
	}
	return ::valid_leave(me, dir);
}	

