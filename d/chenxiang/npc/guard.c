#include <ansi.h>

inherit NPC;

void create()
{
        set_name("青龙会弟子", ({ "dragon dizi","dizi" }) );
        set("long",
                "这是一位青龙会专门担任看守之责的弟子。\n");
        set("attitude", "aggressive");
      
        set("combat_exp", 1200000);
        set_skill("sword", 150);
        set_skill("parry", 170);
        set_skill("dodge", 170);
        set_skill("move",  150);
        set_skill("huanhua-sword",120);
        set_skill("huanhua-steps",120);
        
        map_skill("sword","huanhua-sword");
        map_skill("parry","huanhua-sword");
        map_skill("dodge","huanhua-steps");
        
        setup();
        carry_object("obj/armor/cloth")->wear();
        carry_object("obj/weapon/sword")->wield();
}

