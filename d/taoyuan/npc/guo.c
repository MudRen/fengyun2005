#include <ansi.h>

inherit NPC;


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

int check_legit(object ob) {
	object me, *team, owner;
	me=this_player();
	
	if (ob==me) return 0;
	team=me->query_team();
	if (team) {
		if (member_array(ob,team)!=-1) return 1;
		if (owner=ob->query("possessed"))
		if (member_array(owner,team)!=-1) return 1;
	}
	return 0;
}


int fin()
{
	object obj;
	object me=this_player();
	object *inv;
	string a;
	int i,f,j;

	if (!QUESTS_D->verify_quest(me, "收获的季节"))
	{
		ccommand("say 小孩子不懂事别乱问。");
		return 1;
	}

	if (me->query("quest/short") != CYN"回去向郭大妈报告结果(end)"NOR)
	{
		ccommand("say 你的任务没完成吧。");
		return 1;
	}
		
	if (me->query_temp("annie_quest/halloween")-me->query_temp("annie_quest/halloween_done")>0)
	{
		ccommand("sigh");									// 等着它 expire... 300sec - 270 sec
		ccommand("say 原来连你都拿那些南瓜们没办法……");
		ccommand("idle");
		return 1;
	}


	ccommand("jump");
	ccommand("bow");

	me->set("quest/difficulty",240);

	if (QUESTS_D->verify_quest(me, "收获的季节"))
		QUESTS_D->special_reward(me, "收获的季节");

	return 1;
}


int lic()
{

	object obj,oe;
	object me=this_player();
	object *inv;
	int i,x,y,z;

	if (me->query("quest/short") != "到桃源解除郭大妈的烦恼")
	{
		ccommand("say 小孩子不懂事别乱问。");
		return 1;
	}

	me->set_temp("annie_quest/halloween",0);
	me->set_temp("annie_quest/halloween_done",0);

	ccommand("say 桃源村什么土产没有，这日子只能靠着南瓜来过");
	ccommand("say 虽说这南瓜不值什么钱，马村长他家老四每天倒也能卖出百八十个，村子里大家便过得滋滋润润");
	ccommand("say 可你说这世道，自从酱牛肉流行以来……");
	ccommand("sigh");
	ccommand("say 咱村仓库里堆着的那些南瓜呀，没人去看管，都已经成了精啦");
	ccommand("say 也不是什么大事儿，可这南瓜精闹腾着，心里到底有点儿不塌实");
	ccommand("say 大侠您就行行好，去把那些南瓜精砍回南瓜吧");
	ccommand("say 大娘我也不清楚里面有几个南瓜精，您一边砍我一边儿到处转转数数，多多少少您包涵着点儿。");

	obj=find_object("/obj/dungeon/halloween/"+me->query("id")+"/entry");
	if (obj)
	{
		obj->destruct_maze();
		obj=find_object("/obj/dungeon/halloween/"+me->query("id")+"/entry");
	}
	if (!obj)
		obj=load_object("/obj/dungeon/halloween/"+me->query("id")+"/entry");
	if (!obj)	
		obj="/obj/dungeon/halloween"->query_maze_room(me->query("id")+"/entry");

	if (obj)
	{
		for (x=0; x<4; x++)
			for (y=0; y<4; y++)
				for (z=0; z<2; z++)
					"/obj/dungeon/halloween"->query_maze_room(me->query("id")+"/"+x+"/"+y+"/"+z);
	}

	inv = all_inventory(environment());
	for (i=0; i<sizeof(inv); i++)
		if (check_legit(inv[i]))
			inv[i]->move(obj);

	me->move(obj);
	me->set("quest/short", CYN"消灭所有南瓜精"NOR);
	me->set("quest/duration",270);
	me->set("quest_time",time());

	if (obj)
		tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);

	return 1;
}

void create()
{

	set_name("郭大娘", ({ "guo dama", "guo" }) );

	set("gender", "女性" );

	set("age", 50);

	set("long",

"没有人记得郭大妈是什么时候搬来桃园的，大家只记得当初她是带着一个半大

的孩子来的，也没有人注意到孩子什么时候不见了。 \n");


	set("inquiry",([
		"孩子": CYN"哎呀，大路他他他老早就跟着拿根竹竿的、背把长剑的与阴阳怪气的三个人跑了……"NOR,
		"南瓜": (:lic:),
		"pumpkin": (:lic:),
		"烦恼": (:lic:),
		"help": (:lic:),
		"job":	(:lic:),
		"end": (:fin:),
		"结果": (:fin:),
    	]) );


	set("combat_exp", 100);

	set("attitude", "friendly");

	set("per",15);

	set("chat_chance", 2);

	

	set("chat_msg", ({

		"郭大娘叹了一口气说道：“江湖，江湖，一入江湖身不由己。。。”\n",

		"郭大娘自言自语道：“我那儿，不知你带走的冬衣还保暖吗？”\n",

		"郭大娘在屋内忙碌着。\n",

	}) );

	setup();

	

    carry_object("/obj/armor/cloth")->wear();

    add_money("coin", 20);

}



int accept_fight(object me)

{

        command("say 我老太婆哪里是您的对手？");

        return 0;

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


