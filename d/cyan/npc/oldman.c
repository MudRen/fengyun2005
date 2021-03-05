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

	if (me->query("quest/short") != "到明霞山听垂暮老人讲一场当年的故事")
	{
		ccommand("say 小孩子不懂事别乱问。");
		return 1;
	}
//goto /d/phoenix/cyan2/peak3;updatep /d/phoenix/cyan2/npc/;update here;l
	set("mud_age",999999);
	ccommand("cemote $ME$脸上显现出悠然神往的神色。");
	ccommand("chat 话说当年．．．");

	obj = find_object("/d/phoenix/base/"+me->query("id")+"/cyan2/peak3");
	if (!obj)
		obj = load_object("/d/phoenix/base/"+me->query("id")+"/cyan2/peak3");

	inv = all_inventory(environment());
	for (i=0; i<sizeof(inv); i++)
		if (check_legit(inv[i]))
			inv[i]->move(obj);

	me->move(obj);
	obj->do_start(me);
	
	me->set("quest/short", "死守明霞山瞭望台"NOR);
	me->set("quest/duration",1800);
	me->set("quest_time",time());
	message_vision(HIY+me->name()+HIY"的任务改变了！\n"NOR,me);

	return 1;

}

void create()
{
		object weapon;
        set_name("垂暮老人", ({ "oldman" }) );
        set("gender", "男性" );

		set("chat_chance",1);
		set("chat_msg", ({
			"垂暮老人叹道：流年暗转，光阴飞逝，光阴飞逝啊。\n",
			"垂暮老人望着天边出神，脸上现出无限向往的神色。\n",
			"垂暮老人轻轻拍着节，唱道：帐前旗，腰后印，桃花马，衣柳叶，惊穿胡阵……\n",
			"垂暮老人低低叹息：流光一瞬，离愁一身。望云山，当时壁垒，蔓草斜曛。\n",
		}) );
		set("NO_KILL","这人很快就老死了，何必再花力气呢？\n");
		
		set("age",87);

        set("combat_exp", 7800000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
        }) );

        set("inquiry",([
 			"故事"  : 	(: lic :),
 			"当年"  : 	(: lic :),
 			"当年的故事"  : (: lic :),
 			"讲故事"  :	 (: lic :),
 			"job"  : (: lic :),
 			"story"  : (: lic :),
        ]) );

		auto_npc_setup("waiter",220,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
		set("perform_busy_d","huashan/throwing/tanzhi-shentong/tanzhijinghun");

		setup();

        weapon=carry_object("/obj/weapon/dart");
        weapon->set_name("两黄金", ({ "gold" }) );
		weapon->set("unit","");
		weapon->set("base_unit","");
		weapon->set("value",0);
		weapon->set("no_transfer",1);
		weapon->set_amount(16);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("洗得发白的黄衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
