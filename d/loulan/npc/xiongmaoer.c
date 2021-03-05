#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("熊猫儿", ({ "xiong maoer","maoer" }) );
        set("gender", "男性" );
        set("title", HIR"江湖第一游侠儿"NOR );
        set("long",
        "只见此人身长八尺，浓眉大眼，腰畔斜插着柄无鞘短刀，手里提着
只发亮的精制酒壶，一面高歌，一面痛饮。\n"
                );
        set("attitude", "peaceful");
		set("class", "npc");
		
		set("perform_busy_d", "npc/dodge/shenji-steps/shenjimiaosuan");
		set("perform_weapon_attack","npc/blade/shenji-blade/jichulianhuan");	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
		set("age", 25);
        
        set("combat_exp", 800000);
        
        set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "熊猫儿放声高歌：千金挥手美人情，落魄自古多英雄，且把壶中陈香酒，萍水江湖一笑逢。\n",
        "熊猫儿苦着脸道："YEL"沈浪"NOR"啊沈浪，你到底在哪里？？\n",
        "熊猫儿拿起精制酒壶咕咕地灌了几口说：有此"YEL"宝壶"NOR"，还有什么酒配不出来！\n",
		}) );
        set("inquiry",  ([
                "沈浪" : "唉，沈浪啊沈浪，你是否还活在人间？\n",
                "朱七七" : "啊！你可知道那丫头的消息么？她。。还好么？\n",
                "王怜花" : "天底下怎么会生出这种魔星？？\n",
                "快活王" : "快活王和沈浪究竟谁会笑到最后呢？\n",
                "宝壶":		"我这酒壶乃祖传之宝，可配天下各类名酒。\n"
                ]));

        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("shenji-blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("shenji-steps", 100);
        set_skill("dragonstrike",120);
        
        map_skill("unarmed","dragonstrike");
        map_skill("dodge", "shenji-steps");
        map_skill("blade", "shenji-blade");
        map_skill("parry", "shenji-blade");
                
        setup();
        carry_object("/obj/weapon/blade_l")->wield();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/loulan/obj/winepot");
}


