// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("钱泰多", ({ "qian taiduo","qian","taiduo" }) );

		set("class","baiyun");
		set("title",BLU"神教外务"NOR);
		set("nickname",MAG"司库左仆"NOR);

//		set("possessed",1);	// to cheat abilityd
		set("ability/huayu_add",4);
		set("always_duxin",1);

    	set("attitude","friendly");
        set("gender", "男性" );
		set("age",27);
	set("chat_chance",1);
	set("chat_msg", ({
		"钱泰多道：大司库真是多虑，神教怎么可能会缺金少银？\n",
	}) );

        set("combat_exp", 7100000);

    	set("chat_chance_combat", 40);
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
		set_skill("spicyclaw",400);
		set_skill("venusfinger",200);
		set_skill("xifengying",180);

		set_skill("divineforce",200);
		set_skill("daimonsword",200);
		set_skill("demosword",200);
		set_skill("xiaodao",200);
		set_skill("zen",200);
		set_skill("chessism",300);
		
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

		set_skill("throwing",240);
		set_skill("tanzhi-shentong",240);
		set_skill("feixian-steps",240);


		map_skill("throwing", "tanzhi-shentong");

		map_skill("magic", "essencemagic");
        map_skill("axe", "xuanyuan-axe");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("blade", "beilongblade");
        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "demosword");
        map_skill("parry", "tanzhi-shentong");
        map_skill("dodge", "feixian-steps");

		set("death_msg",CYN"\n$N叹道：天机．．．\n"NOR);

		setup();


		weapon=carry_object("/obj/weapon/dart");
        weapon->set_name("百万两银票", ({ "million-cash" }) );
		weapon->set("value",0);
		weapon->set("level_required",200);
		weapon->set_amount(15);
		weapon->set("unit","张");
		weapon->set("base_unit","张");
		weapon->wield();
		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("金钱银钱铜钱褂", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
		set("class","huashan");
	ccommand("perform mantianhuayu");
		set("class","baiyun");
	return;
}
