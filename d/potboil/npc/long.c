// annie 07.2003
// dancing_faery@hotmail.com



#include <ansi.h>
#include <combat.h>
inherit SMART_NPC;
void smart_fight();

void create()
{
		object weapon;
        set_name("龙五", ({ "long wu","long","wu","longwu" }) );

		set("class","assassin");
		set("title",CYN"三湘"NOR);
		set("nickname",WHT"行踪常在云霄外"NOR);

		set("always_duxin",1);
        set("gender", "男性" );

		set("age",47);
		set("chat_chance",1);
		set("chat_msg", ({
			"龙五以一方白帕掩住嘴轻轻咳嗽，叹气道：酒是伤人物啊……\n",
		}) );

        set("combat_exp", 7100000);
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
       
 		set("perform_unarmed_attack",	"bat/unarmed/luoriquan/changrijiangjin");
		set("perform_busy_d", 			"bat/dodge/meng-steps/huanyinqianchong");

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

		set_skill("six-sense",300);
		set_skill("fall-steps",220);
		set_skill("meng-steps",220);
		set_skill("perception", 250);
		
        map_skill("force", "jingxing");
        map_skill("hammer", "longfenghuan");
        map_skill("unarmed", "luoriquan");
        map_skill("sword", "lefthand-sword");
        map_skill("parry", "lingxi-zhi");
        map_skill("dodge", "meng-steps");

		set("death_msg",CYN"\n$N大叫道：你～～～～～～～～！\n"NOR);

		setup();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("沾着一点酒垢的白衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}