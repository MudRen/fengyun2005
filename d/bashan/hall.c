#include <room.h>
#include <ansi.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "大殿");
        set("long", @LONG
这是一间金碧辉煌的大殿，两行蟠龙巨柱，有如巨人般排列在大殿中央。巨柱
之间，又是一道猩红长毯。长毯尽头，石阶再起，上面一张巨桌，桌后一张巨椅，
桌椅俱有蟠龙雕花，闪耀著黄金色的光芒。
LONG
        );
	set("no_fly",1);
	set("exits",([
  		"north" : __DIR__"hole4",
	]) );
	set("item_desc", ([
		"north": "绿玉门此刻正半掩着，想是方才水如昔打开。\n",
	]) );
	set("objects", ([
	__DIR__"obj/master" : 1,
					]) );
	set("coor/x",-40);
	set("coor/y",220);
	set("coor/z",50);
	set("outdoors", "bashan");
	setup();
}

void init()
{
	if (userp(this_player()))
	{
		add("count",1);
		if (query("count") == 2)
			call_out("attack",16,this_player());
	}
}
int valid_leave(object me, string dir)
{
	if (dir == "north")
		return notify_fail("你正想举步，突然觉得一阵天旋地转．．．\n");
}

int attack(object ob)
{
	object *inv,p1,p2;
	int i;
	if (!ob)
		ob=this_player();
	message_vision(CYN"箫王孙的石像忽然挪开三尺，露出背后一条暗道。\n水如昔从暗道里走了出来，一怔之下，立时向你袭来！\n"NOR,ob);
	ob=new(__DIR__"npc/shui2");
	ob->move(this_object());
	inv = all_inventory(this_object());
	for (i=0;i<sizeof(inv) ;i++ )
	{
		if (inv[i]->is_corpse() || !inv[i]->is_character() || inv[i]==ob) continue;
		ob->kill_ob(inv[i]);
		if (userp(inv[i]) && !p1)
			p1=inv[i];
		else if (userp(inv[i]))
			p2=inv[i];
	}
	if (p1 && p2)
			CHANNEL_D->do_sys_channel(
			"sys", sprintf("%s(%s)与%s(%s)进入了巴山大殿。\n",
	                p1->query("name"),p1->query("id"),p2->query("name"),p2->query("id")));

	call_out("do_opengate",10,p1,p2,ob);
	return 1;
}

