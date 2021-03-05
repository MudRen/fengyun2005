// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";

void tell_team(object who,string what)
{
	object *team;
	int i; 
	object ob,me=who;
	team=pointerp(who->query_team()) ? who->query_team() : ({ who });
	if(team)
	{
		for (i=0; i<sizeof(team); i++)
		{
			if (!team[i]) continue;
			tell_object(team[i],what);
		}
	}
	return ;
	
}

void create()
{
	set("short", YEL"黄树林"NOR);
    set("long", @LONG
挤出狭窄的山缝，迎接你的是一片奇特的树林。从未见过的各种参天巨木
如列阵般在黑软的淤泥上排布得井然有序，远远看去，犹如墨盘上还未动过的
木棋。仰头上望，但见覆满苍穹的木叶竟无一片苍碧，满满漾着浅浅的鹅黄，
枝条如镀金边，构筑为一种奇异诡谲的美丽。
    不知名的季节，微风。
    金色的光线从树顶中浅浅地透了下来。
LONG
NOR
        );
	set("objects", ([

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"eastdown" : "peak3",
  		"westup" : "peak3",
	]) );

	set("stat",1);
	set("free_cmds",1);

	set("area","cyan4");


	set("item_desc", ([

	"eastdown": "四周大雾迷蒙，你什么也看不清楚。\n",
	"westup": "四周大雾迷蒙，你什么也看不清楚。\n",

	]) );

	set("coor/x",-60);
	set("coor/y",30);
	set("coor/z",90);
	setup();
}





int do_start(object me)
{
	set("commencer",time());
	set("apres_vague",time() + 30);
	set("owner_ob",me->query("id"));

	me->set_temp("annie_quest/cyan4",0);
	me->set_temp("annie_quest/cyan42",0);

	tell_room(this_object(),WHT"\n四周大雾重重，一片静霭，不闻鸟叫虫鸣，惟有一阵阵细碎的呼吸．．\n\n有杂乱无章的脚步声自遥远的彼方似有似无传来。\n\n"NOR);

	
	call_out("attacks",30,me,1,1);

	return 1;

}




void failedd()
{
	object here = this_object();
	object r,*inv;
	int i;
	r=find_object("/d/cyan/path5");
	if (!r)
		r=load_object("/d/cyan/path5");


	inv = all_inventory(here);
	i = sizeof(inv);
		while(i--) 
				if(userp(inv[i])|| inv[i]->query("possessed")|| inv[i]->query("player")==1) 
					inv[i]->move(r);
				else
					destruct(inv[i]);

	"/d/phoenix/base/alive.c"->destruct_area(query("owner_ob"));
}

void finished(object me)
{
	tell_room(this_object(),HIC"\n一声清幽响亮的鸽哨自远方传来，你想起与平七的约定，匆匆向黄树林外奔去。\n\n"NOR);



	me->set("quest/short", WHT"回去向平七打听"CYN"任务结束"NOR);
	me->set("quest/duration",120);
	me->set("quest_time",time());
	tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);



	failedd();

	return;

}

void attacks(object me,int w,int n)
{

	object here = this_object();
	object o;
	int i,j;

	if (w==5)
		j=2+random(2);
	else
		j=3+random(6);

	if (!me)	//player quit?
	{
		failedd();
		return;
	}

	if (wizardp(me))
		tell_object(me,HIG"wave="+w+" n="+n+NOR);

	if (w<5)
	{
		o = new(__DIR__"npc/r"+w);
		o->move(this_object());
		o->set("ol",me);
		o->go(me);
	}
	else
		for (i=0; i<j; i++)
		{
			o = new(__DIR__"npc/r"+w);
			o->move(this_object());
			o->set("ol",me);
			o->go(me);
		}
		


	if (random(3)+1 < n)
	{
		if (w<6)
			call_out("attacks",20+random(10),me,w+1,1);
		else
			call_out("finished",20+random(10),me);
	}
	else
		call_out("attacks",20+random(10),me,w,n+1);

	return;

}

int	valid_leave(object who, string dir)
{
	object me;
	me = who;
	return notify_fail("平七要你在这里静静埋伏，还是不要乱动，以免打草惊蛇。\n");
}


void init()
{
   	add_action("aa", "a");
	::init();
}

int aa()
{
	if (wizardp(this_player()))
		do_start(this_player());
	return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/


