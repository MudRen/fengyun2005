// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("傅婉", ({ "fu wan","fu","wan" }) );

		set("class","demon");
		set("title",BLU"神教外务"NOR);
		set("nickname",CYN"铃兰"NOR);

		set("always_duxin",1);
		set("fly_target",1);

    	set("attitude","friendly");

        set("gender", "女性" );
		set("age",27);

	set("chat_chance",1);
	set("chat_msg", ({
		"傅婉轻笑道：璃妹妹，你又记错了。\n",
	}) );

        set("combat_exp", 7100000);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: smart_fight() :),
        }) );


        set_skill("blade", 200);
        set_skill("sword", 200);
        set_skill("lefthand-sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("chillblade", 200);
        set_skill("13-sword", 150);
        set_skill("unarmed", 200);
        set_skill("hammer", 200);
        set_skill("longfenghuan", 186);
        set_skill("lingxi-zhi", 190);
		set_skill("force",200);
		set_skill("jingxing",200);
		set_skill("luoriquan",350);
		set_skill("venusfinger",200);
		set_skill("xifengying",180);

		set_skill("divineforce",200);
		set_skill("daimonsword",200);
		
	set_skill("magic", 240);
	set_skill("essencemagic", 240);

		set_skill("six-sense",300);
		set_skill("fall-steps",220);
		set_skill("meng-steps",220);

        map_skill("magic", "essencemagic");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("unarmed", "venusfinger");
        map_skill("sword", "daimonsword");
        map_skill("parry", "13-sword");
        map_skill("dodge", "fall-steps");

		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

		setup();

		
        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("森罗云海", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();


        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("铃兰青绫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
	object ob;
	mapping buff;
	object target;
	string msg;
	object me = this_object();
	object *enemy;
	int i;
	enemy = me->query_enemy();


	if (!random(3))
		if (ccommand("perform force.check_gspm"))
			ccommand("perform force.guishenpomie");

	i = sizeof(enemy);
	while(i--)
		if( enemy[i] && living(enemy[i]) )
			if (ANNIE_D->get_buff_num(enemy[i],1) > 0 && !is_busy())
			{
				target=enemy[i];
				SKILL_D("daimonsword")->perform_target(this_object(),"chousi",target);
			}
	
/*	i = sizeof(enemy);
	if (!random(3) && i > 1 && query("kee") < query("max_kee") / 3)
		ccommand("perform force.terror");*/

	ccommand("perform force.baocanshouque");
	return;
}
