// serpent.c

inherit NPC;

void create()
{
        set_name("红冠巨蟒", ({ "serpent" }) );
        set("long", "一只乌黑油亮的巨蟒，头上生著一个通红的大肉瘤。\n");

        set("race", "蛇类");
        set("age", 400);
        set("attitude", "aggressive");

        
        set("cor", 70);
        set("int", 10);

        set_temp("apply/attack", 350);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 300);
        set_temp("apply/dodge",300);

        set("combat_exp", 2000000);
        
        setup();
}
