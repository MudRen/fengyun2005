#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("梅吟雪", ({ "mei yinxue","mei" }) );
        set("gender", "女性" );
        set("title", "孔雀妃子" );
        set("nickname", WHT"百鸟俱往朝丹凤，孔雀独自开彩屏"NOR );
        set("long",
		"白衫，长发，和绝世的容颜，这便是梅吟雪，那纤弱而动人的美丽身躯，裹在一袭正如她面容\n一样纯白的长袍里，海风吹动，白袍飞舞，她身躯竟似也要随风飞去，然而她一双明媚的眼睛，\n却有这无边的大海一般坚定和湛蓝。又有谁能想到，这样一个绝世的女子，十年前却被江湖传\n为一个冷血残忍邪恶的祸水，更有谁能想到，这青春的红颜，竞早已过了韶华之龄。\n"
                );
        set("attitude", "peaceful");
		set("class","huashan");
		set("age", 22);
        set("per", 190);
        set("combat_exp", 6000000);
        set("chat_chance", 1);
        set("chat_msg", ({
		"梅吟雪任由海风吹乱长发，喃喃道： 平，你在哪里？你在哪里，无论到天涯，到海角，我都要找到你。。\n",
		"梅吟雪凄然道：只要能和他在一起，即使世人如何把我看成淫妇，毒妇，即使我又老又丑，\n但只要能和他在一起，所有这一切又有什么呢。。。\n",
		"梅吟雪痴痴地望着海边，柔声道：平，平……即使这一辈子做不了夫妻，还有下辈子，下下辈子，\n我们生生世世，生生世世，永不分离。\n",
		}) );

        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","diesword",1);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
        if (!random(10)) carry_object(BOOKS"sword_75");
}

