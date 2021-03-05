// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;



int check_legit(object ob) {
	object me, *team, owner;
	me=this_player();
	
	if (ob==me) return 1;
	team=me->query_team();
	if (team) {
		if (member_array(ob,team)!=-1) return 1;
		if (owner=ob->query("possessed"))
		if (member_array(owner,team)!=-1) return 1;
	}
	return 0;
}

int lic()
{
	object obj;
	object me=this_player();
	object *inv;
	int i;

	if (me->query("quest/short") != "到明霞山给瞎子平七打打下手")
	{
		ccommand("say 小孩子不懂事别乱问。");
		return 1;
	}

	set("mud_age",999999);
	ccommand("emote 阴阴一笑：且跟我来．．．");
	message_vision(CYN"\n你随着平七在大雾中左转右转，一会儿便迷了方向。\n\n"NOR,this_object());

	obj = find_object("/d/phoenix/base/"+me->query("id")+"/cyan4/peak3");
	if (!obj)
		obj = load_object("/d/phoenix/base/"+me->query("id")+"/cyan4/peak3");

	inv = all_inventory(environment());
	for (i=0; i<sizeof(inv); i++)
		if (check_legit(inv[i]))
			inv[i]->move(obj);


	me->move(obj);

	tell_object(me, CYN"平七停住脚步，对你说道：少年人，你便在这里埋伏，一个时辰后有人路过，
见一个杀一个；哨声一出，立刻回来。

平七翻著一双死鱼样的白眼，阴笑道：杀越多，钱越多，不要多问，不要多说，知道吗？\n"NOR);

	i=6+random(3);
	me->set("quest/short", "刺杀所有路过此处之人（至少"+CHINESE_D->chinese_number(i)+"个）"NOR);
	me->set("quest/duration",3600);
	me->set("quest_time",time());
	me->set_temp("annie_quest/cyan43",i);
	tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);

	obj->do_start(me);

	return 1;

}

int lcic()
{
	object obj;
	object me=this_player();
	object *inv;
	string a;
	int i,f,j;

	if (me->query("quest/short") != WHT"回去向平七打听"CYN"任务结束"NOR)
	{
		ccommand("say 小孩子不懂事别乱问。");
		return 1;
	}

	set("mud_age",999999);
	i=me->query_temp("annie_quest/cyan4");
	ccommand("hmm");
	f=1;
	a="你杀了"+CHINESE_D->chinese_number(i)+"个人，";
	j=me->query_temp("annie_quest/cyan43");
	if (i<j)
	{
		a+="实在是太差劲了。";
		f=2;
	}
	if (i>= j && i<j+3)
	{
		a+="还算是中规中矩吧。";
		f=3;
	}
	if (i>= j+3 && i<j+20)
	{
		a+="实在干得不错！";
		f=4;
	}
	if (i>= j+20)
	{
		a+="，好，好！老夫已经有很多年没见过像你这么出众的高手了！";
		f=6;
	}

	ccommand("say "+a);
	if (f==2)
	{
		ccommand("emote 摇头道：去再好好练练手艺吧。");
		return 1;
	}
	me->set("quest/difficulty",f*80);
	if (QUESTS_D->verify_quest(me, "瞎子平七"))
		QUESTS_D->special_reward(me, "瞎子平七");



	return 1;

}

//update d/phoenix/cyan4/peak3;updatep /d/phoenix/cyan4/npc/;update d/cyan/npc/ping;update here;
void create()
{
	object weapon;
        set_name("平七", ({ "ping qi","pingqi","ping" }) );
		set("nickname",HIR BLK"瞎子"NOR);
        set("title",BLK"寒铁之星"NOR);
        set("gender", "男性" );
		set("class","huashan");

		set("age",57);

        set("long","自雁荡山一战瞎子平七成名起，至今已经有许多年。这许多\n年里江湖上人才辈出，然而却鲜有人敢向平七挑战，因为这么\n做的结果，就是敢向他挑战的人又少了一个。\n");

		set("chat_chance",1);
		set("chat_msg", ({
			"平七执着盲杖，轻轻地在山壁上敲打。\n",
			"平七叨念道：这地方没错啊．．．\n",
		}) );

        set("combat_exp", 7500000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
             }) );


        set("inquiry",([
 		"help"  : (: lic :),
 		"任务结束"  : (: lcic :),
 		"job":		(: lic :),
 		"帮手":		(: lic :),
        "下手":		(: lic :),
              ]) );


		setup();

        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("盲杖", ({ "guide staff","staff" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/weapon/dart");
        weapon->set_name("寒铁之星", ({ "iron star","star" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("洗得发黄的白衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",220,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",2);

		set_skill("staff",220);
		set_skill("dagou-stick",200);
		map_skill("parry","dagou-stick");
		set("perform_weapon_attack3","begger/staff/dagou-stick/tianxiawugou");
}