int do_instantsmash(object p1,object p2,object ob,int i)
{
	object me,who,room;
	mapping data;

	

	if (!ob)
		return 0;
	if (!p1 && !p2)
		return 0;
	
	if (query("done"))
		return 1;
	else
		set("done",1);
	
	if (!p1)
	{
		me=p2;
		tell_object(me,HIY"\n没有来由的，你突然觉得心头一冷，回首望去，只见"NOR);
		message_vision(HIY"\n两枚闪着金光的小东西从$N背后斜斜飞了过来．．．\n\n"NOR,me);
		message_vision(HIW"一道烁目的闪光掠过，跟随着＂啵＂的一声，声音并\n不很响，仿佛情人间相吻的轻触，你还没有反应过来\n究竟发生了什么，眼前就只剩一片茫茫雪白．．．\n"NOR,me);

        environment(me)->set("short","废墟");
        environment(me)->set("long","这里的一切都已经完了，好象刚刚经过一场浩劫，可是你连尸体都看不到，只\n能看到一片乌焦之中好象有些鲜红惨绿的痕迹．．．\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// 落花流水一起去:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","被散花天女炸成了碎片。");
		me->add_temp("block_msg/all",-1);
		me->die();	
		return 1;
	}
	if (!p2)
	{
		me=p1;
		tell_object(me,HIY"\n没有来由的，你突然觉得心头一冷，回首望去，只见"NOR);
		message_vision(HIY"\n两枚闪着金光的小东西从$N背后斜斜飞了过来．．．\n\n"NOR,me);
		message_vision(HIW"一道烁目的闪光掠过，跟随着＂啵＂的一声，声音并\n不很响，仿佛情人间相吻的轻触，你还没有反应过来\n究竟发生了什么，眼前就只剩一片茫茫雪白．．．\n"NOR,me);

        environment(me)->set("short","废墟");
        environment(me)->set("long","这里的一切都已经完了，好象刚刚经过一场浩劫，可是你连尸体都看不到，只\n能看到一片乌焦之中好象有些鲜红惨绿的痕迹．．．\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// 落花流水一起去:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","被散花天女炸成了碎片。");
		me->add_temp("block_msg/all",-1);
		me->die();	
		return 1;
	}
	// 另一人下线了……被抛弃了

	switch (i)
	{
	case 1:
		who=p2;  // 藏起来了
		me=p1;	// 到达终点

		tell_object(who,"水如昔走了过来。\n"CYN"水如昔看着远方"+me->name()+"的背影，冷冷的哼了一声。\n"NOR);
		tell_object(who,HIG"\n水如昔从怀中取出一个缎子做的小荷包，轻握在手。\n"NOR);
		tell_object(who,HIY"\n在叶缝透下的微光闪耀中，你隐约可以看见小荷包上"NOR);
		tell_object(who,HIY"\n用发亮的金线和珠片绣着一朵牡丹花．．．"NOR);
		tell_object(who,HIY"\n没有来由的，你突然打了一个寒颤。\n"NOR);
		tell_object(who,HIW"\n水如昔轻轻的按了一下荷包，两道金光直追"+me->name()+"而去，"NOR);
		tell_object(who,HIW"\n随即化作一片烁目的雪白，仿佛一千个太阳的光亮，"NOR);
		tell_object(who,HIW"\n刺得你一瞬间竟睁不开眼睛。\n"NOR);

		tell_object(me,HIY"\n没有来由的，你突然觉得心头一冷，回首望去，只见"NOR);
		message_vision(HIY"\n两枚闪着金光的小东西从$N背后斜斜飞了过来．．．"NOR,me);
		message_vision(HIY"\n金光并没有追上你，而是落在了拐角的大石头上，\n"NOR,me);
		message_vision(HIW"\n一道烁目的闪光掠过，跟随着＂啵＂的一声，声音并\n不很响，仿佛情人间相吻的轻触，你还没有反应过来\n究竟发生了什么，眼前就只剩一片茫茫雪白．．．\n\n"NOR,me);

		tell_object(who,YEL"\n幸好你站得很远，总算没有被飞激四射的碎片打中，"NOR);
		tell_object(who,YEL"\n但这一刹那发生的事，你一生都无法忘记，因为就在"NOR);
		tell_object(who,YEL"\n这一刹那里，你已在鬼门关前转了一圈。"NOR);
		tell_object(who,YEL"\n漫空飞扬的烟硝尘土，飞激四射的毫光碎片，现在都"NOR);
		tell_object(who,YEL"\n已经落下，你颈上的冷汗，却还没有乾。\n\n"NOR);

		tell_object(me,YEL"幸好你站得很远，总算没有被飞激四射的碎片打中，"NOR);
		tell_object(me,YEL"\n但这一刹那发生的事，你一生都无法忘记，因为就在"NOR);
		tell_object(me,YEL"\n这一刹那里，你已在鬼门关前转了一圈。\n"NOR);
		tell_object(me,YEL"\n漫空飞扬的烟硝尘土，飞激四射的毫光碎片，现在都"NOR);
		tell_object(me,YEL"\n已经落下，你颈上的冷汗，却还没有乾。\n\n"NOR);

		tell_object(who,CYN"水如昔叹了口气，慢慢的走了回去。\n"NOR);

		if (!room=find_object(__DIR__"path7"))
			room=load_object(__DIR__"path7");

		room->set("short","废墟");
		room->set("long","这里的一切都已经完了，好象刚刚经过一场浩劫，可是你连尸体都看不到，只\n能看到一片乌焦之中好象有些鲜红惨绿的痕迹．．．\n");


	data = ([
		"name":		"巴山幽迹",
		"target":	me,
		"att_2":	"con",
		"att_2c":	1,
		"mark":		3,
	]);
		REWARD_D->imbue_att(data);	

	data = ([
		"name":		"巴山幽迹",
		"target":	who,
		"att_2":	"con",
		"att_2c":	1,
		"mark":		3,
	]);
		REWARD_D->imbue_att(data);	
		tell_object(me,WHT"\n空中的烟尘旋转落下，一点一点地沾染在你身上。\n"NOR);
		tell_object(who,WHT"\n空中的烟尘旋转落下，一点一点地沾染在你身上。\n"NOR);


		return 1;
		break;
	case 2:
		who=p1;	// 到达终点		
		me=p2;

		tell_object(who,HIY"\n没有来由的，你突然觉得心头一冷，回首望去，只见"NOR);
		tell_object(who,HIY"\n不远处细微的两道金光一闪即没，"HIW"随即化作了一片烁"NOR);
		tell_object(who,HIW"\n目的雪白，仿佛一千个太阳的光亮，刺得你一瞬间竟"NOR);
		tell_object(who,HIW"\n睁不开眼睛。\n"NOR);

		tell_object(me,HIY"\n没有来由的，你突然觉得心头一冷，回首望去，只见"NOR);
		message_vision(HIY"\n两枚闪着金光的小东西从$N背后斜斜飞了过来．．．\n\n"NOR,me);
		message_vision(HIW"一道烁目的闪光掠过，跟随着＂啵＂的一声，声音并\n不很响，仿佛情人间相吻的轻触，你还没有反应过来\n究竟发生了什么，眼前就只剩一片茫茫雪白．．．\n"NOR,me);

        environment(me)->set("short","废墟");
        environment(me)->set("long","这里的一切都已经完了，好象刚刚经过一场浩劫，可是你连尸体都看不到，只\n能看到一片乌焦之中好象有些鲜红惨绿的痕迹．．．\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// 落花流水一起去:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","被散花天女炸成了碎片。");
		me->add_temp("block_msg/all",-1);
		me->die();	

		tell_object(who,YEL"\n幸好你站得很远，总算没有被飞激四射的碎片打中，"NOR);
		tell_object(who,YEL"\n但这一刹那发生的事，你一生都无法忘记，因为就在"NOR);
		tell_object(who,YEL"\n这一刹那里，你已在鬼门关前转了一圈。"NOR);
		tell_object(who,YEL"\n漫空飞扬的烟硝尘土，飞激四射的毫光碎片，现在都"NOR);
		tell_object(who,YEL"\n已经落下，你颈上的冷汗，却还没有乾。\n\n"NOR);
	data = ([
		"name":		"巴山幽迹",
		"target":	who,
		"att_2":	"con",
		"att_2c":	1,
		"mark":		3,
	]);
		REWARD_D->imbue_att(data);	

		tell_object(who,WHT"\n空中的烟尘旋转落下，一点一点地沾染在你身上。\n"NOR);

		return 1;

		break;
	case 3:
		who=p1;	
		me=p2;

		tell_object(me,HIY"\n没有来由的，你突然觉得心头一冷，回首望去，只见"NOR);
		tell_object(who,HIY"\n没有来由的，你突然觉得心头一冷，回首望去，只见"NOR);
		message_vision(HIY"\n两枚闪着金光的小东西从$N背后斜斜飞了过来．．．\n\n"NOR,me);
		message_vision(HIW"一道烁目的闪光掠过，跟随着＂啵＂的一声，声音并\n不很响，仿佛情人间相吻的轻触，你还没有反应过来\n究竟发生了什么，眼前就只剩一片茫茫雪白．．．\n"NOR,me);

        environment(me)->set("short","废墟");
        environment(me)->set("long","这里的一切都已经完了，好象刚刚经过一场浩劫，可是你连尸体都看不到，只\n能看到一片乌焦之中好象有些鲜红惨绿的痕迹．．．\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// 落花流水一起去:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","被散花天女炸成了碎片。");
		me->add_temp("block_msg/all",-1);
		me->die();	

		who->add_temp("block_msg/all",1);
		who->delete("tiwhor/lifesave");	// 落花流水一起去:p
		who->move("/obj/void");
		who->set_temp("last_damage_from","被散花天女炸成了碎片。");
		who->add_temp("block_msg/all",-1);
		who->die();	


		return 1;

		break;
	case 4:
		who=p1;	// 藏起来了
		me=p2;

		tell_object(who,"水如昔走了过来。\n"CYN"水如昔看着远方"+me->name()+"的背影，冷冷的哼了一声。\n"NOR);
		tell_object(who,HIG"\n水如昔从怀中取出一个缎子做的小荷包，轻握在手。\n"NOR);
		tell_object(who,HIY"\n在叶缝透下的微光闪耀中，你隐约可以看见小荷包上"NOR);
		tell_object(who,HIY"\n用发亮的金线和珠片绣着一朵牡丹花．．．"NOR);
		tell_object(who,HIY"\n没有来由的，你突然打了一个寒颤。\n"NOR);
		tell_object(who,HIW"\n水如昔轻轻的按了一下荷包，两道金光直追"+me->name()+"而去，"NOR);
		tell_object(who,HIW"\n随即化作一片烁目的雪白，仿佛一千个太阳的光亮，"NOR);
		tell_object(who,HIW"\n刺得你一瞬间竟睁不开眼睛。\n"NOR);

		tell_object(me,HIY"\n没有来由的，你突然觉得心头一冷，回首望去，只见"NOR);
		message_vision(HIY"\n两枚闪着金光的小东西从$N背后斜斜飞了过来．．．\n\n"NOR,me);
		message_vision(HIW"一道烁目的闪光掠过，跟随着＂啵＂的一声，声音并\n不很响，仿佛情人间相吻的轻触，你还没有反应过来\n究竟发生了什么，眼前就只剩一片茫茫雪白．．．\n"NOR,me);

        environment(me)->set("short","废墟");
        environment(me)->set("long","这里的一切都已经完了，好象刚刚经过一场浩劫，可是你连尸体都看不到，只\n能看到一片乌焦之中好象有些鲜红惨绿的痕迹．．．\n");

		me->add_temp("block_msg/all",1);
		me->delete("timer/lifesave");	// 落花流水一起去:p
		me->move("/obj/void");
		me->set_temp("last_damage_from","被散花天女炸成了碎片。");
		me->add_temp("block_msg/all",-1);
		me->die();	

		tell_object(who,YEL"\n幸好你站得很远，总算没有被飞激四射的碎片打中，"NOR);
		tell_object(who,YEL"\n但这一刹那发生的事，你一生都无法忘记，因为就在"NOR);
		tell_object(who,YEL"\n这一刹那里，你已在鬼门关前转了一圈。"NOR);
		tell_object(who,YEL"\n漫空飞扬的烟硝尘土，飞激四射的毫光碎片，现在都"NOR);
		tell_object(who,YEL"\n已经落下，你颈上的冷汗，却还没有乾。\n\n"NOR);

		tell_object(who,CYN"水如昔叹了口气，慢慢的走了回去。\n"NOR);

		tell_object(who,WHT"\n空中的烟尘旋转落下，一点一点地沾染在你身上。\n"NOR);

	data = ([
		"name":		"巴山幽迹",
		"target":	who,
		"att_2":	"con",
		"att_2c":	1,
		"mark":		3,
	]);
		REWARD_D->imbue_att(data);	

		return 1;
		break;
	}
	
	
	return 1;
}


