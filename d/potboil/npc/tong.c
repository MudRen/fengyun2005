// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("童铜山", ({ "tong tongsan","tong","tongsan" }) );

		set("title",CYN"大昭弃徒"NOR);
		set("nickname",HIB"疯魔铁杖"NOR);


		set("always_duxin",1);


        set("gender", "男性" );

		set("age",27);

	set("chat_chance",1);
	set("chat_msg", ({
		"童铜山冷笑道：我倒要看看是谁敢使唤卫八太爷。\n",
	}) );

        set("combat_exp", 7100000);

/*    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: smart_fight() :),
        }) );
*/        
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
		set_skill("spicyclaw",400);
		set_skill("venusfinger",200);
		set_skill("xifengying",180);

		set_skill("divineforce",200);
		set_skill("daimonsword",200);
		set_skill("demosword",200);
		set_skill("xiaodao",200);
		set_skill("zen",200);
		set_skill("ironcuff",160);

		set_skill("staff",200);
		set_skill("fengmo-staff",200);
		
		set_skill("strategy",300);
		set_skill("leadership",300);

	set_skill("magic", 240);
	set_skill("essencemagic", 240);
	set_skill("blade", 240);
	set_skill("heavendance", 240);
	set_skill("beilongblade", 280);
	set_skill("axe", 300);
	set_skill("xuanyuan-axe", 200);



		set_skill("six-sense",300);
		set_skill("fall-steps",220);
		set_skill("meng-steps",220);

        map_skill("staff", "fengmo-staff");
        map_skill("magic", "essencemagic");
        map_skill("axe", "xuanyuan-axe");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("blade", "beilongblade");
        map_skill("unarmed", "ironcuff");
        map_skill("sword", "demosword");
        map_skill("parry", "fengmo-staff");
        map_skill("dodge", "fall-steps");

		set("death_msg",CYN"\n$N叹道：天机．．．\n"NOR);

		setup();

	set_temp("pfm/fengmo_2",1);

    set_temp("buff/berserk_attack",1);
	set_temp("buff/berserk_skill","fengmo-staff");
	set_temp("buff/berserk_attack_msg",CYN"\n$N状若疯魔，杖声呼呼，劈头盖脸又向$n击到！\n"NOR);


        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("疯魔铁杖", ({ "staff" }) );
		weapon->set("value",0);
		weapon->wield();
		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("藏黄貂裘", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
//	ccommand("perform heihutaoxin");
	return;
}




mapping ob_hit(object attacker, object victim,int damage)
{
	mapping data = ([]);
	if (!victim->is_busy() || victim->query_busy()<1)
		return 0;
	victim->stop_busy();
	data["msg"] = HIR"$n一声断喝，伤口迸裂而鲜血飞溅，身法却骤然灵动无方！\n"NOR;
	return data;
}