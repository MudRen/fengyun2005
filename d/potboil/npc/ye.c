// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("叶轻衣", ({ "ye qingyi","ye","qingyi" }) );

		set("class","demon");
		set("title",BLU"神教外务"NOR);
		set("nickname",CYN"一舞归于烟尘"NOR);

    	set("attitude","friendly");
        set("gender", "女性" );
		set("age",27);
	set("chat_chance",1);
	set("chat_msg", ({
		"望星崖的风吹过，叶轻衣身上的云裾飘飞而起……\n",
	}) );

        set("combat_exp", 5700000);

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
		set_skill("spicyclaw",400);
		set_skill("venusfinger",200);
		set_skill("xifengying",180);

		set_skill("divineforce",200);
		set_skill("daimonsword",200);
		
		set_skill("magic", 240);
		set_skill("essencemagic", 240);
		set_skill("blade", 240);
		set_skill("heavendance", 240);

		set_skill("six-sense",300);
		set_skill("fall-steps",220);
		set_skill("meng-steps",220);

        map_skill("magic", "essencemagic");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("blade", "heavendance");
        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "daimonsword");
        map_skill("parry", "daimonsword");
        map_skill("dodge", "fall-steps");

		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

		setup();

		weapon=carry_object("/obj/weapon/blade");
        weapon->set_name(HIR"星"HIW"华"HIY"短刃"NOR, ({ "dagger" }) );
		weapon->set("value",0);
		weapon->set("weapon_wielded","持");
		weapon->wield();


		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(CYN"莲云舞衣"NOR, ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
//	ccommand("perform dodge.qiufengluoye");
	if (ANNIE_D->check_buff(this_object(),"prtshield")<1)
		ccommand("perform yuexierenjing");

	return;
}