int do_ics(object who,int i)
{
	object who2;
	if (query("p1") == who)
		who2=query("p2");
	else
		who2=query("p1");

	if (!who || !who2)
		do_instantsmash(who,who2,query("ob"),3);

	switch (i)
	{
	case 1:	// 已有一人到达终点
		
		if (who2->query_temp("condition_type") == NOR CYN" <藏身树后>"NOR)
			// 另一人藏了起来，条件达成。
			do_instantsmash(who,who2,query("ob"),1);
		else
			// 另一人倒霉了..
			do_instantsmash(who,who2,query("ob"),2);
		break;
	case 2:	// 两人一起向前冲去，没有人藏起来。
		// 一起倒霉...
		do_instantsmash(who,who2,query("ob"),3);
		break;
	}	
}

int do_killob(object p1,object p2,object ob)
{
	if (!ob)
		return 0;
	if (!p1 && !p2)	// 都不在了
		return 0;
	
	if (query("interrupted"))
		return 0;

	if (p1 && p1->query_temp("condition_type") == NOR CYN" <藏身树后>"NOR)
	{	// p1藏起来，p2倒霉啦
		do_instantsmash(p1,p2,query("ob"),4);
		return 1;
	}	

	if (p2 && p2->query_temp("condition_type") == NOR CYN" <藏身树后>"NOR)
	{	// p2藏起来，p1倒霉啦
		do_instantsmash(p2,p1,query("ob"),4);
		return 1;
	}	

	// 没有人藏起来。
	do_instantsmash(p1,p2,query("ob"),3);
	return 1;
}

int do_opengate(object p1,object p2,object ob)
{
	object env = this_object(),room;
	if (!p1 || !p2)
		return 0;
	if (environment(p2) != env)
		return 0;
	if (environment(p1) != env)
		return 0;
	if (p1->query("kee") < 1)
		return 0;
	if (p2->query("kee") < 1)
		return 0;
	message_vision(CYN"\n$N觑准空隙，拉着$n自水如昔身边窜过，扑进暗道之中！\n\n"NOR,p1,p2);
	if (!room=find_object(__DIR__"path1"))
		room=load_object(__DIR__"path1");
	p1->move(room);
	p2->move(room);
	message_vision(CYN"\n$n回身飞击一掌在石像上，石像缓缓移回原位，挡住了暗道的入口。\n\n"NOR,p1,p2);
	room->delete("exits/north");
	set("p1",p1);
	set("p2",p2);
	set("ob",ob);
	message_vision(RED"(暂时封住的石像看来似乎并不能阻挡乾达婆王多久，还是尽快离开这里吧。)\n"NOR,p1,p2);
	call_out("do_killob",300,p1,p2,ob);
	return 1;
}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
