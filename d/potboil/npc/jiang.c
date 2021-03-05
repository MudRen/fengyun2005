// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("姜明秀", ({ "jiang mingxiu","jiang","mingxiu" }) );

		set("class","demon");
		set("title",BLU"神教外务"NOR);
		set("nickname",WHT"煮鹤焚琴"NOR);


		set("always_duxin",1);

    	set("attitude","friendly");
        set("gender", "女性" );
		set("age",27);

		set("chat_chance",1);
		set("chat_msg", ({
			"姜明秀淡淡道：爹爹只要哥哥不要我，我便只好也不要他了。\n",
		}) );

        set("combat_exp", 7100000);

    	set("chat_chance_combat", 50);
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

        map_skill("magic", "essencemagic");
        map_skill("axe", "xuanyuan-axe");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("blade", "beilongblade");
        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "daimonsword");
        map_skill("parry", "daimonsword");
        map_skill("dodge", "fall-steps");

		set("death_msg",CYN"\n$N叹道：天机．．．\n"NOR);

		setup();

		

		weapon=carry_object("/d/cyan/npc/obj/pxblade");
        weapon->set_name("断山刀", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();


		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("天青水褂", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
	if (query("kee") > query("max_kee") / 3)
		if (random(2))
			ccommand("perform fentianzhan");	
		else
			return;
	else
			ccommand("perform fenqin");	

	return;
}
