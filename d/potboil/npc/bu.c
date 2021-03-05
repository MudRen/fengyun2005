// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
		object weapon;
        set_name("卜镜", ({ "bu jing","bu","jing" }) );

		set("title",BLU"神教外务"NOR);
		set("nickname",BLK"黑虎掏心"NOR);
		set("always_duxin",1);
    	set("attitude","friendly");
        set("gender", "男性" );
		set("age",27);
		set("chat_chance",1);
		set("chat_msg", ({
		"卜镜叹道：当年与张三兄相别之后，至今已有十载，却未能有缘重聚．．．\n",
		"卜镜静默不言，扎扎实实地打出一套拳法，虽然招式平凡无奇，倒也虎虎生风。\n",
		}) );

        set("combat_exp", 6600000);

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
		set_skill("demosword",200);
		set_skill("xiaodao",200);
		set_skill("zen",200);
		set_skill("ironcuff",160);
		
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

        map_skill("magic", "essencemagic");
        map_skill("axe", "xuanyuan-axe");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("blade", "beilongblade");
        map_skill("unarmed", "ironcuff");
        map_skill("sword", "demosword");
        map_skill("parry", "demosword");
        map_skill("dodge", "fall-steps");

		set("death_msg",CYN"\n$N叹道：天机．．．\n"NOR);
		setup();
		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("玄墨劲装", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}


void smart_fight()
{
	ccommand("perform heihutaoxin");
	return;
}
