// annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
		object weapon;
        set_name("蔚香思", ({ "wei xiangsi","wei","xiangsi" }) );
		set("class","legend");
		set("title",BLU"神教外务"NOR);
		set("nickname",CYN"相思相杀"NOR);

		set("always_duxin",1);
    	set("attitude","friendly");
        set("gender", "女性" );
		set("age",27);

		set("chat_chance",1);
		set("chat_msg", ({
			"蔚香思打了个呵欠。\n",
		}) );

        set("combat_exp", 7100000);
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(40) :),
       	}) );
        
        set("perform_weapon_attack",	"npc/blade/shenji-blade/jichulianhuan");
        set("perform_unarmed_attack",	"demon/unarmed/spicyclaw/extrahit5");
		set("perform_busy_d", 			"demon/dodge/demon-steps/lianhuanbabu");
		set("skill_type_w", 			"blade/shenji-blade");
              
/*    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: smart_fight() :),
        }) );	*/
       
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


	set_skill("chillblade", 230);
	set_skill("stormdance", 200);
	set_skill("qiuzhi-sword", 200);

	set_skill("demon-steps",200);
	set_skill("shenji-blade",200);
	set_skill("shenji-steps",200);

		map_skill("throwing", "tanzhi-shentong");

		map_skill("magic", "essencemagic");
        map_skill("axe", "xuanyuan-axe");
        map_skill("force", "divineforce");
        map_skill("hammer", "longfenghuan");
        map_skill("blade", "shenji-blade");
        map_skill("unarmed", "spicyclaw");
        map_skill("sword", "qiuzhi-sword");
        map_skill("parry", "shenji-blade");
        map_skill("dodge", "shenji-steps");
		setup();
		
        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("相杀", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();
		
        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("相思", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}