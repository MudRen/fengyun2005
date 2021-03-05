// annie 07.2003
// dancing_faery@hotmail.com
// 冷寒袖 & 冷凝霜
#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("冷凝霜", ({ "leng ningshuang","leng" }) );
        set("title","皓月宫");
		set("nickname",WHT"飞絮无痕"NOR);
        set("gender", "女性" );

		set("class","huashan");
		set("age",25);

		set("death_msg",CYN"\n$N挣扎道：寒袖．．．来生．．．\n"NOR);
		set("chat_chance", 1);
		set("chat_msg", ({
			"冷凝霜跺脚道：那个笨呆子，怎么还不来找我？\n",
			"冷凝霜咬咬牙道：他不来寻我，我偏不去见他。\n",
		}) );

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(20) :),
        }) );

        set("combat_exp", 7500000);
        set("score", 50);
		
		set_skill("stormdance",200);
		set_skill("snowforce",200);

		set_skill("zen",200);
		set_skill("xiaodao",200);
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
		set_skill("sword",350);
			
		map_skill("parry","zensword");
		map_skill("sword","zensword");
		map_skill("force","hanmei-force");
		map_skill("dodge","cloud-dance");
		
		set("smartnpc_busy",1);
		set("perform_weapon_attack","npc/sword/zensword/menghuankonghua");
		set("perform_busy_d",	"huashan/dodge/cloud-dance/yexuechuji");

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(RED"落鸿火"NOR, ({"sword" }) );
		weapon->set("long","这是一柄精巧的短剑，剑柄上刻着＂天平＂二字。\n");
		weapon->set("value",0);
		weapon->set("nodrop_weapon",1);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("白蝶绸裙", ({ "cloth" }) );
		weapon->set("long","一件小巧的绸裙。\n");
		weapon->set("value",0);
		weapon->wear();

}