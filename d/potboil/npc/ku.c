// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("玄苦", ({ "monk ku","monk","ku" }) );

		set("class","demon");
		set("title",BLU"神教外务"NOR);
		set("nickname",CYN"众生皆苦"NOR);


		set("always_duxin",1);

    	set("attitude","friendly");


        set("gender", "男性" );

		set("age",67);

	set("chat_chance",1);
	set("chat_msg", ({
		"玄苦叹道：无人不冤，有情皆孽。谁又真的看得破呢？\n",
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
	set_skill("staff", 300);
	set_skill("illusionstick", 400);

		set_skill("six-sense",300);
		set_skill("fall-steps",220);
		set_skill("meng-steps",220);

        map_skill("staff", "illusionstick");
        map_skill("magic", "essencemagic");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("blade", "heavendance");
        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "daimonsword");
        map_skill("parry", "daimonsword");
        map_skill("dodge", "fall-steps");

		set("death_msg",CYN"\n$N愁眉苦脸叹道：苦啊，苦啊．．．\n"NOR);

		setup();

		

		weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("苦修禅杖", ({ "staff" }) );
		weapon->set("value",0);
		weapon->wield();


		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("苦苦僧衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}



int kill_ob(object who)
{
	ccommand("wield all");
	::kill_ob(who);
	smart_fight();
	return 1;
}

void smart_fight()
{
	set("force",4000);
	ccommand("perform menghuantianluo");
}
