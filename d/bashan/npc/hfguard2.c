// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("顾电飞", ({ "gu dianfei","gu","dianfei" }) );
        set("title",CYN"巴山一剑"NOR);
        set("gender", "男性" );

		set("age",27);

        set("long","顾道人生平最为得意的事就是门下风云雷电四个弟子，\n如今雷电尚在，风云已不知去向何方。\n");

		set("chat_chance",1);
		set("chat_msg", ({
			"顾电飞微笑道：师兄这一式沉萼落香，几近无踪无迹，又已精进许多。\n",
			"顾电飞沉吟道：师傅说这套回风剑法专破各家掌法，我看其中却有个大大的漏洞。\n",
			"顾电飞淡淡地说：咱们师兄弟单打独斗，不会以多欺少的。\n",
		}) );
   
		set("inquiry",([
 		"顾云飞"  :"师父让二师兄去．．．等等，我为什么要告诉你？\n",
 		"顾风飞"  :"师父让大师兄去．．．等等，我为什么要告诉你？\n",
 		"顾道人"  :"我师父乃巴山剑客，打遍天下无敌，就连达摩老祖都要敬他三分。\n",
 		"顾剪秋"  :"我师父乃巴山剑客，打遍天下无敌，就连达摩老祖都要敬他三分。\n",
 		"落葭飞"  :"我师父谁都不怕，只怕师娘，可见还是师娘更胜一筹。\n",
 		"退隐"  :"退隐的意思么，就是封存自己，换个身份，重练新人。\n",
 		"封剑退隐"  :"退隐的意思么，就是封存自己，换个身份，重练新人。\n",
 		"九月初九"  :"action顾电飞捂着脸道：讨厌啦，你记得人家的生日就好，不要说出来嘛～\n",
 		"漏洞":		"也不知为何，上次少林来了个种花的和尚，师兄的回风剑法愣是破不了他的掌法，怪哉怪哉！\n",
              ]) );

        set("combat_exp", 9500000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
          	(: auto_smart_fight(30) :)
             }) );
        set_skill("sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("softsword", 180);
		set_skill("unarmed",200);
		set_skill("spicyclaw",200);
		set_skill("13-sword",200);
		
		map_skill("unarmed","spicyclaw");
        map_skill("sword", "softsword");
        map_skill("parry", "softsword");
        map_skill("dodge", "13-sword");
	
		set("perform_weapon_attack","swordsman/sword/softsword/changtianluodian");
		set("perform_unarmed_attack","demon/unarmed/spicyclaw/extrahit5");
		set("perform_unarmed_attack2","demon/unarmed/spicyclaw/extrahit4");
		
		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(HIB"逐电剑"NOR, ({ "lightning sword","sword" }) );
		weapon->set("long"," ");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("飞电衣", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
