
inherit NPC;

void create()
{
        set_name("藏獒", ({ "wolfdog" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 10);
        set("long", "这是一只西域出产的凶猛无比的狼犬，皮糙肉厚，力大无比。\n");
        
   //     set("str", 50);
        
        set("attitude", "friendly");

        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "藏獒在你脚边转来转去，用警惕的目光打量着你。\n"
        }) );
        set("combat_exp", 1200000);
                
        set_temp("apply/attack", 250);
        set_temp("apply/dodge",200);
        set_temp("apply/move",320);
        set_temp("apply/armor",100);
        set_temp("apply/damage",30);
        
        setup();
}
