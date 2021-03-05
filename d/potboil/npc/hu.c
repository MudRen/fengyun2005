// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
	object weapon;
        set_name("胡庐", ({ "hu lu","hu","lu" }) );

		set("class","demon");
		set("title",BLU"神教外务"NOR);
		set("nickname",CYN"呼噜噜"NOR);

    	set("attitude","friendly");
        set("gender", "女性" );

		set("age",27);

	set("chat_chance",1);
	set("chat_msg", ({
		"胡庐躺在草地上大睡，呼噜打得震天响，身边摆着个水葫芦。\n",
	}) );

        set("combat_exp", 6100000);

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
	set_skill("axe", 300);
	set_skill("xuanyuan-axe", 200);

		set_skill("six-sense",300);
		set_skill("fall-steps",220);
		set_skill("meng-steps",220);

        map_skill("magic", "essencemagic");
        map_skill("axe", "xuanyuan-axe");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("blade", "heavendance");
        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "daimonsword");
        map_skill("parry", "daimonsword");
        map_skill("dodge", "fall-steps");

		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

		setup();

		weapon=carry_object("/obj/weapon/axe");
        weapon->set_name("开天斧", ({ "axe" }) );
		weapon->set("value",0);
		weapon->set("weapon_wielded","持");
		weapon->wield();


		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("蓝襟白衫", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

void smart_fight()
{
	if (query("aa")>=2)
	{
		set_temp("apply/haste",200);
		return;
	}
		
	ccommand("perform pangukaitian");	// only pfm twice per-refresh.
	add("aa",1);
	return;
}
