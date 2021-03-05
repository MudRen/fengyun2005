#include <ansi.h>
inherit NPC;
void create()
{
        set_name("宋中", ({ "songzhong" }) );
        set("gender", "男性");
        set("combat_exp", 100000);
        set("title", HIR "一剑送终"NOR);
        set("long","宋中－－一剑送终，大家都认为他拔剑的动作已经比得上荆无命。\n");
        set("class","assassin");
        
        set_skill("move", 50);
        set_skill("dodge", 50);
	set_skill("sword",50);
	set_skill("lefthand-sword",20);
	map_skill("sword","lefthand-sword");
	
	set("chat_chance_combat", 90);
    	set("chat_msg_combat", ({
        	(: perform_action, "sword.duxin" :),
            }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}
