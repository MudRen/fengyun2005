// annie 07.2003
// dancing_faery@hotmail.com
// 冷寒袖 & 冷凝霜
#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("冷寒袖", ({ "leng hanxiu","leng" }) );
        set("title","少林寺下山弟子");
		set("nickname",WHT"冰雪神剑"NOR);
        set("gender", "男性" );
		
		set("class","huashan");
		set("age",25);

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );

        set("combat_exp", 8000000);
        set("score", 50);

		set("death_msg",CYN"\n$N挣扎道：凝霜．．．你．．．一个人．．．要小心．．．\n"NOR);
		set("chat_chance", 1);
		set("chat_msg", ({
		"冷寒袖急道：凝霜，凝霜，别躲了，出来好么？\n",
		"冷寒袖游目四顾，喃喃自语：奇怪，方才还在这里的，跑哪儿去了？\n",
		}) );

		set_skill("zen",200);
		set_skill("xiaodao",200);
		set_skill("demosword",200);
		set_skill("demosword",200);
		set_skill("zensword",200);
		set_skill("cloud-dance",200);
		set_skill("dodge",200);
		set_skill("parry",200);
		set_skill("hanmei-force",200);
		set_skill("zen",200);
		set_skill("xiaodao",200);
		set_skill("snowforce",200);
		set_skill("cloud-dance",200);
		set_skill("anxiang-steps",200);
		set_skill("zensword",200);
		set_skill("sword", 350);
		
		map_skill("parry","zensword");
		map_skill("sword","demosword");
		map_skill("force","hanmei-force");
		map_skill("dodge","cloud-dance");
		
		set("smartnpc_busy",1);
		set("perform_weapon_attack","npc/sword/demosword/zhutianjianzhen");
		set("perform_busy_d",	"huashan/dodge/cloud-dance/yexuechuji");
		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(WHT"玉衡天剑"NOR, ({"sword" }) );
		weapon->set("long","这是一柄精巧的长剑，剑柄上刻着＂霹雳＂二字。\n");
		weapon->set("nodrop_weapon",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("短袖白衫", ({ "cloth" }) );
		weapon->set("long","一件短小的白衣。\n");
		weapon->set("value",0);
		weapon->wear();

}